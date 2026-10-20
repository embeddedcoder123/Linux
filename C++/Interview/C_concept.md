# Example of writing to a register

```c
// Define a pointer to the register (volatile means it can change externally)
volatile unsigned int * const WDT_CONTROL = (unsigned int *)0x40000000;

// Write the value 0x01 to the watchdog control register
*WDT_CONTROL = 0x01;
```

Or using macro:

```c
#define WDT_CONTROL (*(volatile unsigned int *)0x40000000)

WDT_CONTROL = 0x01;  // Write 0x01 to the watchdog control register
```
--------------------------------

# Register Storage class in C

✅ Key Points: register in Embedded C
| Feature                     | Details                                                                                                 |
| --------------------------- | ------------------------------------------------------------------------------------------------------- |
| 🧠 **Purpose**              | Suggests that a variable should be stored in a **CPU register** for fast access                         |
| ⚙️ **Used For**             | Frequently accessed **local variables** in **tight loops** (e.g., counters, flags)                      |
| 🚫 **No Address Access**    | You **cannot use `&` (address-of)** with `register` variables — registers may not have memory addresses |
| 🔍 **Scope**                | Only allowed for **local variables inside functions** — not global/static                               |
| ⚠️ **Compiler Behavior**    | It's only a **hint** — **modern compilers may ignore it**, especially with optimization flags           |
| 📉 **Obsolete in Practice** | Rarely needed today; **compilers handle register allocation better** than humans                        |
| ❌ **Not for HW Registers**  | **Do NOT use `register` for memory-mapped hardware registers** — use `volatile` instead                 |
| ⚠️ **C++ Support**          | `register` is **deprecated in C++17** and removed in C++20 — has **no effect**                          |


What is Debouncing?

Mechanical buttons tend to bounce when pressed or released — the signal toggles between high and low several times quickly. You need to "debounce" it by ignoring fluctuations for a short period (e.g., 5–10 ms).


```c
#define BUTTON_PIN     (*(volatile uint32_t*)0x40010000)  // Hardware-mapped I/O register

void debounce_button() {
    register int stable_count = 0;  // Used frequently in loop
    const int stable_threshold = 1000;

    while (1) {
        if (BUTTON_PIN & 0x01) {  // Check if button is pressed
            stable_count++;
            if (stable_count >= stable_threshold) {
                // Button is stable; take action
                toggle_led();
                break;
            }
        } else {
            stable_count = 0;  // Reset if input is unstable
        }
    }
}
```

# Input : My name is Haresh | Output : Haresh is name My

```c
#include <stdio.h>
#include <string.h>
void swap (char *p, char *q){
    char temp = *p; 
    *p = *q; 
    *q = temp;
}

void reverse_str (char *start , char *last) {
    while (start < last) {
        swap (start, last);
        start++;
        last--;
    }
}

void reverse_words(char *str){
   char *start = str;
   char *end = str;
   reverse_str(start , start + strlen(str) -1);
   while (1) {
       if(*end == ' ' || *end == 0) {
          reverse_str(start, (end-1));
          start = end +1;
          if(*end == 0) break;
       }
       end++;
   }
}


int main (){
    char name[] = "My name is Haresh";
    reverse_words(name);
    printf("%s", name);
    return 0;
}
```

## Reverse string using pointrt
```c
#include <stdio.h>

void reverse_string(char *str){
    if (str == NULL) return;
    char *left = str, *right;
    
    while (*str != '\0') { str++; }
    
    right = str -1;
    
    char temp;
    while (left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        
        left++; right--;
    }  
}
int main()
{
    char str[] = "Embeddded";
    reverse_string(str);
    printf("%s", str);

    return 0;
}
```

## find first non repeating char
```c
char first_n_reteat_char(char *str) {
    
    int count[256] = {0};
    // int count[256] = {-1}; first non repeating char
    char* p = str;
    while (*p) {
        count[(unsigned char)(*p)]++;
        *p++;
    }
     p = str;
    while (*p) {
        if (count[(unsigned char)(*p)] == 1) {
            return *p;
        }
        p++;
    }
    
    return '\0';
}
int main()
{
    char str[] = "embedddedmcb";
    
    printf("%c", first_n_reteat_char(str));

    return 0;
}
```

## remove duplicate character

```c
void remove_duplicate_char(char *name) {
    char seen[256] = {0};
    char read = 0, i = 0;
    char ch;
    while (name[read]) {
        ch = name[read];
        if (!seen[ch]) {
            seen[ch] = 1;
            name[write++] = ch;
        }
        read++;
    }
    name[write] = '\0';
}
```

## Rorate string character

### right side rotation
```c
void rotate_string (char *str, int n) {
    int len = strlen(str) -1 ;
    
    /*
        1. Reverse string ABCED -> DECBA 
        2. reverse only first times of rotatation character DE | CBA => ED | CBA
        3. Reverse let character ED | CBA => ED | ABC => EDABC
    */
    int len = strlen(str);
     
    n %= len;
    reverse_range(str, str + len - 1);

    reverse_range(str, str + n - 1);
     
    reverse_range(str + n, str + len - 1);
     
    
}
```

### left side rotation

```text
Original:
AB | CDE

Reverse First Part:
BA | CDE

Reverse Second Part:
BA | EDC

Reverse Whole String:
CDEAB
```


```c
void rotate_left(char *str, int n)
{
    int len = strlen(str);
     
    n %= len;
     
    reverse_range(str, str + n - 1);
     
    reverse_range(str + n, str + len - 1);
     
    reverse_range(str, str + len - 1);
}
```
## Init 2d array

```c
void array2d_init (void) {
    int col = 5, row = 5;
    
    int **arr = (int **)malloc(col * sizeof(int *));
    
    for (int i =0;i < col;i++) {
        arr[i] = (int *)malloc(row * sizeof(int *));
    }
    
    arr[2][3] = 100;
    printf("%d", arr[2][3] );
    
    for (int i =0;i < col;i++) {
        free(arr[i]);
    }
     free(arr);
}
```

# longest_sunstring

```c
#include <iostream>


void longest_substring(char *str) {
    
    char last_index[256] = {-1};
    
    int right = 0, left =0 , start_index, current_len = 0, max_len;
    for (;str[right]; right++) {
        unsigned char ch = str[right];
        
        if (last_index[ch] >= left) {
            left = last_index[ch] + 1;
        }
        
        last_index[ch] = right;
        
        current_len = right - left + 1;
        
        if(current_len > max_len) {
            max_len = current_len; start_index = left;
        }
    }
    
    printf("length of substring : %d :substring: ", max_len);
    
    for (int i = start_index ;i < start_index + max_len; i++) {
        printf("%c", str[i]);
    }
}



int main()
{
    char name[] = "Hareshpanchal";
    longest_substring(name);

    return 0;
}

// length of substring : 8 :substring: reshpanc
```
-----------------------
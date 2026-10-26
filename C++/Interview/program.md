- [C](#c)
  - [1. Bit Iteration](#1-bit-iteration)
  - [2. Checking stroing Palimdrom](#2-checking-stroing-palimdrom)
  - [3. Prime Number](#3-prime-number)
  - [4. Perfect number](#4-perfect-number)
  - [5. armstrong number](#5-armstrong-number)
  - [6. Count Character in String](#6-count-character-in-string)
  - [7. Number pattern using recursion](#7-number-pattern-using-recursion)
    - [0 1 2 3 4 5 4 3 2 1 0](#0-1-2-3-4-5-4-3-2-1-0)
    - [Prime number](#prime-number)
    - [perfect number](#perfect-number)
    - [armstrong](#armstrong)
  - [8. words reverse](#8-words-reverse)
  - [9. string to word](#9-string-to-word)
  - [10. Array Operation](#10-array-operation)
  - [11. Sorting methods](#11-sorting-methods)
    - [1. Selection Sort logic](#1-selection-sort-logic)
    - [2. Bubble Sort logic](#2-bubble-sort-logic)
  - [12. Function Pointer](#12-function-pointer)
  - [13. callback Function](#13-callback-function)
  - [14.	File handling](#14file-handling)
  - [15.	2D array](#152d-array)
  - [16. 2D array using dynamic memory](#16-2d-array-using-dynamic-memory)
  - [17.	3D Array](#173d-array)
  - [18. Matrix Multiplication](#18-matrix-multiplication)
  - [19. Count character in string](#19-count-character-in-string)
  - [20. find sub vector of sorted input vector with minimimum difference;](#20-find-sub-vector-of-sorted-input-vector-with-minimimum-difference)
  - [20. find number of delete char in two string which is not same](#20-find-number-of-delete-char-in-two-string-which-is-not-same)
  - [21. Binary Search in C](#21-binary-search-in-c)
  - [22. Example of writing to a register](#22-example-of-writing-to-a-register)
  - [23. # Register Storage class in C](#23--register-storage-class-in-c)
  - [24. What is Debouncing?](#24-what-is-debouncing)
  - [25. Reverse string using pointrt](#25-reverse-string-using-pointrt)
  - [26. find first non repeating char](#26-find-first-non-repeating-char)
  - [27. remove duplicate character](#27-remove-duplicate-character)
  - [28. Rorate string character](#28-rorate-string-character)
    - [right side rotation](#right-side-rotation)
    - [left side rotation](#left-side-rotation)
  - [29. longest\_sunstring](#29-longest_sunstring)

# C 
## 1. Bit Iteration

```c
#include <stdio.h>

#define SetBit(num,pos)  	num |= (1<<pos)
#define ClearBit(num,pos)  	num &= ~(1<<pos)
#define ToggleBit(num,pos)  num ^= (1<<pos)
#define BitStatus(num,pos)  (num>>pos) & 1

void print_binary(int num)
{
   // print binary of number
    int pos = 0;
    for( pos=15;pos>=0;pos--)
    {
        printf("%d",BitStatus(num,pos));   //print perticular bit
        if((i)%4 == 0) printf(" ");
    }  
    printf("\n");
}


int main()
{
    int num = 0x1234;
    printf("print Binary of Number\n");
    print_binary(num);
    
    SetBit(num,0);
    printf("print Set Binary of Number\n");
    print_binary(num);
     
    ClearBit(num,9);
    printf("print Clear Binary of Number\n");
    print_binary(num);
    
    ToggleBit(num,5);
    printf("print Toggle Binary of Number\n");
    print_binary(num);
  
    return 0;
}

/*Output

print Binary of Number
0001 0010 0011 0100 
print Set Binary of Number
0001 0010 0011 0101 
print Clear Binary of Number
0001 0000 0011 0101 
print Toggle Binary of Number
0001 0000 0001 0101
*/

 ```
## 2. Checking stroing Palimdrom 

```c
string s = "dasabcbasadsd";

int i =0 ;
for(i = 0; s[i]; i++);
int len = i -1 ;
int j;
for(i = len,j=0; (i > j); i--, j++)
{
    /* char temp = s[i];
    s[i] = s[j];
    s[j] = temp;*/
    if(s[i] != s[j])
        break;
}

if(i == j )
{
    cout<< "true\n";
}
else
{
    cout<< "false\n";
}



// reverse string 
string s = "dasabcbasadsd";

int i =0 ;
for(i=0;s[i];i++);
int len = i;
int j;
for( i=len-1,j=0 ;i>j; i--,j++ )
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    
}
	
	
	//using recursion
void My_stringrev(char* first,char*last){
	if(first<last)
	{
		*first = (*last + *first)-(*last = *first);
		My_stringrev(first + 1,last - 1);
	}
}

main()
{	
	int i =0 ;
     for( i = 0;s[i];i++);
	int len = i;
	char* first = &str[0];
    char* last = first + len - 1;   
    My_stringrev(first,last);
}

```
## 3. Prime Number

```c
int main()
{
    int limit = 200;
    int i,j;
    for( i = 0; i< limit; i++){
        for(j = 2; j<i; j++){
            if(i % j){
                continue;
            }
            else{
                break;
            }  
        }
        
        if(i == j)
            cout<<i<<" , ";
    }
    return 0;
}
```
## 4. Perfect number

```c
int main()
{
    int limit = 20000;
    int i,j;
    for(i = 0; i<limit; i++){
        int sum = 0;
        for( j = 1; j< i; j++){
            if(i % j == 0){
                sum += j;
            } 
        }
        
        if(i == sum)
            cout<<i<<" , ";
    }
    return 0;
}
```
## 5. armstrong number

```c
using namespace std;
int main()
{
    int limit = 200;
    int i,j;
    int num;
	
    for( num = 0; num< limit;num++){
        int j = num;
        int temp = 0;
        for(  ;j; j = j/10 ){
            int k = j % 10;
            temp  = temp +  (k*k*k);    
        }
		
        if(temp == num){
        	cout<<num<<" , ";
        } 
    }
    return 0;
}
```
## 6. Count Character in String
```cpp
#include<iostream>
#include<map>
#include<iterator>
#include<sstream>
using namespace std;
 
int main()
{
	string str = "ABBCCCDDDDEEEEEFFFFFF";
	stringstream ss(str);
	char ch;
	map<char,int> mp;
	
	while(ss >> ch)
	{
		mp[ch]++;
	}
	map<char,int>::iterator it;
    for(it = mp.begin();it != mp.end() ;++it){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}

	cout<<endl;
	for(auto i : mp)
	cout<< i.first<<" "<<i.second<<endl;
		
	return 0;	
}
```

```c
int main()
{
	char str [] =   "ABCABCDDFFRFFFRR";
	int i,j,cnt =0;
	
	for(i = 0;str[i] != 0;i++);
	int str_len = i;

	for(i = 0 ;i< str_len;i++){
		cnt = 1;
	   if(str[i] != 0){
			for( j = i + 1;j < str_len;j++){
				if(str[i] == str[j]){
					cnt++;
					str[j]='\0';
				}
			 }
			cout<<str[i]<<" "<<cnt<<endl;
       }
    }
    return 0;
}
//Other mathod
int main()
{
    char* str = "abbcccddddeee  122121 ^^$&*$&*";
    int arr[500] = {0};
    int i;
    for(i = 0;i , str[i]!= 0;i++)
    {
        arr[str[i]]++;
    }
    for(i =0;i<500;i++)
    {
        if(arr[i] != 0)
        {
            printf("%c\t%d\n",i,arr[i]);
        }
    }
    return 0;
}
```

## 7. Number pattern using recursion

### 0 1 2 3 4 5 4 3 2 1 0 
```c
#include<stdio.h>

void ZeroNumZero(int num)
{
	static int n  = 0;
	if(n <= num && n >= 0)
	{
		printf(" %d ",n);
		n = n+1;
		ZeroNumZero(num);
		n = n-1;
		if(n > 0){printf(" %d ",n-1);}
	}
}

### 5 4 3 2 1 0 1 2 3 4  5
void NumZeroNum(int num)
{
	if(num >= 0)
	{
		printf(" %d ",num--);
		NumZeroNum(num);
	    if(num>=0)printf(" %d ",++num);
	}
}
int main()
{
	int num = 5;
	ZeroNumZero(num);
	printf("\n");
	NumZeroNum(num);
	return 0;
}
```
### Prime number
```c
int isPrime(int num) {
    for(int i=2; i<num; i++) {
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

//Optimized Way
int isPrimeOptimized(int num) {
    for(int i=2; i<sqrt(num); i++){ //(i<n/2) also used 
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}
int isPrimeOptimized1(int num) {
    for(int i=2; i<num/2; i++) { //(i<n/2) also used 
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}
```
### perfect number

```c
int isPerfact(int num) {
    int sum =0;
    for(int i =1; i<num; i++){
        if(num%i == 0) sum += i;
    }
    if(sum ==num) return 1;
    else return 0;
}

```

### armstrong
```c
int isArmstrong(int num){
    int temp = num;
    int sum =0;
    for(;temp;temp /= 10){
        int i = temp%10;
        sum +=(i*i*i);
    }
    if(sum == num) return 1;
    else return 0;
}

```
## 8. words reverse 
```c
/*
Input:  Hello how are you!
Output: you! are how Hello
*/
#include <stdio.h>
#include <string.h>

void reverse_range (char *left, char *right) {
    while (left < right) {
        char temp = *left; *left = *right; *right = temp;
        left ++; right --;
    }
    
}
void reverse_words(char *str) {
    reverse_range(str, str + strlen(str)- 1);

    char *left = str, *right = str;
    while(*str) {
        if (*str == ' '){
            right = str - 1 ;
            reverse_range (left,right);
            left = str + 1;    
        }
        str++;
    }
    
    reverse_range(left, str-1);
}

int main()
{
    char str[] = "Hello how are you!";
    printf("Input:  %s\n", str);
    reverse_words(str);
    printf("Output: %s\n", str);
    return 0;
}
```

## 9. string to word

```c
void string_array(char *in, char** out, int *len) {
     char *str = in;
     *len = 0;
     while (*in) {
        if (*in == ' '){
            *in = '\0';
            *(out + *len) = str;
            (*len)++;
            //printf("debug: %s\n", str);
            str = in + 1;
        }
        in++;
     }
     *(out + *len) = str;
     (*len)++;
}

int main()
{
    char str[] = "Hello how are you!";

    char *name[10]; 
    int *len;
    string_array(str, name, len);

    for (int i=0; i < *len; i++) {
        printf("word %d %s: \n",i,name[i]);
    }
    return 0;
}
/*
word 0 Hello: 
word 1 how: 
word 2 are: 
word 3 you!: 
*/
```

## 10. Array Operation

```c
#include <stdio.h>

//Insert in array and delete duplicate 

 void  swap (int* p ,int *q)
{
    *q = (*p + *q) - (*p = *q); 
}

void remove_duplicate(int *arr, int *len) {
    for(int i=0; i < *len; i++) {
        for(int j=i+1; j < *len; j++) {
            if(arr[i] == arr[j]) {
                for (int k = j; k < (*len) -1; k++) {
                    arr[k] = arr[k+1];
                }
                (*len)--;
            }
        }
    }
}

void insert_at(int *arr, int *len, int pos, int val) {
    if (*len < pos ) {
        printf("Position is out of range...\n"); return;
    }
   
    *len = *len +1;
    for(int i = *len; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
}

void printArray(int* arr, int size){
    
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    
    int arr[] = {10,20,30,40,50,30,2,10,56,25,40,20};
    int ele  = sizeof(arr)/sizeof(arr[0]);
    for(int I_ = 0;I_ < ele;I_ ++)
            printf("%d ",arr[I_]);
     printf("\n");       
    int i , j ,temp;
   /* for(i = 0,j = ele - 1; i < j;i++,j--)
    {
        swap(&arr[i],&arr[j]);
    }*/
   ele =  delet_duplicate(arr,ele);
   printArray(arr,ele);
 
   ele = intsetAt(arr,3,5623,ele);
   printArray(arr,ele);
    
    return 0;
}
```
## 11. Sorting methods

### 1. Selection Sort logic

```text
/*Example
10 8 7 12 3 

3 
3 7
3 7 8
3 7 8 10
3 7 8 10 12
In every Pass Accending value is filled  
```
```c

void swap(int *p, int *q)
{
	*p = (*q + *P)-(*q =*P);
}

void selection_sort(int *arr, int len) {
   
    for (int i=0; i<(len-1); i++) {
        for (int j=(i+1); j<len; j++) {
            if (arr[i] > arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

```
### 2. Bubble Sort logic	

```text
10 8 7 12 3 

         12
      10 12
    8 10 12
  7 8 10 12
3 7 8 10 12

In every Pass Decending value is filled  
```
```c
void bubble_sort(int *arr, int len) {
    for(int i=0; i<len-1; i++){
        for(int j=0; j<(len-i-1); j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

```
## 12. Function Pointer
```c
#include <stdio.h>
int SUM(int a,int b){return (a+b);}
int main() {
    
	int(*FunPtr1)(int,int) = &SUM;
	printf("FunPtr1 %d \n",(*FunPtr1)(10,20));
	
	int(*FunPtr2)(int,int) = SUM;
	printf("FunPtr2 %d \n",(FunPtr2)(10,20));
    return 0;
}


/* Function Pointer 
Functin pointing to functin SUM which takes two arguments int type and 
returns integer.

FunPtr1 => this is fuction pointer pointing a function that takes two arguments and return int;

/* CallBack Function 
Function takes arguments as a function pointer in call back function 
*/
```
## 13. callback Function 
```c
#include <stdio.h>
int SUM(int a,int b){return (a+b);}
int SUB(int a,int b){return (a-b);}
int MUL(int a,int b){return (a*b);}
int DIV(int a,int b){return (a/b);}

int callBack_fun(int(*FunPtr1)(int,int),int a ,int b)
{
	return(FunPtr1(a,b));
}

int main() {
	printf("SUM  %d \n", callBack_fun(SUM,1000,200));
	printf("SUB  %d \n", callBack_fun(SUB,1000,200));
	printf("MUL  %d \n", callBack_fun(MUL,1000,200));
	printf("DIV  %d \n", callBack_fun(DIV,1000,200));

    return 0;
}

/* CallBack Function 
Function takes arguments as a function pointer in call back function 
*/
```

## 14.	File handling 
// information about tellg `seekg` , `tellp` and `seekp`

 put pointer to `put/write` a data on the file.

In C++ we have a get pointer to get/read data from a file.

https://www.quora.com/What-are-seekg-seekp-tellg-and-tellp-functions

## 15.	2D array
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 2D static and Dynamic array

int main()
{
    int arr[3][4] = {{10,20,30,40},
			       {50,60,70,80},
               	   {90,100,110,120}};

  int (*ptr)[4] = arr; // pointer is points to int array contain 4 elements

 // int *p[3]; // dont confuse, here p is int pointer

  int size_row = sizeof(arr)/sizeof(arr[0]);
  int size_col = sizeof(arr[0])/sizeof(arr[0][0]);
  printf("row_size %d \n",size_row);
  printf("size_col %d \n",size_col);
  int rownum, colnum;
  for(rownum = 0; rownum < size_row; rownum++)
  {
	  for(colnum =0; colnum<size_col; colnum++)
	  {
		  printf("%d ",*(*(ptr+rownum)+colnum));
	  }
	  printf("\n");
  }
}
```
## 16. 2D array using dynamic memory 

```c
int row=3, col=4;
   
   /***************Method 1*********************/
   int **p = (int**)malloc(sizeof(int*)*row);
   
   for(int j=0; j<row; j++) {
	    p[j] = (int*)malloc(sizeof(int)*col);
   }

   for(int j=0; j<row; j++) {
	   for(int k =0; k<col; k++) {
		   *(*(p+j)+k) = (j*10)+k+1;
	   }
   }
   
   // print element
   for(int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
   }
   
   // delete row
   for(int i=0; i<row; i++) {
       free (p[i]);
   }

   // delete p
   free(p);

/***************Method 2*********************/

    int (*arr)[col] = (int(*)[col])malloc(row*sizeof(*arr)); // *arr means
    // (int(*)[col]) is not required it will done automatically

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            *(*(arr+i)+j) = (i*10)+j;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
    free(arr); 
```

## 17.	3D Array
```c
#include<stdio.h>
#include<stdlib.h>

int main()
{
    /************** Method-1 ********************/
    int ***ptr = (int***)malloc(M*sizeof(int **));
    
    if (ptr == NULL) return 1;
    for(int i=0; i<M; i++) { 
        ptr[i] = (int**)malloc(N * sizeof(int*));
        if (ptr[i] == NULL) return 1;
        
        for(int j=0; j<N; j++) {
            ptr[i][j] = (int*)malloc(O * sizeof(int *));
            if (ptr[i][j] == NULL) return 1;
        }
    }

    // assign values
    for(int i=0; i<M; i++) {         
        for(int j=0; j<N; j++) {
            for(int k=0; k<O; k++) {
                ptr[i][j][k] = (i*10)+ (j*20)+k;
            }
        }
    }

    // print 
    for(int i=0; i<M; i++) {         
        for(int j=0; j<N; j++) {
            for(int k=0; k<O; k++) {
                printf("%d ", ptr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free memory

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            free(ptr[i][j]);
        }
        free(ptr[i]);
    }
    free(ptr);
    /************** Method-2 ********************/
    
    int (*p)[N][O] = malloc(M * sizeof(*p));
    if(p == NULL) {
        printf("Memory allocation failed\n"); return 1;
    }

    for(int i=0; i<M; i++) {         
        for(int j=0; j<N; j++) {
            for(int k=0; k<O; k++) {
                p[i][j][k] = (i*10)+(j*20)+(k*30);
            }
        }
    }

    for(int i=0; i<M; i++) {         
        for(int j=0; j<N; j++) {
            for(int k=0; k<O; k++) {
                printf("%d ", p[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    // free memory
    free(p);
}

```
## 18. Matrix Multiplication

```c
#include <stdio.h>
#include <stdlib.h>

// matrix dimensions so that we dont have to pass them as
// parametersmat1[R1][C1] and mat2[R2][C2]
#define R1 2 // number of rows in Matrix-1
#define C1 2 // number of columns in Matrix-1
#define R2 2 // number of rows in Matrix-2
#define C2 3 // number of columns in Matrix-2

void multiplyMatrix(int m1[][C1], int m2[][C2])
{
	int result[R1][C2];

	printf("Resultant Matrix is:\n");

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			result[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}

			printf("%d\t", result[i][j]);
		}

		printf("\n");
	}
}

// Driver code
int main()
{
	// R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these
	// values in MACROs)
	int m1[R1][C1] = { { 1, 1 }, { 2, 2 } };

	int m2[R2][C2] = { { 1, 1, 1 }, { 2, 2, 2 } };

	// if coloumn of m1 not equal to rows of m2
	if (C1 != R2) {
		printf("The number of columns in Matrix-1 must be "
			"equal to the number of rows in "
			"Matrix-2\n");
		printf("Please update MACROs value according to "
			"your array dimension in "
			"#define section\n");

		exit(EXIT_FAILURE);
	}

	// Function call
	multiplyMatrix(m1, m2);

	return 0;
}
```
## 19. Count character in string 
```c
#include<stdio.h>

int main(){
    char str[] = "AAABSBDGkmflkdfjlksvdgvfghfghdvf";
    char arr[500] ={0};
    for(int i=0;str[i];i++){
        arr[str[i]]++;
    }
    for(int i=0;i<500;i++){
        if(arr[i] != 0){
            printf("%c: %d\n",i,arr[i]);
        }
    }
    return 0;
}
```
```cpp
#include <iostream>
#include<map>
#include<sstream>
using namespace std;
int main() {
    string str = "ACGFCGDVGmhdsbcvjnvknvf";
    stringstream ss(str);
    char ch;
    map<char,int>m;
    while(ss>>ch){
        m[ch]++;
    }
    for(auto c : m){
        cout<<c.first<<" :"<<c.second<<endl;
    }
    return 0;
}
```
```cpp
#include <iostream>
#include<map>
using namespace std;
int main() {
    string str = "ACGFCGDVGmhdsbcvjnvknvf";
    map<char,int>m;
    for(auto c : str){
        m[c]++;
    }
    for(auto c : m){
        cout<<c.first<<" :"<<c.second<<endl;
    }
    return 0;
}
```

## 20. find sub vector of sorted input vector with minimimum difference;

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMinDiff(vector<int>& arr) {
    if (arr.size() < 2) {
        cout << "At least two elements are required.\n";
        return;
    }

    int minDiff = INT_MAX;
    int first, second;

    for (int i = 1; i < arr.size(); i++) {
        int diff = arr[i] - arr[i - 1];

        if (diff < minDiff) {
            minDiff = diff;
            first = arr[i - 1];
            second = arr[i];
        }
    }

    cout << "Minimum difference: " << minDiff << '\n';
    cout << "Pair: " << first << ", " << second << '\n';
}

int main() {
    vector<int> arr = {1, 4, 8, 10, 15};

    findMinDiff(arr);
    return 0;
}

/*
Minimum difference: 2
Pair: 8, 10
*/
```

## 20. find number of delete char in two string which is not same
- (An anagram is word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once)

```cpp
#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

int count_del(map<char,int> mp1, map<char,int>mp2 ){
     int del_count = 0;
     for(auto ele : mp1){
            if(mp2.find(ele.first) != mp2.end()){
                del_count += abs(.second - mp2[eleele.first]);
            }
            else{
                del_count++;
            }
        }
        return del_count;
}
int main(){

    string str1 = "abac";
    string str2 = "aabcefgad6789";
    int del_count = 0;
    map<char,int>mp1;
    map<char,int>mp2;
    for(auto ch : str1) mp1[ch]++;
    
    for(auto ch : str2) mp2[ch]++;
    
    if(mp1.size() > mp2.size()){
        del_count = count_del(mp1,mp2);
    }
    else{
        del_count = count_del(mp2,mp1);
    }

   
    cout<<"max delete character is: "<<del_count;
    return 0;
}
```

## 21. Binary Search in C
```cpp
#include <iostream>
int binary_search(int arr[],int l,int r,int val){
    
    while(l <= r){
        
        int m = l + ((r-l) /2);
        
        if(arr[m] == val) return m;
        
        if(val > arr[m]){
            l = m + 1;            
        }
        else{
            r = m - 1;
        }
    }
    
    return -1;
}

int main()
{
    int a[] = {10,30,40,60,70,80,100,120,140,160};
    
    int ele = sizeof(a)/sizeof(a[0]);
    int value_search =70;
    int n = binary_search(a,0,ele,value_search);
    if(n == -1){
        std::cout<<"element is not present in array\n";
    }
    else{
        std::cout<<value_search<<" is located at: "<<n;
    }
    
    std::cout<<"\nEnd of main....";

    return 0;
}
```

## 22. Example of writing to a register

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
## 23. # Register Storage class in C

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

## 24. What is Debouncing?

> Mechanical buttons tend to bounce when pressed or released — the signal toggles between high and low several times quickly. You need to "debounce" it by ignoring fluctuations for a short period (e.g., 5–10 ms).

```c
#define BUTTON_PIN (*(volatile uint32_t*)0x40010000)  // Hardware-mapped I/O register

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

## 25. Reverse string using pointrt

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
## 26. find first non repeating char
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

## 27. remove duplicate character

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
## 28. Rorate string character

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

## 29. longest_sunstring

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
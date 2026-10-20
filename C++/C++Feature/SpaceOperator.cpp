#include <iostream>
#include <compare>
#include <string>

class Employee {
public:
    int id;
    std::string name;
    double salary;

    Employee(int i, std::string n, double s) : id(i), name(n), salary(s) {}

    // Spaceship operator
    auto operator<=>(const Employee& other)const  -> std::partial_ordering {
        if (auto cmp = id <=> other.id; cmp != 0) {
            return cmp;
        }
        if (auto cmp = name <=> other.name; cmp != 0) {
            return cmp;
        }
        return (salary <=> other.salary);
    }

    // Equality operator (optional, for demonstration)
    bool operator==(const Employee& other) const = default;
};

int main() {
    Employee emp1(1, "Alice", 50000);
    Employee emp2(2, "Bob", 60000);
    Employee emp3(1, "Alice", 50000);

    if (emp1 < emp2) {
        std::cout << "emp1 is less than emp2\n";
    } else if (emp1 > emp2) {
        std::cout << "emp1 is greater than emp2\n";
    } else {
        std::cout << "emp1 is equal to emp2\n";
    }

    if (emp1 == emp3) {
        std::cout << "emp1 is equal to emp3\n";
    } else {
        std::cout << "emp1 is not equal to emp3\n";
    }

    return 0;
}
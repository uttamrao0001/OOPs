# Object-Oriented Programming (OOP) in C++

## 1. Basic OOP Concepts

### 1.1 Class and Object

- **Class**: A class in C++ is a user-defined data type that acts as a blueprint for creating objects. It encapsulates data members (variables) and member functions (methods) that operate on the data.
  A class can be understood as a template or a blueprint, which contains some values, known as member data or member, and some set of rules, known as behaviors or functions. So when an object is created, it automatically takes the data and functions that are defined in the class.
  Therefore the class is basically a template or blueprint for objects. Also one can create as many objects as they want based on a class.

- **Object**: An object is an instance of a class. When a class is defined, no memory is allocated until an object of that class is created.

```cpp
class Car {
public:
    string brand;
    int year;

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car c1;
    c1.brand = "Toyota";
    c1.year = 2022;
    c1.display();
    return 0;
}
```

### 1.2 Encapsulation

- Wrapping data and functions together to protect data from direct access.
- Use private/protected access specifiers.

#### Two Important property of Encapsulation

- **Data Protection**: Encapsulation protects the internal state of an object by keeping its data members private. Access to and modification of these data members is restricted to the class’s public methods, ensuring controlled and secure data manipulation.
- **Information Hiding**: Encapsulation hides the internal implementation details of a class from external code. Only the public interface of the class is accessible, providing abstraction and simplifying the usage of the class while allowing the internal implementation to be modified without impacting external code.

#### Features of Encapsulation

- We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class.
- The function which we are making inside the class must use only member variables, only then it is called encapsulation.
- If we don’t make a function inside the class which is using the member variable of the class then we don’t call it encapsulation.
- Encapsulation improves readability, maintainability, and security by grouping data and methods together.
- it helps to control the modification of our data members.

#### The process of implementing encapsulation can be sub-divided into two steps:

- Creating a class to encapsulate all the data and methods into a single unit.
- Hiding relevant data using access specifiers.

```cpp
class BankAccount {
private:
    double balance;
public:
    void setBalance(double b) { balance = b; }
    double getBalance() { return balance; }
};
```

### 1.3 Abstraction

- Abstraction means displaying only essential information and hiding the details.

#### Abstraction Types:

- **Abstraction using Classes**: We can implement Abstraction in C++ using classes. The class helps us to group data members and member functions using available access specifiers. A Class can decide which data member will be visible to the outside world and which is not.
- **Abstraction in Header files**: One more type of abstraction in C++ can be header files. For example, consider the pow() method present in math.h header file. Whenever we need to calculate the power of a number, we simply call the function pow() present in the math.h header file and pass the numbers as arguments without knowing the underlying algorithm according to which the function is actually calculating the power of numbers.

```cpp
class AbstractCar {
public:
    virtual void startEngine() = 0; // Pure virtual function
};

class BMW : public AbstractCar {
public:
    void startEngine() override { cout << "BMW Engine Started" << endl; }
};
```

### 1.4 Inheritance

- Mechanism of deriving new classes from existing classes.
- Supports **Single, Multiple, Multilevel, Hierarchical, and Hybrid** inheritance.
- **Single Inheritance**- child class derived directly from the base class;
- **Multiple Inheritance**-Child class derived from multiple base class;
- **Multilevel Inheritance**-child class derived from the class which is also derived from the another base class;
- **Hierarchical Inheritance**-multiple child derived from a single base class.
- **Hybrid Inheritance**-Inheritance consisting of multiple inheritance types of the above specified.

```cpp
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking..." << endl; }
};
```

### 1.5 Polymorphism

- Ability to take multiple forms (Compile-time and Runtime polymorphism).
- **Function Overloading** and **Operator Overloading** (Compile-time).
- **Method Overriding** (Runtime, using virtual functions).

| Polymorphism Type             | Description                                                     | Examples                                                                                 |
| ----------------------------- | --------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| **Compile-time Polymorphism** | Polymorphism resolved at compile time.                          | Function Overloading, Operator Overloading, Template Overloading                         |
| **Runtime Polymorphism**      | Polymorphism resolved at runtime using dynamic method dispatch. | Function Overriding (via Virtual Functions), Interface Implementation (Abstract Classes) |

#### 1. Compile-time Polymorphism

##### Function Overloading

- When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded, hence this is known as Function Overloading. Functions can be overloaded by changing the number of arguments or/and changing the type of arguments.

```cpp
// function overloading or
// Compile-time Polymorphism
#include <bits/stdc++.h>

using namespace std;
class Geeks {
public:
    // Function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }

    // Function with same name but
    // 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }

    // Function with same name and
    // 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y
             << endl;
    }
};

// Driver code
int main()
{
    Geeks obj1;

    // Function being called depends
    // on the parameters passed
    // func() is called with int value
    obj1.func(7);

    // func() is called with double value
    obj1.func(9.132);

    // func() is called with 2 int values
    obj1.func(85, 64);
    return 0;
}
```

```cpp
// Function Overloading
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

// Virtual Function for Runtime Polymorphism
class Base {
public:
    virtual void show() { cout << "Base class" << endl; }
};
class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }
};
```

##### Operator Overloading

- C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can make use of the addition operator (+) for string class to concatenate two strings. We know that the task of this operator is to add two operands. So a single operator ‘+’, when placed between integer operands, adds them and when placed between string operands, concatenates them.

```cpp
// Operator Overloading or
// Compile-Time Polymorphism
#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // This is automatically called
    // when '+' is used with between
    // two Complex objects
    Complex operator+(Complex const& obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

// Driver code
int main()
{
    Complex c1(10, 5), c2(2, 4);

    // An example call to "operator+"
    Complex c3 = c1 + c2;
    c3.print();
}
```

#### 2. Runtime Polymorphism

- This type of polymorphism is achieved by Function Overriding. Late binding and dynamic polymorphism are other names for runtime polymorphism. The function call is resolved at runtime in runtime polymorphism. In contrast, with compile time polymorphism, the compiler determines which function call to bind to the object after deducing it at runtime.

##### Function Overriding:

-Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.

```cpp
// C++ program for function overriding with data members
#include <bits/stdc++.h>
using namespace std;

//  base class declaration.
class Animal {
public:
    string color = "Black";
};

// inheriting Animal class.
class Dog : public Animal {
public:
    string color = "Grey";
};

// Driver code
int main(void)
{
    Animal d = Dog(); // accessing the field by reference
                      // variable which refers to derived
    cout << d.color;
}
```

##### Virtual Function

- A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class.

- Some Key Points About Virtual Functions:
- Virtual functions are Dynamic in nature.
- They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class
- A virtual function is called during Runtime.

```cpp
// the Virtual Function
#include <iostream>
using namespace std;

// Declaring a Base class
class GFG_Base {

public:
    // virtual function
    virtual void display()
    {
        cout << "Called virtual Base Class function"
             << "\n\n";
    }

    void print()
    {
        cout << "Called GFG_Base print function"
             << "\n\n";
    }
};

// Declaring a Child Class
class GFG_Child : public GFG_Base {

public:
    void display()
    {
        cout << "Called GFG_Child Display Function"
             << "\n\n";
    }

    void print()
    {
        cout << "Called GFG_Child print Function"
             << "\n\n";
    }
};

int main()
{
    // Create a reference of class GFG_Base
    GFG_Base* base;

    GFG_Child child;

    base = &child;

    // This will call the virtual function
    base->display();

    // This will call the non-virtual function
    base->print();
}
```

```cpp
// C++ program for virtual function overriding
#include <bits/stdc++.h>
using namespace std;

class base {
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }

    void show() { cout << "show base class" << endl; }
};

class derived : public base {
public:
    // print () is already virtual function in
    // derived class, we could also declared as
    // virtual void print () explicitly
    void print() { cout << "print derived class" << endl; }

    void show() { cout << "show derived class" << endl; }
};

// Driver code
int main()
{
    base* bptr;
    derived d;
    bptr = &d;

    // Virtual function, binded at
    // runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, binded
    // at compile time
    bptr->show();

    return 0;
}
```

### Interface

- A unique class type known as an interface contains methods but not their definitions. Inside an interface, only method declaration is permitted. You cannot make objects using an interface. Instead, you must put that interface into use and specify the procedures for doing so.
- | Feature          | Abstract Class                                        | Interface                                                     |
  | ---------------- | ----------------------------------------------------- | ------------------------------------------------------------- |
  | Definition       | A class with at least one pure virtual function.      | A class with only pure virtual functions.                     |
  | Implementation   | Can have both implemented and pure virtual functions. | Cannot have implemented functions (only declarations).        |
  | Constructor      | Can have constructors.                                | Cannot have constructors.                                     |
  | Member Variables | Can have member variables.                            | Cannot have member variables.                                 |
  | Access Modifiers | Can have public, protected, and private members.      | Only public methods are allowed.                              |
  | Inheritance      | Supports single and multiple inheritance.             | Typically used for multiple inheritance.                      |
  | Usage            | Used when a base class provides some shared behavior. | Used when multiple unrelated classes need a common interface. |
  | Example          | `class Shape { virtual void draw() = 0; };`           | `struct IDrawable { virtual void draw() = 0; };`              |

### Static, Final

- | Keyword     | Description                                                             | Usage                                                     |
  | ----------- | ----------------------------------------------------------------------- | --------------------------------------------------------- |
  | `static`    | Defines a class member that belongs to the class rather than instances. | `static int count;`                                       |
  | `final`     | Prevents further inheritance or method overriding.                      | `class MyClass final {};` or `virtual void func() final;` |
  | `const`     | Declares a variable or function parameter as unmodifiable.              | `const int x = 10;`                                       |
  | `constexpr` | Evaluates expressions at compile time.                                  | `constexpr int square(int x) { return x * x; }`           |
  | `mutable`   | Allows modification of a member in a `const` object.                    | `mutable int counter;`                                    |
  | `volatile`  | Prevents compiler optimizations on a variable.                          | `volatile int flag;`                                      |
  | `override`  | Ensures a method overrides a base class method.                         | `void func() override;`                                   |
  | `delete`    | Prevents use of a function or operator.                                 | `void operator=(const MyClass&) = delete;`                |
  | `default`   | Uses the default implementation for special functions.                  | `MyClass() = default;`                                    |

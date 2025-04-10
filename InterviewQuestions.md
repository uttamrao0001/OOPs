# Important OOP Interview Questions with Answers

### Q1: What is the difference between Class and Struct in C++?

**Answer:**

- `class` members are **private** by default, whereas `struct` members are **public** by default.
- `struct` is preferred for Plain Old Data (POD), while `class` is used for OOP design.

### Q2: Explain Virtual Functions and their use.

**Answer:**

- #### Virtual Functions in C++

A **virtual function** is a member function in a base class that you can override in a derived class while ensuring dynamic (runtime) polymorphism. It allows function calls to be resolved at runtime rather than compile time.

### Syntax:

```cpp
class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Overriding virtual function
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* ptr;
    Derived d;
    ptr = &d;

    ptr->show(); // Calls Derived's show() due to runtime polymorphism
    return 0;
}

```

### Q3: What is the difference between a static and non-static method?.

**Answer:**
In C++, a static method is a member function of a class that can be called without an instance of the class. It belongs to the class itself, not to any instance of the class. A static method can access only static data members and other static methods of the class. It cannot access non-static data members or non-static methods of the class. Additionally, a static method can be called using the class name followed by the scope resolution operator (::) and the name of the method.

On the other hand, a non-static method is a member function of a class that can be called only on an instance of the class. It can access both static and non-static data members and methods of the class. Non-static methods are called using an instance of the class followed by the dot operator (.) and the name of the method.

### Q4: What is the purpose of an interface in OOP?.

**Answer:**
n object-oriented programming, an interface is a collection of abstract methods that define a set of behaviors that a class can implement. It is a contract between the class and the outside world that specifies what the class can do. An interface defines a set of methods that a class must implement, but it does not provide any implementation of those methods. Instead, the class that implements the interface provides the implementation of those methods.

The purpose of an interface is to provide a way to achieve abstraction in programming. It allows you to define a set of methods that a class must implement without specifying how those methods are implemented. This makes it possible to write code that can work with any class that implements the interface, without knowing the details of how the class works. Interfaces also provide a way to achieve polymorphism in programming, which allows you to write code that can work with objects of different classes as long as they implement the same interface.

### Q5: Explain the 4 pillars of OOP.

**Answer:**
The four pillars of Object-Oriented Programming (OOP) are Abstraction, Encapsulation, Inheritance, and Polymorphism.

**Abstraction:** Abstraction is the process of hiding complex implementation details and showing only the necessary information to the user. It allows the user to focus on what the object does instead of how it does it. Abstraction is achieved through abstract classes and interfaces.

**Encapsulation:** Encapsulation is the process of wrapping data and methods into a single unit, called a class. It provides data security by preventing unauthorized access to the data. Encapsulation also helps in code maintenance and reusability.

**Inheritance:** Inheritance is the process of creating a new class from an existing class. The new class inherits the properties and methods of the existing class. Inheritance allows the creation of a hierarchy of classes, where the child classes inherit the properties and methods of the parent class.

**Polymorphism**: Polymorphism is the ability of an object to take on many forms. It allows objects of different classes to be treated as if they were objects of the same class. Polymorphism is achieved through method overloading and method overriding.

### Q6: What is the difference between a public and private constructor?.

**Answer:**
A public constructor is accessible from anywhere, while a private constructor is only accessible within the same class. A public constructor can be used to create objects of a class from anywhere in the program, while a private constructor is typically used to restrict object creation to within the same class. Private constructors are often used in the Singleton design pattern, where only one instance of a class is allowed to exist.

### Q7: What is the difference between an abstract class and an interface?.

**Answer:**
An abstract class is a class that cannot be instantiated and is typically used as a base class for other classes to inherit from. An abstract class can contain both abstract and non-abstract methods, and can also have instance variables. An abstract class contains at least one pure virtual function. You declare a pure virtual function by using a pure specifier ( = 0 ) in the declaration of a virtual member function in the class declaration.
An interface, on the other hand, is a collection of abstract methods that can be implemented by any class. In C++, an interface is typically implemented using an abstract class with only pure virtual functions.

Note: Abstract method is a method that has no implementation and is declared using the abstract keyword.

### Q8: What is the difference between a shallow copy and a deep copy?.

**Answer:**
In programming, when we copy an object, we can either create a shallow copy or a deep copy. The main difference between the two is how they handle references to other objects.

A shallow copy creates a new object that is a copy of the original object, but the new object only contains references to the same memory locations as the original object. In other words, the new object points to the same memory locations as the original object, so any changes made to the original object will also be reflected in the new object. Shallow copy is a quick and efficient way to copy objects, but it can lead to unexpected behavior if the original object is modified.

A deep copy, on the other hand, creates a new object that is a copy of the original object, and all of its fields and references are also copied. In other words, a deep copy creates a new object with its own memory locations, so any changes made to the original object will not be reflected in the new object. Deep copy is a safer way to copy objects, but it can be slower and more memory-intensive than shallow copy.

```cpp
// Shallow copy
Person* person2 = person1;
person2->setAddress(new Address("456 Oak St", "Othertown"));
cout << person1->address->street << endl; // Output: 456 Oak St

// Deep copy
Person* person3 = new Person(person1->name, new    Address(person1->address->street, person1->address->city));
person3->setAddress(new Address("789 Pine St", "Somewhere"));
cout << person1->address->street << endl; // Output: 456 Oak St

```

### Q9:Explain different types of constructors.

**Answer:**

In C++, there are three types of constructors: default constructor, parameterized constructor, and copy constructor.

**Default Constructor:** A default constructor is a constructor that takes no arguments. It is called when an object is created without any arguments. If a class does not have any constructor defined, the compiler automatically generates a default constructor.

**Parameterized Constructor:** A parameterized constructor is a constructor that takes one or more arguments. It is used to initialize the object with the given values.

**Copy Constructor:** A copy constructor is a constructor that creates a new object by copying the values of an existing object. It is used to create a new object that is a copy of an existing object.

```cpp
class MyClass {
   public:
      int x, y;
      MyClass() {
         cout << "Default constructor called" << endl;
      }

      MyClass(int a, int b) {
         x = a;
         y = b;
         cout << "Parameterized constructor called" << endl;
      }

      MyClass(const MyClass &obj) {
         x = obj.x;
         y = obj.y;
         cout << "Copy constructor called" << endl;
      }
};
```

### Q10: What is a destructor in OOP?.

**Answer:**
In object-oriented programming (OOP), a destructor is a special member function that is called when an object is destroyed or goes out of scope. It is used to release any resources that were allocated by the object during its lifetime, such as memory, files, or network connections.

The destructor has the same name as the class, preceded by a tilde (~) symbol. It does not take any arguments and has no return type.

It is important to note that if a class does not have a destructor defined, the compiler will automatically generate a default destructor that does nothing. However, if a class allocates any resources during its lifetime, it is recommended to define a destructor to release those resources when the object is destroyed.

```cpp
class MyClass {
   public:
      MyClass() {
         cout << "Constructor called" << endl;
      }
      ~MyClass() {
         cout << "Destructor called" << endl;
      }
};

int main() {
   MyClass obj;
   return 0;
}
```

### Q10: What is the difference between encapsulation and data abstraction?.

**Answer:**
Encapsulation and data abstraction are two fundamental concepts in object-oriented programming, often used together to design and implement classes and objects. While they are related, they serve different purposes:

1. Encapsulation: Encapsulation is defined as the wrapping up of data under a single unit. It is the mechanism that binds together code and the data it manipulates. Another way to think about encapsulation is that it is a protective shield that prevents the data from being accessed by the code outside this shield. Technically in encapsulation, the variables or data of a class is hidden from any other class and can be accessed only through any member function of its own class in which they are declared. As in encapsulation, the data in a class is hidden from other classes, so it is also known as data-hiding. Encapsulation can be achieved by Declaring all the variables in the class as private and writing public methods in the class to set and get the values of variables.

```cpp
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string address;


public:
    // Public member functions to access and modify the private data members
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        }
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getAddress() const {
        return address;
    }
};

int main() {
    Person person1;
    person1.setName("John Doe");
    person1.setAge(30);
    person1.setAddress("123 Main St");

    // Accessing the private data members through public member functions
    cout << "Name: " << person1.getName() << endl;
    cout << "Age: " << person1.getAge() << endl;
    cout << "Address: " << person1.getAddress() << endl;

    return 0;
}

```

In this example, we have a Person class that represents a person with three private data members: name, age, and address. The private data members are not directly accessible from outside the class, as they are declared as private.

Encapsulation is achieved by providing public member functions (setName, setAge, setAddress, getName, getAge, and getAddress) to interact with the private data members. These public member functions act as an interface to access and modify the private data in a controlled manner.

The setName, setAge, and setAddress member functions are used to set the values of the private data members, and they provide validation to ensure that valid data is stored (e.g., non-negative age). The getName, getAge, and getAddress member functions are used to retrieve the values of the private data members.

2. Data Abstraction: Data Abstraction is the property by virtue of which only the essential details are displayed to the user. The trivial or the non-essential units are not displayed to the user. Ex: A car is viewed as a car rather than its individual components. Data Abstraction may also be defined as the process of identifying only the required characteristics of an object ignoring the irrelevant details. The properties and behaviors of an object differentiate it from other objects of similar type and also help in classifying/grouping the objects.

```cpp

#include <bits/stdc++.h>
#include <iostream>

class Shape {
public:
    // Virtual function for calculating the area
    virtual double calculateArea() {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of the calculateArea function for Circle
    double calculateArea() {
        return 3.14159 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    // Implementation of the calculateArea function for Square
    double calculateArea() {
        return side * side;
    }
};

int main() {
    // Creating objects and calculating the areas
    Circle myCircle(5.0);
    Square mySquare(4.0);

    // Using the Shape pointer to access the calculateArea function
    Shape* shape1 = &myCircle;
    Shape* shape2 = &mySquare;

    // Calculating and displaying the areas without const and override keywords
    std::cout << "Circle Area: " << shape1->calculateArea() << std::endl;
    std::cout << "Square Area: " << shape2->calculateArea() << std::endl;

    return 0;
}
```

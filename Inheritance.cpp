#include <iostream>
using namespace std;

class Animal
{
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal
{
public:
    void bark() { cout << "Barking..." << endl; }
};

int main()
{
    Dog d;
    d.eat();
    d.bark();
    return 0;
}

/*
Single Inheritance:
Multiple Inheritance:
Hierarchical Inheritance:
Multilevel Inheritance:
*/

/*
The capability of a class to derive properties and characteristics from another class is called Inheritance.

Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
Super Class: The class whose properties are inherited by sub class is called Base Class or Super class.
Re-usability: Inheritance supports the concept of “re-usability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.

Basic Syntax of Inheritance
class Subclass_name : access_mode Superclass_name
Public Inheritance
This is the most used inheritance mode. In this the protected member of super class becomes protected members of sub class and public becomes public.

class Subclass : public Superclass
Private Inheritance
In private mode, the protected and public members of super class become private members of derived class.

class Subclass : Superclass   // By default its private inheritance
Protected Inheritance
In protected mode, the public and protected members of Super class becomes protected members of Sub class.

class subclass : protected Superclass
*/

class Base
{
    int x;

public:
    // parameterized constructor
    Base(int i)
    {
        x = i;
        cout << "Base Parameterized Constructor\n";
    }
};

class Derived : public Base
{
    int y;

public:
    // parameterized constructor
    Derived(int j) : Base(j)
    {
        y = j;
        cout << "Derived Parameterized Constructor\n";
    }
};

/*
Ambiguity Resolution in Inheritance
Ambiguity can be occurred in using the multiple inheritance when a function with the same name occurs in more than one base class. The issue can be resolved by using the scope resolution operator with the function.

*/

class A
{
public:
    void func()
    {
        cout << " I am in class A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << " I am in class B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C obj;
    obj.A::func(); // Calling function func() in class A
    obj.B::func(); // Calling function func() in class B
    return 0;
}
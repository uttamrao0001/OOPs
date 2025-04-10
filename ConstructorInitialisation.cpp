#include <iostream>
using namespace std;

// 1-----------------------------------------------
class Base
{
protected:
    int x;

public:
    Base(int a) : x(a)
    { // Base class constructor
        cout << "Base constructor called\n";
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int a, int b) : Base(a), y(b)
    { // Derived class constructor
        cout << "Derived constructor called\n";
    }

    /*Base constructor called
     Derived constructor called*/
};

// 2----------------------------------------------
class Parent
{
private:
    int age;

public:
    Parent(int a) : age(a) {}
    int getAge() { return age; }
};

class Child : public Parent
{
private:
    string name;

public:
    Child(string n, int a) : Parent(a), name(n) {}
    void display()
    {
        cout << "Name: " << name << ", Age: " << getAge() << endl;
    }

    /*
     */
};

// 3------------------------------------------------------
class Animal
{
public:
    Animal(string type) { cout << "Animal: " << type << " created\n"; }
};

class Dog : public Animal
{
public:
    Dog(string breed) : Animal("Dog")
    {
        cout << "Breed: " << breed << " created\n";
    }

    /*
    Animal: Dog created
    Breed: Labrador created
    */
};

// 4----------------------------------------------------
class A
{
public:
    A() { cout << "A constructor\n"; }
};
class B
{
public:
    B() { cout << "B constructor\n"; }
};
class C : public A, public B
{
public:
    C() { cout << "C constructor\n"; }
};

/*
A constructor
B constructor
C constructor
*/

// 5------------------------------------------------------
class MyClass
{
private:
    int a, b;

public:
    MyClass(int x) : a(x), b(0) {}
    MyClass(int x, int y) : MyClass(x) { b = y; }
};

/*
The base class constructor is always called before the derived class constructor.

Use initializer lists for efficient member initialization.

Order of constructor calls follows the inheritance hierarchy.

Private members must be initialized using a base class constructor.

Multiple inheritance follows the order of declaration.
*/

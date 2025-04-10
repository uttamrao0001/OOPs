#include <iostream>
// By default, all data members and member functions of a class are made private by the compiler.
/*
Access specifiers are special types of keywords that are used to specify or control the accessibility of entities like classes, methods, and so on. Private, Public, and Protected are examples of access specifiers or access modifiers.
The key components of OOPs, encapsulation and data hiding, are largely achieved because of these access specifiers.
*/
class Example
{
private:
    int privateVar; // Private variable, accessible only within the class

protected:
    int protectedVar; // Protected variable, accessible within the class and derived classes

public:
    int publicVar; // Public variable, accessible from outside the class

    // Public methods
    void setVar(int val)
    {
        privateVar = val;
    }

    void displayVar()
    {
        std::cout << "Private Variable: " << privateVar << std::endl;
        std::cout << "Protected Variable: " << protectedVar << std::endl;
        std::cout << "Public Variable: " << publicVar << std::endl;
    }
};

class Derived : public Example
{
public:
    void setProtectedVar(int val)
    {
        protectedVar = val; // Accessible in derived class
    }
};

int main()
{
    Example obj;
    obj.publicVar = 10; // Direct access to public variable
    obj.setVar(20);     // Accessing public method
    obj.displayVar();   // Calling public function

    Derived derivedObj;
    derivedObj.setProtectedVar(30); // Accessing protected variable through derived class
    return 0;
}

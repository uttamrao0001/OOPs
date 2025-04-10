// Smart Pointers in C++
// Smart pointers manage memory automatically to prevent memory leaks.
// Types: unique_ptr, shared_ptr, weak_ptr

#include <iostream>
#include <memory>
using namespace std;

// Example using unique_ptr
void uniquePointerExample()
{
    unique_ptr<int> ptr1 = make_unique<int>(10);
    cout << "Unique Pointer Value: " << *ptr1 << endl;
}

// Example using shared_ptr
void sharedPointerExample()
{
    shared_ptr<int> ptr1 = make_shared<int>(20);
    shared_ptr<int> ptr2 = ptr1; // Both ptr1 and ptr2 share ownership
    cout << "Shared Pointer Value: " << *ptr1 << ", Count: " << ptr1.use_count() << endl;
}

// Example using weak_ptr
void weakPointerExample()
{
    shared_ptr<int> sharedPtr = make_shared<int>(30);
    weak_ptr<int> weakPtr = sharedPtr; // Does not increase reference count
    cout << "Weak Pointer Value: " << *sharedPtr << ", Count: " << sharedPtr.use_count() << endl;
}

int main()
{
    uniquePointerExample();
    sharedPointerExample();
    weakPointerExample();
    return 0;
}

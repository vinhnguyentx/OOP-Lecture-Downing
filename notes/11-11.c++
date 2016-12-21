/*
In C++, when is the member initialization list in the constructor required?
    1. a base class without a default constructor
    2. a const     data member
    3. a reference data member
    4. a user-type data member without a default constructor
*/

struct B : A {
    B (const B& rhs) :
        A (rhs)
        {}

    B& operator = (const B& rhs) {
        A::operator=(rhs);}};

struct A {
    void f (int) {}};

struct B : A {
    using A::f;
//  void f (int i)  {A::f(i);}
    void f (string) {}};

int main () {
    B x;
    x.f(2);    // not ok, becomes ok
    x.A::f(2); // ok

/*
Lookup differs between C++ and Java.
In C++ the name is being looked up. In Java the signature is being looked up.
The C++ way is better. It reduces the chance of a logic error.
*/

struct A {
    virtual void f (int) {}};

struct B : A {
    void f (int) {}};

int main () {
    A* p;
    if (...)
        p = new B;
    else
        p = new C;
    p->f(2);
    return 0;}

/*
In C++  dynamic binding is off by default. The keyword virtual turns it on.
In Java dynamic binding is on  by default.
*/

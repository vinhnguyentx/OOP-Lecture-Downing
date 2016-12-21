/*
motivation for abstract classes
    1. protected assignment
    2. obligate derived classes to exhibit particular behaviors
    3. avoid concrete classes extending concrete classes
*/

struct Triangle : Shape {
    Triangle (...) : Shape (...) {}};

struct A {}
struct B : A {}

struct A' {}
struct A : A' {}
struct B : A' {}

/*
make a class abstract in Java
*/

abstract class A {
    abstract void f ();}

/*
make a class abstract in C++
*/

struct A {
    virtual void f () = 0;};

/*
consequences of a pure virtual method
    1. class becomes abstract
    2. derived class must define method or become abstract
    3. defintion of abstract method: in Java is prohibited, in C++ is optional
*/

struct A {
    virtual ~A () = 0;};

struct B : A
    {}

int main () {
    B x;
    A* p = new B;
    delete p;

/*
consequences of an pure virtual destructor
    1. class becomes abstract
*/

/*
what does inline mean?
*/

int main () {
    A* p;
    if (...)
        p = new B;
    else
        p = new C;
    p->f(2);

/*
in C++ four cases where virtual will not be dynanically bound
    1. on objects
    2. with the scope operator
    3. in a constructor
    4. in a destructor

*/

int main () {
    B x;
    x.f(2);

    A* p = new B;
    p->A::f(2);

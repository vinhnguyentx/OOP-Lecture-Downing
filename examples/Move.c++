// --------
// Move.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
struct A {
    A () {
        cout << "A() ";}

    A (const A& rhs) {
        cout << "A(const A&) ";}

    A (A&&) {
        cout << "A(A&&) ";}

    A& operator = (const A&) {
        cout << "=(const A&) ";
        return *this;}

    A& operator = (A&&) {
        cout << "=(A&&) ";
        return *this;}

    ~A() {
        cout << "~A() ";}};

template <typename T>
struct B {
    A<T> _x;

    B () :
            _x () {
        cout << "B() ";}

    B (const B& rhs) :
            _x (rhs._x) {
        cout << "B(const B&) ";}

    B& operator = (const B& rhs) {
        _x = rhs._x;
        cout << "=(const B&) ";
        return *this;}

    ~B() {
        cout << "~B() ";}};

template <typename T>
struct C {
    A<T> _x;

    C () :
            _x () {
        cout << "C() ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

    C (C&& rhs) :
            _x (move(rhs._x)) {
        cout << "C(C&&) ";}

    C& operator = (const C& rhs) {
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    C& operator = (C&& rhs) {
        _x = move(rhs._x);
        cout << "=(C&&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

B<int> f (B<int>& z) {
    return z;}

C<int> g (C<int>& z) {
    return z;}

int main() {
    {
    cout << "1. ctor: ";
    B<int> x;             // 1. ctor: A() B()
    cout << endl;

    {
    cout << "2. copy: ";
    B<int> y = f(x);      // 2. copy: A(const A&) B(const B&) ~B() ~A()
    }
    cout << endl;

    cout << "3. copy: ";
    x = f(x);             // 3. copy: A(const A&) B(const B&) =(const A&) =(const B&) ~B() ~A()
    cout << endl;

    cout << "4. dtor: ";
    }                     // 4. dtor: ~B() ~A()
    cout << endl << endl;



    {
    cout << "1. ctor: ";
    C<int> x;            // 1. ctor: A() C()
    cout << endl;

    {
    cout << "2. copy: ";
    C<int> y = g(x);     // 2. ctor: A(const A&) C(const C&) ~C() ~A()
    }
    cout << endl;

    cout << "3. move: ";
    x = g(x);            // 3. copy: A(const A&) C(const C&) =(A&&) =(C&&) ~C() ~A()
    cout << endl;

    cout << "4. dtor: ";
    }                    // 4. dtor: ~C() ~A()
    cout << endl;

    return 0;}

/*
1. ctor: A() B()
2. copy: A(const A&) B(const B&) ~B() ~A()
3. copy: A(const A&) B(const B&) =(const A&) =(const B&) ~B() ~A()
4. dtor: ~B() ~A()

1. ctor: A() C()
2. copy: A(const A&) C(const C&) ~C() ~A()
3. move: A(const A&) C(const C&) =(A&&) =(C&&) ~C() ~A()
4. dtor: ~C() ~A()
*/

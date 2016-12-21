// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // make_unique, unique_ptr
#include <utility>  // move

using namespace std;

struct A {
    static int c;

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

int main () {
    cout << "UniquePtr.c++" << endl;

    assert(A::c == 0);

    {
//  unique_ptr<A> x = new A; // error: no viable conversion from 'A *' to 'unique_ptr<A>'
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
//  unique_ptr<A> y = x;       // error: call to implicitly-deleted copy constructor of 'unique_ptr<A>'
//  unique_ptr<A> y(x);        // error: call to implicitly-deleted copy constructor of 'unique_ptr<A>'
    unique_ptr<A> y = move(x);
    assert(!x);
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    unique_ptr<A> x(new A);
    unique_ptr<A> y(new A);
    assert(A::c == 2);
//  x = y;                  // error: object of type 'std::__1::unique_ptr<A, std::__1::default_delete<A> >' cannot be assigned because its copy assignment operator is implicitly deleted
    x = move(y);
    assert(!y);
    assert(A::c == 1);
    }

    assert(A::c == 0);

/*
    {
    unique_ptr<A> x = make_unique<A>(); // C++14
    assert(A::c == 1);
    }

    assert(A::c == 0);

    {
    auto x = make_unique<A>(); // C++14
    assert(A::c == 1);
    }

    assert(A::c == 0);
*/

    cout << "Done." << endl;
    return 0;}

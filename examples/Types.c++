// ---------
// Types.c++
// ---------

// http://en.cppreference.com/w/cpp/language/types

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <limits>   // numeric_limits
#include <sstream>  // ostringstream

template <typename T>
struct A {
    int    i;
    double d;
    T      x;};

template <typename T>
struct B {
    double d;
    int    i;
    T      x;};

template <typename T>
struct C : A<T> {
    A<T> y;};

union U {
    int  i;
    long j;};

enum class Color {red, green, blue};

int main () {
    using namespace std;
    cout << "Types.c++" << endl;

    bool b1 = true;
    bool b2 = false;
    assert(sizeof(b1)   ==  1);
    assert(sizeof(b2)   ==  1);
    assert(sizeof(bool) ==  1);

    char c = 'a';
    assert(sizeof(c)    ==  1);
    assert(sizeof(char) ==  1);
    assert(numeric_limits<         char>::min() == -128);
    assert(numeric_limits<         char>::max() ==  127);
    assert(numeric_limits<unsigned char>::min() ==    0);
    assert(numeric_limits<unsigned char>::max() ==  255);

    short s = 2;
    assert(sizeof(s)     ==  2);
    assert(sizeof(short) ==  2);
    assert(numeric_limits<         short>::min() == -32768);
    assert(numeric_limits<         short>::max() ==  32767);
    assert(numeric_limits<unsigned short>::min() ==      0);
    assert(numeric_limits<unsigned short>::max() ==  65535);

    int i = 2;
    assert(sizeof(i)   ==  4);
    assert(sizeof(int) ==  4);
    assert(numeric_limits<         int>::min() == -2147483648);
    assert(numeric_limits<         int>::max() ==  2147483647);
    assert(numeric_limits<unsigned int>::min() ==  0);
    assert(numeric_limits<unsigned int>::max() ==  4294967295U);

    long l = 2L;
    assert(sizeof(l)    ==  8);
    assert(sizeof(long) ==  8);
//  assert(numeric_limits<         long>::min() == -9223372036854775808L);     // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
//  assert(numeric_limits<         long>::min() == -9223372036854775808UL);    // warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
    assert(numeric_limits<         long>::min() == -9223372036854775807L -1 );
    assert(numeric_limits<         long>::max() ==  9223372036854775807L);
    assert(numeric_limits<unsigned long>::min() ==                    0);
    assert(numeric_limits<unsigned long>::max() == 18446744073709551615UL);

    long long ll = 2LL;
    assert(sizeof(ll)        ==  8);
    assert(sizeof(long long) ==  8);
//  assert(numeric_limits<         long long>::min() == -9223372036854775808LL);     // warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned
//  assert(numeric_limits<         long long>::min() == -9223372036854775808ULL);    // warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
    assert(numeric_limits<         long long>::min() == -9223372036854775807LL - 1);
    assert(numeric_limits<         long long>::max() ==  9223372036854775807LL);
    assert(numeric_limits<unsigned long long>::min() ==                    0);
    assert(numeric_limits<unsigned long long>::max() == 18446744073709551615ULL);

    float f = 2.34F;
    assert(sizeof(f)     == 4);
    assert(sizeof(float) == 4);
    {
    ostringstream out;
    out << numeric_limits<float>::min();
    assert(out.str() == "1.17549e-38");
    }
    {
    ostringstream out;
    out << numeric_limits<float>::max();
    assert(out.str() == "3.40282e+38");
    }

    double d = 2.34;
    assert(sizeof(d)      == 8);
    assert(sizeof(double) == 8);
    {
    ostringstream out;
    out << numeric_limits<double>::min();
    assert(out.str() == "2.22507e-308");
    }
    {
    ostringstream out;
    out << numeric_limits<double>::max();
    assert(out.str() == "1.79769e+308");
    }

    long double ld = 2.34L;
    assert(sizeof(ld)          == 16);
    assert(sizeof(long double) == 16);
    {
    ostringstream out;
    out << numeric_limits<long double>::min();
    assert(out.str() == "3.3621e-4932");
    }
    {
    ostringstream out;
    out << numeric_limits<long double>::max();
    assert(out.str() == "1.18973e+4932");
    }

    {
    char a[] = "abc";
    assert(sizeof(a) == 4 * sizeof(char));
    }

    {
    int a[] = {2, 3, 4};
    assert(sizeof(a) == 3 * sizeof(int));
    }

    {
    A<int> x = {2, 3.45, 6};
    assert(sizeof(A<int>) == 24);
    assert(sizeof(x)      == 24);
    }

    {
    A<double> x = {2, 3.45, 6.78};
    assert(sizeof(A<double>) == 24);
    assert(sizeof(x)         == 24);
    }

    {
    A< A<int> > x = {2, 3.45, {2, 3.45, 6}};
    assert(sizeof(A< A<int> >) == 40);
    assert(sizeof(x)           == 40);
    }

    {
    B<int> x = {2.34, 5, 6};
    assert(sizeof(B<int>) == 16);
    assert(sizeof(x)      == 16);
    }

    {
    B<double> x = {2.34, 5, 6.78};
    assert(sizeof(B<double>) == 24);
    assert(sizeof(x)         == 24);
    }

    {
    C<double> x;
    assert(sizeof(C<double>) == 48);
    assert(sizeof(x)         == 48);
    }

    {
    U u1 = {2};
    U u2 = {2L};
    assert(sizeof(U)  == 8);
    assert(sizeof(u1) == 8);
    assert(sizeof(u2) == 8);
    }

    {
    Color c1 = Color::red;
    Color c2 = Color::green;
    Color c3 = Color::blue;
    assert(sizeof(Color) == 4);
    assert(sizeof(c1)    == 4);
    assert(sizeof(c2)    == 4);
    assert(sizeof(c3)    == 4);
    }

    cout << "Done." << endl;
    return 0;}

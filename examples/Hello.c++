// ---------
// Hello.c++
// ---------

// http://en.cppreference.com/w/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << "Nothing to be done." << endl;
    return 0;}

/*
Developed in 1978 by Bjarne Stroustrup of Denmark.
C++ is procedural, object-oriented, statically typed, and not garbage collected.


% which g++-4.8
/usr/bin/g++-4.8


% g++-4.8 --version
g++-4.8 (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


% g++ -pedantic -std=c++11 -Wall Hello.c++ -o Hello


% ./Hello
Nothing to be done.
*/

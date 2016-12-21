// -----------
// Shapes1.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <utility>  // !=

#include "gtest/gtest.h"

using namespace std;
using rel_ops::operator!=;

class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return (lhs._x == rhs._x) && (lhs._y == rhs._y);}

    friend istream& operator >> (istream& lhs, Shape& rhs) {
        return lhs >> rhs._x >> rhs._y;}

    friend ostream& operator << (ostream& lhs, const Shape& rhs) {
        return lhs << rhs._x << " " << rhs._y;}

    private:
        int _x;
        int _y;

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {}

        Shape (const Shape&) = default;
/*
        Shape (const Shape& rhs) :
                _x (rhs._x),
                _y (rhs._y)
            {}
*/
          ~Shape () = default;
/*
        ~Shape ()
            {}
*/
        Shape& operator = (const Shape&) = default;
/*
        Shape& operator = (const Shape& rhs) {
            _x = rhs._x;
            _y = rhs._y;
            return *this;}
*/

        double area () const {
            return 0;}

        void move (int x, int y) {
            _x = x;
            _y = y;}};

#include "Shapes1.h"

TEST(ShapeFixture, test_1) {
    Shape x(2, 3);
    x.move(4, 5);
    ASSERT_EQ(0, x.area());
//  x.radius();               // doesn't compile
    }

TEST(ShapeFixture, test_2) {
    const Shape x(2, 3);
          Shape y(4, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);}

TEST(ShapeFixture, test_3) {
    Circle x(2, 3, 4);
    x.move(5, 6);
    ASSERT_EQ(3.14 * 4 * 4, x.area());
    ASSERT_EQ(4, x.radius());}

TEST(ShapeFixture, test_4) {
    const Circle x(2, 3, 4);
          Circle y(2, 3, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);}

TEST(ShapeFixture, test_5) {
//  Circle* const p = new Shape(2, 3);         // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);
    p->move(5, 6);
    ASSERT_EQ(0, p->area());
//  p->radius();                               // doesn't compile
//  delete p;                                  // illdefined
    Circle* const q = static_cast<Circle*>(p);
    ASSERT_EQ(3.14 * 4 * 4, q->area());
    ASSERT_EQ(4, q->radius());
    delete q;}

TEST(ShapeFixture, test_6) {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
//  ASSERT_NE(*p, *q);                                     // illdefined
//  *q = *p;                                               // illdefined
//  ASSERT_EQ(*p, *q);                                     // illdefined
//  delete p;                                              // illdefined
//  delete q;                                              // illdefined
    const Circle* const r = static_cast<const Circle*>(p);
          Circle* const s = static_cast<      Circle*>(q);
    ASSERT_NE(*r, *s);
    *s = *r;
    ASSERT_EQ(*r, *s);
    delete r;
    delete s;}

TEST(ShapeFixture, test_7) {
//  const Circle a[] = {Shape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const Shape  a[] = {Shape(2, 3), Circle(4, 5, 6)};
    ASSERT_EQ(0, a[0].area());
    ASSERT_EQ(0, a[1].area());}

TEST(ShapeFixture, test_8) {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    ASSERT_EQ(3.14 * 4 * 4, a[0].area());
    ASSERT_EQ(3.14 * 7 * 7, a[1].area());
    const Shape* const p = a;
    ASSERT_EQ(0, p[0].area());
//  p[1].area();                                           // illdefined
    }

// -----------
// Shapes2.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <utility>  // !=

#include "gtest/gtest.h"

using namespace std;
using rel_ops::operator!=;

class Shape {
    friend bool operator == (const Shape& lhs, const Shape& rhs) {
        return lhs.equals(rhs);}

    friend std::istream& operator >> (std::istream& lhs, Shape& rhs) {
        return rhs.read(lhs);}

    friend std::ostream& operator << (std::ostream& lhs, const Shape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        virtual bool equals (const Shape& rhs) const {
            return (_x == rhs._x) && (_y == rhs._y);}

        virtual std::istream& read (std::istream& in) {
            return in >> _x >> _y;}

        virtual std::ostream& write (std::ostream& out) const {
            return out << _x << " " << _y;}

    public:
        Shape (int x, int y) :
                _x (x),
                _y (y)
            {}

        Shape (const Shape&) = default;

        virtual ~Shape ()
            {}

        Shape& operator = (const Shape&) = default;

        virtual double area () const {
            return 0;}

        void move (int x, int y) {
            _x = x;
            _y = y;}};

#include "Shapes2.h"

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
//  Circle* const p = new Shape(2, 3);              // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);
    p->move(5, 6);
    ASSERT_EQ(3.14 * 4 * 4, p->area());
//  p->radius();                                    // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        ASSERT_EQ(4, q->radius());
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        ASSERT_TRUE(false);}
    delete p;}

TEST(ShapeFixture, test_6) {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
    ASSERT_NE(*p, *q);
//  *q = *p;                                                    // illdefined
    if (const Circle* const r = dynamic_cast<const Circle*>(p))
        if (Circle* const s = dynamic_cast<Circle*>(q))
            *s = *r;
    ASSERT_EQ(*p, *q);
    delete p;
    delete q;}

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
    ASSERT_EQ(3.14 * 4 * 4, p[0].area());
//  p[1].area();                                           // illdefined
    }

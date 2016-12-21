// -----------
// Shapes3.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <utility>  // !=

#include "gtest/gtest.h"

using namespace std;
using rel_ops::operator!=;

class AbstractShape {
    friend bool operator == (const AbstractShape& lhs, const AbstractShape& rhs) {
        return lhs.equals(rhs);}

    friend std::istream& operator >> (std::istream& lhs, AbstractShape& rhs) {
        return rhs.read(lhs);}

    friend std::ostream& operator << (std::ostream& lhs, const AbstractShape& rhs) {
        return rhs.write(lhs);}

    private:
        int _x;
        int _y;

    protected:
        AbstractShape& operator = (const AbstractShape&) = default;

        virtual bool equals (const AbstractShape& rhs) const = 0;

        virtual std::istream& read (std::istream& in) = 0;

        virtual std::ostream& write (std::ostream& out) const = 0;

    public:
        AbstractShape (int x, int y) :
                _x (x),
                _y (y)
            {}

        AbstractShape (const AbstractShape&) = default;

        virtual ~AbstractShape ()
            {}

        virtual double area () const = 0;

        virtual AbstractShape* clone () const = 0;

        void move (int x, int y) {
            _x = x;
            _y = y;}};

bool AbstractShape::equals (const AbstractShape& rhs) const {
    return (_x == rhs._x) && (_y == rhs._y);}

std::istream& AbstractShape::read (std::istream& in) {
    return in >> _x >> _y;}

std::ostream& AbstractShape::write (std::ostream& out) const {
    return out << _x << " " << _y;}

#include "Shapes3.h"
/*
TEST(ShapeFixture, test_1) {
    AbstractShape x(2, 3);
    x.move(4, 5);
    ASSERT_EQ(0, x.area());
//  x.radius();                       // doesn't compile
    }

TEST(ShapeFixture, test_2) {
    const AbstractShape x(2, 3);
          AbstractShape y(4, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);}
*/
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
//  Circle*        const p = new AbstractShape(2, 3); // doesn't compile
    AbstractShape* const p = new Circle(2, 3, 4);
    p->move(5, 6);
    ASSERT_EQ(3.14 * 4 * 4, p->area());
//  p->radius();                                      // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        ASSERT_EQ(4, q->radius());
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        ASSERT_EQ(4, r.radius());}
    catch (const bad_cast& e) {
        ASSERT_TRUE(false);}
    delete p;}

TEST(ShapeFixture, test_6) {
    const AbstractShape* const p = new Circle(2, 3, 4);
    const AbstractShape*       q = new Circle(2, 3, 5);
    ASSERT_NE(*p, *q);
//  *q = *p;                                            // error: no viable overloaded '='
    delete q;
    q = p->clone();
    ASSERT_EQ(*p, *q);
    delete p;
    delete q;}
/*
TEST(ShapeFixture, test_7) {
//  const Circle        a[] = {AbstractShape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const AbstractShape a[] = {AbstractShape(2, 3), Circle(4, 5, 6)};
    ASSERT_EQ(0, a[0].area());
    ASSERT_EQ(0, a[1].area());}
*/
TEST(ShapeFixture, test_8) {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    ASSERT_EQ(3.14 * 4 * 4, a[0].area());
    ASSERT_EQ(3.14 * 7 * 7, a[1].area());
    const AbstractShape* const p = a;
    ASSERT_EQ(3.14 * 4 * 4, p[0].area());
//  p[1].area();                                           // illdefined
    }

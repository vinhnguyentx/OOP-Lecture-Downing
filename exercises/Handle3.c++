// -----------
// Handle3.c++
// -----------

#include <utility> // !=

#include "gtest/gtest.h"

#include "Shapes.h"
#include "Handle3.h"

using namespace std;
using rel_ops::operator!=;

struct Shape : Handle<AbstractShape> {
    Shape (AbstractShape* p) :
            Handle<AbstractShape> (p)
        {}

    Shape             (const Shape&) = default;
    ~Shape            ()             = default;
    Shape& operator = (const Shape&) = default;

    double area () const {
        return get()->area();}

    void move (int x, int y) {
        return get()->move(x, y);}};

TEST(HandleFixture, test_1) {
    const Shape x = new Circle(2, 3, 4);
//  x.move(5, 6);                        // doesn't compile
    ASSERT_EQ(3.14 * 4 * 4, x.area());
//  x.radius();                          // doesn't compile
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());}

TEST(HandleFixture, test_2) {
    Shape x = new Circle(2, 3, 4);
    x.move(5, 6);
    ASSERT_EQ(new Circle(5, 6, 4), x);
    ASSERT_EQ(3.14 * 4 * 4, x.area());
//  x.radius();                        // doesn't compile
    ASSERT_TRUE(x.unique());
    ASSERT_EQ(1, x.use_count());}

TEST(HandleFixture, test_3) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = x;
    ASSERT_EQ(x, y);
    ASSERT_FALSE(x.unique());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    y.move(5, 6);
    ASSERT_EQ(new Circle(2, 3, 4), x);
    ASSERT_EQ(new Circle(5, 6, 4), y);
    ASSERT_TRUE(x.unique());
    ASSERT_TRUE(y.unique());
    ASSERT_EQ(1, x.use_count());
    ASSERT_EQ(1, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y.area());}

TEST(HandleFixture, test_4) {
    const Shape x = new Circle(2, 3, 4);
          Shape y = new Circle(2, 3, 5);
    ASSERT_NE(x, y);
    y = x;
    ASSERT_EQ(x, y);
    ASSERT_FALSE(x.unique());
    ASSERT_FALSE(y.unique());
    ASSERT_EQ(2, x.use_count());
    ASSERT_EQ(2, y.use_count());
    y.move(5, 6);
    ASSERT_EQ(new Circle(2, 3, 4), x);
    ASSERT_EQ(new Circle(5, 6, 4), y);
    ASSERT_TRUE(x.unique());
    ASSERT_TRUE(y.unique());
    ASSERT_EQ(1, x.use_count());
    ASSERT_EQ(1, y.use_count());
    ASSERT_EQ(3.14 * 4 * 4, y.area());}

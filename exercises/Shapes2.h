// ---------
// Shapes2.h
// ---------

#ifndef Shapes2_h
#define Shapes2_h

#include <utility> // !=

using std::rel_ops::operator!=;

class Circle : public Shape {
    private:
        int _r;

    protected:
        bool equals (const Shape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return Shape::equals(*p) && (_r == p->_r);
            return false;}

        std::istream& read (std::istream& in) override {
            return Shape::read(in) >> _r;}

        std::ostream& write (std::ostream& out) const override {
            return Shape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                Shape (x, y),
                _r    (r)
            {}

                Circle     (const Circle&) = default;
               ~Circle     ()              = default;
        Circle& operator = (const Circle&) = default;

        double area () const override {
            return 3.14 * _r * _r;}

        int radius () const {
            return _r;}};

#endif // Shapes2_h

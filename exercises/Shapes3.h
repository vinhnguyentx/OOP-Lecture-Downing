// ---------
// Shapes3.h
// ---------

#ifndef Shapes3_h
#define Shapes3_h

#include <utility> // !=

using std::rel_ops::operator!=;

class Circle : public AbstractShape {
    private:
        int _r;

    protected:
        bool equals (const AbstractShape& rhs) const override {
            if (const Circle* const p = dynamic_cast<const Circle*>(&rhs))
                return AbstractShape::equals(*p) && (_r == p->_r);
            return false;}

        std::istream& read (std::istream& in) override {
            return AbstractShape::read(in) >> _r;}

        std::ostream& write (std::ostream& out) const override {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r            (r)
            {}

                Circle     (const Circle&) = default;
               ~Circle     ()              = default;
        Circle& operator = (const Circle&) = default;

        double area () const override {
            return 3.14 * _r * _r;}

        Circle* clone () const override {
            return new Circle(*this);}

        int radius () const {
            return _r;}};

#endif // Shapes3_h

// ---------
// Handle1.h
// ---------

#ifndef Handle1_h
#define Handle1_h

#include <algorithm> // swap
#include <cassert>   // assert

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if ((lhs.get() == nullptr) && (rhs.get() == nullptr))
            return true;
        if ((lhs.get() == nullptr) || (rhs.get() == nullptr))
            return false;
        return (*lhs.get() == *rhs.get());}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p;

    protected:
        pointer get () {
            assert(_p != nullptr);
            return _p;}

        const_pointer get () const {
            assert(_p != nullptr);
            return _p;}

    public:
        Handle (pointer p) :
                _p (p)
            {}

        Handle (const Handle& rhs) :
                _p ((rhs._p == nullptr) ? nullptr : rhs._p->clone())
            {}

        ~Handle () {
            delete _p;}

        Handle& operator = (Handle rhs) {
            swap(rhs);
            return *this;}

        void swap (Handle& rhs) {
            std::swap(_p, rhs._p);}};

#endif // Handle1_h

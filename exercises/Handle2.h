// ---------
// Handle2.h
// ---------

#ifndef Handle2_h
#define Handle2_h

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
        typedef T           value_type;
        typedef value_type* pointer;
        typedef value_type& reference;

    private:
        pointer _p;

    public:
        Handle (pointer p) :
                _p (p)
            {}

        Handle (const Handle& rhs) :
                _p ((rhs._p == nullptr) ? nullptr : rhs._p->clone())
            {}

        ~Handle () {
            delete _p;}

        Handle& operator = (Handle that) {
            swap(that);
            return *this;}

        reference operator * () {
            assert(_p != nullptr);
            return *_p;}

        pointer operator -> () {
            assert(_p != nullptr);
            return _p;}

        pointer get () const {
            assert(_p != nullptr);
            return _p;}

        void swap (Handle& that) {
            std::swap(_p, that._p);}};

#endif // Handle2_h

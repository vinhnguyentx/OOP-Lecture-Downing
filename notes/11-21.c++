/*
dynamic binding in Java
*/

class A {
    void f () {}}

class B extends A {
    void f () {}}

class C extends A {
    void f () {}}

class T {
    public static void main (...) {
        A x;
        if (...)
            x = new B;
        else
            x = new C;
        x.f();}}

/*
cases where Java does not dynamically bind
    1. final   method
    2. final   class
    3. private method
    4. static  method
*/

template <typename T>
class Handle {
    private:
        T* _p

    protected:
        const T* get () const {
            return _p;}

        T* get () {
            return _p;}

    public:
        Handle (T* p) {
            _p = p;}

        Handle (const Handle& rhs) {
            _p = rhs._p->clone();}

        Handle& operator = (Handle rhs) {
            swap(_p, rhs._p);
            return *this;}

        ~Handle () {
            delete _p;}};

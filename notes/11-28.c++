struct A {
    void f           () {}
    A*   operator -> () {...}
    A&   operator *  () {...}};

int main () {
    A* p = new A;

    p.f();    // not ok
    *p.f();   // not ok
    (*p).f(); // ok
    p->f();   // ok

    delete p;


    A x;

    *x.f();            // not ok
    (*x).f();          // ok
    x.operator*().f();

    x->f();
    x.operator->()->f();

    return 0;}

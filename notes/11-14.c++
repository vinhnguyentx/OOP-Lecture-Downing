struct A {
            void f (int) {}
    virtual void g (int) {}};

struct B : A {
    void f (int)          {}   // bad idea
    void g (int) override {}}; // insure correct signature

int main () {
    A* p;
    if (...)
        p = new A;
    else
        p = new B;
    p->f(2);       // statically  bound
    p->g(2);       // dynamically bound

bool equals (const Shape& rhs) {
    if (const Circle* p = dynamic_cast<const Circle*>(&rhs))
        return Shape::equals(rhs) && (_r == p->_r);
    return false;}

struct A {
    virtual A* clone () const = 0;}; // pure virtual function

struct B : A {
    A* clone () const {
        return new B(*this;}};

struct C : A {
    A* clone () const {
        return new C(*this;}};

int main () {
    A* p = new B;
    A* q = new C;

    *p = *q;        // not ok
    delete p;
    p = q->clone();

    return 0;}

struct A {
    virtual void f (int) final {}     // child can't override
    virtual void g (int)       {}     // child may   override
    virtual void h (int)       = 0;}; // child must  override

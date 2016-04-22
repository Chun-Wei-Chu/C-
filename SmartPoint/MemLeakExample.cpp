//leak error case

class A {
  public: shared_ptr<A> x;
}

shared_ptr<A> a1(new A());
shared_ptr<A> a2(new A());
a1->x = a2;
a2->x = a1;

//ref: http://stackoverflow.com/questions/2735982/memory-leak-using-shared-ptr

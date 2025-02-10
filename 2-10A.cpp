/*
1. In C++, what do you have to do to a member function to make it overridable (and use dynamic dispatch)? Why?
Declare it as virtual in the base class, static dispatch is more effiicent and therefore is default

2. What is a pure virtual function? What happens to a class with a pure virtual function?
A function that has no implementation and must be overriden to be used

3. Why would this code not compile?
Override will prevent it from compiling since it is not overriding anything

4. If you are adding virtual member functions to your class, what other member function might you consider making virtual?
Destructor

5. What is the diamond problem with multiple inheritance? What is a way you might get around it?
When a class inherits multiple base classes, virtual inheritance helps
*/

/*
Write the implementation for two classes Base and Derived.  Derived inherits from Base and the classes have two member functions: redefinable and overridable.  Both functions return the name of the class as a string; however, the derived class redefines redefinable and overrides overridable.

Hint: one member function should be virtual and one should not.
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  virtual ~Base() {} // recommended
  // TODO
  string redefinable() const { return "Base"; }
  virtual string overridable() const { return "Base"; }
};

class Derived: public Base {
public:
  virtual ~Derived() {} // recommended
  // TODO
  string redefinable() const { return "Derived"; }
  string overridable() const override { return "Derived"; }
};

void use_base(const Base & b) {
  cout << b.redefinable() << " " << b.overridable() << endl;
}

void use_derived(const Derived & d) {
  cout << d.redefinable() << " " << d.overridable() << endl;
}

int main() {
  Base b;
  Derived d;

  use_base(b); // prints "Base Base"
  use_base(d); // prints "Base Derived"
  use_derived(d);  // prints "Derived Derived"
}
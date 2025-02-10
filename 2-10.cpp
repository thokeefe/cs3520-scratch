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
/*
From the given code for WrappedUInt, add overloaded operators for prefix and postfix decrement (--). Decrementing at 0 should
produce the largest possible value. Write them as member functions defined outside the class body.

Hint: Prefix takes no argument and returns the updated value; postfix takes an (unused) int argument and returns the old value.
You can use (*this) to access the object within member functions.
*/

#include <iostream>
using namespace std;

typedef unsigned int UInt;

class WrappedUInt {
public:
  WrappedUInt(UInt value, UInt modBy);
  friend ostream & operator<<(ostream &, const WrappedUInt &);

  // TODO
  WrappedUInt & operator--();
  WrappedUInt operator--(int);

private:
  UInt m_value;
  const UInt m_modBy;
};

WrappedUInt::WrappedUInt(UInt value, UInt modBy):
  m_value(value % modBy),
  m_modBy(modBy)
{}

ostream & operator<<(ostream & os, const WrappedUInt & wi) {
  return (os << wi.m_value);
}

// TODO
WrappedUInt & WrappedUInt::operator--() {
    if (m_value == 0) {
        m_value = m_modBy - 1;
    } else {
        --m_value;
    }
    return *this;
}

WrappedUInt WrappedUInt::operator--(int) {
    WrappedUInt temp = *this;
    --(*this);
    return temp;
}

int main() {
  WrappedUInt wi(2U, 3U);

  cout << "wi--: " << wi-- << endl; // 2
  cout << "wi  : " << wi << endl;   // 1
  cout << "wi--: " << wi-- << endl; // 1
  cout << "wi  : " << wi << endl;   // 0
  cout << "wi--: " << wi-- << endl; // 0
  cout << "wi  : " << wi << endl;   // 2

  cout << "--wi: " << --wi << endl; // 1
  cout << "wi  : " << wi << endl;   // 1
  cout << "--wi: " << --wi << endl; // 0
  cout << "wi  : " << wi << endl;   // 0
  cout << "--wi: " << --wi << endl; // 2
  cout << "wi  : " << wi << endl;   // 2
}
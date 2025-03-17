/*
Complete the implementation of the chess piece class hierarchy, and fill in the destructors and print member functions, 
to produce the indicated output.
*/

#include <iostream>
#include <vector>
using namespace std;

class ChessPiece {
public:
  // TODO
  virtual ~ChessPiece() { cout << "~ChessPiece" << endl; }
  virtual void print() const = 0;
};

class Rook : public ChessPiece/* TODO */ {
public:
  // TODO
  ~Rook() override { cout << "~Rook" << endl; }
  void print() const override { cout << "Rook" << endl; }
};

class Bishop : public ChessPiece /* TODO */ {
public:
  // TODO
  ~Bishop() override { cout << "~Bishop" << endl; }
  void print() const override { cout << "Bishop" << endl; }
};

int main() {
  vector<ChessPiece *> v;
  v.push_back(new Rook);
  v.push_back(new Bishop);

  // prints "Rook" then "Bishop"
  for (const auto elem: v) {
    elem->print();
  }

  // prints "~Rook" then "~Bishop"
  for (auto elem: v) {
    delete elem;
  }
  v.clear();
}
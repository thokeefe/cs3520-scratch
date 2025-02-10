/*
Given the implementation for the class ChessPiece, fill in the implementation for the derived classes Bishop and Rook.

Provide implementations for isLegalMove in the derived classes. A bishop can move along diagonals [ https://en.wikipedia.org/wiki/Bishop_(chess) ] and a rook can move along rows and columns [ https://en.wikipedia.org/wiki/Rook_(chess) ].  You only need to check the given cell against the piece’s movement rules. Also add constructors and destructors.
*/

#include <iostream>
using namespace std;

struct Cell {
  int row, col;
};

class ChessPiece {
public:
  ChessPiece(const Cell & cell): m_cell(cell) {}
  virtual ~ChessPiece() {} // recommended
  const Cell & getCell() const { return m_cell; }
  bool moveIfLegal(const Cell & cell) {
    if (isLegalMove(cell)) {
      m_cell = cell;
      return true;
    } else {
      return false;
    }
  }
private:
  virtual bool isLegalMove(const Cell & cell) const = 0;
  Cell m_cell;
};

class Bishop: public ChessPiece /* TODO */ {
public:
  // TODO
  Bishop(const Cell & cell): ChessPiece(cell) {}
  virtual ~Bishop() {}
  virtual bool isLegalMove(const Cell & cell) const override final {
    return abs(cell.row - getCell().row) == abs(cell.col - getCell().col);
  }
private:
 // TODO
};

class Rook: public ChessPiece /* TODO */ {
public:
  // TODO
  Rook(const Cell & cell): ChessPiece(cell) {}
  virtual ~Rook() {}
  virtual bool isLegalMove(const Cell & cell) const override final {
    return cell.row == getCell().row || cell.col == getCell().col;
  }
private:
  // TODO
};

void try_move(ChessPiece & p, const Cell & c) {
  if (p.moveIfLegal(c)) {
    cout << "move was legal, now at: ";
  } else {
    cout << "move was not legal, now at: ";
  }
  cout << p.getCell().row << "," << p.getCell().col << endl;
}

int main() {
  Bishop b({0, 0});
  cout << "moving bishop:" << endl;
  try_move(b, {0, 4}); // at 0,0 (not legal)
  try_move(b, {4, 4}); // at 4,4 (legal)
  try_move(b, {5, 3}); // at 5,3 (legal)

  Rook r({0, 0});
  cout << "moving rook:" << endl;
  try_move(r, {4, 4}); // at 0,0 (not legal)
  try_move(r, {0, 3}); // at 0,3 (legal)
  try_move(r, {5, 3}); // at 5,3 (legal)
}
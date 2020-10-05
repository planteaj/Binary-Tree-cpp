#include <fstream>


#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {LESS, GREATER, EQUAL};

class ItemType
{
 public:
  ItemType();
  void print();
  void initialize(int num);
  Comparison compareTo(ItemType item);
  int getValue() const;
 private:
  int value;
};
#endif

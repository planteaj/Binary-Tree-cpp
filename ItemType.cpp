#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType(){
  value = 0;
}

void ItemType::print(){
  std::cout << value << std::endl;
}

void ItemType::initialize(int number)
{
  value = number;
}

Comparison ItemType::compareTo(ItemType item){
      if (value < item.value)
	return LESS;
      else if(value > item.value)
	return GREATER;
      else return EQUAL;
}

int ItemType::getValue() const {
  return value;
}


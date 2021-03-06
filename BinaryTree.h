#include "ItemType.h"
#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node;
class BinaryTree
{
 public:
  BinaryTree();
  ~BinaryTree();
  void insert(ItemType key);
  void deleteItem(ItemType key);
  void DeleteNode(Node * & tree);
  void deleteRecursion(Node * &tree, ItemType key);
  void retrieve(ItemType &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
 private:
  Node* root;
};

struct Node
{
  ItemType key;
  Node *left;
  Node *right;
};

#endif

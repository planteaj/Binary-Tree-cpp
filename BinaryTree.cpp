#include <iostream>
#include "ItemType.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
  root = NULL;
}

void Destroy(Node *& tree)
{
  if(tree != NULL)
    {
      Destroy(tree->left);
      Destroy(tree->right);
      delete tree;
    }
}

BinaryTree::~BinaryTree()
{
  Destroy(root);
}

void insertRecursion(Node * &tree, ItemType key)
{
  if(tree == NULL)
    {
      tree = new Node;
      tree->left = NULL;
      tree->right = NULL;
      tree->key = key;
    }
  else if(key.compareTo(tree->key) == LESS)
    insertRecursion(tree->left, key);
  else
    insertRecursion(tree->right, key);
}

void BinaryTree::insert(ItemType key)
{
    insertRecursion(root, key);
}

void getPredecessor(Node * tree, ItemType & data)
{
  while(tree->right !=NULL)
    tree = tree->right;
  data = tree->key;
}


void BinaryTree::DeleteNode(Node * & tree)
{
  ItemType data;
  Node * temp;
  temp = tree;
  if(tree->left == NULL)
    {
      tree = tree->right;
      delete temp;
    }
  else if(tree->right == NULL)
    {
      tree = tree->left;
      delete temp;
    }
  else
    {
      getPredecessor(tree->left, data);
      tree->key = data;
      deleteRecursion(tree->left, data);
      
    }
}

void BinaryTree::deleteRecursion(Node * &tree, ItemType key)
{
  if(key.compareTo(tree->key) == LESS)
    deleteRecursion(tree->left, key);
  else if(key.compareTo(tree->key) == GREATER)
    deleteRecursion(tree->right, key);
  else
    DeleteNode(tree);
}

void BinaryTree::deleteItem(ItemType key)
{
    deleteRecursion(root, key);
}

int count(Node *tree)
{
  if(tree == NULL)
    return 0;
  else
    return count(tree->left) + count(tree->right) + 1;
}

int BinaryTree::getLength() const
{
  return count(root);
}

void getItem(Node * tree, ItemType & item, bool & found)
{
  if(tree == NULL)
    found = false;
  else if(item.compareTo(tree->key) == LESS)
    getItem(tree->left, item, found);
  else if(item.compareTo(tree->key) == GREATER)
    getItem(tree->right, item, found);
  else
    {
      item = tree->key;
      found = true;
    }
}

void BinaryTree::retrieve(ItemType &item, bool &found) const
{
  getItem(root, item, found);
}

void print(Node *tree, int a)
{
  if(a == 1)
    {
      if(tree != NULL)
	{
	  std::cout << tree->key.getValue() << " ";
	  print(tree->left, a);
	  print(tree->right, a);
	}
    }
  else if(a == 2)
    {
      if(tree != NULL)
	{
	  print(tree->left, a);
	  std::cout << tree->key.getValue() << " ";
	  print(tree->right,a);
	}
    }
  else
    {
      if(tree != NULL)
	{
	  print(tree->left, a);
	  print(tree->right, a);
	  std::cout<< tree->key.getValue() << " ";
	}
    }
}

void BinaryTree::preOrder() const
{
  print(root, 1);
  std::cout << "\n";
}

void BinaryTree::inOrder() const
{
  print(root, 2);
  std::cout << "\n";
}

void BinaryTree::postOrder() const
{
  print(root, 3);
  std::cout << "\n";
}







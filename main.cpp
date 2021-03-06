#include <iostream>
#include "BinaryTree.h"
#include "ItemType.h"

using namespace std;


int main(int argc, char ** argv) {
  if(argc != 2)
    {
      cout << "Wrong command-line input" << endl;
      return -1;
    }
  fstream fs;
  fs.open(argv[1]);
  BinaryTree list;
  int streamInt;
  while(fs >> streamInt)
    {
      ItemType temp;
      temp.initialize(streamInt);
      list.insert(temp);
    }
  
  fs.close();

  cout << argv[0] << " " << argv[1] << " Commands:" << endl;
  cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getSameLevelNonsiblings (c), quit (q)" << endl;
 
  while(true) {
    cout << "Enter a command: ";
    char inp;
    cin >> inp;

    if(inp == 'i')
      {
	cout << "Item to insert: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	bool found;
	list.retrieve(temp, found);
	if(found)
	  cout << "Item already in tree." << endl;
	else
	  list.insert(temp);
	cout << "In-Order: ";
	list.inOrder();
      }
    else if(inp == 'd')
      {
	cout << "Item to delete: ";
	int itemp;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	bool found;
	list.retrieve(temp, found);
	if(list.getLength() == 0)
	  cout <<"You cannot delete from an empty list." << endl;
	else if(found)
	  list.deleteItem(temp);
	else
	  cout << "Item not in tree." << endl;
	cout << "In-Order: ";
	list.inOrder();
      }
    else if(inp == 'r')
      {
	cout << "Item to be retrieved: " ;
	int itemp;
	bool found = false;
	cin >> itemp;
	ItemType temp;
	temp.initialize(itemp);
	list.retrieve(temp, found);
	if(found)
	  cout <<"\nItem found in tree." << endl;
	else
	  cout <<"\nItem not in tree." << endl;
      }
    else if(inp == 'n')
      {
	cout << "In-Order: " ;
	list.inOrder();
      }
    else if(inp == 'p')
      {
	cout << "Pre-Order: ";
	list.preOrder();
      }
    else if(inp == 'o')
      {
	cout << "Post-Order: ";
	list.postOrder();
      }
    else if(inp == 'l')
      {
	cout << "List Length: " <<  list.getLength() << endl;
      }
    else if(inp == 'q')
      {
	cout << "Quitting Program..." << endl;;
	return 0;
      }
    else
      cout << "Command not recognized. Try again" << endl;
  }  
  return 0;
	  
}

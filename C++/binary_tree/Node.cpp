#include "Tree.h"
using namespace std;

  Node::Node(Data* idata)
  {
    _left=NULL;
    _right=NULL;
    _data=idata;
  }

  Node* buildTree(int in[], char** preorder, int inStrt, int inEnd)
  {
  	static int preorderIndex = 0;

  	if (inStrt > inEnd)
  		return NULL;
    Data* theData = new Data(preorderIndex,preorder[preorderIndex]);
    preorderIndex++;

  	Node* theNode = new Node(theData);

    if (inStrt == inEnd)
  		return theNode;

  	int inIndex = search(in, inStrt, inEnd, theNode->_data->get_index());

  	theNode->_left = buildTree(in, preorder, inStrt, inIndex - 1);
  	theNode->_right = buildTree(in, preorder, inIndex + 1, inEnd);

  	return theNode;
  }

  int search(int arr[], int strt, int end, int value)
  {
  	int i;
  	for (i = strt; i <= end; i++)
  	{
  		if (arr[i] == value)
  			return i;
  	}
  }

    void printPostorder(Node* Node)
    {
    	if (Node == NULL)
    		return;
      printPostorder(Node->_left);
      printPostorder(Node->_right);
    	cout<<*(Node->_data);
    }


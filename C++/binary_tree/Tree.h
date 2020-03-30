#ifndef Tree_H
#define Tree_H

#include<iostream>
using namespace std;
class Data
{
private:
  char* _name;
  const int _index;

public:
  Data(int index,char* name);
  char* get_name();
  int get_index();
  friend ostream& operator<<(ostream& os,const Data& data);
};

ostream& operator<<(ostream& os,const Data& data);

class Node
{
public:
  Node* _left;
  Node* _right;
  Data* _data;

public:
  Node(Data* idata);
};

int search(int arr[], int strt, int end, int value);
Node* buildTree(int in[], char** preorder, int inStrt, int inEnd);
void printPostorder(Node* Node);

#endif

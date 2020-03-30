#include "Tree.h"

#include<string>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
  int no;
  cin>>no;
  char** preorder;
  int* inorder;
  inorder=new int[no];

  preorder=new char*[no];
  for(int i=0;i<no;i++)
  {
    preorder[i]=new char[20];
  }
  for(int i=0;i<no;i++)
  {
    cin>>preorder[i];
    for(int j=0;preorder[i][j]!='\0';j++)
    {
      // cout<<preorder[i][j]<<" ";
      if((preorder[i][j]>='A' && preorder[i][j]<='Z') || (preorder[i][j]>='a' && preorder[i][j]<='z') || ((preorder[i][j]-48)>=0 && (preorder[i][j]-48)<=9))
      {}
      else
      {
      cout<<"Invalid Input : Please Enter Valid Input(Alphanumerics only)"<<endl;
      cin>>preorder[i];
      break;
      }
    }
  }
  for(int i=0;i<no;i++)
  {
    cin>>inorder[i];
  }

	Node* root = buildTree(inorder, preorder, 0, no - 1);
	// cout << "Postorder traversal of the constructed tree is \n";
	printPostorder(root);
}

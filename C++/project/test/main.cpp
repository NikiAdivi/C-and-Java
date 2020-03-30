#include<bits/stdc++.h>
#include"Task3.h"


int main()
{
  Equation* e=new Task3();
  string s;
  cin>>s;
  e->checkvalid(s);
  if(e->getflag())
  {
    cout<<e->solve();
  }
}

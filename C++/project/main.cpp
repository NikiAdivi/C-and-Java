#include<bits/stdc++.h>
#include"Task3.h"


int main()
{
  Equation* e=new Task3();
  e->checkvalid("3.5x+7.5x-4=4.5x-8+5.5x-2");
  if(e->getflag())
  {
    cout<<e->solve();
  }
}
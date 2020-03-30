#ifndef EQUATION_H
#define EQUATION_H

#include <bits/stdc++.h>

using namespace std;

class Equation
{
private:
    bool flag;
public:
    Equation();
    ~Equation();
    virtual void checkvalid(string)=0;
    virtual string solve()=0;
    void setflag(bool);
    bool getflag();
};

#endif


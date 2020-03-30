// #include "equation.hpp"
#include <bits/stdc++.h>

using namespace std;

class Equation
{
private:
    bool flag;
public:
    Equation(){}
    ~Equation(){}
    virtual void checkvalid(string)=0;
    virtual string solve()=0;
    void setflag(bool){}
    bool getflag(){}
};


class Task3 : public Equation
{
  string input;
  vector<float> x_coeff_lhs;
  vector<float> constants_lhs;
  vector<float> x_coeff_rhs;
  vector<float> constants_rhs;
  vector<string> terms_lhs;
  vector<string> terms_rhs;
  float x_lhs_sum;
  float x_rhs_sum;
  float c_lhs_sum;
  float c_rhs_sum;

  string convertToString(char* a, int size)
  {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
  }

public:

  Task3(string s):Equation()
  {
    input=s;
  }


  void checkvalid(string i)
  {
    char arr[input.length()+1];
    strcpy(arr,input.c_str());
    char* token=strtok(arr,"=");
    char* lhs=token;
    token=strtok(NULL,"=");
    char* rhs=token;
    cout<<" "<<lhs<<" "<<rhs<<" ";
    char* copy_lhs=strdup(lhs);
    char* copy_rhs=strdup(rhs);
    char* tokenlhs=strtok(lhs,"+-");

    if(lhs[0]=='-' && tokenlhs!=NULL)
      terms_lhs.push_back("-"+convertToString(tokenlhs,strlen(tokenlhs)));
    else
      terms_lhs.push_back(convertToString(tokenlhs,strlen(tokenlhs)));
    // char** array_ip=new char*[input.length()];

    while(tokenlhs!=NULL)
    {
      char delim=copy_lhs[tokenlhs-lhs+strlen(tokenlhs)];
      tokenlhs=strtok(NULL,"+-");
      if(tokenlhs!=NULL)
      {
        string tokenlhs_str=convertToString(tokenlhs,strlen(tokenlhs));
        if(delim=='+')
        {
          terms_lhs.push_back(tokenlhs_str);
        }
        else if(delim=='-')
        {
          terms_lhs.push_back("-"+tokenlhs_str);
        }
      }
    }

    char* tokenrhs=strtok(rhs,"+-");

    if(rhs[0]=='-' && tokenrhs!=NULL)
      terms_rhs.push_back("-"+convertToString(tokenrhs,strlen(tokenrhs)));
    else
      terms_rhs.push_back(convertToString(tokenrhs,strlen(tokenrhs)));

    while(tokenrhs!=NULL)
    {
      char delim1=copy_rhs[tokenrhs-rhs+strlen(tokenrhs)];
      tokenrhs=strtok(NULL,"+-");
      if(tokenrhs!=NULL)
      {
        string tokenrhs_str=convertToString(tokenrhs,strlen(tokenrhs)+1);
        if(delim1=='+')
        {
          terms_rhs.push_back(tokenrhs_str);
        }
        else if(delim1=='-')
        {
          terms_rhs.push_back("-"+tokenrhs_str);
        }
      }
    }

    //LHS:
    for(vector<string>::iterator i=terms_lhs.begin();i<terms_lhs.end();i++)
    {
      string s=*i;
      // cout<<s<<" "<<s.length()<<" ";
      if(s[0]=='x')
      {
        s="1"+s;
      }
      if(s[s.length()-1]=='x')
      {
        if(s[0]=='-')
        {
          if(s[1]=='x')
          {
            s="-1"+s.substr(1,s.length()-1);
          }
          s=s.substr(1,s.length()-2);
          int term=-stof(s);
          x_coeff_lhs.push_back(term);
        }
        else
        {
          s=s.substr(0,s.length()-1);
          x_coeff_lhs.push_back(stof(s));
        }
      }
      else
      {
        if(s[0]=='-')
        {
          s=s.substr(1,s.length()-1);
          int term=-stof(s);
          constants_lhs.push_back(term);
        }
        else
        {
          s=s.substr(0,s.length());
          constants_lhs.push_back(stof(s));
        }
      }
    }

    for(vector<float>::iterator i=x_coeff_lhs.begin();i<x_coeff_lhs.end();i++)
    {
      // cout<<*i<<" ";
      x_lhs_sum+=*i;
    }
    for(vector<float>::iterator i=constants_lhs.begin();i<constants_lhs.end();i++)
    {
      // cout<<*i<<" ";
      c_lhs_sum+=*i;
    }

    //RHS:
    for(vector<string>::iterator i=terms_rhs.begin();i<terms_rhs.end();i++)
    {
      string s=*i;
      // cout<<s<<" "<<s.length()<<" ";
      if(s[0]=='x')
      {
        s="1"+s;
      }
      if(s[s.length()-1]=='x')
      {
        if(s[0]=='-')
        {
          if(s[1]=='x')
          {
            s="-1"+s.substr(1,s.length()-1);
          }
          s=s.substr(1,s.length()-2);
          int term=-stof(s);
          x_coeff_rhs.push_back(term);
        }
        else
        {
          s=s.substr(0,s.length()-1);
          x_coeff_rhs.push_back(stof(s));
        }
      }
      else
      {
        if(s[0]=='-')
        {
          s=s.substr(1,s.length()-1);
          int term=-stof(s);
          constants_rhs.push_back(term);
        }
        else
        {
          s=s.substr(0,s.length());
          constants_rhs.push_back(stof(s));
        }
      }
    }

    for(vector<float>::iterator i=x_coeff_rhs.begin();i<x_coeff_rhs.end();i++)
    {
      // cout<<*i<<" ";
      x_rhs_sum+=*i;
    }
    for(vector<float>::iterator i=constants_rhs.begin();i<constants_rhs.end();i++)
    {
      // cout<<*i<<" ";
      c_rhs_sum+=*i;
    }
    if(x_lhs_sum==x_rhs_sum)
    {
      cout<<"No Solution!";
    }
    else
      cout<<"x="+to_string((c_rhs_sum-c_lhs_sum)/(x_lhs_sum-x_rhs_sum));
  }

  string solve(){}
};

int main()
{
  Equation* e=new Task3("3.5x-4=4.5x-8");
  e->checkvalid(" ");
}


//Overload assignment operator
//Shouldnt be any other alphabet, one x on left and one x on right
//Conditions:
//If alphabet then x
//One alphabet on left and one on right;
//Check general validity()

#include <bits/stdc++.h>
// #include<sstream>
#include "Task3.h"

using namespace std;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

void Task3::populate()
{
    char arr[input.length()+1];
    strcpy(arr,input.c_str());
    char* token=strtok(arr,"=");

    char* lhs=token;
    token=strtok(NULL,"=");
    char* rhs=token;

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
        string tokenrhs_str=convertToString(tokenrhs,strlen(tokenrhs));
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
}

//To check if this is my type of equation
void Task3::checkvalid(string s)
{
    input=s;
    char arr[input.length()+1];
    strcpy(arr,input.c_str());         //Convert string to character

    char* token=strtok(arr,"=");
    char* lhs=token;
    token=strtok(NULL,"=");            //Splitting at =
    char* rhs=token;
    int flag_lhs=1;int flag_rhs=1;
    int flag_lhs_x=0;int flag_rhs_x=0;

    for(int i=0;i<strlen(lhs);i++)
    {
      if(lhs[i]=='x'){
      if(i<strlen(lhs)-1){
        if(lhs[i+1]=='+' || lhs[i+1]=='-')
          flag_lhs_x=1;
        else
        {
          flag_lhs_x=0;
          break;}}}
      if(lhs[i]=='^' || (lhs[i]>=97 && lhs[i]<=122 && lhs[i]!='x') || lhs[i]=='|')
      {
        flag_lhs=0;
        break;
      }
    }

    for(int i=0;i<strlen(rhs);i++)
    {
      if(rhs[i]=='x'){
      if(i< strlen(rhs)-1){
        if(rhs[i+1]=='+' || rhs[i+1]=='-')
        flag_rhs_x=1;
        else
        {
        flag_rhs_x=0;
        break;}}}
      if(lhs[i]=='^' || (rhs[i]>=97 && rhs[i]<=122 && rhs[i]!='x') || rhs[i]=='|')
      {
        flag_rhs=0;
        break;
      }
    }

    if(flag_lhs && flag_rhs && flag_lhs_x && flag_rhs_x)
    {
      populate();
      setflag(true);
    }
}

string Task3::solve()
{
    //LHS:
    for(vector<string>::iterator i=terms_lhs.begin();i<terms_lhs.end();i++)
    {
      string s=*i;
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
      x_lhs_sum+=*i;
    }
    for(vector<float>::iterator i=constants_lhs.begin();i<constants_lhs.end();i++)
    {
      c_lhs_sum+=*i;
    }

    //RHS:
    for(vector<string>::iterator i=terms_rhs.begin();i<terms_rhs.end();i++)
    {
      string s=*i;
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
      x_rhs_sum+=*i;
    }
    for(vector<float>::iterator i=constants_rhs.begin();i<constants_rhs.end();i++)
    {
      c_rhs_sum+=*i;
    }
    if(x_lhs_sum==x_rhs_sum)
    {
      return "NoSolution!";
    }
    else
    {
      float f=(c_rhs_sum-c_lhs_sum)/(x_lhs_sum-x_rhs_sum);
      stringstream stream;
      stream<<fixed<<setprecision(4)<<f;
      return "x="+stream.str()+"\n";
    }
}

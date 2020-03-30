#ifndef T
#define T
#include<bits/stdc++.h>
#include "equation.h"

class Task3 : public Equation
{
    public:
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

        Task3():Equation(){}

        void populate();
        void checkvalid(string s);
        string solve();

};
#endif

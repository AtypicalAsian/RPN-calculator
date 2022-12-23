//==========================================================
// Stack calculator
// This program simulates the operation of an RPN calculator
// that uses a stack to keep track of operands.
//==========================================================
#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<vector>
using namespace std; 

float calculator(float one, float two, string op);
vector<string> splitSpaces(string str);

//==========================================================
// main
//==========================================================
int main (void)
{
    string input;
    while (getline(cin,input))
    {
        stack<float> s;
        vector<string> v = splitSpaces(input);

        for (int i=0; i<v.size(); i++)
        {
            if (v[i]=="+" || v[i]=="-" || v[i]=="*" ||
                v[i]=="/" || v[i]=="^")
            {
                float last = s.top(); s.pop();
                float secLast = s.top(); s.pop();
                s.push(calculator(secLast, last, v[i]));
            }
            else if (v[i] == "clear")
            {
                while ( !s.empty() )
                    s.pop();
            }
            else
            {
                float n = stof(v[i]);
                s.push(n);
            }
        }
        cout << s.top() << endl;

    }
    return 0;
}

//==========================================================
// splitSpaces
// This function splits a string into vector by spaces.
// PARAMETERS:
// - a string str
// RETURN: 
// - a vector of string
//==========================================================
vector<string> splitSpaces(string str)
{
    vector<string> ret;

    int i=0;
    string sub = "";
    while (i<str.length())
    {
       if(str[i]!=' ')
           sub += str[i];
       else 
       {
           ret.push_back(sub);
           sub.clear();
       }
       i++;
    }
    ret.push_back(sub);
    return ret;
}

//==========================================================
// calculator
// This function does the binary calculation.
// PARAMETERS:
// - one, two : (float) numbers
// - op : (string) the binary operation
// RETURN: 
// - the result of calculation.
//==========================================================
float calculator(float one, float two, string op)
{
    float ret;
    if (op == "+")
        ret = one+two;
    else if (op == "-")
        ret = one-two;
    else if (op == "*")
        ret = one*two;
    else if (op == "/")
        ret = one/two;
    else if (op == "^")
        ret = pow(one,two);
        
    return ret;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    string data="Al Amin";
    bool res= true;
    getline(cin,name);
    for(int i=0;i<name.length();i++)
    {
        if(name[i]!=data[i])
        {
            res= false;
            break;
        }
    }
    if(res)
    {
        cout<<"Name is Match"<<endl;
    }
    else
    {
        cout<<"Name not match"<<endl;
    }
}
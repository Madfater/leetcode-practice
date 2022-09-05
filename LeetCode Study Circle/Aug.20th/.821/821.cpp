#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> shortestToChar(string s, char c) 
{
    vector<int> v(s.length(),INT_MAX);

    for(int i=0;i<s.length();i++)
        if(s[i]==c)
        {
            v[i]=0;

            for (int j=1;i-j>=0 and v[i-j]!=0;j++)
                v[i-j]=min(j,v[i-j]);

            for (int j=1;i+j<=s.length()-1 and v[i+j]!=0;j++)
                v[i+j]=min(j,v[i+j]);
    
        }

    return v;
}

int main()
{
    for(int& n:shortestToChar("loveleetcode",'e'))
        cout<<n<<' ';
    cout<<'\n';
}
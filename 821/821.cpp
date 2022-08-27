#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> shortestToChar(string s, char c) 
{
    vector<int> v(s.length(),10000);

    for(int i=0;i<s.length();i++)
        if(s[i]==c)
            v[i]=0;

    for(int i=0;i<s.length();i++)
        if(v[i]==0)
        {
            int j=1;
            while (i-j>=0 and v[i-j]!=0)
            {
                v[i-j]=min(j,v[i-j]);
                j++;
            }
            j=1;
            while (i+j<=s.length()-1 and v[i+j]!=0)
            {
                v[i+j]=min(j,v[i+j]);
                j++;
            }
            
        }

    return v;
}

int main()
{
    for(int& n:shortestToChar("loveleetcode",'e'))
        cout<<n<<' ';
    cout<<'\n';
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
static bool comp(vector<int> &a,vector<int> &b)
{
    if(a[0]!=b[0])
        return a[0]>b[0];
    return a[1]<b[1];
}
int numberOfWeakCharacters(vector<vector<int>>& prop) 
{
    sort(prop.begin(),prop.end(),comp);
    int max_num = INT_MIN;
    int ans=0;
    for(auto p:prop)
    {
        if(max_num>p[1]) 
            ans++;
        else 
            max_num=p[1];
    }
    return ans;
}
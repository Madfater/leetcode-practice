#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
{
    int ans=0;
    
    sort(arr2.begin(),arr2.end());

    for(auto &i:arr1)
    {
        if(abs(i-(*lower_bound(arr2.begin(),arr2.end(),i-d)))<=d)
            continue;
        ans++;
    }
            
    return ans;
}

int main()
{
    vector<int> arr1{4,5,8},arr2{10,9,1,8};
    int d=2;
    cout<<findTheDistanceValue(arr1,arr2,d)<<'\n';
    return 0;
}
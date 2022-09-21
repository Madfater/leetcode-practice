#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
{
    int num=0;
    vector<int> ans;
    
    for(int &j:nums)
        if(j%2==0)
            num+=j;
    
    for(auto &i:queries)
    {
        if(nums[i[1]]%2==0)
            num-=nums[i[1]];
        nums[i[1]]+=i[0];
        if(nums[i[1]]%2==0)
            num+=nums[i[1]];
        ans.push_back(num);
    }
        
    return ans;
}
int main()
{
    vector<int> nums{1,2,3,4};
    vector<vector<int>> queries{{1,0},{-3,1},{-4,0},{2,3}};
    for(auto &i:sumEvenAfterQueries(nums,queries))
        cout<<i<<' ';
    cout<<'\n';
}
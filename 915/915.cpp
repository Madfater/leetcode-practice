#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partitionDisjoint(vector<int>& nums) 
{
    vector<int> left_max(nums.size(),0),right_min(nums.size(),0);
    int max_num=INT_MIN,min_num=INT_MAX;

    for(int i=0;i<nums.size();i++)
    {
        max_num=max(max_num,nums[i]);
        left_max[i]=max_num;
    }

    for(int i=nums.size()-1;i>0;i--)
    {
        min_num=min(min_num,nums[i]);
        right_min[i]=min_num;
    }

    /*for (int& n:left_max)
        cout<<n<<' ';
    cout<<'\n';
    
    for (int& n:right_min)
        cout<<n<<' ';
    cout<<'\n';*/

    for(int i=0;i<nums.size()-1;i++)
        if(left_max[i]<=right_min[i+1])
            return i+1;

    return -1;
}

int main()
{
    vector<int> nums({5,0,3,8,6});
    cout<<partitionDisjoint(nums);
}  
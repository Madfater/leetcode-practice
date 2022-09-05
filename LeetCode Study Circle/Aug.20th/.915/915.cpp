#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partitionDisjoint(vector<int>& nums) 
{
    vector<int> left_max(nums.size(),INT_MIN),right_min(nums.size(),INT_MAX);

    left_max[0]=nums[0];
    right_min[nums.size()-1]=nums[nums.size()-1];

    for(int i=1;i<nums.size();i++)
        left_max[i]=max(nums[i],left_max[i-1]);

    for(int i=nums.size()-2;i>0;i--)
        right_min[i]=min(nums[i],right_min[i+1]);


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
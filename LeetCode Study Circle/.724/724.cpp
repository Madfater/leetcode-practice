#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int pivotIndex(vector<int>& nums) 
{
        
    int size=nums.size();
    vector<int> right_sum(size,0);
    vector<int> left_sum(size,0);

    partial_sum(nums.begin(),nums.end(),right_sum.begin());
    partial_sum(nums.rbegin(),nums.rend(),left_sum.rbegin());

    for(int i=0;i<size;i++)
        if(right_sum[i]==left_sum[i])
            return i;
    
    return -1;
}


int main()
{
    vector<int> nums({1,7,3,6,5,6});
    
    cout<<pivotIndex(nums);
    
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<stack>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) 
{
    stack<int> st;
    int ans=INT_MIN;
    ListNode* fast=head;
    ListNode* half=head;

    while(fast!=nullptr)
    {
        st.push(half->val);
        fast=fast->next->next;
        half=half->next;
    }

    while (half!=nullptr)
    {
        ans=max(ans,st.top()+half->val);
        st.pop();
        half=half->next;
    }
    
    return ans;
}
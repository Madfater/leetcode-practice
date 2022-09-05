#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DFS(TreeNode* node,int *cnt,int max_num)
{
    if(!node)
        return ;
        
    if(node->val>=max_num)
        (*cnt)++;

    DFS(node->right,cnt,std::max(max_num,node->val));
    DFS(node->left,cnt,std::max(max_num,node->val));
}

int goodNodes(TreeNode* root) 
{
    int cnt=0;
    DFS(root,&cnt,INT_MIN);
    return cnt;
}

int main()
{
    TreeNode* root=nullptr;
    cout<<goodNodes(root)<<'\n';
    return 0;
}
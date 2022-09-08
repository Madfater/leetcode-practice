#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<stack>
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

void DFS(TreeNode* node,vector<int>* ans)
{
    if(!node)
        return;
    
    DFS(node->left,ans);
    (*ans).push_back(node->val);
    DFS(node->right,ans);
}

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> ans;
    
    DFS(root,&ans);

    return ans;
}
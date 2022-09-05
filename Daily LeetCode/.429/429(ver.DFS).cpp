#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Node 
{
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) 
        {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) 
        {
            val = _val;
            children = _children;
        }
};

void DFS(Node* node,int level,vector<vector<int>>* ans)
{
    if (node==nullptr)
        return;

    if ((*ans).size()==level)
        (*ans).push_back(vector<int>(1,node->val));   
    else
        (*ans)[level].push_back(node->val);

    for(auto& i:node->children)
        DFS(i,level+1,ans);

}

vector<vector<int>> levelOrder(Node* root) 
{
        vector<vector<int>> ans;
        
        DFS(root,0,&ans);

        return ans;
}

int main()
{

}
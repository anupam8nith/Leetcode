/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    vector<int> ans;
    
    void pre(Node* curr)
    {
        if(curr==NULL)
            return;
       
        if(curr!=NULL)
         ans.push_back(curr->val);
        
        for(auto ptr : curr->children)
        {
            if(ptr!=NULL)
            pre(ptr);
        }
        
        return;
    }
    
    
    vector<int> preorder(Node* root) 
    {
        if(root==NULL)
        return ans;
        
        pre(root);
        
        return ans;
        
    }
};

//fastest solution

// class Solution {
// public:
//     vector<int> ans;
//     void solve(Node* root)
//     {
//         if(root==NULL)return;
//         ans.push_back(root->val);
//         for(int i=0;i<root->children.size();i++)
//         {
//             solve(root->children[i]);
//         }
//     }
//     vector<int> preorder(Node* root) {
//         solve(root);
//         return ans;
//     }
// };
// static bool     _foo = ios::sync_with_stdio(false);
// static ostream* _bar = cin.tie(NULL);
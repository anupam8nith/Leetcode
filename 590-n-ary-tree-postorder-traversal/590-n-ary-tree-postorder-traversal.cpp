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

class Solution {
public:
    vector<int> ans;
    
     void post(Node* curr)
    {
        if(curr==NULL)
            return;
       
        
        
        for(auto ptr : curr->children)
        {
            if(ptr!=NULL)
            post(ptr);
        }
         if(curr!=NULL)
         ans.push_back(curr->val);
        
        return;
    }
    
    
    vector<int> postorder(Node* root) 
    {
        if(root==NULL)
        return ans;
        
        post(root);
        
        return ans;
        
    }
};
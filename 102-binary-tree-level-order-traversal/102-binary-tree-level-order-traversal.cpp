/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>level;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                level.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


//working code

// vector<vector<int>> ans; // to store and return the tree in BFS way
//         queue<TreeNode*> q; // queue for storing at every level
//         //if root is null
//         if(root==NULL)
//             return ans;
//         //loop
//         q.push(root); //put first element of tree in queue
        
//         while(!q.empty()) // exit condition
//         {
//             int size = q.size();
//             vector<int> level; // for storing elements in each level
            
//             for(int i=0;i<size;i++)
//             {   
//                 TreeNode *curr_node = q.front(); // store the first node in queue and pop it
//                 q.pop();
                
//                 if(curr_node->left !=NULL) q.push(curr_node->left);
//                 if(curr_node->right !=NULL) q.push(curr_node->right);
                
//                 level.push_back(curr_node->val);
//             }
//             ans.push_back(level);
            
//         }
        
        
//         return ans;
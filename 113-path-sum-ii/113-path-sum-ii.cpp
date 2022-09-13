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

// you can improve this code

// class Solution {
// public:
//     void helper(TreeNode* root, int &targetSum, vector<int> sumpath,int tillnow, vector<vector<int>> &sums)
//     {
//         if(root->left==NULL && root->right==NULL)
//         {
//             if(tillnow+root->val==targetSum)
//             {
//                 sumpath.push_back(root->val);
//                 sums.push_back(sumpath);
//             }
//             return; 
//         }
        
//         tillnow+=root->val;
//         sumpath.push_back(root->val);
        
//         if(root->left)
//         helper(root->left,targetSum,sumpath,tillnow,sums);
//         if(root->right)
//         helper(root->right,targetSum,sumpath,tillnow,sums);
        
//         return;
//     }
    
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
//     {
//         vector<vector<int>> sums;
//         if(root==NULL) return sums;
        
//         vector<int> sumpath;
//         int tillnow=0;
        
//         helper(root,targetSum,sumpath,tillnow,sums);
        
        
//         return sums;
        
//     }
// };


//best solution

class Solution {
public:
    void getAllPaths(TreeNode *root,int targetSum,vector<int> temp,vector<vector<int>> &ans)
    {
        if(!root)
            return;
        if(!root->left and !root->right and targetSum == root->val)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getAllPaths(root->left,targetSum-root->val,temp,ans);
        getAllPaths(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        getAllPaths(root,targetSum,{},ans);
        return ans;
    }
};
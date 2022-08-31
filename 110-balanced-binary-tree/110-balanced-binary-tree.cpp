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
    bool check = true;
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh - rh) > 1) check = false;
        
        return max(lh,rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
       height(root);      
        return check;
          
    }
    
};
// O(n) complexity

// class Solution {
// public:
// int height(TreeNode *root)
//     {
//         if(root==NULL) return 0;
        
//         int lft = height(root->left);
//         if(lft==-1) return -1;
//         int rht = height(root->right);
//         if(rht==-1) return -1;
    
        
//         if(abs(lft-rht)>1) return -1;
    
//         return max(lft, rht) + 1;
//     }
    
// bool isBalanced(TreeNode* root) 
//     {
//         if(root==NULL) return true;
        
//         if(height(root)==-1)
//             return false;
        
//         return true;
//     }
// };

//n*n complexity solution

// class Solution {
// public:
    
//     int height(TreeNode *root)
//     {
//         if(root==NULL) return 0;
        
//         int lft = height(root->left);
//         int rht = height(root->right);
        
//         return max(lft, rht) + 1;
//     }
    
//     bool isBalanced(TreeNode* root) 
//     {
//         if(root==NULL) return true; 
        
//         int lh = height(root->left);
//         int rh = height(root->right);
        
//         if(abs(lh-rh)>1) return false;
        
//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);
        
//         if(left==false || right==false) return false;
        
//         return true;
        
//     }
// };
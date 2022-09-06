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
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(!root) return NULL;
        
        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        
        return root;
    }
};

// //Approach-2 (We check from bottom to up and at the same time remove subtree) 
// //Time (O(n))
// class Solution {
// public:
//     TreeNode* pruneTree(TreeNode* root) {
//         if(!root)
//             return NULL;
//         /*
// 			Recursion is like writing a story
// 		*/
//         root->left  = pruneTree(root->left);   //I looked at my left and pruned them (if any)
//         root->right = pruneTree(root->right);  //I looked at my right and pruned them (if any)
        
// 		//But wait a second, If i don't have left and right child and myself is '0' then I am pruning myself too :-(
//         if(!root->left && !root->right && root->val == 0)
//             return NULL;
        
//         return root;
//     }
// };




// //Approach-1 (Naive and the first approach that comes to mind) Time: O(n^2)
// /*
// 	 I am at node X, 
//      if my left doesn't contain '1', X->left = NULL
//      if my right doesn't contain '1', X->right = NULL
// 	 Do this for every node while DFS
// */

// class Solution {
// public:
// 	//This is called for all node and hence Time : O(n^2)
//     bool checkOne(TreeNode* root) {
//         if(!root)
//             return false;
        
//         if(root->val == 1)
//             return true;
        
//         return checkOne(root->left) || checkOne(root->right);
//     }
    
//     TreeNode* pruneTree(TreeNode* root) {
//         if(!root)
//             return NULL;
        
//         pruneTree(root->left);
//         pruneTree(root->right);
        
//         if(!checkOne(root->left))  root->left = NULL;
//         if(!checkOne(root->right)) root->right = NULL;
        
        
//         if(!root->left && !root->right && root->val == 0)
//             return NULL;
//         return root;
//     }
// };
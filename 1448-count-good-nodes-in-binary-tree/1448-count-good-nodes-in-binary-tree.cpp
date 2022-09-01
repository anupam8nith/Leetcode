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
// Time complexity: O(N) as we visit every node only once.
// Space complexity: O(H) where H is the height of the tree.
// In the worst case, H would be N given that the tree only has one path.
class Solution {
public:
    // the idea is to record the max value from the root to the node
    // we can first initialise mx as INT_MIN 
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        // if the root is null, we return 0
        if (!root) return 0;
        // then we can break it into 3 parts
        // the first part is the current node
        // if the current node value is greater than the maximum value so far
        // that means the current node is a good node
        // hence we add 1, else add 0
        return (mx <= root->val ? 1 : 0) + 
                // the second part is the result of the left sub-tree
                // we traverse it with the updated maximum value at the current point
                // we don't need to check if root->left is null or not here
                // as we cover the null case in the first line
                goodNodes(root->left, max(root->val, mx)) + 
                // the last part is the result of the right sub-tree
                // we traverse it with the updated maximum value at the current point
                // we don't need to check if root->right is null or not here
                // as we cover the null case in the first line
                goodNodes(root->right, max(root->val, mx));
    }
};

//best

// class Solution {
// public:
    
//     int solve(TreeNode* root,int maxi)
//     {
//         if(root==NULL)
//             return 0;
        
//         maxi=max(root->val,maxi);
//         if(root->val>=maxi)
//             return 1+ solve(root->left,maxi)+solve(root->right,maxi);
//         return solve(root->left,maxi)+solve(root->right,maxi);
        
        
//     }
//     int goodNodes(TreeNode* root) {
        
      
//         return solve(root,INT_MIN);
        
//     }
// };



//best soltion

// int goodNodes(TreeNode* r, int ma = -10000) {
//         return r ? goodNodes(r->left, max(ma, r->val)) + goodNodes(r->right, max(ma, r->val)) + (r->val >= ma) : 0;
//     }


// a good solution

// class Solution {
// public:
//     int goodNodes(TreeNode* root) 
//     {
        
//     }
// };

// class Solution {
// public:
//     int goodNodes(TreeNode* root) {
//         int count =0;
//         dfss(root,root->val,count);
//         return count;
            
        
//     }
//     void dfss(TreeNode* root, int maximum,int&count)
//     {
        
//         if(root==NULL)
//         {
//          return ;
//          }
//         if(maximum<=root->val)
//         {
//             count++;
//         }
//         dfss(root->left,max(maximum,root->val),count);
//         dfss(root->right,max(maximum,root->val),count);
        
//     }
// }; 
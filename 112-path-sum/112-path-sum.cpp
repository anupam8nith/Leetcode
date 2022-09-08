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
    
    bool hasPathSum(TreeNode* root, int sum) 
    {
        // manaual dfs 
        stack <tuple <TreeNode*, int>> S;
        int cur_total;
        TreeNode *cur_node;
        S.push(make_tuple(root, 0));
        
        while (!S.empty()) {
            cur_node = get<0>(S.top());
            cur_total = get<1>(S.top());
            S.pop();
            
            if (!cur_node) {
                continue;
            } else if (!cur_node->left && !cur_node->right) {
                if (cur_total + cur_node->val == sum) { return true; }
                continue;
            }
            
            S.push(make_tuple(cur_node->right, cur_total+cur_node->val)); 
            S.push(make_tuple(cur_node->left, cur_total+cur_node->val));
        }
        
        return false;
       
    }
};


 //recursive
//         if(root==NULL) return false;
        
//          if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
//         return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);


//recrsive

// if(root == NULL)  return false;
//     if(root->right == root->left)  return sum == root->val;
//     return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val) ;



// recursive

// if(root == NULL)
//         {
//             return false;
//         }
//         if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
//         {
//             return true;
//         }
        
//         bool left = hasPathSum(root->left,targetSum - root->val);
//         bool right = hasPathSum(root->right,targetSum - root->val);
        
//         return left || right;

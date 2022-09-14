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
    
    int count = 0;
//     bool canbepalindrome(unordered_map<int,int> &um)
//     {
//         int oddcount=0;
        
//         for(auto freq: um)
//         {
//             if(freq.second % 2 == 1)
//                 oddcount++;
            
// //             if(oddcount>1)
// //                 return false;
//         }
        
//         // if(oddcount==0)
//         //     return true;
//         // else if(oddcount==1)
//         //     return true;
//         // else
//         //     return true;
        
//         if(oddcount <= 1){
//             return true;
//         }else{
//             return false;
//         }
//     }
    
    void getstring(TreeNode * root,unordered_map<int,int> &um)
    {
        if(!root) return;
        
         um[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int odd = 0;
            for(auto el : um){
                if(el.second %2 == 1)
                    odd++;
            }
            
            if(odd <= 1)
              count++;

        }
        
       
      
        
        getstring(root->left,um);
        getstring(root->right,um);
                     um[root->val]--;


    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
    
        
        if(root->left==NULL and root->right==NULL) return 1;
        
        unordered_map<int,int> um;
        
        getstring(root,um);
        
        return count;
    }
};

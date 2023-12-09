class Solution {
public:
    string ans="";
    void solve(TreeNode* root){
        if(!root) return;
        ans += to_string(root->val);
        if(root->left==NULL && root->right==NULL) return;
        ans += "(";
        solve(root->left);
        ans += ")";
        if(root->right!=NULL){
            ans += "(";
            solve(root->right);
            ans += ")";
        }
    }
    string tree2str(TreeNode* root) {
        solve(root);
        return ans;
    }
};
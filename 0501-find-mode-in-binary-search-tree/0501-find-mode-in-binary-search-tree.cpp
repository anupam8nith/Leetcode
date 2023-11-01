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
    map<int, int> um;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        um[root->val]++;
        traverse(root->left);  // Fixed the condition for left and right subtrees
        traverse(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        traverse(root);

        // Changed the loop to iterate over the map and extract keys and values
        for (auto it = um.begin(); it != um.end(); ++it) {
            if (ans.empty() || it->second > um[ans.back()]) {
                ans.clear();
                ans.push_back(it->first);
            } else if (it->second == um[ans.back()]) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};
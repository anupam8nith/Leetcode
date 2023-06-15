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
  int maxLevelSum(TreeNode* root) {
    // Initialize the level, answer, and maximum sum.
    int level = 1;
    int ans = 1;
    int max_till = INT_MIN;

    // Create a queue to store the nodes of the current level.
    queue<TreeNode*> q;
    q.push(root);

    // While the queue is not empty, do the following:
    while (!q.empty()) {
      // Get the size of the current level.
      int sz = q.size();

      // Initialize the sum of the current level.
      int sum = 0;

      // Iterate over all the nodes of the current level.
      for (int i = 0; i < sz; i++) {
        // Get the node at the front of the queue.
        TreeNode* node = q.front();
        q.pop();

        // Add the value of the node to the sum.
        sum += node->val;

        // If the node has a left child, add it to the queue.
        if (node->left) {
          q.push(node->left);
        }

        // If the node has a right child, add it to the queue.
        if (node->right) {
          q.push(node->right);
        }
      }

      // If the sum of the current level is greater than the maximum sum so far, update the maximum sum and the answer.
      if (sum > max_till) {
        max_till = sum;
        ans = level;
      }

      // Increment the level.
      level++;
    }

    // Return the answer.
    return ans;
  }
};

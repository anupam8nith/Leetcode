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
   
    unordered_map<int, pair<int,int>> mp;
    
	void solve(TreeNode* root, int level, int parent)
    {

		if(root == NULL){
			return;
		}

		mp[root->val] = {level, parent};

		solve(root->left, level + 1, root->val);
		solve(root->right, level + 1, root->val);
	}

	bool isCousins(TreeNode* root, int x, int y) 
    {
		solve(root, 0, -1);

		if(mp[x].first == mp[y].first && mp[x].second != mp[y].second){
			return true;
		}

		return false;
	}
    
    };
    
// DFS solution

// class Solution {
// public:

// 	unordered_map<int, pair<int,int>> mp;
// 	void solve(TreeNode* root, int level, int parent){

// 		if(root == NULL){
// 			return;
// 		}

// 		mp[root->val] = {level, parent};

// 		solve(root->left, level + 1, root->val);
// 		solve(root->right, level + 1, root->val);
// 	}

// 	bool isCousins(TreeNode* root, int x, int y) {

// 		solve(root, 0, -1);

// 		if(mp[x].first == mp[y].first && mp[x].second != mp[y].second){
// 			return true;
// 		}

// 		return false;
// 	}
// };






// my solution: bfs

// class Solution {
// public:
//     bool isCousins(TreeNode* root, int x, int y) 
//     {
//         //BFS
        
//         queue<TreeNode*> q;
//     q.push(root);
    
//     while(!q.empty())
//     {
//         int size = q.size();
//         bool foundX = false;
//         bool foundY = false;
        
//         for(int i=0;i<size;i++)
//         {
//             TreeNode* curr = q.front();
//             q.pop();
//             if(curr->val == x)
//                 foundX = true;
//             if(curr->val == y)
//                 foundY = true;
            
//             if(curr->left && curr->right)  // check if x and y are children of the same parent 
//             {
//                 if((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
//                     return false;
//             }
            
//             if(curr->left)
//                 q.push(curr->left);
            
//             if(curr->right)
//                 q.push(curr->right);
//         }
        
//         if(foundX && foundY)  // if x and y are cousins 
//             return true;
//     }
    
//     return false;
// }
    
// };
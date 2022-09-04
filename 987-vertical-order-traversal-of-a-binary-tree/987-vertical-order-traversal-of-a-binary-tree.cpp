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
    //DFS
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0, 0, nodes);
        
        vector<vector<int>> ans;
        
        for (auto p : nodes) 
        {
            vector<int> col;
            
            for (auto q : p.second) 
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
private:
    void traverse(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) 
    {
        if (root) 
        {
            nodes[x][y].insert(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};



//BFS

// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) 
//     {
//         map<int, map<int, set<int>>> nodes;
//         queue<pair<TreeNode*, pair<int, int>>> todo;
//         todo.push({root, {0, 0}});
        
//         while (!todo.empty()) 
//         {
//             auto p = todo.front();
//             todo.pop();
//             TreeNode* node = p.first;
            
//             int x = p.second.first, y = p.second.second;
//             nodes[x][y].insert(node -> val);
            
//             if (node -> left) 
//             {
//                 todo.push({node -> left, {x - 1, y + 1}});
//             }
//             if (node -> right) 
//             {
//                 todo.push({node -> right, {x + 1, y + 1}});
//             }
//         }
//         vector<vector<int>> ans;
        
//         for (auto p : nodes) 
//         {
//             vector<int> col;
//             for (auto q : p.second) 
//             {
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             ans.push_back(col);
//         }
//         return ans;
//     }
// };



// solution 1

// class Solution 
// {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) 
//     {
// 	map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
        
// 	queue<pair<int, TreeNode*> > q; // for level traversal
// 	q.push(make_pair(0, root));  // root default x-axis is 0
        
// 	while(!q.empty()) 
//     {
//         // k: x-axis, v:val Already solved the case when the position is ths same
// 		set<pair<int, int> > tmp;
        
// 		int len=q.size();
        
// 		for(int i=0;i<len;++i) 
//         {
// 			auto p=q.front();
//             q.pop();
            
// 			tmp.insert(make_pair(p.first, p.second->val));
            
// 			if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
// 			if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
// 		}

// 		for(auto p : tmp) m[p.first].push_back(p.second);
// 	}

// 	vector<vector<int> > res;
        
// 	for(auto kv : m) 
//         res.push_back(kv.second);
        
// 	return res;
// }
   
// };


//NOT WORKING

//  vector<vector<int>> verticalTraversal(TreeNode* root) 
//     {
//         // vectical,         level, multi-nodes
//         //   x,              y,   ,   node->val
//         map<int,map<int,multiset<int,int>>> mp;
        
//         queue<pair<TreeNode*,pair<int,int>>> q;
//         q.push({root,{0,0}});
        
//         while(!q.empty())
//         {
//             // store node, vertical, level in p
//             auto p = q.front();
//             q.pop();
            
//             //store the address of node in curr for a vertical order
//             TreeNode *curr = p.first;
            
//             // x= vertical , y= level
//             int x = p.second.first, y = p.second.second;
            
//             //insert the curr->val according to x,y
//             mp[x][y].insert(curr->val);
            
//             // store if left or right is available
//             if(curr->left!=NULL) q.push({curr->left,{x-1,y+1}});
//             if(curr->right!=NULL) q.push({curr->right,{x+1,y+1}});
     
//         }
        
//         vector<vector<int>> ans;
        
//         for(auto p: mp)
//         {
//              vector<int> col;
            
//             for(auto q: p.second)
//             {
//                 col.insert(col.end(),q.second.begin(),q.second.end());
//             }
//             ans.push_back(col);
//         }
        
//         return ans;
        
//     }
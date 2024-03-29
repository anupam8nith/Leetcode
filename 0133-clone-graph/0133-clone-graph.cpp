/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> um;
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL) return NULL;
        
        if(um.find(node)==um.end())
        {
            um[node] = new Node(node->val,{});
            
            for(auto it: node->neighbors)
                um[node]->neighbors.push_back(cloneGraph(it));   
        }
        return um[node];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL) return nullptr;
        //BFS
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
                Node *curr=q.front();
                q.pop();
               
               if(curr)
               {
                   if(!q.empty())
                   {    
                       curr->next=q.front();
                   }
                   else
                   {
                       curr->next=NULL;
                       
                   }
                   
                   if(curr->left)q.push(curr->left);
                   if(curr->right)q.push(curr->right);
                }
                
            else 
            {
                if(!q.empty())
                    q.push(NULL);
            }
                
        }
        
        return root;
    }
};



// review


// class Solution {
// public:
//     Node* connect(Node* root) 
//     {
//         if(root==NULL) return nullptr;
//         //BFS
//         queue<Node*> q;
        
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int size=q.size();
            
//             vector<Node*> level;
            
//             for(int i=0;i<size;i++)
//             {
//                 Node *curr=q.front();
//                 q.pop();
                
//                 //operations
//                 level.push_back(curr);
                
                
//                 //store next level
//                 if(!curr->left)q.push(curr->left);
//                 if(!curr->right)q.push(curr->right);
//             }
            
//             for(int j=0;j<=level.size()-1;j++)
//             {
//                 if(j!=level.size()-1)
//                 level[j]->next=level[j+1];
//                 else
//                 level[j]->next=NULL;
//             }
//         }
        
//         return root;
//     }
// };
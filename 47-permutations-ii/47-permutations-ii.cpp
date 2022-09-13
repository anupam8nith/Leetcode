class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());
        
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);
     
        return ans;
    }
};

//
// class Solution {
// public:
//     void f(vector<vector<int>> &ans,vector<int> &nums,vector<int>&cur,vector<int>&visited,/*set<vector<int>>&s,*/int n){
//         if(cur.size()==n /*&& s.find(cur)==s.end()*/){
//             ans.push_back(cur);
//            // s.insert(cur);
//             return;
//         }
//         for(int i=0;i<n;i++){
//             if(visited[i]==0){
//                 if(i!=0 && nums[i]==nums[i-1] && visited[i-1]==0){
                    
//                 }
//                 else{
//                     cur.push_back(nums[i]);
//                 visited[i]=1;
//                 f(ans,nums,cur,visited,/*s,*/n);
//                 visited[i]=0;
//                 cur.pop_back();
//                 //f(ans,nums,cur,visited,s,n);
                    
//                 }
                
                
                
//             }
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>cur;
//         int n=nums.size();
//         vector<int> visited(n,0);
//         //set<vector<int>> s;
//         sort(nums.begin(),nums.end());
//         f(ans,nums,cur,visited,/*s,*/n);
//         return ans;
        
//     }
// };

//
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int> &a) {
      
//         sort(a.begin(),a.end());
//         int n=a.size();
//         vector<vector<int>>res;
//         res.push_back(a);
//         while(true){
//             int l=n-1;
//             while(l>0&&a[l-1]>=a[l]) l--;
//             if(l==0) break;
//             int k=l-1;
//             l=n-1;
//             while(a[k]>=a[l]) l--;
//             swap (a[k],a[l]);
//             sort(a.begin()+k+1,a.end());
//             res.push_back(a);
            
//         }
//         return res;
        
        
//     }
// };


//

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) 
//     {
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
        
//         do
//         ans.push_back(nums);
//         while(next_permutation(nums.begin(),nums.end()));
        
//         return ans;
        
//     }
// };
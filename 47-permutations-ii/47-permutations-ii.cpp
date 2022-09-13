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
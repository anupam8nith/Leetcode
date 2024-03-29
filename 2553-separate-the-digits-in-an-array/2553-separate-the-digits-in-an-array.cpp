class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans ;
        
        for( auto &it : nums ){
            
            string tmp = to_string(it);
            
            for( auto &s : tmp ) ans.push_back(s-'0');
            
        }
        
        return ans ;
    }
};


// class Solution {
// public:
//     void solve(vector<int> & nums, vector<int> &answer,int &n)
//     {
        
//         for(int i=0;i<n;i++)
//         {
//             vector<int> temp;
//             while(nums[i]!=0)
//             {
//                 int rem = nums[i]%10;
//                 nums[i]/=10;
//                 temp.push_back(rem);
//             }
//             reverse(temp.begin(),temp.end());
//             for(auto it: temp)answer.push_back(it);
//         }
//     }
    
    
//     vector<int> separateDigits(vector<int>& nums) 
//     {
//         int n =size(nums);
        
//         vector<int> answer;
        
//         solve(nums,answer,n);
        
//         return answer;
        
//     }
// };
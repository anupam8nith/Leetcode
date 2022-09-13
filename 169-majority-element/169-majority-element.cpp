class Solution {
public:
    int majorityElement(vector<int>& nums) {
          int n=nums.size();
        int vote =0,leader=0;
        for(int i=0;i<n;i++)
        {
            if(vote==0) leader=nums[i];
            if(leader==nums[i]) vote++;
            else vote--;
        }
        return leader;
    }
};

//naive solution

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) 
//     {
//         ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
        
//       unordered_map<int,int> um;
        
//         int n= nums.size();
        
//         for(int i=0;i<n;i++)
//         {
//             um[nums[i]]++;
            
//             if(um[nums[i]]>n/2)
//                 return nums[i];
//         }
        
//         return -1;
//     }
// };
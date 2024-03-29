class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) 
    {
        unordered_map<int,int> um; int n=size(nums); long long ans=n;
        
        for(int i=0;i<n;i++)
            um[nums[i]]=i;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++)
           if (um[nums[i]] < um[nums[i - 1]])
                ans += n - i;
        
        return ans;
        
    }
};


// TLE:-

// #pragma GCC optimise('O3')

// class Solution {
// public:
//     long long countOperationsToEmptyArray(vector<int>& nums) 
//     {
        
//         ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
        
//         deque<int>dq; set<int> s; long long ans=0;
        
//         for(auto it: nums) 
//         {dq.push_back(it);s.insert(it);}
        
//         while(!dq.empty())
//         {
//             if(*dq.begin()==*s.begin())
//             {
//                     s.erase(*dq.begin()); dq.pop_front();
//                     ans++;
//             }
//             else
//             {
//                 int x = dq.front();
//                 dq.pop_front();
//                 dq.push_back(x);
//                 ans++;
//             }
//         }
        
//         return ans;
        
//     }
// };
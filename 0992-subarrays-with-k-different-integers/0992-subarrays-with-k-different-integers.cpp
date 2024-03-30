class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    int atMostK(vector<int>& A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++) K--;
            while (K < 0) {
                if (!--count[A[i]]) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

//  TLE

// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) 
//     {
//         int n = nums.size(),ans=0; 
        
//         for(int i=0;i<n;i++)
//         {
//             unordered_set<int> us;
//             int j=i;
//             while(j<n)
//             {
//                 if(us.size()>k)
//                     break;
//                 us.insert(nums[j]);
//                 if(us.size()==k)
//                     ans++;
                
//                 j++;
//             }
//         }
//         return ans;
        
//     }
// };

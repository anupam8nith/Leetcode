class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; ++i) {
            vector<int> cur2;
            
            for (int x : cur) 
            {
                int y = x % 10;
                
                if (y + k < 10)
                    cur2.push_back(x * 10 + y + k);
                
                if (k > 0 && y - k >= 0)
                    cur2.push_back(x * 10 + y - k);
            }
            cur = cur2;
            cur2.clear();
        }
        return cur;
    }
};




// try to improve the code using the symmetry 

// TLE code but working o(n*n) solution

// class Solution 
// {
// public:
//     vector<int> numsSameConsecDiff(int n, int k)
//     {
//         vector<int> ans;
//         int min  = 1;
//         int maxm = 9;
        
//         for(int i=0;i<n-1;i++)
//         {
//             min*=10;
//             maxm = maxm*10 +9;
//         }
//         for(int i = min;i<=maxm;i++)
//         {
//             string s = to_string(i);
            
//             for(int j=1;j<s.size();j++)
//             {
//                 if(abs(s[j]-s[j-1])!=k)
//                     break;
                
//                 if(j==s.size()-1)
//                     ans.push_back(i);
                    
//             }
//         }
        
//         return ans;
//     }
// };
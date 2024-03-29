// Time Complexity: O(2 ^ n)
// Space Complexity: O(2 ^ n)
class Solution {
public:
    // The idea is to use BFS to try appending 0 - 9 to each number 
    // starting from a single digit 1 - 9 until the number has n digits
    vector<int> numsSameConsecDiff(int n, int k) {
        // push all numbers with single digit to a deque
        deque<int> q{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        // do the following logic n - 1 times
        while (--n > 0) {
            // get the queue size
            int sz = q.size();
            // for each item in the current queue,
            // do the following logic
            for (int i = 0; i < sz; i++) {
                // get the first number from the queue
                int p = q.front();
                // pop it
                q.pop_front();
                // we can potentially add 0 to 9 to the current number p
                for (int j = 0; j < 10; j++) {
                    // we use p % 10 to get the last digit of p
                    // then get the difference with j
                    // since (p % 10) - j can be negative and positive
                    // we use abs to cover both case
                  if (abs((p % 10) - j) == k) {
                    // if the difference is equal to k
                    // we can include digit j 
                    // so multiply the current number by 10 and add j
                    q.push_back(p * 10 + j);
                  }
                }
          }
        }
        // return all numbers in deque, return them in vector<int>
        return vector<int>{q.begin(), q.end()};
    }
};

// class Solution {
// public:
    
//     vector<int> numsSameConsecDiff(int n, int k) 
//     {
        
//         vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//         for (int i = 2; i <= n; ++i) {
//             vector<int> cur2;
            
//             for (int x : cur) 
//             {
//                 int y = x % 10;
                
//                 if (y + k < 10)
//                     cur2.push_back(x * 10 + y + k);
                
//                 if (k > 0 && y - k >= 0)
//                     cur2.push_back(x * 10 + y - k);
//             }
//             cur = cur2;
//             cur2.clear();
//         }
//         return cur;
//     }
// };




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
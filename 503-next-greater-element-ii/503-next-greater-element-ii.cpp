class Solution {
public:
     vector<int> nextGreaterElements(vector<int>& nums) 
     {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s; // index stack
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n]; 
            while (!s.empty() && nums[s.top()] < num) {
                next[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }   
        return next;
    }

};





// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> l(n,-1),r(n,n);
//         stack<int> st;
//         for(int i=n-1;i>=0;i--){
//             while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
//             if(!st.empty()){
//                 r[i]=st.top();
//             }
//             st.push(i);
//         }
//         // for(int i=0;i<n;i++) cout<<r[i]<<" ";
//         // cout<<"\n";
//         vector<int> ans(n,-1);
//         // while(!st.empty()) st.pop();
//         vector<int> d;
//         for(int i=0;i<n;i++){
//             if(d.empty() || d.back()<nums[i]) d.push_back(nums[i]);
//             if(r[i]!=n) ans[i]=nums[r[i]];
//             else{
//                 int pos=upper_bound(d.begin(),d.end(),nums[i])-d.begin();
//                 if(pos<d.size()) ans[i]=d[pos];
//             }
//         }
//         return ans;
//     }
// };

// My solution 946ms

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) 
//     {
//         int n=nums.size();
//         vector<int> ans(n);
//         if(n==1)
//         {
//             ans[0]=-1;
//             return ans;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//                 if(nums[(i+1)%n]>nums[i])
//                 {
//                     ans[i]=nums[(i+1)%n];
//                 }
//                 else
//                 {
//                     int j=i+1,count=0;
                    
//                     while(count<n-1)
//                     {
//                         if(nums[(j+1)%n]>nums[i])
//                         {
//                             ans[i]=nums[(j+1)%n];
//                             break;
//                         }  
//                         j++;
//                         count++;
//                     }
//                     if(count==n-1)
//                         ans[i]=-1;
                    
//                 }
            
//         }
        
//         return ans;
//     }
// };


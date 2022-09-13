class Solution {
public:
    int nextGreaterElement(int n) 
    {
        if(n==INT_MAX)
            return -1;
        
        string s= to_string(n);

        if(next_permutation(s.begin(),s.end())!=NULL && stol(s)<=INT_MAX)
        {
            return stol(s);
        }
        else return -1;
        
    }
};
//
// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         string s = to_string(n);
//         if (s.length() == 1) {
//             return -1;
//         }
       
//         int i = s.length() - 2; // 21 -> i = 0; 59876 -> i = 3
//         for (; i >= 0 && s[i] >= s[i + 1]; i--) { }
//         if (i == -1) {  
//             return -1;
//         }
//         reverse(s.begin() + i + 1, s.end());
//         for (int j = i + 1; j < s.length(); j++) {
//             if (s[j] > s[i]) {
//                 swap(s[i], s[j]);
//                 break;
//             }
//         }
//         long next = stol(s);
//         return next == n || next > INT_MAX ? -1 : next;
//     }
// };

//

// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         string s = to_string(n);
//         int i=s.size()-2;
//         for(;i>=0;i--){
//             if(s[i]<s[i+1]) break;
//         }
//         if(i<0) return -1;
//         for(int j=s.size()-1;j>i;j--){
//             if(s[j]>s[i]){
//                 swap(s[i],s[j]);
//                 break;
//         }
//         }
//         reverse(s.begin()+i+1,s.end());
//         long res=stol(s);
//         return res>INT_MAX?-1:res;
//     }
// };

//

// class Solution {
// public:  
//     int nextGreaterElement(int n) {
//         string s = to_string(n);
//         int i = s.size() - 2;
//         // start from right
//         // find the number x which is smaller than the next one
//         for(; i >= 0; i--){
//             if(s[i] < s[i + 1]) break;
//         }
//         // if it doesn't exist, return -1
//         if(i < 0) return -1;
//         // find the number x' in the right side which is just greater than x
//         for(int j = s.size() - 1; j > i; j--){
//             if(s[j] > s[i]){
//                 swap(s[i], s[j]);
//                 break;
//             }
//         }
//         // reverse right side to make it in increasing order
//         reverse(s.begin() + i + 1, s.end());
//         long res = stol(s);
//         return res > INT_MAX? -1 : res; // check if the result is longer than 32-bits
        
//     }
// };



//solutions to understand

// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         vector<int>data;
//         while(n != 0){
//             int k = n%10;
//             data.push_back(k);
//             n = n/10;
//         }
//         reverse(data.begin(),data.end());
//          n = data.size();
//         int idx1 = -1,idx2 = -1;
//         for(int i = n-2;i >= 0;i--){
//             if(data[i+1] > data[i]){
//                 idx1 = i;
//                 break;
//             }
//         }
//         if(idx1 == -1){
//             return idx1;
//         }
//         for(int i = n-1;i > idx1;i--){
//             if(data[i] > data[idx1]){
//                 idx2 = i;break;
//             }
//         }
//         if(idx2 == -1){
//             return -1;
//         }
//         swap(data[idx1],data[idx2]);
//         reverse(data.begin()+idx1+1,data.end());
//        long long int ans = 0;
//         long long int a = 0;
//         for(int i = 0;i < n;i++){
//             a += data[i];
//             ans = a;
//             a = a*10;
//         }
//         if(ans > INT_MAX){
//             return -1;
//         }
//         return ans;
//     }
// };
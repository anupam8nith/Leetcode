class Solution {
public:
    int firstUniqChar(string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char,int> um;
        
       for(long int i=0;i<s.size();i++) um[s[i]]++;
        
       for(long int i=0;i<s.size();i++)
       {
           if(um[s[i]]==1)
               return i;
       }
        
        return -1;
        
    }
};

//51 ms 

// class Solution {
// public:
//     int firstUniqChar(string s) 
//     {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         unordered_map<char,int> um1,um2;
        
//         for(int i=s.length()-1;i>=0;i--)
//         {
//             um1[s[i]]++; //freq
//             um2[s[i]] = i; //index;
//         }
        
//         for(auto ch: um1)
//         {
//             if(ch.second==1)
//              return um2[ch.first];
//         }
        
//         return -1;
        
//     }
// };
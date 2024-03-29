class Solution {
public:
    bool isAnagram(string s, string t) 
{
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
        vector<int> freq(26,0); //only freq
        
        for(auto ch: s) freq[ch-'a']++;
        for(auto ch: t) freq[ch-'a']--;
        
        for(auto f: freq)
            if(f) return 0; //if f!=0 return false
        
      
        return 1;
    
}
};


//18ms 

// class Solution {
// public:
//     bool isAnagram(string s, string t) 
//     {
//         // ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
        
//         int p= s.size();
//         int q= t.size();
        
//         if(p!=q)
//             return false;
        
//         unordered_map<char,int> m;
        
//         for(int i=0;i<p;i++) m[s[i]]++; //frequency of s
        
//         for(int i=0;i<q;i++) m[t[i]]--;
        
//         for(int i=0;i<q;i++) 
//         {
//             if(m[t[i]]!=0)
//                 return false;
//         }
            
//         return true;
//     }
// };
class Solution {
public:
    // kind of like a dp map, which stores if the calculated string is a palindrome or not
    unordered_map<string, bool> check;
    // function to check is string is palindrome
    bool palin(string &s)
    {
        if(check.find(s) != check.end())
            return check[s];
        
        if(s.length() == 0){
            check[s] = true;
            return true;
        }
        int n = s.length();
        for(int i = 0; i <= n/2; i++)
        {
            if(s[i] != s[(n - i) - 1])
            {
                check[s] = false;
                return false;
            }
        }
        check[s] = true;
        return true;    
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        //storing the reverse of every string in unordered map
        for(int i = 0 ; i < words.size(); i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            mp[str] = i;
        }
        // if any string is "" means palindrome strings and "" string will form a pair
        if(mp.find("") != mp.end())
        {
            for(int i = 0; i < words.size(); i++)
            {
                if(i == mp[""])
                    continue;
                if(palin(words[i]))
                {
                    ans.push_back({i, mp[""]});
                }
            }
        }
        // checking in the main vector
        for(int i = 0 ; i < words.size(); i++)
        {
            // storing the ith word in right and left as ""
            string right = words[i];
            string left = "";
            // we will delete letters from right and insert each letter, character by character in left and check if it is present in the map or not. If present, it should not have the same index as i.
            
            // if all these conditions pass, then we can push the indexes in our answer vector
            for(int j = 0 ; j < words[i].length(); j++)
            {
                left.push_back(words[i][j]);
                right.erase(right.begin() + 0);
                if(mp.find(left) != mp.end() and palin(right) and mp[left] != i)
                    ans.push_back({i, mp[left]});
                
                if(mp.find(right) != mp.end() and palin(left) and mp[right] != i)
                    ans.push_back({mp[right], i});
            }
        }
        // return ans;
        return ans;
    }
};

//best solution

// class Solution {
    
// public:
// public:
//     bool isPalin(string &s, int i, int j) {
//         while(i < j)
//         {
//             if(s[i++] != s[j--]) return false;
//         }
//     return true;
// }
// vector<vector<int>> palindromePairs(vector<string> &words) {
//     vector<vector<int>> ans;
//     if (words.empty()) return ans;
//     unordered_map<string, int> mp;
//     set<int> st;
//     for (int i = 0; i < words.size(); i++) {
//         mp[words[i]] = i;
//         st.insert(words[i].size());
//     }
//     for (int i = 0; i < words.size(); ++i) {
//         string cpy(words[i]);
//         reverse(cpy.begin(),cpy.end());
//         int ln = cpy.size();
//         if(mp.find(cpy) != mp.end() && mp[cpy] != i)
//             ans.push_back({i,mp[cpy]});
//         for(auto l : st){
//             if(l >= ln) break;
//             if(isPalin(words[i],0,ln-l-1)){
//                 string p = cpy.substr(0,l);
//                 if(mp.find(p) != mp.end())
//                     ans.push_back({mp[p],i});
//             }
//             if(isPalin(words[i],l,ln-1)){
//                 string  p = cpy.substr(ln-l);
//                 if(mp.find(p) != mp.end())
//                     ans.push_back({i,mp[p]});
//             }
//         }
//     }
//     return ans;
// }
// };


//O(n^3)


// class Solution {
// public:
//     bool canbepdrome(string &a, string &b)
//     {
//         string temp = a;
//         temp += b;
//         // cout<<temp<<endl;
        
//         int l=0, r= temp.size()-1;
        
//         while(l<r)
//         {
//             if(temp[l]!=temp[r])
//                 return false;
//             l++;
//             r--;
//         }
        
//         return true;
//     }
    
//     vector<vector<int>> palindromePairs(vector<string>& words) 
//     {
//         vector<vector<int>> ans;
        
//         int n = words.size();
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
                
//                 if(j!=i)
//                 {
//                     bool include = canbepdrome(words[i],words[j]);
//                     // cout<<words[i]<<" "<<words[j]<<endl;
//                     vector<int> idx;
//                     if(include)
//                     {
//                         idx.push_back(i);
//                         idx.push_back(j);
//                         // cout<<i<< " "<<j<<endl;
//                         ans.push_back(idx);
//                     }
//                 }
//             }
//         }
        
//         return ans;
        
//     }
// };
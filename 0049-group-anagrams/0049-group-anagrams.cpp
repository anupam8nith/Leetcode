class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map< string, vector<string> > um;
        
        for(auto s: strs)
        {
            string temp = s;
            
            sort(temp.begin(),temp.end());
            
            um[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto u : um)
            ans.push_back(u.second);
        
        return ans;
    }
};

//Incomplete code (needs debugging)

// class Solution {
// public:
    
//     bool anagrams(string a , string b)
//     {
//         if(a.size()!=b.size())
//             return false;
//         else
//         {
//             unordered_map<int,int> um;
            
//             for(auto ch: a)
//                 um[ch]++;
            
//             for(auto ch: b)
//                 um[ch]--;
            
//             if(um.empty())
//                 return true;
//         }
        
//         return false;
//     }
    
// //     bool comp(string a, string b)
// //     {
// //         return a.size() > b.size();
// //     }
    
    
//     vector<vector<string>> groupAnagrams(vector<string>& words) 
//     {
//         vector<vector<string>> ans;
        
//         int n = words.size();
        
//         sort(words.begin(),words.end(), [](const string &a, string &b)
//         {
//          return a.size()<b.size();
//         });
        
//         // //
//         // for(auto s: words)
//         //     cout<<s<<endl;
        
        
//         for(int i=0;i<n;i++)
//         {
//             vector<string> group;
            
//             //
//             cout<<"i:"<<i<<endl;
            
//             for(int j=i+1;j<n;j++)
//             {
//                 cout<<words[i].size()<<" "<<words[j].size()<<endl;
//                 if(words[i].size()!=words[j].size())
//                 {
//                     cout<<"break"<<j<<endl;
//                     break;
//                 }
//                 else
//                 {   
//                     if(anagrams(words[i],words[j]))
//                     {
//                         group.push_back(words[j]);
//                         cout<<j<<endl;
//                     }
//                 }
//             }
            
//             if(!group.empty())
//             {
//                 group.push_back(words[i]);
//                 ans.push_back(group);
//             }
           
            
//         }
        
//         return ans;
//     }
// };
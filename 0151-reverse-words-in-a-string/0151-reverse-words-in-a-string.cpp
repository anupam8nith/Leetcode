// class Solution {
// public:
//     string reverseWords(string s) 
//     {
//         int n = size(s);
        
//         if(n==1)
//         return s;
        
//         vector<string> ans;
        
//         int j=0;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]!=' ')
//             {
//                 j=i;
//                 string temp="";
                
//                 while(s[j]!=' ' && j<n)
//                 {
//                     temp+=s[j];
//                     j++;
//                 }
                
//                 ans.push_back(temp);
//                 i=j;
//                 // cout<<temp<<endl;
//             }
//             else
//                 continue;
//         }
        
//         reverse(ans.begin(),ans.end());
//         string str ="";
        
//         for(int i=0;i<ans.size();i++)
//         {
//             str += ans[i];
            
//             if(i!=ans.size()-1)
//             str+=" ";
//         }
        
        
//         return str;
        
        
//     }
// };


class Solution {
public:
    // REVERSE THE WHOLE STRING, THEN REVERSE THE INDIVIDUAL WORDS
    
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        //index to the string s, used for inplace change
        int storeIndex = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                
                //to add space after every word, except before the first word
                if(storeIndex != 0) s[storeIndex++] = ' ';
                
                int j = i;
                
                while(j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                //after this loop i -> start of word, j/storeindex -> at the space after the word
                
                reverse(s.begin() + storeIndex - (j-i), s.begin() + storeIndex);
                
                //Move i to the j(that is the blank space after the word)
                i = j; 
            }
        }
        
        //storeindex now points to the last word in the string
        //removes trailing spaces
        s.erase(s.begin() + storeIndex, s.end());
        
        return s;
    }
};

/* INSIDE FOR LOOP
put a blank space in front of the word if this word is not the first word

copy the word to the position starts with storeIndex

reverse the word

update the possible start of next word
*/
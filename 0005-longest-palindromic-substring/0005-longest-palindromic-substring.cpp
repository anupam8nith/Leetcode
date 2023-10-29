class Solution {
public:
   bool palindrome(string s){
       int left=0,right=s.length()-1;
       while(left<right){
           if(s[left]!=s[right]) return 0;
           left++;
           right--;
       }
       return 1;
   }
    string longestPalindrome(string s) 
    {
        if(s.length()==1) return s;
        
        int max=0,flag=0;
        string ans;
        
        map<char,vector<int>> m;
        
        for(int i=0;i<s.length();i++) 
        { m[s[i]].push_back(i); if(m[s[i]].size()>1) flag=1;}
        
        if(flag==0) 
        {
            string s1;
            s1+=s[0];
            return s1;
        }
        for(auto i:m)
        {
            for(int j=0;j<i.second.size()-1;j++)
            {
                for(int k=j;k<i.second.size();k++)
                {
                    if(palindrome(s.substr(i.second[j],i.second[k]-i.second[j]+1)) and i.second[k]-i.second[j]+1>max) 
                    {ans=s.substr(i.second[j],i.second[k]-i.second[j]+1); max=i.second[k]-i.second[j]+1;}
                }
            }
        }
        return ans;
    }
};
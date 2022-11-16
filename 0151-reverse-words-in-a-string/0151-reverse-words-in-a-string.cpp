class Solution {
public:
    string reverseWords(string s) 
    {
        int n = size(s);
        
        if(n==1)
        return s;
        
        vector<string> ans;
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                j=i;
                string temp="";
                
                while(s[j]!=' ' && j<n)
                {
                    temp+=s[j];
                    j++;
                }
                
                ans.push_back(temp);
                i=j;
                // cout<<temp<<endl;
            }
            else
                continue;
        }
        
        reverse(ans.begin(),ans.end());
        string str ="";
        
        for(int i=0;i<ans.size();i++)
        {
            str += ans[i];
            
            if(i!=ans.size()-1)
            str+=" ";
        }
        
        
        return str;
        
        
    }
};
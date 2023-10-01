class Solution 
{
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
            int start=i; string temp="";
                
            while(s[start]!=' ' && start<n) temp+=s[start++];
            
                // cout<<temp<<endl;
                
            reverse(temp.begin(),temp.end());
                
            for(int j=i;j<start;j++)s[j]=temp[j-i];
            i = start;
                
            }
        }
        return s;
    }
};
class Solution {
public:
    string removeDuplicates(string s) 
    {
        int n = s.size();
        
        if(n==1)
        return s;
        
        string ans="";
        
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty()==1)
            {
                st.push(s[i]);
                continue;
            }
            
            if(st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        
        while(!st.empty())
        {
               ans+=st.top();
               st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
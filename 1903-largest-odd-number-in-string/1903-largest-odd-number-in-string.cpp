class Solution {
public:
    string largestOddNumber(string num) 
    {
        int n = num.size(); string ans="";
        
        for(int i=n-1;i>=0;i--)
            if(((num[i]-'0'))&1){ans=max(ans,num.substr(0,i+1));break;}
        
        return ans;
        
    }
};
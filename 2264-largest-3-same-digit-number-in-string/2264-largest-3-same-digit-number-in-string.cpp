class Solution {
public:
    string largestGoodInteger(string num) 
    {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        string ans="";
        
        for(int i=1;i<num.size()-1;i++) if(num[i]==num[i-1] && num[i]==num[i+1])
        ans = max(ans,num.substr(i-1,3));
        
        return ans;
    }
};
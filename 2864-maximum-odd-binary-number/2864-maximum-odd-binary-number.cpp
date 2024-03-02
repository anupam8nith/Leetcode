class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int n =s.size(), count=0;
        
        for(auto it: s)if(it=='1')count++;
        
        string ans ="";
        
        for(int i=1;i<=count-1;i++)ans+="1";
        for(int i=1;i<=n-count;i++)ans+="0";
        ans+="1";
        
        return ans;
        
    }
};
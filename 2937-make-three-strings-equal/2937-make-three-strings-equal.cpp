class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) 
    {
        if(s1[0]!=s2[0] || s1[0]!=s3[0]) return -1;
        if(s1==s2 && s1==s3) return 0;
        
        int n1=s1.size(),n2 = s2.size(), n3= s3.size();
        
        int i=0;
        while(s1[i]==s2[i] && s2[i]==s3[i])i++;
        
        return n1+n2+n3-3*(i);
    }
};
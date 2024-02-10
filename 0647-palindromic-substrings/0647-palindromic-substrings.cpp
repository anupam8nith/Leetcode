class Solution {
public:

    int expand(string s,int i,int j)
    {
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {

        int totalcount=0;
 

        for(int i=0;i<s.length();i++)
        {
            int j=i;
            int oddans=expand(s,i,j);

            j=i+1;
            int evenans=expand(s,i,j);
            totalcount=totalcount+oddans+evenans;
        }
        return totalcount;
    }
};
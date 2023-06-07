class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        bitset<32> b1(a),b2(b),b3(c); int ans=0;
        
        for(int i=0;i<32;i++)
        {
             if ((b1[i] | b2[i]) == b3[i])continue;
            else
            {
                if(b1[i]==1 && b2[i]==1 && b3[i]==0) ans+=2;
                else ans++;
            }
        }
        
        return ans;
        
        
    }
};
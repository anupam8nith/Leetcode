class Solution {
public:
    
    int printncr(int n, int r)
    {
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        long long p = 1, k = 1;

        if (n - r < r)
            r = n - r;

        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;

                long long m = __gcd(p, k);

                p /= m;
                k /= m;

                n--;
                r--;
            }
        }
        else
            p = 1;

        return p;
    }
    
    
    vector<int> getRow(int n) 
    {
        vector<int> ans;
        
        for(int i=0;i<=n;i++)
        {
            ans.push_back((int) printncr(n,i));
        }
        
        return ans;
    }
};
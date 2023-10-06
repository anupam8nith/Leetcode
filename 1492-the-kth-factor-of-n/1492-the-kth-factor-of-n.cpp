class Solution {
public:
    int kthFactor(int n, int k) 
    {
        vector<int> ans;ans.push_back(1);int count=1;
        
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
                {
                    ans.push_back(i);
                    count++;
                    if(count==k) return i;
                }
        if(count==0 && n>2) return -1;
        if(k>2*count) return -1;
        
        int sz = ans.size();
        
        for(int i= sz-1;i>=0;i--)if(ans[i]*ans[i]!=n)ans.push_back(n/ans[i]);
        if(ans.size()<k) return -1;
        
        return ans[k-1];
    }
};
class Solution {
public:
    
    vector<long long> v;
    
    void fib(vector<long long> &v)
    {
        v[0]=1;
        v[1]=1;
        
        int i=2;
        while(i< 45)
        {
          v[i] = v[i-1] + v[i-2];
            
          i++;
        }
    }
    
    
    int findMinFibonacciNumbers(int k) 
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        //find the nearest fib number
        v.resize(45,0);
        
        if(v[44]==0)
        fib(v);
        
        // for(auto x: v)
        //     cout<<x<<" ";
        
        int ans=0;
        long long nearest=0;
        
        while(k>0)
        {
           
            
            if(binary_search(v.begin(),v.end(),k)==0)
                nearest = *(lower_bound(v.begin(),v.end(),k)-1);
            else
                nearest = *(lower_bound(v.begin(),v.end(),k));
            
                // cout<<nearest<<endl;
            
            k-=nearest;
            ans++;
        }
        
        return ans;
    }
};
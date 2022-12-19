class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = size(temperatures);
        
        vector<int> ans(n,0);
        
        //implementing monotonic stack
        
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            
            while(s.empty()==0 && temperatures[s.top()]<temperatures[i])
            {
                ans[s.top()] = (i - s.top());
                
                s.pop();
            }
            
            s.push(i);
        }
        
        while(s.empty()==false)
        {
            ans[s.top()]=0;
            s.pop();
        }
        
        return ans;
        
    }
};

//best solution

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int>answer(n,0);
//         int maxTemp = 0;
//         for(int currDay=n-1;currDay>=0;currDay--){
//             int currTemp = temperatures[currDay];
//             if(currTemp>=maxTemp){
//                 maxTemp=currTemp;
//                 continue;
//             }
//             int days = 1;
//             while(currTemp>=temperatures[currDay+days])
//                 days+=answer[currDay+days];
//             answer[currDay]=days;
//         }
//         return answer;
//     }
// };
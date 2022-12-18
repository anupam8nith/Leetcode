class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int,int> um;
        
       for(auto t: tasks)
       um[t]++;
        
        // stored in sorted order
        int ans=0;
        
        for(auto x: um)
        {
            if(x.second==1)
            return -1;
            else
            {
                while(x.second>0)
                {
                    if(x.second>=3)
                    {
                        ans++;
                        x.second-=3;
                    }
                    else if(x.second<=2)
                    {
                        ans++;
                        
                        if(x.second>=2)
                            x.second-=2;
                        else
                             x.second-=1;
                    }
                }
            }
            
        }
        return ans;
    }
};

//best solution:

// class Solution {
// public:
//     int minimumRounds(vector<int>& tasks) {
//         int n = tasks.size();
        
//         // sort(tasks.begin(), tasks.end());
//         // for(int i= 0 ; i<n; i++){
//         //     cout<<tasks[i]<<endl;
//         // }
//         unordered_map<int,int>mp;
        
       
//         int i=0;
//         int count = 0;
//        for(auto num:tasks){
//            mp[num]++;
//        }
        
//         for(auto val : mp){
//             int k = val.second%3;
//             if(val.second==1){
//                 return -1;
//             }
//           count+= val.second/3;
//             if(k==1 || k==2){
//                 count+=1;
//             }
            
          
//         }
//         return count;
//     }
// };
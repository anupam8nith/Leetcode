class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        cout.tie(0);
        
        int n = arr.size();
        if(k>=n-1) return *max_element(arr.begin(),arr.end());
        
        queue<int>q;
        
        for(auto it: arr)q.push(it);
        
        
        int wcount=0, winner=q.front();q.pop();
        while(wcount!=k)
        {
           int ele2=q.front();q.pop();
            
            if(winner>ele2){q.push(ele2);wcount++;}
            else{wcount=0;q.push(winner);winner = ele2;wcount++;}
            
            if(wcount==k) return winner;
        }
        
        return winner;
    }
};
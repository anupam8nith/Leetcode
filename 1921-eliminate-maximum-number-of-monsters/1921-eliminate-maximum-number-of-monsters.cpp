class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        int n = dist.size();
        vector<double> reaches;

        for (int i = 0; i < n; i++) reaches.push_back((double) dist[i] / (double) speed[i]);

        sort(reaches.begin(), reaches.end());
    
        for(int i=0;i<n;i++)
        {
            if(reaches[i]<=i) return i;
        }
       
        return n;
    }
};

class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        int n = words.size();
        vector<int> freq(26,0);
        
        for(int i=0;i<n;i++)
           for(int j=0;j<words[i].size();j++)freq[words[i][j]-'a']++;
       
        for(auto& it: freq)if(it%n!=0) return false;
        
        return true;
    }
};
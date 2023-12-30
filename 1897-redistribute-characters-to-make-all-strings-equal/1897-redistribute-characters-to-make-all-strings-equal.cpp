class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        int n = words.size();
        vector<int> freq(26,0);
        
        for(string& str: words)
           for(char& ch: str)freq[ch-'a']++;
       
        for(auto& it: freq)if(it%n!=0) return false;
        
        return true;
    }
};
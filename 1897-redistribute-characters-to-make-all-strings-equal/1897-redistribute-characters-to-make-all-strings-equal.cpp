class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        int n = words.size();
        unordered_map<char,int> um;
        
        for(string& str: words)
           for(char& ch: str)um[ch]++;
       
        for(auto& var: um)if(var.second%n!=0) return false;
        
        return true;
    }
};
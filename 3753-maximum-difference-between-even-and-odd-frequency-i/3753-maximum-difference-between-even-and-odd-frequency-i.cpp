class Solution {
public:
    int maxDifference(string s) {
        int a1=0, a2=100;

        unordered_map<char,int> um;

        for(char ch: s)um[ch]++;

        for(auto it: um)
        {
            if(it.second&1)
                a1=max(a1,it.second);
            else
                a2=min(a2,it.second);
        }

        return a1-a2;
        
    }
};
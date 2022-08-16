class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        reverse(s.begin(),s.end());
        return;
    }
};
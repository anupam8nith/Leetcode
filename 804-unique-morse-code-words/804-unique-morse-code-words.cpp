class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto w : words) {
            string code;
            for (auto c : w) code += d[c - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};
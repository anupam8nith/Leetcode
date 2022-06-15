class Solution {
   public:
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> um;
        int res = 1;
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        
        for (string word : words) {
            um[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (um.find(prev) != um.end()) {
                    um[word] = um[prev] + 1;
                    res = max(res, um[word]);
                }
            }
        }
        return res;
    }
};
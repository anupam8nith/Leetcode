class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans(n);

        int depth = 0;
        for (int i = 0; i < n; i++) {
            char ch = seq[i];
            if (ch == '(') {
                // If the current depth is even, assign it to subsequence A
                ans[i] = (depth++ % 2 == 0) ? 0 : 1;
            } else {
                // ')' encountered, decrease depth
                ans[i] = (depth-- % 2 == 0) ? 1 : 0;
            }
        }
        
        return ans;
    }
};

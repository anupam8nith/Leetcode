class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> s(n);

        // Initialize vector
        iota(s.begin(), s.end(), 1);

        int idx = 0;

        while (s.size() > 1) {
            idx = (idx + k - 1) % s.size();
            s.erase(s.begin() + idx);
        }

        return s.front();
    }
};

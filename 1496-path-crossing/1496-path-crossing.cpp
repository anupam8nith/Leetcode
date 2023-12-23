class Solution {
public:
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
    
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, pairHash> loc = {{0, 0}}; // Use custom hash function
        pair<int, int> position = {0, 0};

        for (char ch : path) {
            if (ch == 'N') position.second++;
            else if (ch == 'S') position.second--;
            else if (ch == 'E') position.first++;
            else if (ch == 'W') position.first--;

            if (!loc.insert(position).second) return true;
        }

        return false;
    }
};

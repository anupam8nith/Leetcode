class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> loc = {{0, 0}};  // Use set for efficient lookups
        pair<int, int> position = {0, 0};

        for (char ch : path) {
            position = { position.first + (ch == 'E') - (ch == 'W'),
                         position.second + (ch == 'N') - (ch == 'S') };
            if (!loc.insert(position).second) return true;  // Check for insertion success
        }

        return false;
    }
};

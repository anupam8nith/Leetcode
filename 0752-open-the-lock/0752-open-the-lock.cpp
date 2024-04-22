class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1; // If the initial state is in deadSet
        
        queue<string> q;
        set<string> visited;
        q.push("0000");
        visited.insert("0000");

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();

                if (current == target) return level;

                // Generate neighboring combinations
                for (int j = 0; j < 4; ++j) {
                    string up = current;
                    string down = current;
                    up[j] = (up[j] == '9') ? '0' : up[j] + 1;
                    down[j] = (down[j] == '0') ? '9' : down[j] - 1;

                    if (!visited.count(up) && !deadSet.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!visited.count(down) && !deadSet.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            level++;
        }
        
        return -1; // Target cannot be reached
    }
};
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> loc;
        pair<int, int> position = {0, 0};
        loc.insert(to_string(position.first) + "," + to_string(position.second));
        
        for (char ch : path) {
            if (ch == 'N') position.second++;
            else if (ch == 'S') position.second--;
            else if (ch == 'E') position.first++;
            else if (ch == 'W') position.first--;

            string pos_str = to_string(position.first) + "," + to_string(position.second);
            
            if (loc.count(pos_str) == 0) {
                loc.insert(pos_str);
            } else {
                return true;
            }
        }
        return false;
    }
};

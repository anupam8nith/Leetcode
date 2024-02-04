class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> tmap, smap;

        for (char ch : t) {
            tmap[ch]++;
        }

        int i = 0, j = 0, minStart = 0, minLen = INT_MAX;

        while (j < m) {
            smap[s[j]]++;

            while (i <= j && containsAll(smap, tmap)) {
                if (j - i + 1 < minLen) {
                    minStart = i;
                    minLen = j - i + 1;
                }

                smap[s[i]]--;
                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }

private:
    bool containsAll(const unordered_map<char, int>& smap, const unordered_map<char, int>& tmap) {
        for (const auto& p : tmap) {
            if (smap.count(p.first) == 0 || smap.at(p.first) < p.second) {
                return false;
            }
        }
        return true;
    }
};

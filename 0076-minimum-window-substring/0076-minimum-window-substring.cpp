class Solution {
public:
    string minWindow(string s, string t) 
    {
        int m = s.size(), n = t.size();

        if (m < n) return "";

        unordered_map<char, int> tmap, smap;

        for (char ch : t) tmap[ch]++;

        int i = 0, j = 0, minStart = 0, minLen = INT_MAX;

        int counter = n;

        while (j < m) 
        {
            char ch = s[j];
            smap[ch]++;

            if (tmap.count(ch) && smap[ch] <= tmap[ch])
                counter--;

            while (counter == 0) 
            {
                if (j - i + 1 < minLen) 
                {
                    minStart = i;
                    minLen = j - i + 1;
                }

                char ch = s[i];
                smap[ch]--;

                if (tmap.count(ch) && smap[ch] < tmap[ch])
                    counter++;

                i++;
            }
            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

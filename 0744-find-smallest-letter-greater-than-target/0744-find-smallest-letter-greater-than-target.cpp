class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        sort(letters.begin(), letters.end());

        auto it = upper_bound(letters.begin(), letters.end(), target);

        return it == letters.end() ? letters[0] : *it;
    }
};

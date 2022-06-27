class Solution {
public:
    int minPartitions(string n) 
    {
        return *max_element(begin(n), end(n)) - '0'; //Just return max digit
    }
};
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end()); //sort the array.
        
        int d = arr[1]-arr[0]; //difference of A.P = d
        
        for(int i=0;i<(arr.size()-1);i++) if((arr[i+1]-arr[i])!=d) return false; // if d != arr[i+1] - arr[i] return false
        
        return true;
    }
};
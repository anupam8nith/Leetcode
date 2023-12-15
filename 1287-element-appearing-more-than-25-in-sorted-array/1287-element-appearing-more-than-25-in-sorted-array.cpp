class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
         int n = arr.size() / 4;
        int res = arr[0], count = 1;

        if(arr.size() == 1)
            return arr[0];

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == res)
                count++;
            else
                count = 1;

            if(count > n)
                return arr[i];

            res = arr[i];
        }
        return res;
    }
};
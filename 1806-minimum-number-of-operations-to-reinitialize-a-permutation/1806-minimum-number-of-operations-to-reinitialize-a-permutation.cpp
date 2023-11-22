class Solution {
public:
    int reinitializePermutation(int n) 
    {
        int ans = 0;
        vector<int> perm(n), arr(n);

        for (int i = 0; i < n; ++i) perm[i] = i;

        do
        {
            ++ans;
            for (int i = 0; i < n; ++i) 
            {
                if (i & 1) arr[i] = perm[n / 2 + (i - 1) / 2];
                else arr[i] = perm[i / 2];
            }
            perm = arr;
        } while (!isIdentity(arr, n));

        return ans;
    }

    bool isIdentity(vector<int>& arr, int n) 
    {
        
        for (int i = 0; i < n; ++i) if (arr[i] != i) return false;
        
        return true;
    }
};

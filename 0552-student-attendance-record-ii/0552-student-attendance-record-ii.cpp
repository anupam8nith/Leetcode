class Solution {
public:
    int checkRecord(int n) 
    {
        if (n <= 0) return 0; // Base case for invalid input

        int m = 1e9+7;
        vector<int> A(n), P(n), L(n); // Use vectors for automatic memory management

        P[0] = 1;
        L[0] = 1;
        A[0] = 1;

        if (n > 1) 
        {
            L[1] = 3;
            A[1] = 2;
        }

        if (n > 2) A[2] = 4;

        for (int i = 1; i < n; i++) 
        {
            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

            if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;

            if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }

        return ((A[n - 1] + P[n - 1]) % m + L[n - 1]) % m; 
    }
};

class Solution 
{
public:
    // Declare a global array to store computed values for dynamic programming
    int dp[38];

    // Recursive function to calculate tribonacci sequence
    int find(int n) 
    {
        // Base cases: if n is out of range, return 0
        if (n < 0 || n > 37)
            return 0;
        
        // If the value for n is already computed, return it
        if (dp[n] != 0)
            return dp[n];

        // Calculate the value for n using dynamic programming
        if (n >= 3)
            dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];

        // Recursively calculate the value for n-1, n-2, and n-3
        return dp[n] = find(n - 1) + find(n - 2) + find(n - 3);
    }

    // Function to find the tribonacci number for a given input n
    int tribonacci(int n) 
    {
        // Initialize the first two values in the dp array
        dp[1] = 1;
        dp[2] = 1;

        // If the value for n is already computed, return it
        if (dp[n] != 0)
            return dp[n];

        // Call the recursive function to calculate the tribonacci number for n
        return find(n);
    }
};

class Solution 
{
public:
    
    bool isPrime(int n) 
    {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 3; i <= static_cast<int>(sqrt(n)) + 1; i += 2)
        if (n % i == 0) return false;
    return true;
    }

    bool isPalindrome(string str) 
    {
        int l = 0, r = str.length() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int primePalindrome(int n) 
    {
        while (true) 
        {
            string str = to_string(n);
            if (to_string(n).length() % 2 == 0 && n > 11) 
            {
                n = static_cast<int>(pow(10, ceil(log10(n + 1))));
                continue;
            }
            if (!isPalindrome(str)) 
            {
                n++;continue;
            }
            if (isPrime(n)) return n;
            n++;
        }
        return -1;
    }

};
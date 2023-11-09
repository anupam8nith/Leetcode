class Solution {
public:
    int countHomogenous(string s) 
    {
        long long a = 0;
        int j =0;
        long long r= 0;
        for(int i =0 ; i<s.size() ; i++)
        {
            for(j= i ; j<s.size() ; j++)
            {
                if(s[j]!=s[i]) break;
                r++;
            }
            i =j-1;
            a = a + r*(r+1)/(2);
            r= 0;
        }
        return a%1000000007;
    }
};

// class Solution {
// public:
//     int countHomogenous(string s) 
//     {
//         int left = 0;
//         long long res = 0;
        
//         for (int right = 0; right < s.length(); right++) 
//         {
//             if (s[left] == s[right]) res += right - left + 1;
//             else 
//             {
//                 res += 1;
//                 left = right;
//             }
//         }

//         return (int) (res % (1000000007));        
//     }
// };
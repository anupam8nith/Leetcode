class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //code
        
        long int n = s.size();
        
        for(long int i=0;i<n/2;i++)
            swap(s[i],s[n-1-i]);
        
       return;
    }
};

//code1 18ms using STL

// std::ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         reverse(s.begin(),s.end());
//         return;
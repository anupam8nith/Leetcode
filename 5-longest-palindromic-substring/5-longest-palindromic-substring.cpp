class Solution {
public:
    
  
    string longestPalindrome(string s) 
    {
        int n = s.length();
        
        if(n<2)
            return s;
        
        int maxLength = 1,start=0;
    int low=0, high=0;
        
    for (int i = 0; i < n; i++) 
    {
        low = i - 1;
        high = i + 1;
        
        while ( high < n && s[high] == s[i]) //increment 'high'                                  
            high++;
       
        while ( low >= 0 && s[low] == s[i]) // decrement 'low'                   
            low--;
       
        while (low >= 0 && high < n && s[low] == s[high])
        {
              low--;
            high++;
        }
 
        int length = high - low - 1;
        if (maxLength < length) {
            maxLength = length;
              start=low+1;
        }
    }
     
      
    return s.substr(start,maxLength);;
}
    
};
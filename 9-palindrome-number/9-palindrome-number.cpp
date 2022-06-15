class Solution {
public:
    bool isPalindrome(int x) 
    {
        //we are going to reverse the number and then check whether the reversed number is same as the given               //number x
        
        //Code:
        int flag=0;                 //flag for returning bool at last
        int n=x, temp=0;
        
        long int ans=0;             // long int because int*10 might belong to long int data type
        
        
            
      if(x>0)                       // we will check for reverse of number only when when it is positive.
      {
        while(n!=0)                 //code snippet for reversing the integer and storing in 'ans'.
         {
            temp=n%10;
            ans=ans*10+temp;
            n/=10;
         }   
          
          if(ans==x)                // if x is equal to the reversed number then it is palindrome
              flag=1;
      }
        
        
        if(x==0)                    // zero is a palindrome
        {
            flag=1;
        }
                            
        if(x<0)                     // negative numbers are not palindrome.
        {
            flag=0;
        }
     
        
                                    // return according to the value of flag.
        if(flag==1)
            return true;
        else
            return false;
        
    }
};
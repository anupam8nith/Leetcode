class Solution {
public:
    set<int> s;
    
    bool isHappy(int n) 
    {
       if(n==1)
        return true;
        
        int temp=0;
        while(n!=0)
        {
            temp+=pow(n%10,2);
            n/=10;
        }
        if(s.find(temp)!=s.end())
            return false;
        
        s.insert(temp);
        
        return isHappy(temp);
        
    }
};
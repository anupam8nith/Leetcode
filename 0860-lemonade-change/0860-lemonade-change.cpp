class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int cnt5=0,cnt10=0;
        for(int it: bills)
        {
            if(it==5)++cnt5;
            else if(it==10) {++cnt10;--cnt5;}
            else
            {
                if(cnt10>0 && cnt5>0)
                {--cnt5;--cnt10;}
                else if(cnt10<=0 && cnt5>=3)
                    cnt5-=3;
                else return false;
            }
            
            if(cnt5<0 || cnt10<0) return false;
        }
        
        return (cnt5>=0 && cnt10>=0);
    }
};
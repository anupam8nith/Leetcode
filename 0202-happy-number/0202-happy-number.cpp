class Solution {
public:
    int getNextNum(int n) {
        int nextNum = 0;
        while(n) {
            int d = (n % 10);
            nextNum += d*d;
            n /= 10;
        }
        return nextNum;
    }

    bool isHappy(int n) {
        //Floyd's Cycle Detection Algorithm
        int slow = n;
        int fast = n;
        do {
            slow = getNextNum(slow);
            fast = getNextNum(getNextNum(fast));
            if(fast == 1) return true;
        } while (slow != fast);
        
        return false;
    }
};
// class Solution {
// public:
//     set<int> s;
    
//     bool isHappy(int n) 
//     {
//        if(n==1)
//         return true;
        
//         int temp=0;
//         while(n!=0)
//         {
//             temp+=pow(n%10,2);
//             n/=10;
//         }
//         if(s.find(temp)!=s.end())
//             return false;
        
//         s.insert(temp);
        
//         return isHappy(temp);
        
//     }
// };
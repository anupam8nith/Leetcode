class Solution {
public:
    string tern(int n){
        string s = "";
        if(n / 3 != 0) s += tern(n / 3);
        s += to_string(n%3);
        return s;
    }

    bool checkPowersOfThree(int n) {
		if(n <= 0) return false;
		string t = tern(n);
		for(auto i: t) if(i == '2') return false;
		return true;
    }
};



// sol1

// class Solution {
// public:
//     bool checkPowersOfThree(long int n) 
//     {
//         // ios_base::sync_with_stdio(false);
//         // cin.tie(NULL);
        
//         if(n==1 || n==3)
//             return true;
//         if(n==2 )
//             return false;
        
//         long int val = 1;
        
//         while(val<=n)
            
//         {
//             val*=3;
//         }
//         val/=3;
        
//         if(val==n)
//             return true;
        
//         if(n>=2*val)
//             return false;
//         else
            
//             n=n-val;
        
//         return checkPowersOfThree(n);
//     }
// };
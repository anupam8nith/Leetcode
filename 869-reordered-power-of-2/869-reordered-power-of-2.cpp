class Solution {
public:
    bool reorderedPowerOf2(int N) 
    {
         unordered_set<string> powerOfTwos;
        
         for (int i = 0; i < 32; ++i) 
         {
             int n = 1 << i;
             string s = to_string(n);
             sort(s.begin(), s.end());
             powerOfTwos.insert(s);
         }
        
         string s = to_string(N);
         sort(s.begin(), s.end());
         return powerOfTwos.count(s) > 0;
        
    }
};


// class Solution {
// public:
//     bool reorderedPowerOf2(int n) 
//     {
//         if(n==1 || n==2 || n==4 || n==8)
//             return true;
        
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
//         vector<int> digit;
//         map<int,int> mp;
        
//         // if n is power of 2
//         if((n&(n-1))==0) return true;
        
//         //store frequency of digits of n
//         while(n)
//         {
//             int rem= n%10;
//             digit.push_back(rem);
//             mp[rem]++;
//             n/=10;
//         }
        
//         // //2,4,8 not present in mp
//         // if(mp[2]<1 && mp[6]<1 && mp[4]<1 && mp[8]<1)
//         //     return false;
        
        
//         // if either of 2,4,8 present in mp
//         sort(digit.begin(),digit.end(),greater<int>());
        
//         //find largest number formed by reordering the digits of n
//         long long lar=0,near=1;
        
//         for(auto x: digit)
//             lar = lar*10 + x;
        
//         //reach the nearest power of 2
//         for(near=1;near<lar;near*=2);
        
//             if(near!=lar)
//             near/=2;
        
//         //now check while near becomes 1
       
//         while(near)
//         {
//              long long num=near;
            
//             map<int,int> mp1;
            
//              while(num)
//         {
//             int rem= num%10;
//             mp1[rem]++;
//             num/=10;
//         }
//             cout<<endl;
            
//             if(mp1==mp)
//                 return true;
            
//             else
//             {
//                 near/=2;
//                 mp1.clear();
//             }
            
//         }
        
        
//         return false;
//     }
// };
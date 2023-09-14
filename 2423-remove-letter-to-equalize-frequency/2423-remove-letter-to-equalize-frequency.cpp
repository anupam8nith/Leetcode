class Solution {
public:
    bool equal(string s, int i)
    {
        s.erase(i,1);
        
        unordered_map<char,int> um;
        
        for(auto it: s)um[it]++;
        unordered_map<int,int> nm;
        for(auto it: um)nm[it.second]++;
        
        if(nm.size()==1)return true;
        else return false;
        
    }
    
    bool equalFrequency(string word) 
    {
        for(int i=0;i<word.size();i++)
            if(equal(word,i))return true;
        
        return false;
    }
};

// class Solution {
// public:
//     bool equalFrequency(string word) 
//     {
//         if(word.size()<=2) return 2;
        
//         unordered_map<char,int> um;
        
//         for(auto it: word) um[it]++;
        
//         unordered_map<int,int> mp;
        
//         int count=0,val1=0,val2=0,vc1=0,vc2=0;
        
//         for(auto it: um) 
//         {
//             mp[it.second]++;
            
//             if(count==0)
//             {val1=it.second;vc1++;}
//             else if(it.second!=val1)
//             {val2=it.second;vc2++;}
            
//             count++;
//         }
        
//         if(mp.size()>2)return false;
            
//        if(vc1>vc2 && val2-val1==1) return true;
//         if(vc2>vc1 && val1-val2==1) return true;
        
        
//         return false;
//     }
// };
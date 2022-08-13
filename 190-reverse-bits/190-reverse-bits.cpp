class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        
        cout<<n<<endl;
        uint32_t ans;
        string s = "";
        int i = 1;
        while(i<=32){
            if(n & 1){
                s += '1';
            }else{
                s += '0';
            }
            i++;
            n = n >> 1;
        
        }
        
        return stoul(s,0,2);
    }
};
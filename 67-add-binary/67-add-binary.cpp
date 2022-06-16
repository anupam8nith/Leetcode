class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size()-1;
        int m = b.size()-1;
        int carry = 0;
        string res = "";
        while(n>=0 && m>=0){
            if(a[n] == '0' && b[m] == '1'){
                if(carry == 0){
                    res += '1';
                }else{
                    res += '0';
                }
            }
            else if(a[n] == '1' && b[m] == '0'){
                if(carry == 0){
                    res += '1';
                }else{
                    res += '0';
                }
            }
            else if(a[n] == '0' && b[m] == '0'){
                if(carry == 0){
                    res += '0';   
                }else{
                    res += '1';
                    carry = 0;
                }
            }
            else if(a[n] == '1' && b[m] == '1'){
                if(carry == 0){
                    res += '0';
                    carry = 1;
                }
                else{
                    res += '1';
                }
            }
            n--,m--;
        }
        while(n>=0){
            if(a[n] == '0'){
                if(carry == 0){
                    res += '0';
                }else{
                    res += '1';
                    carry = 0;
                }
            }else{
                if(carry == 0){
                    res += '1';
                }else{
                    res += '0';
                    carry = 1;
                }
            }
            n--;
        }
        while(m>=0){
            if(b[m] == '0'){
                if(carry == 0){
                    res += '0';
                }else{
                    res += '1';
                    carry = 0;
                }
            }else{
                if(carry == 0){
                    res += '1';
                }else{
                    res += '0';
                    carry = 1;
                }
            }
            m--;
        }
        if(carry == 1) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
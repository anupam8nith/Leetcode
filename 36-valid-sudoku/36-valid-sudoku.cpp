class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map <char,int> um;
        
        //1.check row wise duplicacy
        for(auto x: board)
        {
            for(auto y: x)
            {
                if(y !='.')
                {    
                    um[y]++;
                }
                
                if(um[y]>1)
                    return false;
            }
        
            um.clear();
        }
        
        //2.check columnwise duplicacy 
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char y = board[j][i];
                
                if(y !='.')
                um[y]++;
                
                if(um[y]>1)
                    return false;
            }
            
            um.clear();
        }
        
     // 3. check for sub box validity
        
        int r =0,c=0,count=0,i=0,j=0;
        while(count!=9)
    {
        for(i=r;i<r+3;i++)
        {
            for(j=c;j<c+3;j++)
            {  auto y = board[i][j];
                if(y!='.')
                    um[y]++;
                
                if(um[y]>1)
                    return false;
            }
        }
            um.clear();

            count++; //1 more subarray scanned
            
            if(count%3==0)
            {
                c=0;
                r+=3;
            }
            else
            {
                c+=3;
            }
    }
        return true;
    }
};



        
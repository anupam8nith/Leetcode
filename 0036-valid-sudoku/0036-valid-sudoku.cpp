class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
         // ios_base::sync_with_stdio(false);
         //    cin.tie(NULL);
        
        vector<bool> row(9*9, false);
        vector<bool> col(9*9, false);
        vector<bool> box(9*9, false);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int bi = (i/3)*3 + (j/3);
                char c = board[i][j];
                if (c == '.') continue;
                int val = c - '1';
                
                if (row[i*9 + val]) return false;
                row[i*9 + val] = true;
                if (col[j*9 + val]) return false;
                col[j*9 + val] = true;
                if (box[bi*9+ val]) return false;
                box[bi*9 + val] = true;
            }
        }
        
        return true;
    }
};

// my beloved code 34 ms by iteration

    // class Solution {
    // public:
    //     bool isValidSudoku(vector<vector<char>>& board) 
    //     {
            // ios_base::sync_with_stdio(false);
            // cin.tie(NULL);

    //         unordered_map <char,int> um;

    //         //1.check row wise duplicacy
    //         for(auto x: board)
    //         {
    //             for(auto y: x)
    //             {
    //                 if(y !='.')
    //                 {    
    //                     um[y]++;
    //                 }

    //                 if(um[y]>1)
    //                     return false;
    //             }

    //             um.clear();
    //         }

    //         //2.check columnwise duplicacy 

    //         for(int i=0;i<9;i++)
    //         {
    //             for(int j=0;j<9;j++)
    //             {
    //                 char y = board[j][i];

    //                 if(y !='.')
    //                 um[y]++;

    //                 if(um[y]>1)
    //                     return false;
    //             }

    //             um.clear();
    //         }

    //      // 3. check for sub box validity

//             int r =0,c=0,count=0,i=0,j=0;
//             while(count!=9)
//         {
//             for(i=r;i<r+3;i++)
//             {
//                 for(j=c;j<c+3;j++)
//                 {  auto y = board[i][j];
//                     if(y!='.')
//                         um[y]++;

//                     if(um[y]>1)
//                         return false;
//                 }
//             }
//                 um.clear();

//                 count++; //1 more subarray scanned

//                 if(count%3==0)
//                 {
//                     c=0;
//                     r+=3;
//                 }
//                 else
//                 {
//                     c+=3;
//                 }
//         }
    //         return true;
    //     }
    // };




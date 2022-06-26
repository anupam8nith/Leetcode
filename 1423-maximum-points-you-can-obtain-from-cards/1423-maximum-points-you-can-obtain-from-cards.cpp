class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        // Sliding Window approach
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
        
        int sum =0;
        int maxsum;
        
        for(int  i=0;i<k;i++){
            sum += cardPoints[i];
        }
        maxsum = sum;
        
        for(int i=0;i<k;i++){
            sum += cardPoints[cardPoints.size()-i-1] - cardPoints[k-i-1];
            if(sum > maxsum){
                maxsum = sum;
            }
        }
        return maxsum;
    }
};
    
// solution 1

// int sum = 0;
//         int n = cardPoints.size();
        
//         vector<int> cummulativeSumFromFront(n+1, 0);
//         vector<int> cummulativeSumFromBehind(n+1, 0);
        
//         sum = 0;
//         for (int i=0; i<n; i++) {
//             sum += cardPoints[i];
//             cummulativeSumFromFront[i+1] = sum;
//         }
//         sum = 0;
//         for (int i=n-1; i>=0; i--) {
//             sum += cardPoints[i];
//             cummulativeSumFromBehind[i] = sum;
//         }
        
//         // Reversing is optional. I reversed it so that it would be easy
//         // to access sum of last (k-i) elements by just indexing at [k-i]
//         // Otherwise, I would have had to index it at [n-k+i] which would
//         // have made it difficult to read.
//         reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
        
//         int answer = 0;
//         for(int i=0; i<=k; i++) {      
//             answer = max(answer, 
//                            cummulativeSumFromFront[i] // Sum of first 'i' cards.
//                          + cummulativeSumFromBehind[k-i]); // Sum of last 'k-i' cards.
//         }
//         return answer;





    
    //debug this
    
// long int i=0,count=0,sum=0,n=cardPoints.size();
        
//          vector<int>::iterator start=cardPoints.begin(), end = cardPoints.end();
        
//         while(count<k)
//         {
//            if(*start>*end)
//            {
//                sum+= *start;
//                cardPoints.erase(start);
//                count++;
               
//                if(count==k)
//                      break;
//            }
//             else if(*start<*end)
//             {
//                 sum+=*end;
//                 cardPoints.erase(end);
//                 count++;
                
//                 if(count==k)
//                      break;
//             }
            
//              else if(*start==*end)
//              {
//                  vector<int>::iterator it1,it2;
                 
//                  it1=++start;
//                  it2=--end;
                 
//                  while(*it1==*it2)
//                  {
//                      it1++;
//                      it2--;
//                  }
                 
//                  if(*it1>*it2)
//                  {
//                      sum+= *start;
//                cardPoints.erase(start);
//                count++;
//                  }
//                  else
//                  {
//                      sum+=*end;
//                 cardPoints.erase(end);
//                 count++;
//                  }
                 
//                  if(count==k)
//                      break;
//              }
        
//         }
//         return sum;
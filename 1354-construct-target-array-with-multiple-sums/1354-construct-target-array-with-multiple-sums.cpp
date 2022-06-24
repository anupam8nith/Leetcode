class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        //solution 1
        
        // long total = 0;
        // int n = A.size(), a;
        // priority_queue<int> pq(A.begin(), A.end());
        // for (int a : A)
        //     total += a;
        // while (true) {
        //     a = pq.top(); pq.pop();
        //     total -= a;
        //     if (a == 1 || total == 1)
        //         return true;
        //     if (a < total || total == 0 || a % total == 0)
        //         return false;
        //     a %= total;
        //     total += a;
        //     pq.push(a);
        
        //solution 2
        
        long long sum = 0;
        priority_queue<long long> pq;
        
        for(int item : target)
        {
            pq.push((long long)item);
            sum += item;
        }
        
        while(pq.top() != 1)
        {
            long long top = pq.top(); pq.pop();
            
            sum = sum - top;
            
            if(sum <= 0 || sum >= top) return false;
            
            top = top % sum;
            sum += top;
            
            pq.push(top > 0 ? top : sum);
        }
        
        return true;    
        
        }
    
};
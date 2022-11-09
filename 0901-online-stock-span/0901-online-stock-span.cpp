class StockSpanner {
public:
    StockSpanner() { }
    stack<pair<int,int>> sk;
    int next(int price) 
    {
        int ct = 1;
        while(sk.size() and sk.top().first <= price)
				ct+=sk.top().second , sk.pop();            // we add count of popped element's count
				
        sk.push({price , ct});
        return ct;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
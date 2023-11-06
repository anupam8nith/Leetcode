class SeatManager 
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
public:
    SeatManager(int n) 
    {
        num = 1;
    }
    
    int reserve() 
    {
        if(!pq.empty()) 
        {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        return num++;
    }
    
    void unreserve(int seatNumber) 
    {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
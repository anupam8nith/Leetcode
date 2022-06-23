class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        // solution 1
        
        //  if(courses.size() <= 0) return 0;
        // sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
        //     return a[1] < b[1];
        // });
        // priority_queue<int> que;
        // int sum = 0;
        // for(auto i : courses) {
        //     sum += i[0];
        //     que.push(i[0]);
        //     if(sum > i[1]) {
        //         sum -= que.top();
        //         que.pop();
        //     }
        // }
        // return que.size();
        
        //solution 2
        
        sort(begin(courses),end(courses),[](auto & a,auto & b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int time=0;
        for(auto & i:courses){
            int dur=i[0],last=i[1];
            if(time+dur<=last){
                pq.push(dur);
                time+=dur;
            }
            else{
                if(!pq.empty()){
                    int top=pq.top();
                    if(top>dur){
                    time-=top;
                    pq.pop();
                    time+=dur;
                    pq.push(dur);
                    }
                }
            }
        }
        return pq.size();
    }
};
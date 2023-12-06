class Solution {
public:
    int totalMoney(int n) 
    {
        int weeks  = n / 7;
        int remain_days = n % 7,saving_in_week = 28;
        int day_in_week = 0,savings = 0;
        for (int i = 1; i <= weeks; i++){
            savings =  savings + saving_in_week + day_in_week;
            day_in_week = day_in_week + 7;
        }
        for (int j = weeks+1; j <= remain_days+weeks; j++){
            savings = savings + j;
        }
        return savings;
}
};
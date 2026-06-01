class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0;
        
        for(int i : prices){
            if(i < min) min = i;

            int curr_profit = i - min;
            if(curr_profit > max_profit) max_profit = curr_profit;
        }
        return max_profit;
    }
};
//local maxima - local minima. This is one way.
//Here we compare consecutive prices and if there is an increase we do a transaction.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Profit = 0;
        int n = prices.size();
        
        for(int i =1; i<n; i++){
            if(prices[i]>prices[i-1]){
                Profit += (prices[i]-prices[i-1]);
            }
        }
        return Profit;
    }
};

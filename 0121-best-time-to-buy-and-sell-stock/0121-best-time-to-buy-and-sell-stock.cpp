class Solution {
public:

void maxProfitFinder(vector<int>& Prices, int i, int&minPrice, int&maxProfit){
    //base
    if(i == Prices.size()) return;

    // sol for one case
    if(Prices[i] < minPrice) minPrice = Prices[i];
    int todaysProfit = Prices[i] - minPrice;
    if(todaysProfit > maxProfit) maxProfit = todaysProfit;

    // RE
    maxProfitFinder(Prices, i+1, minPrice, maxProfit);
}
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        maxProfitFinder(prices, 0, minPrice, maxProfit);
        return maxProfit;
        
    }
};
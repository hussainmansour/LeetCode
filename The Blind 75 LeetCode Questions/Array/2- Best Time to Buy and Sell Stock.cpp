class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int minPrice = prices[0];
        for(int i = 1 ; i < n ; i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            else{
                ans = max(ans,prices[i]-minPrice);
            }
        }
        return ans;
    }
};


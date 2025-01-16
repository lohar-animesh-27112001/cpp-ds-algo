#ifndef ZERO_ONE_KNAPSACK
#define ZERO_ONE_KNAPSACK

#include <bits/stdc++.h>
using namespace std;

class ZeroOneKnapsack {
private:
    int max_weight;
    vector<int> profit;
    vector<int> weight;
    vector<vector<int>> dp;
public:
    ZeroOneKnapsack(int max_weight, vector<int> profit, vector<int> weight) : 
                    max_weight(max_weight), profit(profit), weight(weight) {
        dp.resize(profit.size() + 1, vector<int>(max_weight + 1, 0));
    }

    int maxProfitDP() {
        for(int i = 1; i <= profit.size(); i++) {
            for(int j = 1; j <= max_weight; j++) {
                if(j >= weight[i-1])
                    dp[i][j] = max(dp[i-1][j], profit[i-1]+dp[i-1][j-weight[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        cout << "Max profit we can get: " << dp[profit.size()][max_weight] << endl;
        return dp[profit.size()][max_weight];
    }
};

#endif
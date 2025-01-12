#ifndef MATRIX_CHAIN_MULTIPLICATION
#define MATRIX_CHAIN_MULTIPLICATION

#include <bits/stdc++.h>
using namespace std;

class MatrixChainMul {
private:
    vector<int> vec;
    vector<vector<int>> dp;

public:
    MatrixChainMul(const vector<int>& vec) : vec(vec) {
        int n = vec.size();
        dp.resize(n - 1, vector<int>(n - 1, 0));
    }

    int getOptimalValue() {
        int n = vec.size() - 1;
        if (n == 1) {
            cout << "The minimum cost for the Matrix Chain Multiplication: " << 0 << endl;
            return 0;
        }
        for (int len = 1; len < n; len++)
            for (int i = 0; i <= n - (len + 1); i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + vec[i] * vec[k + 1] * vec[j + 1];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        cout << "The minimum cost for the Matrix Chain Multiplication: " << dp[0][n - 1] << endl;
        return dp[0][n - 1];
    }
};

#endif
#pragma once

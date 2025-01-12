#ifndef LCS_HEADER
#define LCS_HEADER

#include <bits/stdc++.h>
using namespace std;

class LCS {
private:
    string str_one;
    string str_two;
    vector<vector<int>> dp;

public:
    LCS(string str1, string str2) : str_one(str1), str_two(str2) {
        dp.resize(str1.length()+1, vector<int>(str2.length()+1, 0));
    }

    int lcs_dp() {
        int m = str_one.length();
        int n = str_two.length();
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str_one[i-1] == str_two[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << "Longest Common Sequence is: " << dp[m][n] << endl;
        return dp[m][n];
    }

    string get_lcs_str() {
        int m = str_one.length();
        int n = str_two.length();
        string lcs_str = "";
        while (m > 0 && n > 0) {
            if (str_one[m - 1] == str_two[n - 1]) {
                lcs_str = str_one[m - 1] + lcs_str;
                m--;
                n--;
            } else if (dp[m - 1][n] >= dp[m][n - 1]) m--;
            else n--;
        }
        cout << "One of the LCS strings is : " << lcs_str << endl;
        return lcs_str;
    }
};

#endif
#pragma once
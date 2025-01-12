
#include <bits/stdc++.h>
#include "lcs.h"

using namespace std;

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    LCS lcs_solver(str1, str2);
    lcs_solver.lcs_dp();
    lcs_solver.get_lcs_str();

    return 0;
}
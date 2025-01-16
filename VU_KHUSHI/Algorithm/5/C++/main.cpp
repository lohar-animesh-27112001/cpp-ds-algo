#include "knapsack_zero_one.h"

using namespace std;

int main() {
    int maxWeight = 10;
    vector<int> profits = {10, 40, 30, 50, 70};
    vector<int> weights = {1, 3, 4, 6, 8};

    ZeroOneKnapsack knapsack(maxWeight, profits, weights);
    knapsack.maxProfitDP();

    return 0;
}

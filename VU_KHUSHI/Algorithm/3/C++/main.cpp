#include "matrixChainMul.h"

int main() {
    vector<int> vec = {40, 20, 30, 10, 30};
    MatrixChainMul mcm(vec);
    mcm.getOptimalValue();
    return 0;
}

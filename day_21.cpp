#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using std::vector;
using std::string;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
    int get(int x, int y) {
        return mat[x][y];
    }

    vector<int> dimensions() {
        vector<int> out;
        out.emplace_back(mat.size());
        out.emplace_back(mat[0].size());
        return out;
    }

private:
//    vector<vector<int>> mat = {{0, 0, 0, 1},
//                               {0, 0, 1, 1},
//                               {0, 1, 1, 1},
//                               {0, 0, 0, 0}};

//    vector<vector<int>> mat = {{0, 0},
//                               {0, 0}};

//    vector<vector<int>> mat = {{0, 0},
//                               {0, 1}};

//    vector<vector<int>> mat = {{0, 0},
//                               {1, 1}};

//    vector<vector<int>> mat = {{0, 0, 0, 1},
//                               {0, 0, 1, 1},
//                               {0, 1, 1, 1}};

//    vector<vector<int>> mat = {{0, 0, 0, 0, 1, 1},
//                               {0, 0, 0, 1, 1, 1},
//                               {0, 0, 0, 0, 1, 1},
//                               {0, 0, 0, 0, 1, 1},
//                               {0, 0, 0, 1, 1, 1},
//                               {0, 0, 0, 1, 1, 1}};

//    vector<vector<int>> mat = {{0, 0, 1, 1, 1, 1, 1, 1},
//                               {0, 0, 0, 0, 0, 1, 1, 1},
//                               {0, 0, 0, 1, 1, 1, 1, 1},
//                               {0, 0, 0, 0, 0, 1, 1, 1},
//                               {0, 0, 0, 1, 1, 1, 1, 1},
//                               {0, 0, 1, 1, 1, 1, 1, 1},
//                               {0, 0, 0, 0, 1, 1, 1, 1},
//                               {0, 1, 1, 1, 1, 1, 1, 1}};


    vector<vector<int>> mat = {{0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                               {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                               {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}};
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int i = 0, j = dim[1] - 1, num = 0;

        for (; i < dim[0]; ++i) {
            num = binaryMatrix.get(i, j);
            if (num == 1) {
                --j;
                break;
            }
        }

        if (i == dim[0]) return -1;

        while (j >= 0 && i < dim[0]) {
            num = binaryMatrix.get(i, j);
            if (num == 0) { ++i; }
            if (num == 1) { --j; }
        }

        return j + 1;
    }
};

int main() {
    Solution solution = Solution();

    BinaryMatrix mat;

    std::cout << solution.leftMostColumnWithOne(mat) << std::endl;

    return 0;
}
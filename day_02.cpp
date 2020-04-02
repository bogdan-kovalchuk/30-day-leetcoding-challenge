#include <vector>
#include <iostream>
#include <cmath>

using std::vector;
using std::map;

class Solution {
public:
int isHappy(int n) {
	int res = n;
	while (int(log10(res) + 1) > 1){
		int num = res;
		res = 0;
		while (num > 0){
		    res += (num%10)^2;
		    num /= 10;
		}
    }
	return res;
}
};

int main() {
    Solution solution = Solution();
    int num = 19;

    int out = solution.isHappy(num);

    std::cout << out << std::endl;

    return 0;
}
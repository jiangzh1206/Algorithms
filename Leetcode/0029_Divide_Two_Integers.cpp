#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long m = labs(dividend); 
        long n = labs(divisor);
        int res = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        if (n == 1) {
            return sign == 1 ? m : -m;
        }

        // 每次除数左移乘2
        while (m >= n) {
            long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;   //从被除数中减去已经增加的除数次数之和
        }
        return sign == 1 ? res : -res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    int ret = sln.divide(-2147483648, -1);
    return 0;
}

#include <iostream>
using namespace std;
/*
    F(m, n) = F(m-1, n) + F(m, n-1);
    F(0, 0) = 1;
    if (n == 0 || m == 0) F(m, n) = 1;
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *F = new int[m*n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || i == 0) {
                    F[i*n + j] = 1;
                } else {
                    // F(i, j) = F(i-1,j) +　F(i,j-1);
                    F[i*n + j] = F[(i-1)*n + j] + F[i*n + j - 1];
                }
            }
        }
        
        // F[m-1,n-1];
        int res =  F[m*n - 1]; 
 
        delete [] F;
        return res;
    }
};

int main() {
    Solution sln;
    int res = sln.uniquePaths(3, 7);
    cout << "result: " << res << endl;

    return 0;
}

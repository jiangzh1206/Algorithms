#include <iostream>
#include <vector>
using namespace std;
/*
    F(m, n) = F(m-1, n) + F(m, n-1);
    F(0, 0) = 1;
    if (n == 0 || m == 0) F(m, n) = 1;
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int *F = new int[m*n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    F[i*n + j] = 0;
                } else {
                    if (i == 0 && j == 0) {
                        if (obstacleGrid[0][0] == 1)
                            return 0; // 迈不出第一步
                        F[0] = 1;
                    } else if (j == 0) {
                        // 上一行是否为障碍，否则等于上一行
                        if (obstacleGrid[i-1][j] == 1){
                            F[i*n + j] = 0;
                        } else {
                            F[i*n + j] = F[(i-1)*n + 0];
                        }
                    } else if(i == 0) {
                        // 前一列是否为障碍，否则等于前一列
                        if (obstacleGrid[i][j-1] == 1){
                            F[i*n + j] = 0;
                        } else {
                            F[i*n + j] = F[0 + j-1];
                        }
                    } else {
                        // F(i, j) = F(i-1,j) +　F(i,j-1);
                        F[i*n + j] = F[(i-1)*n + j] + F[i*n + j - 1];
                    }
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
    vector<vector<int>> input{{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0}};
    int res = sln.uniquePathsWithObstacles(input);
    cout << "result: " << res << endl;

    return 0;
}
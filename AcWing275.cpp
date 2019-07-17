#include <bits/stdc++.h>
using namespace std;
int n, m;
/**
 * 给定一个 N*M 的矩阵A，每个格子中有一个整数。
 * 现在需要找到两条从左上角 (1,1) 到右下角 (N,M) 的路径，路径上的每一步只能向右或向下走。
 * 路径经过的格子中的数会被取走，两条路径可以经过同一个格子，但格子中的数 只能被取一次
 * 求取得的数之和最大是多少。
 * 考虑只走一条的情况
 * 假设dp[i][j]为走到<i, j>位置的最大值是多少
 * 只能向右或者向下走
 * dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j])
 * 如果能将走过的路径变化为0，那么再跑一次上述的转移方程就ok了
 * 如果在每个点的位置记录走到该位置的最大值的路径
 * 那么跑完第一趟将对应的数值变成0
 * 然后跑第二遍
 * 应该就ok了
 * vector<pair<int, int>>arr[n][m];
 * for(int i = 1; i <= n; i ++){
 * for(int j = 1; j <= m; j ++){
 * 
 * }
 * }
 * **/
const int MAXN = 55;
vector< pair<int, int> >lj[MAXN][MAXN];
int arr[MAXN][MAXN];
int dp[MAXN][MAXN]; 
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(dp[i - 1][j] + arr[i][j] > dp[i][j - 1] + arr[i][j]){
                dp[i][j] = dp[i - 1][j] + arr[i][j];
                for(int z = 0; z < lj[i - 1][j].size(); z ++){
                    lj[i][j].push_back(lj[i - 1][j][z]);
                }
                lj[i][j].push_back(make_pair(i, j));
            }
            else{
                dp[i][j] = dp[i][j - 1] + arr[i][j];
                for(int z = 0; z < lj[i][j - 1].size(); z ++){
                    lj[i][j].push_back(lj[i][j - 1][z]);
                }
                lj[i][j].push_back(make_pair(i, j));
            }
        }
    }
    int re = 0;
    re += dp[n][m];
    for(int i = 0; i < lj[n][m].size(); i ++){
        printf("%d %d\n", lj[n][m][i].first, lj[n][m][i].second);
        arr[lj[n][m][i].first][lj[n][m][i].second] = 0;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);
        }
    }
    re += dp[n][m];
    printf("%d\n", re);
    return 0;
}
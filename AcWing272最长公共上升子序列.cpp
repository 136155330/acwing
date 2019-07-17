#include <bits/stdc++.h>
using namespace std;
/*
假设dp[a][b]为上面长度a下面长度b的最大值
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i] == brr[j])
            {
                for(int z = 0; z < j; z ++){
                    if(arr[i] > brr[z]){
                        dp[i][j] = max(dp[i][j], dp[i - 1][z] + 1);
                    }
                }
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
 */
const int MAXN = 3000 + 5;
int arr[MAXN], brr[MAXN], dp[MAXN][MAXN], n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &brr[i]);
    }
    arr[0] = brr[0] = -0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i] == brr[j])
            {
                for(int z = 0; z < j; z ++){
                    if(arr[i] > brr[z]){
                        dp[i][j] = max(dp[i][j], dp[i - 1][z] + 1);
                    }
                }
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int re = 0;
    for(int i = 1; i <= n; i ++){
        re = max(re, dp[n][i]);
    }
    printf("%d\n", re);
    return 0;
}
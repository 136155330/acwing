#include <bits/stdc++.h>
using namespace std;
/*
假设出状态dp[a][b]作为结尾
dp[a][b] = max(dp[i][j] + 1, dp[a][b]) i < a j < b
for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
        if(arr[i] == brr[j]){
            for(int ii = 1; ii < i; ii ++){
                for(int jj = 1; jj < j; jj ++){
                    dp[i][j] = max(dp[ii][jj] + 1, dp[ii][jj]);
                }
            }
        }
    }
}
dp[a]代表以第一行的第i个作为结尾
for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= i; j ++){
        for(int z = 0; z < i; z ++){
            if(arr[i] > arr[z])
            dp[i] = max(dp[z] + 1, dp[i]);
        }
    }
}
dp[a] 以这个位置结尾的arr或者brr的最大值
for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= i; j ++){
        for(int z = 1; z <= i; z ++){
            if(arr[j] == brr[z]){
                for(int h = 0; h < min(j, z); h ++){
                    if(arr[j] > arr[h] || arr[j] > brr[h])
                    dp[max(j, z)] = max(dp[h] + 1, dp[max(j, z)]);
                }
            }
        }
    }
}
 */
const int MAXN = 3000 + 5;
int arr[MAXN], brr[MAXN], dp[MAXN], dps[MAXN], n;
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
        for (int j = 1; j <= i; j++)
        {
            for (int z = 1; z <= i; z++)
            {
                if (arr[j] == brr[z])
                {
                    for (int h = 0; h <= min(j, z); h++)
                    {
                        if (arr[j] > arr[h] || arr[j] > brr[h])
                            dp[max(j, z)] = max(dp[h] + 1, dp[max(j, z)]);
                    }
                }
            }
        }
    }
    int re = 0;
    for (int i = 1; i <= n; i++)
    {
        re = max(re, dp[i]);
    }
    printf("%d\n", re);
    return 0;
}
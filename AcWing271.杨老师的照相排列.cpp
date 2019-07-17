#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 35;
typedef long long ll;
ll dp[MAXN][MAXN][MAXN][MAXN][MAXN];
int arr[MAXN];
int n;
int main(){
    while(~scanf("%d", &n) && n){
        for(int i = 0; i < n; i ++){
            scanf("%d", &arr[i]);
        }
        for(int i = n; i < 5; i ++){
            arr[i] = 0;
        }
        for(int i1 = 0; i1 <= arr[0]; i1 ++){
            for(int i2 = 0; i2 <= arr[1]; i2 ++){
                for(int i3 = 0; i3 <= arr[2]; i3 ++){
                    for(int i4 = 0; i4 <= arr[3]; i4 ++){
                        for(int i5 = 0; i5 <= arr[4]; i5 ++){
                            dp[i1][i2][i3][i4][i5] = 0;
                        }
                    }
                }
            }
        }
        dp[0][0][0][0][0] = 1;
        for(int i1 = 0; i1 <= arr[0]; i1 ++){
            for(int i2 = 0; i2 <= arr[1]; i2 ++){
                for(int i3 = 0; i3 <= arr[2]; i3 ++){
                    for(int i4 = 0; i4 <= arr[3]; i4 ++){
                        for(int i5 = 0; i5 <= arr[4]; i5 ++){
                            ll now = dp[i1][i2][i3][i4][i5];
                            if(i1 < arr[0]){
                                dp[i1 + 1][i2][i3][i4][i5] += now;
                            }
                            if(i2 < arr[1] && i1 > i2){
                                dp[i1][i2 + 1][i3][i4][i5] += now;
                            }
                            if(i3 < arr[2] && i2 > i3){
                                dp[i1][i2][i3 + 1][i4][i5] += now;
                            }
                            if(i4 < arr[3] && i3 > i4){
                                dp[i1][i2][i3][i4 + 1][i5] += now;
                            }
                            if(i5 < arr[4] && i4 > i5){
                                dp[i1][i2][i3][i4][i5 + 1] += now;
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n", dp[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
const int MAXN = 105;
LL dp[MAXN * 100];
LL arr[MAXN];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    dp[0] = 1;
    for(int i = 0; i < n; i ++){
        for(int j = m; j >= arr[i]; j --){
            dp[j] += dp[j - arr[i]];
        }
    }
    printf("%lld\n", dp[m]);
    return 0;
}
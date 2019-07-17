#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 4005;
typedef long long LL;
const LL mod = 2147483648;
LL dp[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    printf("%lld\n", dp[n] - 1);
    return 0;
}
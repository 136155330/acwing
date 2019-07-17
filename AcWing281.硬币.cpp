#include <bits/stdc++.h>
#define mem(x) memset(x, 0, sizeof(x))
using namespace std;
const int MAXM = 1e5 + 5;
const int MAXN = 1e2 + 5;
int arr[MAXN], crr[MAXN], dp[MAXM], used[MAXM];
int n, m;
int main(){
    ios::sync_with_stdio(false);
    while(cin >> n >> m && n && m){
        mem(arr), mem(crr), mem(dp), mem(used);
        for(int i = 1; i <= n; i ++) cin >> arr[i];
        for(int i = 1; i <= n; i ++) cin >> crr[i];
        dp[0] = 1;
        for(int i = 1; i <= n; i ++){
            mem(used);
            for(int j = arr[i]; j <= m; j ++){
                if(!dp[j] && dp[j - arr[i]] && used[j - arr[i]] < crr[i]){
                    used[j] = used[j - arr[i]] + 1;
                    dp[j] = 1;
                }
            }
        }
        int re = 0;
        for(int i = 1; i <= m; i ++){
            if(dp[i]) re ++;
        }
        cout << re << endl;
    }
    return 0;
}
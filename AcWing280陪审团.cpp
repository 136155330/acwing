#include <bits/stdc++.h>
#define mem(x) memset(x, 0, sizeof(x))
using namespace std;
const int MAXN = 205;
int n, m;
int drr[MAXN], prr[MAXN], dp[25][405][405], lujing[25][405][405];
int main(){
    int step = 0;
    while(cin >> n >> m && (n || m)){
        mem(drr), mem(prr), mem(dp), mem(lujing);
        for(int i = 1; i <= n; i ++){
            cin >> drr[i] >> prr[i];
        }
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = m; j > 0; j --){
                for(int d = 404; d >= drr[i]; d --){
                    for(int p = 404; p >= prr[i]; p --){
                        if(dp[j - 1][d - drr[i]][p - prr[i]] == 1){
                            dp[j][d][p] = 1;
                            lujing[j][d][p] = i; 
                        }
                    }
                }
            }
        }
        int maxs = 0x7fffffff;
        int a, b;
        a = b = 0;
        for(int i = 1; i <= 404; i ++){
            for(int j = 1; j <= 404; j ++){
                if(dp[m][i][j] == 1){
                    if(abs(i - j) < maxs){
                        maxs = abs(i - j);
                        a = i, b = j;
                    }
                    else if(abs(i - j) == maxs && i + j > a + b){
                        a = i, b = j;
                    }
                }
            }
        }
        printf("Jury #%d\n", ++ step);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", a, b);
        vector<int>vec;
        vec.clear();
        while(1){
            if(m == 0 && a == 0 && b == 0){
                break;
            }
            vec.push_back(lujing[m][a][b]);
            int aa = a, bb = b;
            a = a - drr[lujing[m][aa][bb]];
            b = b - prr[lujing[m][aa][bb]];
            m --;
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i ++){
            printf(" %d", vec[i]);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
#define mem(x) memset(x, 0, sizeof(x))
using namespace std;
const int MAXN = 205;
int drr[MAXN], prr[MAXN], dp[25][805], lujing[25][805][500];
void Init(){
    mem(drr), mem(prr), mem(lujing);
    for(int i = 0; i < 25; i ++){
        for(int j = 0; j < 805; j ++){
            dp[i][j] = -1;
        }
    }
    dp[0][400] = 0;
}
int n, m;
int main(){
    int step = 0;
    while(~scanf("%d%d", &n, &m) && (n || m)){
        Init();
        for(int i = 1; i <= n; i ++){
            scanf("%d%d", &drr[i], &prr[i]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = m; j > 0; j --){
                ///因为drr[i] - prr[i]会存在 < 0的情况
                ///按照原来的转移方程 k = 0; k <= 400; k ++
                ///dp[0][0]选了0个dsum - rsum = 0 为 1
                ///dp[m][k - (d[i] - r[i])] + d[i] + r[i]
                ///会出现负数，导致状态转移是错误的
                ///所以加上400，使得dp[0][0]变成dp[0][400]
                ///k就变成了 k = 0; k <= 800; k ++,可得如下的状态转移
                for(int k = 0; k <= 800; k ++){
                    if(k - (drr[i] - prr[i]) >= 0 && dp[j - 1][k - (drr[i] - prr[i])] >= 0 && k - (drr[i] - prr[i]) <= 800){
                        if(dp[j - 1][k - (drr[i] - prr[i])] + drr[i] + prr[i] > dp[j][k]){
                            dp[j][k] = dp[j - 1][k - (drr[i] - prr[i])] + drr[i] + prr[i];
                            lujing[j][k][dp[j][k]] = i;
                            /*
                            采用三维进行路径的标记
                            lujing的第一维度与第二维度与背包一样
                            第三维度这是背包的价值，这样的话，就可以避免重叠状态的查找
                            比如 <2 , 3> <1 , 2> 这两个二元组占用的是同一个dp[j][k]
                            那么他们的区别就是背包的价值，所以我们可以通过一个这样的
                            三维数组来标记当前的状态是因为选了哪个物体而得到的。
                            这样只要减去选择的物体就可以得到前一个的状态，从而实现路径的输出
                             */
                        }
                    }
                }
            }
        }
        /*
        通过数学我们容易得知，
        a - b = x
        a + b = y

        可得 2 * a = x + y
             a = (x + y) / 2
             b = y - a
        可得p的总和 与 d的总和
        所以 a - b为 k
            a + b 为 dp[m][k]
         */
        int sum = 0x7fffffff;/// a - b
        int num = 0;/// a + b
        int re = 0;
        int flag = 0;
        for(int k = 0; k <= 800; k ++){
            if(k <= 400){
                int temp = 400 - k;
                if(temp < sum && dp[m][k] >= 0){
                    sum = temp;
                    num = dp[m][k];
                    re = k;
                    flag = 0;
                }
                else if(temp == sum && dp[m][k] >= num){
                    num = dp[m][k];
                    re = k;
                    flag = 0;
                }
            }
            else{
                int temp = k - 400;
                if(temp < sum && dp[m][k] >= 0){
                    sum = temp;
                    num = dp[m][k];
                    re = k;
                    flag = 1;
                }
                else if(temp == sum && dp[m][k] >= num){
                    num = dp[m][k];
                    re = k;
                    flag = 1;
                }
            }
        }
        int a, b;///因为a - b 存在正负，所以对应以下两种情况
        if(flag == 1){
            a = (sum + num) / 2;
            b = num - a;
        }
        else{
            a = (num - sum) / 2;
            b = num - a;
        }
        printf("Jury #%d\n", ++ step);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", a, b);
        vector<int>vec;
        vec.clear();
        int k = re;
        int mysum = dp[m][k];
        while(lujing[m][k][mysum]){///寻找路径
        /*
        将选择的物体数量减一，将a-b的值减去对应的物体的(drr[i] - prr[i]), a+b的值减去对应物体的drr[i],prr[i]
        就可以得到上一个的状态。 
         */
            vec.push_back(lujing[m][k][mysum]);
            int temp = lujing[m][k][mysum];
            m --;
            k = k - (drr[temp] - prr[temp]);
            mysum = mysum - drr[temp] - prr[temp];
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i ++){
            printf(" %d", vec[i]);
        }
        printf("\n\n");///注意输出要一个空行
    }
    return 0;
}
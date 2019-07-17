#include<stdio.h>

typedef long long LL;
const int MAXN = 105;

struct Node{
    int left, right;
    LL num;
}node[MAXN];

void nodeInit(int i){
    node[i].left = -1;
    node[i].right = -1;
}

int sign;

void treeInsert(LL x){
    int now = 0;
}

int main(){
    int n, i;
    LL x;
    while (scanf("%d", &n) != EOF){
        sign = 0;
        scanf("%lld", &x);
        nodeInit(sign);
        node[sign++].num = x;

        for(i = 1; i < n; i ++){
            scanf("%lld", &x);
            treeInsert(x);
        }
    }
    return 0;
}

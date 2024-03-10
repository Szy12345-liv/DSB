#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0)) ;
int main() {
    freopen("in.txt","w",stdout) ;
    int n = 35 , m = 105 , rmn = 1, rmx = 5 , k = 4;
    printf("%d %d %d %d %d\n",n,m,rmn,rmx,k);
    for(int i = 1;i <= n;i++) printf("%d ",rnd()%k + 1); printf("\n") ;
    for(int i = 1;i <= m;i++) {
        int u =rnd()%n + 1 , v = rnd()%n + 1;
        printf("%d %d\n",u,v);
    }
}
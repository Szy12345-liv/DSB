#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
typedef pair<int,int> pii;
int c[maxn + 5];
vector<int> E[maxn + 5] ;
pii ans = {0,0};
int n , m , rmn , rmx , k;
int main() {
    freopen("in.txt","r",stdin) ;
    cin >> n >> m >> rmn >> rmx >> k;
    for(int i = 1;i <= n;i++) cin >> c[i] ;
    for(int i = 1;i <= m;i++)  {
        int u , v ; cin >> u >> v;
        if(u != v) E[u].push_back(v) , E[v].push_back(u) ;
        else E[u].push_back(u) ;
    }
    for(int i = 1;i < (1<<n);i++) {
        int e = 0 , v= 0;
        vector<int> col(k + 1);
        for(int j = 0;j < n;j++) {
            v += ((i >> j) & 1);
            if((i >> j) & 1) col[c[j + 1]]++;
        }
        int mn = 1e9 , mx = 0;
        for(int i = 1;i <= k;i++) mn = min(mn , col[i]) , mx = max(mx , col[i]) ;
        if(mn * rmx < mx * rmn) continue ;

        for(int j = 0;j < n;j++) {
            if(!((i >> j) & 1)) continue ;
            for(auto v : E[j + 1]) {
                if(v >= j + 1 && ((i >> v - 1) & 1)) e++;
            }
        }
        if(ans.first * v <= ans.second * e) ans = {e , v};
    }
    printf("%d %d\n",ans.first,ans.second) ;
}
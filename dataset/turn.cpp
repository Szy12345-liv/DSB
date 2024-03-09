#include <bits/stdc++.h>
using namespace std;
int n , m;
int c[200005];
typedef pair<int,int> pii;
vector<pii> Ed;
mt19937 rnd(0) ;
const int CUT = 1e3;
int main() {
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    freopen("graph1.txt","r",stdin) ;
    cin >> n >> m;
    int k = 10 , rmn = 1 , rmx = 3;
    n = min(n , CUT) ;
    for(int i = 1;i <= n;i++) c[i] = rnd()%k + 1;
    for(int i = 1;i <= m;i++) {
        int u , v;cin >> u >> v;
        if(u > n || v > n) continue ;
        Ed.push_back({u , v});
    }
    freopen("input1.txt" , "w" , stdout) ;
    cout << n <<' ' << m << ' ' << rmn <<' ' << rmx <<' ' << k << '\n' ;
    for(int i = 1;i <= n;i++) cout << c[i] <<' ' ; cout << '\n' ;
    for(auto [u,v] : Ed) cout << u <<' ' << v << '\n' ;
    return 0;
}
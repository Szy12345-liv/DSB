#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 ;
typedef pair<int,int> pii;

int n , m , rmn , rmx , k;
int c[maxn + 5];
int p[maxn + 5];
vector<int> E[maxn + 5] ;
pii ans ;
int cur_e = 0 , cur_v = 0;
int num_c[maxn + 1];
bool ch[maxn] ;
struct st {
    int num[maxn + 5];
    int mx , mn;
    st() {
        mx = 0 ; mn = 0;
    }
    void add(int u) {
        num[u]-- ; num[u + 1]++;
        if(u + 1 > mx) mx = u + 1;
        if(mn == u && num[u] == 0) mn = u + 1;
    }
    void dec(int u) {
        num[u]-- ; num[u - 1]++;
        if(u == mx && num[u] == 0) mx = u - 1;
        if(u - 1 < mn) mn = u - 1;
        
    }
}S;
bool cmp(int a,int b,int c,int d) { //[a/b <= c/d]
    return 1LL * a * d <= 1LL *b*c;
}
int cc = 0;

int sum_e[maxn + 5];
void choose(int u) {
    S.add(num_c[c[p[u]]]) ;
    num_c[c[p[u]]]++;
    ch[p[u]] = 1; sum_e[p[u]] = 0;
    for(auto v : E[p[u]]) {
        sum_e[p[u]] += ch[v];
    }
    cur_e += sum_e[p[u]] ; cur_v++;
}
void dchoose(int u) {
    cur_e -= sum_e[p[u]] ; cur_v-- ;
    ch[p[u]] = 0;
    S.dec(num_c[c[p[u]]]) ;
    num_c[c[p[u]]]--;
}
bool verify() {
    return cmp(rmn , rmx , S.mn , S.mx) ;
}
void upd_ans() {
    if(cur_e && cmp(ans.first , ans.second , cur_e , cur_v) && cmp(rmn , rmx , S.mn , S.mx)) {
        // printf("in upd %d %d\n" , cur_e , cur_v) ;
        ans = {cur_e , cur_v} ;
    }
}
void dfs(int u) {
    cc++;
    if(u == n + 1) {
        return ;
    }
    if(cur_e && ans.first) {
        bool ff = 1;
        int ca = cur_e , cb = cur_v ;
        for(int i = u;i <= n;i++) {
            ca += E[p[i]].size() ;
            cb += 1;
            if(cmp(ans.first , ans.second , ca , cb)) {ff = 0;break ;}
        }
        if(ff) return ;
    }
    choose(u) ;

    upd_ans() ;

    dfs(u + 1) ;
    dchoose(u) ;

    dfs(u + 1) ;
    return ;
    ///
}
int main() {
    freopen("in.txt","r",stdin) ;
    cin >> n >> m >> rmn >> rmx >> k;
    for(int i = 1;i <= n;i++) cin >> c[i] ;
    for(int i = 1;i <= m;i++)  {
        int u , v ; cin >> u >> v;
        if(u != v) E[u].push_back(v) , E[v].push_back(u) ;
        else E[u].push_back(u) ;
    }
    for(int i = 1;i <= n;i++) p[i] = i;
    sort(p + 1 , p + n + 1, [&](int u,int v) {return E[u].size() > E[v].size() ;}) ;

    S.num[0] = k;
    dfs(1) ;
    cout << ans.first <<' ' << ans.second << '\n' ;
    cerr << "total " << cc << '\n' ;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(0) ;
const int rt0 = 300; //inside ratio
const int rt1 = 70; //outside ratio
int c[100005];
typedef pair<int,int> pii;
int p[100005];
bool check(vector<int>& col,int rmn,int rmx) {
    for(int i = col.size() - 1;i >= 1;i--) col[i] -= col[i - 1];
    sort(col.begin() , col.end()) ;
    // cerr << col[0] <<' ' << col.back() << '\n' ;
    if(1LL * col.back() * rmn < 1LL * col[0] * rmx) return 0;
    return 1;
}
pii gen(int n,int rmn,int rmx,int n0,int k) { ///总点数，比例要高于rmx/rmn，plant的点数是n0，总共k种颜色
    vector<pii> Ed;
    for(int i = 1;i <= n;i++) p[i] = i;
    for(int i = 1;i <= n;i++) swap(p[i] , p[rnd()%i + 1]) ;
    vector<int> col(k) ;
    while(check(col , rmn , rmx)) {
        int mn = rnd()%(n0 / k) + 1;
        for(int i = 0;i < k;i++) col[i] = rnd()%(n0 - (k - 1) * mn) + 1;
        sort(col.begin() , col.end()) ;
        for(int i = 0;i < k;i++) col[i] += i * mn ;
    }
    // cerr << "OJK\n";
    for(int i = 1;i <= n0;i++) {
        for(int j = 1;j < col.size();j++) swap(col[j] , col[rnd()%j]) ;
        int cnt = 0;
        for(int j = 0;j < col.size();j++) {
            for(int k = cnt ; k <= cnt + col[j] - 1;k++) c[p[k]] = j + 1;
            cnt += col[j];
        }
    }
    for(int i = n0 + 1;i <= n;i++) c[p[i]] = rnd()%k + 1;
    int ans_cnt = 0;
    for(int i = 1;i <= n0;i++) {
        for(int j = i + 1 ; j <= n0;j++) {
            if(rnd()%1000 <= rt0) Ed.push_back({p[i] , p[j]}) , ans_cnt++;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = max(i + 1 , n0 + 1) ; j <= n;j++) {
            if(rnd()%1000 <= rt1) Ed.push_back({p[i] , p[j]}) ;
        }
    }
    printf("%d %d %d %d %d\n",n,Ed.size(),rmn,rmx,k);
    for(int i = 1;i <= n;i++) printf("%d ",c[i]) ; printf("\n") ;
    for(auto [u,v] : Ed) printf("%d %d\n",u,v) ;
    return {ans_cnt , n0} ;
}
int main() {
    for(int i = 1;i <= 10;i++) {
        string s = "input" + to_string(i) + ".txt" ;
        freopen(s.c_str() , "w",stdout) ;
        int n = 2e3 , rmn = 1 , rmx = 3 , n0 = 1e3 , k = 20;
        auto [u,v] = gen(n,rmn,rmx,n0,k);
        s = "output" + to_string(i) + ".txt";
        freopen(s.c_str() , "w" , stdout) ;
        printf("%d %d\n",u,v);
    }
}
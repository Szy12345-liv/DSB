#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> vec;
void ins(int u,int v) {
    if(u > v) swap(u , v);
    vec.push_back({u , v}) ;
}
int n , m;
bool ok[3];
void test(bool x,int i) {
    ok[i] &= x;
}
int main() {
    ios::sync_with_stdio(false) ; cin.tie(0) ;
    for(int i = 15;i <= 15;i++){
        string s = "graph" + to_string(i) + ".txt" ;
        freopen(s.c_str() , "r" , stdin) ;
        cin >> n >> m;ok[0] = ok[1] = ok[2] = 1; vec.clear() ;
        for(int j = 1;j <= m;j++) {
            int u , v;cin >> u >> v;
            test(1 <= u && u <= n , 0);
            test(1 <= v && v <= n , 0);
            test(u != v , 1);
            ins(u , v);
            if(j % 10000000 == 0) printf("ok %d\n",j);
        }
        sort(vec.begin() , vec.end()) ;
        for(int i = 1;i < vec.size();i++) test(vec[i] != vec[i - 1] , 2) ;
        if(ok[0] && ok[1] && ok[2]) printf("GRAPH %d OK\n",i) ;
        else {
            printf("GRAPH %d \n",i) ;
            if(!ok[0]) printf("Nodes out of range ");
            if(!ok[1]) printf("Self loops ");
            if(!ok[2]) printf("Multiple Edges ");
            printf("\n");
        }
    }
}
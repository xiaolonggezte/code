#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

#define clr(x,y) memset(x,y,sizeof x)
typedef long long ll;
const int maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n,m,k;
vector<int>g[maxn];
typedef pair<int,int> P;
typedef pair<ll,P> PP;
ll d[maxn][12];
void dijstra() {
    priority_queue<PP,vector<PP>,greater<P> > q;
    q.push(PP(d[1][0] = 0,P(1,0)));
    while(! q.empty()) {
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    int Tcase;cin >> Tcase;
    while(Tcase --) {
        cin >> n >> m >> k;
        for(int i = 0;i <= n;i ++) {
            g[i].clear();
        }
        for(int i = 1;i <= m;i ++) {
            int x,y;cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dijstra();
    }
    return 0;
}
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
const int maxn = 1000 + 100;
const ll Mod = 1e9 + 7;
#define INF 0x3f3f3f3f

bool vis[maxn];
int n,m,u,v;
vector<int> g[maxn];
int in[maxn],out[maxn];
void dfs(int u,int f) {
    vis[u]=1;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(f==v||vis[v]) continue;
        dfs(v,u);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;++i) {
        memset(vis,0,sizeof(vis));
        dfs(i,0);
        for(int j=1;j<=n;++j) {
            if(vis[j]) out[i]++,in[j]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) {
        if(out[i]>in[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10000000 + 10;
typedef long long ll;
bool vis[maxn];
int len;
int main() {
    ios::sync_with_stdio(false);
    int x;
    memset(vis,false,sizeof(vis));
    while(cin >> x) {
        if(vis[x]) {
            cout << x << endl;
        }
        vis[x] = true;
    }
    
    return 0;
}
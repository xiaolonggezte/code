#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<cmath>
#include<queue>
using namespace std;

#define clr(x,y) memset(x,y,sizeof x)
typedef long long ll;
const int maxn = 1e5 + 2;
const ll Mod = 1e9 + 7;
#define INF 0x3f3f3f3f

ll a[maxn];
ll p[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    ll temp = 1;
    int ans = 0;
    while(k) {
        if(k & 1) {
            ans += temp;
        }
        temp *= n;
        k >>= 1;
    }
    cout << ans << endl;
    return 0;
}
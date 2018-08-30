#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<cstring>
using namespace std;
const int maxn = 2000 + 10;
typedef long long ll;

char s[maxn];
int a[maxn];
int get(int l,int r) {
    // cout << l << " -> " << r << endl;
    int ret = 0;
    for(int i = l;i <= r;i ++) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}
int fun() {
    int len = strlen(s);
    int cnt = 0;
    for(int i = 0;i < len;i ++) {
        if(i == len - 1 || s[i + 1] == ' ') {
            for(int j = i;j >= 0;j --) {
                if(j == 0 || s[j - 1] == ' ') {
                    a[++ cnt] = get(j,i);
                    break;
                }
            }
        }
    }
    return cnt;
}

int n,h;

bool check(int x) {
    int cnt = 0;
    for(int i = 1;i <= n;i ++) {
        cnt += a[i] / x + (a[i] % x == 0 ? 0 : 1);
    }
    return cnt <= h;
}

int solve() {
    int ret = -1;
    int l = 1,r = 0;
    for(int i = 1;i <= n;i ++) {
        r = max(r,a[i]);
    }
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ret = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ret;
}
int main() {
    gets(s);
    n = fun();
    cin >> h;
    int ans = solve();
    cout << ans << endl;
    return 0;
}
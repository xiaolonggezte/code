#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

int a[maxn];
ll sum = 0;
int n,k;
bool check(int x) {
    ll t1 = 0,t2 = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] > x) {
            t1 += a[i] - x;
        } else {
            t2 += x - a[i];
        }
    }
    if(t1 >= t2) {
        return true;
    }
    return false;
}
bool check2(int x) {
    ll t1 = 0,t2 = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] > x) {
            t1 += a[i] - x;
        } else {
            t2 += x - a[i];
        }
    }
    // cout << x << " -> " << t1 << " " << t2 << endl;
    if(t1 >= t2 && t1 - t2 <= k) {
        return true;
    }
    return false;
}
int find1(int maxs) {
    int ret = 0;
    int l = 0,r = maxs;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ret = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ret;
}
int find2(int maxs) {
    int ret = 0;
    int l = 0,r = maxs;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check2(mid)) {
            ret = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int maxs = 0;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        sum += a[i];
        maxs = max(maxs,a[i]);
    }
    int R = find1(maxs);
    cout << R -  << endl;
    return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10;
typedef long long ll;
struct Node {
    int x,y;
    int pos;
}a[maxn];
int ans[maxn];
bool cmp(Node t1,Node t2) {
    return t1.x < t2.x;
}
set<int> se[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i].x >> a[i].y;
        a[i].pos = i;
    }
    sort(a + 1,a + n + 1,cmp);
    for(int i = n;i >= 1;i --) {
        se[i].insert(i);
        for(int j = i + 1;j <= n;j ++) {
            if(a[j].x > a[i].x + a[i].y - 1) {
                break;
            }
            for(set<int>::iterator it = se[j].begin();it != se[j].end();it ++) {
                se[i].insert(*it);
            }
        }
        ans[a[i].pos] = se[i].size();
    }
    for(int i = 1;i <= n;i ++) {
        if(i < n) {
            cout << ans[i] << " ";
        } else {
            cout << ans[i] << endl;
        }
    }
}
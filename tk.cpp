#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct Node{
    int x,y;
}a[maxn];
bool cmp(Node p1,Node p2) {
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; 
}
int temp[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1,a + n,cmp);
    int len = 0;
    temp[len ++] = a[1].y;
    for(int i = 2;i <= n;i ++) {
        if(a[i].y >= temp[len - 1]) {
            temp[len ++] = a[i].y;
            continue;
        } else {
            int pos = upper_bound(temp,temp + len,a[i].y) - temp;
            temp[pos] = a[i].y;
        }
    }
    cout << len << endl;
    return 0;
}

/*

5
2 2 
2 4
3 3
2 5
4 5
*/
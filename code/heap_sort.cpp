#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

void rejust(int n,int *a) {
    
    int pos = 1;
    while(pos <= n) {
        int l = pos * 2,r = l + 1;
        if(l > n) {
            break;
        }
        if(l <= n && r <= n) {
            if(a[pos] >= max(a[l],a[r])) {
                break;
            }
            if(a[l] > a[r]) {
                swap(a[l],a[pos]);
                pos = l;
            } else {
                swap(a[r],a[pos]);
                pos = r;
            }
        } else {
            if(a[pos] >= a[l]) {
                break;
            }
            swap(a[l],a[pos]);
            break;
        }
    }
}
void heap_sort(int* a) {
    for(int i = maxn - 1;i > 1;i --) {
        swap(a[1],a[i]);
        // cout << i << " " << a[i] << endl;
        rejust(i - 1,a);
    }
}
void heap_build(int* a) {
    for(int i = maxn - 1;i > 1;i --) {
        if(a[i] > a[i / 2]) {
            swap(a[i],a[i / 2]);
        }
    }
}
int main() {

    int a[maxn];
    for(int i = 1;i < maxn;i ++) {
        a[i] = maxn - i;
    }
    heap_build(a);
    heap_sort(a);
    for(int i = 1;i < maxn;i ++) {
        printf("%d%c",a[i],i < maxn - 1 ? ' ' : '\n');
    }
    return 0;
}
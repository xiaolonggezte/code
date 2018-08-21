#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
/**
 * 实现堆排序
 * 思路：建一个大顶堆，然后每次从堆顶放出一个和当前要排序的数组的最后一个进行交换，然后调整堆
 * 需要n次取出次i大的值，每次的复杂度为logn，所以总的复杂度为nlogn
 */
int a[maxn];
//调整堆
void rejust(int n) {
    int rt = 1;
    while(rt <= n) {
        int l = rt << 1,r = rt << 1|1;
        if(l <= n && r <= n) {
            if(a[l] > a[r]) {
                swap(a[rt],a[l]);
                rt = l;
            } else if(a[r] > a[rt]){
                swap(a[rt],a[r]);
                rt = r;
            } else {
                break;
            }
        } else if(l <= n && a[l] > a[rt]) {
            swap(a[rt],a[l]);
            rt = l;
        } else if(r <= n && a[r] > a[rt]) {
            swap(a[rt],a[r]);
            rt = r;
        } else {
            break;
        }
    }
}
void sorts(int n) {
    for(int i = 1;i <= n - 1;i ++) {
        swap(a[1],a[n + 1 - i]);
        rejust(n - i);
    }
}
int main() {
    int n = 100;
    for(int i = 1;i <= n;i++) {
        a[i] = n + 1 - i;
    }
    //建一下堆
    for(int i = n;i >= 2;i --) {
        if(a[i] > a[i/2]) {
            swap(a[i],a[i/2]);
        }
    }
    sorts(n);
    for(int i = 1;i <= n;i ++) {
        printf("%d%c",a[i],i < n ? ' ' : '\n');
    }
    return 0;
}
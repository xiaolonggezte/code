#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];


void sorts(int l,int r) {
    if(l >= r) {
        return;
    }
    int i = l,j = r;
    int top = a[i];
    while(i < j) {
        while(a[j] >= top && j > i)j --;
        a[i] = a[j];
        while(a[i] <= top && j > i)i ++;
        a[j] = a[i];
    }
    a[i] = top;
    sorts(l,i - 1);
    sorts(i + 1,r);
}
int main(){
    int n = maxn - 3;
    for(int i = 1;i <= n;i ++) {
        a[i] = n - i;
    }
    sorts(1,n);
    for(int i = 1;i <= n;i ++) {
        cout << a[i] << " ";
    }
    puts("");
    return 0;
}
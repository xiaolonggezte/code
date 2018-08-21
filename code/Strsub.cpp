#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 1e6 + 10;
char s1[maxn],s2[maxn];
int Next[maxn];

/**
 * KMP
 * https://www.luogu.org/problemnew/show/P3375
*/
vector<int>ans;
void getNext(char s[]) {
    int len = strlen(s);
    Next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < len) {
        if(k == -1 || s[j] == s[k]) {
            Next[++ j] = ++ k;
        } else {
            k = Next[k];
        }
    }
    
}

void KMP(char s[],char t[]) {
    int len1 = strlen(s),len2 = strlen(t);
    getNext(t);
    int i = 0,j = 0;
    while(i < len1) {
        if (j == -1 || s[i] == t[j]) {
            i ++;
            j ++;
        } else {
            j = Next[j];
        }
        if (j == len2) {
            ans.push_back(i - len2);
            j = Next[j];//匹配多次，如果匹配一次的话直接break
        }
    }
}
int main() {
    while( cin >> s1 >> s2 ) {
        ans.clear();
        //KMP算法
        KMP(s1,s2);
        for(int i = 0;i < (int)ans.size();i ++) {
            cout << ans[i] + 1 << endl;
        }
        int len2 = strlen(s2);
        for(int i = 0;i < len2;i ++) {
            printf("%d%c",Next[i + 1],i < len2 - 1 ? ' ' : '\n');
        }
    }
    
    return 0;
}
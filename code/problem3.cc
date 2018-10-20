#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

class TreeNode {
    public:
    TreeNode(int _x) {
        x = _x;
        flag = false;
        l = r = NULL;
    }
    int x;
    bool flag;
    TreeNode *l,*r;
};

TreeNode* solve(TreeNode *rt,TreeNode *L ,TreeNode *R) {
    if(rt == L || rt == R || rt == NULL) {
        return rt;
    }
    
    int LL = solve(rt -> l,L,R);
    int RR = solve(rt -> r,L,R);
    
    if(LL && RR) {
        return rt;
    } else if(LL && RR == NULL) {
        return LL;
    } else if(LL == NULL && RR) {
        return RR;
    } else {
        return NULL;
    }


}
char s[maxn];
int dp[maxn];
int main() {

    cin >> s + 1;
    int len = strlen(s + 1);
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i <= len;i ++) {
        for(int j = max(0,  ))
    }
    return 0;
}
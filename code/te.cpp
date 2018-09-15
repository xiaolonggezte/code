#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

#define clr(x,y) memset(x,y,sizeof x)
typedef long long ll;
const int maxn = 2000000 + 2;
const ll Mod = 1e9 + 7;
#define INF 0x3f3f3f3f

char s[maxn];
char ss[maxn];
int cnt[maxn];
int pos[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int len = strlen(s);
    int t = 0;
    for(int i = 0;i < len;i ++) {
        if(i == len - 1) {
            cnt[++ t] = 1;
            ss[t] = s[i];
            pos[t] = i;
            break;
        }
        for(int j = i + 1;j < len;j ++) {
            if(s[j] != s[i]) {
                cnt[++ t] = j - i;
                pos[t] = i;
                ss[t] = s[i];
                i = j - 1;
                break;
            } else if(j == len - 1) {
                cnt[++ t] = j - i + 1;
                ss[t] = s[i];
                pos[t] = i;
                i = len;
                break;
            }
        }
    }
    int ans = -1,poss = -1;
    for(int i = 1;i <= t - 2;i ++) {
        if(cnt[i] == cnt[i + 2] && cnt[i] * 2> cnt[i + 1]) {
            if(cnt[i] + cnt[i + 1] + cnt[i + 2] > ans) {
                ans = cnt[i] + cnt[i + 1] + cnt[i + 2];
                poss = i;
            }
        }
    }
    if(ans == -1) {
        puts("NULL");
    } else {
        // for(int i = 1;i <= t;i ++) {
        //     cout << ss[i] << " " << cnt[i] << endl;
        // }
        // cout << ans << " " << poss << " " << pos[poss] << endl;
        for(int i = pos[poss];i <= pos[poss] + ans - 1;i ++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
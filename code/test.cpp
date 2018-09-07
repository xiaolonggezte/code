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
const int maxn = 1000 + 2;
const ll Mod = 1e9 + 7;

#include<iostream>
#include<cstdio>
using namespace std;
char s[maxn];
int main()
{
    int m,a[200005],n;
    while(cin >> s)
    {
        int len = strlen(s);
        int m = 0;
        int sum=0;
        int x = 0;
        for(int i = 1;i < len;i ++) {
            if(s[i] == ',' || i == len - 1) {
                a[m ++] = x;
                x = 0;
            }
            x = x * 10 + s[i] - '0';

        }

        
         int t;
         for(int i=0;i<m;i++)
         {
             t=sum^a[i];
             if(t<=a[i])
                cout<<t<<endl;
         }
    }
    return 0;
}

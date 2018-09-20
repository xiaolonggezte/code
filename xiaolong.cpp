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
const int maxn = 1000 + 100;
const ll Mod = 1e9 + 7;
#define INF 0x3f3f3f3f



vector<string> evaluateActions(vector<string> actions) {
    string temp[10];
    map<string,int>person,place;
    string persions[1000],places[1000];
    int ans[1000];
    int support[1000];
    int per_cnt = 0,place_cnt = 0;
    memset(ans,0,sizeof(ans));
    memset(support,-1,sizeof(support));
    int now[1000],to[1000];
    for(int i = 0;i < (int)actions.size();i ++) {
        string s = actions[i];
        string t = "";
        int k = 0;
        for(int j = 0;j < s.size();j ++) {
            if(s[j] == ' ') {
                temp[++ k] = t;
                t = "";
            } else if(j == s.size() - 1) {
                t += s[j];
                temp[++ k] = t;
                break;
            } else {
                t += s[j];
            }
        }
        if(k == 3) {
            if(person[temp[1]] == 0) {
                person[temp[1]] = ++ per_cnt;
                persions[per_cnt] = temp[1];
            }
            if(place[temp[2]] == 0) {
                place[temp[2]] = ++ place_cnt;
                places[place_cnt] = temp[2];
            }
            now[person[temp[1]]] = to[person[temp[1]]] = place[temp[2]];
        } else if(k == 4 && temp[3] == "Move") {
            if(person[temp[1]] == 0) {
                person[temp[1]] = ++ per_cnt;
                persions[per_cnt] = temp[1];
            }
            if(place[temp[2]] == 0) {
                place[temp[2]] = ++ place_cnt;
                places[place_cnt] = temp[2];
            }
            if(place[temp[4]] == 0) {
                place[temp[4]] = ++ place_cnt;
                places[place_cnt] = temp[4];
            }
            now[person[temp[1]]] = place[temp[2]];
            to[person[temp[1]]] = place[temp[4]];
        } else if(k == 4 && temp[3] == "Support") {
            if(person[temp[1]] == 0) {
                person[temp[1]] = ++ per_cnt;
                persions[per_cnt] = temp[1];
            }
            if(person[temp[4]] == 0) {
                person[temp[4]] = ++ per_cnt;
                persions[per_cnt] = temp[4];
            }
            if(place[temp[2]] == 0) {
                place[temp[2]] = ++ place_cnt;
                places[place_cnt] = temp[2];
            }
            now[person[temp[1]]] = to[person[temp[1]]] = place[temp[2]];
            support[person[temp[1]]] = person[temp[4]];
        }
    }
    int in[1000],out[1000];
    int vis[1000];
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    for(int i = 1;i <= per_cnt;i ++) {
        if(now[i] != to[i]) {
            vis[to[i]] = true;
        }
    }
    for(int i = 1;i <= per_cnt;i ++) {
        if(vis[now[i]]) {
            support[i] = -1;
        }
        if(support[i] != -1) {
            in[support[i]] ++;
        }
    }
    vector<string>ret;
    for(int i = 1;i <= per_cnt;i ++) {
        
        if( (vis[now[i]] || vis[to[i]]) && in[i] == 0) {
            string tt = persions[i] + "[dead]";
            ret.push_back(tt);
        } else if(now[i] == to[i]) {
            string tt = persions[i] + places[now[i]]; 
            ret.push_back(tt);
        } else {
            string tt = persions[i] + places[to[i]]; 
            ret.push_back(tt);
        }
    }
    return ret;
}

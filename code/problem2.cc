#include<bits/stdc++.h>
using namespace std;
/**
 * 层次遍历二叉树，要求输出NULL
 */ 
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
void solve(TreeNode *rt) {
    queue<TreeNode* >q;
    q.push(rt);
    TreeNode* temp = new TreeNode(-1);
    temp -> flag = true;
    q.push(temp);
    while(!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if(t == NULL) {
            cout << "NULL ";
        } else if(t -> flag) {
            cout << endl;
            if(! q.empty())  {
                q.push(temp);
            } 
        } else {
            cout << (t -> x) << " ";
            q.push(t -> l);
            q.push(t -> r);
        }
    }
}
int main() {
    TreeNode *a[1000];
    for(int i = 1;i <= 100;i ++) {
        a[i] = new TreeNode(i);
    }
    for(int i = 1;i <= 100;i ++) {
        int l = i * 2,r = l + 1;
        if(l <= 100) {
            a[i] -> l = a[i * 2];
        }
        if(r <= 100) {
            a[i] -> r = a[r];
        }
    }
    
    solve(a[1]);
    return 0;
}

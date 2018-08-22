#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Node {
    public:
    Node(int _x) {
        this -> x = _x;
        left = right = NULL;
    }
    int x;
    Node *left,*right;
};
int is_balance(Node * rt) {
    if(rt == NULL) {
        return 0;
    }
    cout << (rt -> x) << endl;
    int cntL = is_balance(rt -> left);
    int cntR = is_balance(rt -> right);
    if(cntL == -1 || cntR == -1 || abs(cntL - cntR) > 1) {
        return -1;
    }
    return max(cntL,cntR) + 1;
}
int main() {
    //构造平衡树
    Node *root = new Node(1);
    Node *tree[20];
    for(int i = 2;i <= 7;i ++) {
        tree[i] = new Node(i);
    }
    root -> left = tree[2];
    root -> right = tree[3];
    tree[2] -> left = tree[4];
    tree[2] -> right = tree[5];
    tree[3] -> left = tree[6];
    tree[3] -> right = tree[7];

    //运行
    int ans = is_balance(root);
    if(ans == -1) {
        puts("No balance");
    } else {
        puts("Balance");
    }
    return 0;
}
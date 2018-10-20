#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e1 + 10;
/**
 * 链表反转
 */

class Node{  
    public:
    Node(int _x) {
        x = _x;
        next = NULL;
    }
    int x;
    Node *next;
};
Node *a[maxn];
void print(Node *p) {
    while(p) {
        // cout << p << " -- " << (p -> next) << endl;
        // cout << (p -> x) << " -> " << (p -> next -> x) << endl;
        // p = p -> next;
        cout << (p -> x) <<  (p -> next != NULL ? ' ' : '\n');
        p = p -> next;
    }
}
Node* reverse_solve(Node* rt) {
    if(rt == NULL || rt -> next == NULL) {
        return rt;
    }
    Node* ret = rt,*p = rt -> next;
    while(p) {
        Node *t = p -> next;
        p -> next = ret;
        ret = p;
        rt -> next = t;        
        p = t;
    }
    return ret;
}


int main() {
    for(int i = 1;i < maxn;i ++) {
        a[i] = new Node(maxn - i);
        if(i > 1) {
            a[i - 1] -> next = a[i];
        }
    }
    Node* ans = reverse_solve(a[1]);
    print(ans);
    return 0;
}
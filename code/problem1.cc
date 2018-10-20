#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
class Node {
    
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
        cout << (p -> x) <<  (p -> next != NULL ? ' ' : '\n');
        p = p -> next;
    }
}

Node* solve(Node *rt) {
    if(rt == NULL || rt -> next == NULL) {
        return rt;
    }
    Node* p = rt;
    Node *ret = NULL,*q = NULL;
    while(true) {
        Node* temp = new Node(p -> x);
        if(ret == NULL) {
            ret = q = temp;
        } else {
            q -> next = temp;
            q = q -> next;
        }
        if(p -> next == NULL || p -> next -> next == NULL) {
            break;
        }
        p = p -> next -> next;
    }
    // print(ret);
    p = rt -> next;
    while(p) {
        q = ret;
        while(true) {
            if(q -> x <= p -> x && (q -> next == NULL || q -> next -> x > p -> x)) {
                Node *temp = new Node(p -> x);
                Node *t = q -> next;
                q -> next = temp;
                temp -> next = t;
                break;
            }
            q = q -> next;
        }
        if(p -> next == NULL || p -> next -> next == NULL) {
            break;
        }
        p = p -> next -> next;
    }
    
    return ret;
}
int main() {
    for(int i = 1;i < maxn;i ++) {
        if(i & 1) {
            a[i] = new Node(i);
        } else {
            a[i] = new Node(maxn - i);
        }
        if(i > 1) {
            a[i - 1] -> next = a[i];
        }
    }
    Node* ans = solve(a[1]);
    Node *p = ans;
    cout << (ans -> x) << endl;
    while(p) {
        if(p -> next) {
            cout << (p -> x) << " ";
        } else {
            cout << (p -> x) << endl;
        }
        p = p -> next;
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 反转链表
 */
struct Node {
    Node(int _x) {
        x = _x;
        next = NULL;
    }
    int x;
    Node *next;
};
Node* reverse(Node *root) {
    if(root == NULL || root -> next == NULL) {
        return root;
    }
    Node *p = root -> next;
    Node *first = root;
    while(p) {
        Node *temp = p -> next;
        p -> next = first;
        first = p;
        root -> next = temp;
        p = temp;
    }
    return first;
}
int main() {
    Node *first;
    Node *p;
    for(int i = 1;i <= 10;i ++) {
        Node *temp = new Node(i);
        if(i == 1) {
            first = temp;
            p = temp;
        } else {
            p -> next = temp;
            p = p -> next;
        }
    }
    Node * root = reverse(first);
    p = root;
    while(p) {
        cout << (p -> x) << endl;
        p = p -> next;
    }
    return 0;
}
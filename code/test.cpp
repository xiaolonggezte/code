#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
/**
 * 链表判环
 * 1.判断是否有环
 * 2.找出环的入口地址
 * 推理：
 * 假设：快指针跑了2s的距离，慢指针跑了s的距离（相同时间，速度一半）
 * r为环的长度，a为开始节点到环入口处的距离，x为环入口到相遇点的距离，t为r - x
 * 2s - s = s =n * r
 * a + x = n * r 
 * a = (n - 1) * r + (r - x)
 * a = (n - 1) * r + t
 * 所以从表头到入口点的距离，等于从相遇点继续遍历又到表头的距离
 * 从表头设立一个指针，从相遇点设立一个指针，两个同时移动，必然能够在入口点相遇，这样，就求出了相遇点。
 */

struct ListNode {
    ListNode(int x) {
        this -> x = x;
        this -> next = NULL;
    }
    int x;
    ListNode *next;
};
//判断是否有环
ListNode* is_circle(ListNode *root) {
    ListNode *p1 = root,*p2 = root;
    p1 = p1 -> next;
    if(p2 -> next -> next == NULL) {
        return NULL;
    }
    p2 = p2 -> next -> next;
    while(p1 -> next && p2 -> next -> next) {
        if(p1 == p2) {
            p2 = root;
            while(p1 && p2) {
                if(p1 == p2) {
                    return p1;
                }
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
            break;
        }
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }
    return NULL;
} 
ListNode * list[20];
int main() {
    
    for(int i = 1;i <= 10;i ++) {
        list[i] = new ListNode(i);
    }
    //构造一个有环的链表
    
    for(int i = 1;i < 10;i ++) {
        list[i] -> next = list[i + 1];
    }
    list[10] -> next = list[5];
    ListNode *circle = is_circle(list[1]);
    if(circle == NULL) {
        cout << "没有环" << endl;
    } else {
        cout << "存在环，环的入口处在节点 " << (circle -> x) << endl;
    }
    return 0;
}


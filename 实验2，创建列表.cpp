#include <iostream>
using namespace std;

// 定义链表节点
struct Node {
    int data;
    Node* next;
};

int main() {
    int num;
    Node* head = nullptr;  // 链表头指针
    Node* tail = nullptr;  // 链表尾指针

    while (cin >> num && num != -1) {
        // 创建新节点
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;

        // 将新节点加入链表
        if (head == nullptr) {
            head = newNode;  // 第一个节点
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 遍历链表输出
    if (head == nullptr) {
        cout << -1;
    } else {
        Node* p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
    }

    // 释放链表内存
    Node* p = head;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}

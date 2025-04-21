#include<iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

// 创建链表
node* createList()
{
    int x;
    node* head = NULL;  // 链表头
    node* tail = NULL;  // 用于插入新节点的尾部指针

    while (cin >> x)  // 一直输入直到遇到-1
    {
        if (x == -1) break;  // 输入-1时终止输入

        node* newNode = new node;  // 创建新节点
        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;  // 第一个节点
        }
        else
        {
            tail->next = newNode;  // 将新节点连接到尾部
        }
        tail = newNode;  // 更新尾部指针
    }
    return head;  // 返回头指针
}

// 反转链表
node* reverseList(node* head)
{
    node* prev = NULL;
    node* curr = head;

    while (curr != NULL)
    {
        node* nextNode = curr->next;  // 保存下一个节点
        curr->next = prev;            // 当前节点指向前一个节点
        prev = curr;                  // 前移
        curr = nextNode;              // 后移
    }
    return prev;  // prev是反转后的链表的头节点
}

int main()
{
    node* head = NULL;
    head = createList();  // 创建链表

    node* head1 = NULL;
    head1 = reverseList(head);  // 反转链表

    if (head1 == NULL)
    {
        cout << "-1 ";  // 如果链表为空，输出-1
    }
    else
    {
        node* p = head1;
        while (p != NULL)
        {
            cout << p->val << " ";  // 输出链表的值
            p = p->next;
        }
    }

    return 0;
}

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

// 删除链表中所有值为v的节点
node* deleteElements(node* head, int v)
{
    node* dummy = new node;  // 创建虚拟头节点
    dummy->next = head;
    node* current = dummy;

    while (current->next != NULL)
    {
        if (current->next->val == v)
        {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;  // 删除节点
        }
        else
        {
            current = current->next;  // 移动到下一个节点
        }
    }

    node* newHead = dummy->next;
    delete dummy;  // 删除虚拟头节点
    return newHead;
}

int main()
{
    node* head = NULL;
    head = createList();  // 创建链表

    int v;
    cin >> v;  // 读取要删除的元素

    head = deleteElements(head, v);  // 删除元素

    if (head == NULL)
    {
        cout << "-1 ";  // 如果链表为空，输出-1
    }
    else
    {
        node* p = head;
        while (p != NULL)
        {
            cout << p->val << " ";  // 输出链表的值
            p = p->next;
        }
    }

    return 0;
}

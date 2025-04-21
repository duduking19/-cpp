#include<iostream>
using namespace std;
struct node
{
int val;
node* next;
node(int x=0):val(x),next(nullptr){}
};
node* createList()
{ 
    node*dummy=new node(0);
    node*cur=dummy;
    int x;
    while(cin>>x && x !=-1){
        cur->next=new node(x);
        cur=cur->next;
    }
    node* head =dummy->next;
    delete dummy;
    return head;
}
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
head = createList();
int v;
cin >> v;
head = deleteElements(head, v);
if (head == NULL)
{
cout << "-1 ";
}
else
{
node* p = head;
while (p != NULL)
{
cout << p->val << " ";
p = p->next;
}
}
return 0;
}
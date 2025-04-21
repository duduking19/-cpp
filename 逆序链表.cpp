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
   node* dummy=new node(0);
   node* cur=dummy;
   int x;
   while(cin>>x && x !=-1){
    cur->next=new node(x);
    cur=cur->next;
   }
   node* head=dummy->next;
   delete dummy;
   return head;
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
head = createList();
node* head1 = NULL;
head1 = reverseList(head);
if (head1 == NULL)
{
cout << "-1 ";
}
else
{
node* p = head1;
while (p != NULL)
{
cout << p->val << " ";
p = p->next;
}
}
return 0;
}
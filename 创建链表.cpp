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
int main()
{
node* head = NULL;
head = createList();
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
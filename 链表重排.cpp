#include <iostream>
using namespace std;
struct ListNode
{
int val;
ListNode* next;
ListNode(int x=0):val(x),next(nullptr){}
};
ListNode* createList()
{
   ListNode*dummy=new ListNode(0);
   ListNode*cur=dummy;
   int x;
   while(cin>>x && x !=-1){
    cur->next=new ListNode(x);
    cur=cur->next;
   }
   ListNode*head=dummy->next;
   delete dummy;
   return head;
}

ListNode* oddEvenList(ListNode* head) 
{
   if(!head || !head->next)
   return head;
   ListNode*odd=head;
   ListNode*even=head->next;
   ListNode*evenHead=even;
   while(even && even->next){
    odd->next=even->next;
    odd=odd->next;
    even->next=odd->next;
    even=even->next;
   }
   odd->next=evenHead;
   return head;
}
int main()
{
ListNode* head;
head = createList();
ListNode* ans = oddEvenList(head);
if (ans == NULL)
cout << "-1";
else
{
while (ans != NULL)
{
cout << ans->val << " ";
ans = ans->next;
}
}
return 0;
}
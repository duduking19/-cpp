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
ListNode* mergeNodes(ListNode* head)
{ 
    ListNode*dummy=new ListNode(0);
    ListNode*cur=dummy;
    int sum=0;
    ListNode*current=head->next;
    while(current){
        if(current->val==0){
            if(sum>0){
                cur->next=new ListNode(sum);
                cur=cur->next;
                sum=0;
            }
        }
        else{
            sum+=current->val;
        }
        current=current->next;
    }
    cur->next=nullptr;
    return dummy->next;
}
int main()
{
ListNode* head;
head = createList();
ListNode* ans = mergeNodes(head);
while (ans != NULL)
{
cout << ans->val << " ";
ans = ans->next;
}
return 0;
}
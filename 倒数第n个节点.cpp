#include <iostream>
using namespace std;
struct ListNode{
int val;
ListNode* next;
ListNode(int x=0):val(x),next(nullptr){}
};
ListNode* createList(){
ListNode* dummy=new ListNode(0);
ListNode* cur=dummy;
int x;
while(cin>>x && x!=-1){
    cur->next=new ListNode(x);
    cur=cur->next;
}
ListNode*head=dummy->next;
delete dummy;
return head;
}
ListNode* getKthFromEnd(ListNode* head, int k) {
if(head == NULL || k<0){
    return NULL;
}
ListNode* fast=head;
ListNode* slow=head;
for(int i=0;i<k;i++){

    if(fast==NULL){
    return NULL;
    }
    fast=fast->next;
}
while(fast !=NULL){
    fast=fast->next;
    slow=slow->next;
}
return slow;
}
int main()
{
ListNode* head;
int k;
head = createList();
cin >> k;
ListNode* ans = getKthFromEnd(head, k);
if (ans == NULL)
cout << "-1";
else cout << ans->val;
return 0;
}
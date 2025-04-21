#include <iostream>
 using namespace std;
 struct ListNode
{
   int val;
   ListNode* next;
   ListNode(int x=0):val(x),next(nullptr){}
};

 ListNode* createList()
{\
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

 int isPalindrome(ListNode* head) {
     if(!head) return -1;
     if(!head->next) return 1;
     ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL)
    {
        ListNode* nextNode = curr->next;  // 保存下一个节点
        curr->next = prev;            // 当前节点指向前一个节点
        prev = curr;                  // 前移
        curr = nextNode;              // 后移
    }
    while(head && prev){
        if(head->val !=prev->val){
            return 0;
        }
        else{
            head=head->next;
            prev=prev->next;
        }
        
    }return 1;

 }

 int main() {
     ListNode* head;
     head = createList();
     int ans = isPalindrome(head);
     cout<<ans<<'\n';
     return 0;
 }

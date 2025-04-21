#include <iostream>
using namespace std;
struct node
{
int val;
node* next;
node(int x=0):val(x),next(nullptr){}
};
node* createList()
{  node*dummy=new node(0);
   node*cur=dummy;
   int x;
   while(cin>>x && x!=-1){
    cur->next=new node(x);
    cur=cur->next;
   } 
   node*head=dummy->next;
   delete dummy;
   return head;//将这个函数补充完整
}
node* merge(node* head1, node* head2)

{node*dummy=new node();
        node*t=dummy;

	while(head1 && head2){
		if(head1->val <= head2->val) {
		t->next = head1,
		head1=head1->next;}
		else{
			t->next =head2,
			head2=head2->next;
			
		}t=t->next;
	}
	t->next =head1? head1:head2;
	return dummy->next;//将这个函数补充完整

}
int main()
{
node *head1, *head2, *head3;
head1 = createList();
head2 = createList();
head3 = merge(head1, head2);
if (head3 == NULL)
{
cout << "-1 ";
}
else
{
node* p = head3;
while (p != NULL)
{
cout << p->val << " ";
p = p->next;
}
}
return 0;
}
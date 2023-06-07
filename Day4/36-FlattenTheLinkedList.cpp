/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

// Node* merge(Node *head1,Node *head2){
// 	Node* ans=head1;
// 	while(head1&&head2){
// 		if(head1->child==NULL){
// 				head1->child=head2;
// 				break;
// 		}
// 		if(head1->data<=head2->data){
// 			head1=head1->child;
// 		}
// 		else{
// 		Node *temp=head1;
// 		head1=head1->child;
// 		temp->child=head2;
// 		temp=head2;
// 		head2=head2->child;
// 		temp->child=head1;
// 		}
// 	}
// 	return ans;
// }
// Node* flattenLinkedList(Node* head) 
// {
	// Node* temp1=head;
	// Node* temp2;
	// while(temp1){
	// 	temp2=temp1;
	// 	temp1=temp1->next;
	// 	temp2->next=NULL;
	// 	while(temp2->child)temp2=temp2->child;
	// 	temp2->child=temp1;
	// }
	// return head;
// 	Node* ans=head;
// 	while(head){
// 		Node *temp=head;
// 		head=head->next;
// 		temp->next=NULL;
// 		ans=merge(ans,head);
// 	}
// 	return ans;
// 	// Write your code here
// }
//Find why the above code is giving wrong output
Node *merge(Node *first, Node *second)
{
    if (first == NULL)
    {
        second->next = nullptr;
        return second;
    }
    if (second == NULL)
    {
        first->next = nullptr;
        return first;
    }
    Node *merged = NULL;
    if (first->data < second->data)
    {
        merged = first;
        merged->child = merge(first->child, second);
    }
    else
    {
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}
Node *flattenLinkedList(Node *head)
{
  if (head == NULL || head->next == NULL) {
    return head;
  }
  head->next = flattenLinkedList(head->next);
  head = merge(head, head->next);
  return head;
}

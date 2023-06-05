/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
  Node* head=NULL;
    Node* tail=NULL;
    void insert(int data){
        if(head==NULL){
            head=new Node(data);
            tail=head;
        }
        else{
            tail->next=new Node(data);
            tail=tail->next;
        }
    }
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    //This code is written by me without any other persons help-
    int carry=0;
    while(num1&&num2){
        int data=num1->data+num2->data;
        if(data+carry<10){
            insert(data+carry);
        }
        else{
            int rem=(data+carry)%10;
            insert(rem);
        }
        carry=(data+carry)/10;
        num1=num1->next;
        num2=num2->next;
    }
    while(num1){
        int data=num1->data;
        if(data+carry<10){
            insert(data+carry);

        }
        else{
            int rem=(data+carry)%10;
            insert(rem);
        }
        carry=(data+carry)/10;
        num1=num1->next;
    }
    while(num2){
        int data=num2->data;
        if(data+carry<10){
            insert(data+carry);
        }
        else{
            int rem=(data+carry)%10;
            insert(rem);
        }
        carry=(data+carry)/10;
        num2=num2->next;
    }
    if(carry!=0)insert(carry);
    return head;
}

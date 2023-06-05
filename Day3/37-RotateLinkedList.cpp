/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     //Sovle this problem again as this is the best problem of link list which tells how to handle edge cases.
     if(head==NULL||head->next==NULL)return head;
        Node* temp;
        temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(k==length)return head;
        if(k>length)k=k%length;
        int difference=length-k-1;
        temp=head;
        temp=head;
        while(difference){
        temp=temp->next;
        difference--;
        }
        Node* tempmid=temp;
        while(temp->next!=NULL)temp=temp->next;
        //Finally doing the required operation
        temp->next=head;
        temp=tempmid->next;
        tempmid->next=NULL;
        return temp;
}

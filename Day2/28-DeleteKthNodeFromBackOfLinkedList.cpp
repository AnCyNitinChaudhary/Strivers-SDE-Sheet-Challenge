/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    //The approach which is coming in my brain is to count the total number of nodes and then delete N-Kth node from starting.
    Node *temp=NULL;
    if(head==NULL||head->next==NULL)return temp;
    int count=0;
    temp=head;
    while(temp){
        count++;
        temp=temp->next;
    }
    int startK=count-K-1;
    if(startK==-1){
        head=head->next;
        return head;
    }
    temp=head;
    while(startK--)temp=temp->next;
    temp->next=temp->next->next;
    return head;

    // Write your code here.
}

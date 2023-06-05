/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(secondHead==NULL||firstHead==NULL)return NULL;


    Node* slow=firstHead;
    while(slow->next!=NULL)slow=slow->next;
    slow->next=firstHead;
    slow=secondHead;
    Node* fast=secondHead;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        // if(slow==NULL&&fast==NULL)return 0;
        if(slow==fast)break;
    }
    if(fast==NULL||fast->next==NULL)return NULL;
    slow=secondHead;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
    
    //Write your code here
}

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    //Using Extra space
    // if(head==NULL||head->next==NULL)return true;
    //     string temp="";
    //     LinkedListNode<int>* phead=head;
    //     while(phead){
    //         temp+=(phead->data);
    //         phead=phead->next;
    //     }
    //     int i=0;
    //     int j=temp.size()-1;
    //     while(i<=j){
    //         if(temp[i]!=temp[j])return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
     //Using constant space
        //Using slow and fast pointer appraoch of two pointer method
        LinkedListNode<int>* slow=head;
        LinkedListNode<int>* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //Now reverse the linked list after slow
        LinkedListNode<int>* prev=NULL;
        LinkedListNode<int>* curr=slow;
        LinkedListNode<int>* nex=slow;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        slow=prev;
        fast=head;
        while(slow){
            if(slow->data!=fast->data)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
}

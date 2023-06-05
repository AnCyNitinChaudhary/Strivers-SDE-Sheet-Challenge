#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* head=NULL;
Node<int>* tail=NULL;
void insert(int data){
    if(head==NULL){
        head=new Node<int>(data);
        tail=head;
    }
    else{
        tail->next=new Node<int>(data);
        tail=tail->next;
    }
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    //Firstly I am going to solve this using the extra space and O(N) time
    // while(first&&second){
    //     if(first->data<=second->data){
    //         insert(first->data);
    //         first=first->next;
    //     }
    //     else{
    //         insert(second->data);
    //         second=second->next;
    //     }
    // }
    // while(first){
    //     insert(first->data);
    //     first=first->next;
    // }
    // while(second){
    //     insert(second->data);
    //     second=second->next;
    // }
    // return head;
//This second appraoch is understood by me from the striver.
    if(first==NULL)return second;
    if(second==NULL)return first;
    if(first->data>second->data)swap(first,second);
    Node<int> *ans=first;
    while(first&&second){
        Node<int> *temp=NULL;
        while(first&&first->data<=second->data){
            temp=first;
            first=first->next;
        }
        temp->next=second;
        swap(first,second);
    }
    return ans;
}

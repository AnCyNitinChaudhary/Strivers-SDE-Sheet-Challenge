#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
        //There are two approaches to solve this question-
        //1-Using unordered map and without it.
        //Using unordered map
        // unordered_map<Node*,Node*>um;
        // Node* temp=head;
        // while(temp){
        //     Node *copy=new Node(temp->val);
        //     um[temp]=copy;
        //     temp=temp->next;
        // }
        // temp=head;
        // Node *ans=um[temp];
        // while(temp){
        //     ans->next=um[temp->next];
        //     if(temp->random==NULL)ans->random=NULL;
        //     else{
        //         ans->random=um[temp->random];
        //     }
        //     temp=temp->next;
        //     ans=ans->next;
        // }
        // ans->next=NULL;
        // ans=um[temp];
        // return ans;
        //This approach is giving error
        
        //Solving in constant space
        if(head==NULL)return NULL;
        LinkedListNode<int> *temp=head;
        while(temp){
            LinkedListNode<int> *copy=new LinkedListNode<int>(temp->data);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        LinkedListNode<int> *copyhead=temp->next;
        while(temp&&temp->next){
            if(temp->random==NULL)copyhead->random=NULL;
            else{
                copyhead->random=temp->random->next;
            }
            if(temp->next!=NULL)temp=temp->next->next;
            if(copyhead->next!=NULL)copyhead=copyhead->next->next;
        }
        if(temp)temp->next=NULL;
        copyhead->next=NULL;
        temp=head;
        copyhead=temp->next;
        LinkedListNode<int> *ans=temp->next;
        while(temp){
            temp->next=copyhead->next;
            if(copyhead->next)copyhead->next=copyhead->next->next;
            temp=temp->next;
            copyhead=copyhead->next;
        }
        return ans;
}

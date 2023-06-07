#include <bits/stdc++.h>

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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    //  if(head==NULL||head->next==NULL)return head;//if the size of the Linked List is 1 or 0 then no need to do reverse.
    //     int count=0;
    //     Node* temp=head;
    //     Node* ans;
    //     //Extra pointers required to connect each group after doing reversal.
    // 	Node* prev2;
    //     Node* prev1;

    //     //The three pointers which are required for doing simple Linked list reversal.
    //     Node* prev;
    //     //curr and nex are initialized with head for first iteration
    //     Node* curr=head;
    // 	Node* nex=head;
	// 	int index=0;
    //     int counter=0;//Counter to store, How many groups got reversed
    //     while(index<n&&curr){
    //         prev=NULL;//prev is set as NULL for each iteration as we set in normal Linked List revarsal.
    //         int tempk=B[index];
	// 		if(tempk==0){
	// 			index++;
	// 			continue;
	// 		}
	// 		if(tempk==1){
	// 			index++;
	// 			prev2=curr;
	// 			curr=curr->next;
	// 			nex=curr;
	// 		}
    //         //Doing normal link list reversal of the group of size k
    //         else{
	// 			while(tempk--){
    //             nex=curr->next;
    //             curr->next=prev;
    //             prev=curr;
    //             curr=nex;
    //             if(tempk==B[index]-1)prev2=prev;//Storing in prev2 to connect with next group.
    //         }
	// 		}
	// 		index++;
    //         counter++;
    //         if(counter==1)ans=prev;//Storing the answer if counter=1
    //         else prev1->next=prev;//otherwise connect with next group.
    //         prev1=prev2; //store prev2 in prev1 as prev2 will again change in next iteration before doing connection.
    //     }
    //     //If the curr is not NULL means there must be some elemets left whose group can not be formed, so need to attach them.
    //     if(curr)prev2->next=curr;
    //     return ans;
	//Hard question and this will require a lot of dry run.
	//I will be doing this again but now I am going to take the help from the solutions.
	//The below solution is understood from coding ninjas solution and it is quite similar to the above solution.
	if (head == NULL) {
        return NULL;
    }
    int idx = 0;
    Node *prev = NULL, *cur = head, *temp = NULL;
    Node *tail = NULL, *join = NULL;
    bool isHeadUpdated = false;

    while (cur != NULL && idx < n) {
        int K = b[idx];

        if (K == 0) {
            idx++;
            continue;
        }

        join = cur;
        prev = NULL;

        while (cur != NULL && K--) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        if (isHeadUpdated == false) {
            head = prev;
            isHeadUpdated = true;
        }

        if (tail != NULL) {
            tail->next = prev;
        }

        tail = join;
        idx++;
    }

    if (tail != NULL) {
        tail->next = cur;
    }
    return head;
}

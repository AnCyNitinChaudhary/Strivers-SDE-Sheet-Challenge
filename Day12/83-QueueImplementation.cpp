#include <bits/stdc++.h> 
class Node {
public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
public:

    Node *head;
    Node *tail;
    int size;

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~Queue() {
        Node *temp = head;
        while (temp)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {

        // Increase the count of elements present in the List.
        size++;

        // Create a new node.
        Node *newNode = new Node(data);

        // Check if the Queue is empty.
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Push the element to the last of the queue.
        tail->next = newNode;
        tail = newNode;
        return;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = head->data;


        Node *tmp = head;
        head = head->next;

        // If the queue is empty make the tail pointer NULL.
        if (head == NULL) {
            tail = NULL;
        }
        delete tmp;

        size--;

        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty())  {
            return -1;
        }

        // Return the element at the front.
        return head->data;
    }
};

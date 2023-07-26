#include <queue>

class Stack {
   public:
    queue<int> *q1, *q2;

    Stack() {  
        // Constructor.
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    int getSize() {
        // Return the size of the queue 'q1'.
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {  
        // Simply enqueue data to q1.
        q1->push(data);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        // Enqueue all the elements of q1 into q2 except the last one.
        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        // Last element of q1 is our answer.
        int ans = q1->front();  
        q1->pop();

        // Swap q1 and q2.
        queue<int> *temp = q1;  
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        // Enqueue all the elements of q1 into q2 except the last one.
        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        // Last element of q1 is our answer.
        int ans = q1->front();  
        q1->pop();
        // Enqueue the top to q2.
        q2->push(ans);  

        queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
};

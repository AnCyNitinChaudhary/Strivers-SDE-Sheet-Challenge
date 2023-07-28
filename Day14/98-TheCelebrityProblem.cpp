
#include <stack>

int findCelebrity(int n) {
    stack<int> ids;
    for(int i = 0; i < n; i++) {
        ids.push(i);
    }
    while(ids.size() > 1) {
        int id1 = ids.top();
        ids.pop();
        int id2 = ids.top();
        ids.pop();
        
        if(knows(id1, id2)) {
            ids.push(id2); 
        }
        else {
            ids.push(id1); 
        }
    }
    int celebrity = ids.top();
    bool knowAny = false, knownToAll = true;
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        celebrity = -1;
    }

    return celebrity;
}

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(){
        data = -1;
        next = prev = NULL;
    }
    Node(int d){
        data = d;
        prev = next = NULL;
    }
};

class FrontMiddleBackQueue {
public:
    int curSize = 0;
    Node* list = NULL;
    Node* front = NULL;
    Node* mid = NULL;
    Node* tail = NULL;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        if(curSize == 0){
            list = new Node(val);
            front = list;
            tail = list;
            mid = list;
        }
        else{
            Node* nd = new Node(val);
            nd->next = front;
            front->prev = nd;
            front = nd;

            if(curSize % 2 != 0){
                mid = mid->prev;
            }
        }
        curSize++;
    }
    
    void pushMiddle(int val) {
        if(curSize == 0){
            list = new Node(val);
            front = list;
            tail = list;
            mid = list;
        }
        else if(curSize == 1){
            Node* nd = new Node(val);
            nd->next = mid;
            mid->prev = nd;
            mid = nd;
            front = nd;
        }
        else{
            if(curSize % 2 != 0){
                Node* nd = new Node(val);
                nd->next = mid;
                nd->prev = mid->prev;
                mid->prev->next = nd;
                mid->prev = nd;
                mid = nd;
            }
            else{
                Node* nd = new Node(val);
                nd->next = mid->next;
                nd->prev = mid;
                mid->next = nd;
                nd->next->prev = nd;
                mid = nd;
            }
        }
        curSize++;
    }
    
    void pushBack(int val) {
        if(curSize == 0){
            list = new Node(val);
            front = list;
            tail = list;
            mid = tail;
        }
        else{
            tail->next = new Node(val);
            tail->next->prev = tail;
            tail = tail->next;
            if(curSize % 2 == 0){
                mid = mid->next;
            }
        }
        curSize++;
    }
    
    int popFront() {
        if(curSize == 0){
            return -1;
        }
        int v = front->data;
        if(curSize == 1){
            list = tail = front = mid = NULL;
        }
        else{
            if(curSize % 2 == 0){
                mid = mid->next;
            }
            front = front->next;
            front->prev = NULL;
        }
        curSize--;
        return v;
    }
    
    int popMiddle() {
        if(curSize == 0) return -1;
        int v = mid->data;
        if(curSize == 1){
            list = front = mid = tail = NULL;
        }
        else if(curSize == 2){
            list = front = mid = tail = front->next;
        }
        else{
            mid->next->prev = mid->prev;
            mid->prev->next = mid->next;
            if(curSize % 2 != 0){
                mid = mid->prev;
            }
            else{
                mid = mid->next;
            }
        }
        curSize--;
        return v;
    }
    
    int popBack() {
        if(curSize == 0) return -1;
        int v = tail->data;
        if(curSize == 1){
            list = tail = front = mid = NULL;
        }
        else{
            if(curSize % 2 != 0){
                mid = mid->prev;
            }
            tail = tail->prev;
            tail->next = NULL;
        }
        curSize--;
        return v;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
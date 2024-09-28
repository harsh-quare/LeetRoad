class MyCircularDeque {
    int size;
    int rear;
    int front;
    vector<int> arr;
    int curSize;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = vector<int>(size, 0);
        front = 0;
        rear = size-1;
        curSize = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front - 1 + size) % size;
        arr[front] = value;
        curSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){  //already full h
            return false;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        curSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false; //empty array me se delete krna not possible
        front = (front + 1) % size;
        curSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear - 1 + size) % size;
        curSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(curSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(curSize == size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
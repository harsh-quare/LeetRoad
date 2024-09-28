class MyCircularDeque {
    int* arr;
    int size;
    int rear;
    int front;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool insertFront(int value) {
        if(front == (rear+1)%size) return false;
        else if(front == -1 && rear == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }

        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){  //already full h
            return false;
        }
        else if(isEmpty()) {
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else rear++;

        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false; //empty array me se delete krna not possible
        int val = arr[front];
        arr[front] = -1;
        if(front == rear) front = rear = -1; //front == rear means only single element present in the array  
        else if(front == size-1) front = 0;
        else front++;   //if(front != size-1)

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        int val = arr[rear];
        arr[rear] = -1;

        if(front == rear) front = rear = -1;
        else if(rear == 0) rear = size-1;
        else rear--;  //if(rear != 0)

        return true;
    }
    
    int getFront() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(front == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(front == (rear+1) % size) return true;
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
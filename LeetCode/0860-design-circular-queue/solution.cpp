class MyCircularQueue {
private:
    std::vector<int> queue;
    int size = 0;
    int ptr_1 = 0;
    int ptr_2 = 0;
    
    int nextIndex(int index) {
        return (index + 1) % queue.size();
    }

public:
    MyCircularQueue(int k) {
        queue.resize(k);
    }
    
    bool enQueue(int value) {
        if(ptr_1 == ptr_2 && size != 0) {
            return false;
        }
        
        queue[ptr_2] = value;
        ptr_2 = nextIndex(ptr_2);
        size++;
        return true;
    }
    
    bool deQueue() {
        if(ptr_1 == ptr_2 && size == 0) {
            return false;
        }
        
        ptr_1 = nextIndex(ptr_1);
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }

        return queue[ptr_1];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        
        return queue[(ptr_2 + (queue.size() - 1)) % queue.size()];
    }
    
    bool isEmpty() {
        return ptr_1 == ptr_2 && size == 0;
    }
    
    bool isFull() {
        return ptr_1 == ptr_2 && size > 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

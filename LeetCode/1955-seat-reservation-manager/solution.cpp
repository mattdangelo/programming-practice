class SeatManager {
    int ptr = 1;
    std::priority_queue<int, vector<int>, greater<int>> quickpool;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if(quickpool.empty()) {
            return ptr++;
        }
        else {
            int top = quickpool.top();
            if(top < ptr) {
                quickpool.pop();
                return top;
            }
            else {
                return ptr++;
            }
        }
    }
    
    void unreserve(int seatNumber) {
        quickpool.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

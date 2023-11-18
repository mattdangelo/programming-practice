class MovingAverage {
    std::queue<int> last;
    int max_size;
    int current_size;
    int current_sum;
public:
    MovingAverage(int size) {
       this->max_size = size;
       current_size = 0;
       current_sum = 0; 
    }

    double next(int val) {
        if(current_size < max_size) {
            // Incrament the size by 1
            current_size++;
        }
        else {
            // Remove the front element, the size won't change
            current_sum -= last.front();
            last.pop();
        }

        current_sum += val;
        last.push(val);

        return current_sum / (double)current_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

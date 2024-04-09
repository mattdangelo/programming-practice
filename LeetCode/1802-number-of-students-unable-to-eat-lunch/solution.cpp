class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> queue;
        for(int i : students) {
            queue.push(i);
        }

        int sandwich_ptr = 0;

        bool queue_size_changed = true;
        while(queue_size_changed) {
            queue_size_changed = false;
            for(int i=0;i<queue.size();i++) {
                if(queue.front() == sandwiches[sandwich_ptr]) {
                    queue.pop();
                    sandwich_ptr++;
                    queue_size_changed = true;
                }
                else {
                    queue.push(queue.front());
                    queue.pop();
                }
            }
        }

        return queue.size();
    }
};

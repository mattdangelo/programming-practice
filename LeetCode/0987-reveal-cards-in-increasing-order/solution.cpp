class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::sort(deck.begin(), deck.end());
        std::vector<int> new_order(deck.size(), 0);
        std::queue<int> queue;
        for(int i=0;i<deck.size();i++) {
            queue.push(i);
        }

        for(int i : deck) {
            new_order[queue.front()] = i;
            queue.pop();

            if(queue.size() > 0) {
                queue.push(queue.front());
                queue.pop();
            }
        }

        return new_order;
    }
};

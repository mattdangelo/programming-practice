class Solution {
    std::unordered_map<int, int> wins;
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()) {
            return *max_element(arr.begin(), arr.end());
        }

        std::deque<int> game(arr.size());
        game.insert(game.begin(), std::make_move_iterator(arr.begin()), std::make_move_iterator(arr.end()));

        while(true) {
            // Play a round
            int first = game.front();
            game.pop_front();

            if(first < game.front()) {
                // Move the first element we popped to the back of the queue
                game.push_back(first);
            }
            else {
                // Move the element in game.front() to the back, and reinsert first at the front
                int move_to_back = game.front();
                game.pop_front();
                game.push_front(first);
                game.push_back(move_to_back);
            }

            if(wins.count(game.front())) {
                wins[game.front()]++;
            }
            else {
                wins[game.front()] = 1;
            }

            if(wins[game.front()] >= k) {
                return game.front();
            }
        }

        return 0;
    }
};

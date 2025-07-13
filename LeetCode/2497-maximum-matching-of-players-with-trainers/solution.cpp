class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int players_ptr = 0;
        int trainers_ptr = 0;
        int count = 0;

        while(players_ptr < players.size() && trainers_ptr < trainers.size()) {
            if(trainers[trainers_ptr] >= players[players_ptr]) {
                count++;
                players_ptr++;
            }

            trainers_ptr++;
        }

        return count;
    }
};

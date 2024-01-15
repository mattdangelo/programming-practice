class Solution {
    std::unordered_map<int, int> losses;
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for(std::vector<int> match : matches) {
            if(losses.count(match[1])) {
                losses[match[1]]++;
            }
            else {
                losses[match[1]] = 1;
            }

            if(!losses.count(match[0])) {
                losses[match[0]] = 0;
            }
        }

        std::vector<int> no_losses = {};
        std::vector<int> one_loss = {};

        for(std::pair<int, int> player_losses : losses) {
            if(player_losses.second == 1) {
                one_loss.push_back(player_losses.first);
            }
            else if(player_losses.second == 0) {
                no_losses.push_back(player_losses.first);
            }
        }

        std::sort(no_losses.begin(), no_losses.end());
        std::sort(one_loss.begin(), one_loss.end());

        return {no_losses, one_loss};
    }
};
#include <iostream>
#include <vector>
#include <set>

int orangesRotting(std::vector<std::vector<int>>& grid) {
    int orange_count = 0;
    int fresh_count = 0;
    int t = 0;
    std::set<std::pair<int, int>> rotten_locations;

    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(grid[i][j] == 2) {
                orange_count++;
                rotten_locations.insert({i, j});
            }
            else if(grid[i][j] == 1) {
                orange_count++;
                fresh_count++;
            }
        }
    }

    if(fresh_count == 0) {
        return 0;
    }

    bool made_rotten = true;

    while(made_rotten) {
        std::set<std::pair<int, int>> to_rot;
        for(auto p : rotten_locations) {
            int i = p.first;
            int j = p.second;

            if(i > 0 && grid[i - 1][j] == 1) {
                to_rot.insert({i - 1, j});
            }

            if(j > 0 && grid[i][j - 1] == 1) {
                to_rot.insert({i, j - 1});
            }

            if(i < grid.size() - 1 && grid[i + 1][j] == 1) {
                to_rot.insert({i + 1, j});
            }

            if(j < grid[0].size() && grid[i][j + 1] == 1) {
                to_rot.insert({i, j + 1});
            }
        }

        made_rotten = !to_rot.empty();
        for(auto p : to_rot) {
            grid[p.first][p.second] = 2;
            rotten_locations.insert(p);
        }
        t++;
    }

    // Return t or t - 1
    return rotten_locations.size() == orange_count ? t - 1 : -1;
}

int main() {
//    std::vector<std::vector<int>> input = {
//            { 2, 1, 1 },
//            { 1, 1, 0 },
//            { 0, 1, 1 }
//    };

//    std::vector<std::vector<int>> input = {
//            { 2, 1, 1 },
//            { 0, 1, 1 },
//            { 1, 0, 1 }
//    };

    std::vector<std::vector<int>> input = {
            { 1, 2 }
    };

    std::cout << orangesRotting(input) << std::endl;
    return 0;
}
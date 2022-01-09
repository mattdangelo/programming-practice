#include <iostream>

enum direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

bool isRobotBounded(std::string instructions) {
    int x = 0;
    int y = 0;
    int dir = NORTH;

    for (int i = 0; i < 4; i++) {
        for (char c : instructions) {
            if (c != 'G') {
                switch (dir) {
                case NORTH:
                    dir = c == 'L' ? WEST : EAST;
                    break;
                case SOUTH:
                    dir = c == 'L' ? EAST : WEST;
                    break;
                case EAST:
                    dir = c == 'L' ? NORTH : SOUTH;
                    break;
                case WEST:
                    dir = c == 'L' ? SOUTH : NORTH;
                    break;
                }
            }
            else {
                switch (dir) {
                case NORTH:
                    y++;
                    break;
                case SOUTH:
                    y--;
                    break;
                case EAST:
                    x++;
                    break;
                case WEST:
                    x--;
                    break;
                }
            }
        }
    }


    return x == 0 && y == 0;
}

int main() {
    std::cout << isRobotBounded("GGLLGG") << std::endl;
    return 0;
}
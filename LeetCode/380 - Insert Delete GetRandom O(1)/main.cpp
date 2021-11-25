#include <iostream>
#include <vector>
#include <unordered_map>

class RandomizedSet {
    std::vector<int> values;
    std::unordered_map<int, int> index;
public:
    RandomizedSet() { }

    bool insert(int val) {
        if (index.count(val)) {
            // Already had element in here
            return false;
        }
        else {
            values.push_back(val);
            index[val] = values.size() - 1;
            return true;
        }
    }

    bool remove(int val) {
        if (index.count(val)) {
            int index_of_val = index[val];

            // Put the element from the end of the values list in its place
            values[index_of_val] = values[values.size() - 1];
            values.pop_back();

            index[values[index_of_val]] = index_of_val;
            index.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        return values.at(rand() % values.size());
    }
};

int main() {
    RandomizedSet r;

    std::cout << r.insert(1) << std::endl;
    std::cout << r.remove(2) << std::endl;
    std::cout << r.insert(2) << std::endl;
    std::cout << r.getRandom() << std::endl;
    std::cout << r.remove(1) << std::endl;
    std::cout << r.insert(2) << std::endl;
    std::cout << r.getRandom() << std::endl;

    return 0;
}
class RandomizedSet {
public:
    std::vector<int> values;
    std::unordered_map<int, int> index;

    RandomizedSet() { }

    bool insert(int val) {
        if(index.count(val)) {
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
        if(index.count(val)) {
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

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
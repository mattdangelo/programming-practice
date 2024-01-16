class RandomizedSet {
    std::unordered_map<int, int> index_map;
    std::vector<int> values;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!index_map.count(val)) {
            values.push_back(val);
            index_map[val] = values.size() - 1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(index_map.count(val)) {
            int index_of_val = index_map[val];

            // Put the element from the end of the values list in its place
            values[index_of_val] = values[values.size() - 1];
            values.pop_back();

            index_map[values[index_of_val]] = index_of_val;
            index_map.erase(val);

            return true;
        }

        return false;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
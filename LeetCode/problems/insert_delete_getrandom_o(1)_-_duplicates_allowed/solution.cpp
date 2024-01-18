class RandomizedCollection {
    std::unordered_map<int, std::unordered_set<int>> index_map;
    std::vector<int> values;
public:
    RandomizedCollection() { }

    bool insert(int val) {
        // Add it to the values vector, and add the index to the map
        values.push_back(val);
        index_map[val].insert(values.size() - 1);

        // If there's only 1 index, it's the one we just added, so the element
        // must have been new to the collection
        return index_map[val].size() == 1;
    }

    bool remove(int val) {
        if(index_map.count(val) && !index_map[val].empty()) {
            // Find the index of one of the elements (just take the first since
            // that's O(1))
            int index_of_val = *index_map[val].begin();

            // Remove the reference to the index in the index map
            index_map[val].erase(index_of_val);

            // Put the element from the end of the values vector in its place
            values[index_of_val] = values.back();
            values.pop_back();

            // Update the index map to point to the new index
            index_map[values[index_of_val]].insert(index_of_val);
            index_map[values[index_of_val]].erase(values.size());

            return true;
        }

        // The element wasn't in the collection
        return false;
    }

    int getRandom() {
        // Pick a random index from values
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
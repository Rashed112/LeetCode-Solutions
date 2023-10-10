class RandomizedSet {
public:
    unordered_map<int,int>indices;
    vector<int>values;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(indices.find(val)==indices.end()){
            values.push_back(val);
            indices[val]=values.size()-1;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(indices.find(val)==indices.end()){
            return false;
        }
        //find the index of last value
        int tempIdx = indices[val];
        //get the last value of vector
        //and change it's idx to current value's idx
        indices[values[values.size()-1]] = tempIdx;
        //replace current values with last value
        values[tempIdx] = values[values.size()-1];
        indices.erase(val);
        values.pop_back();
        return true;     
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

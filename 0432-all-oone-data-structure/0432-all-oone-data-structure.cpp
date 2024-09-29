class AllOne {
public:

    unordered_map<string, int> freq;
    map<int, unordered_set<string>> sets;

    AllOne() {
        
    }
    
    void inc(string key) {
        if(freq.find(key) == freq.end()){
            freq[key]++;
            sets[freq[key]].insert(key);
        }
        else{
            sets[freq[key]].erase(key);
            if(sets[freq[key]].size() == 0) sets.erase(freq[key]);
            freq[key]++;
            sets[freq[key]].insert(key);
        }
    }
    
    void dec(string key) {
        sets[freq[key]].erase(key);
        if(sets[freq[key]].size() == 0) sets.erase(freq[key]);

        if(freq[key] == 1){
            freq.erase(key);
            return;
        }
        freq[key]--;
        sets[freq[key]].insert(key);
    }
    
    string getMaxKey() {
        if(sets.size() == 0) return "";
        return *((sets.rbegin())->second.begin());
    }
    
    string getMinKey() {
        if(sets.size() == 0) return "";
        return *((sets.begin())->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
class LRUCache {
public:
    list<int> ref_list;
    unordered_map<int,pair<int,list<int>::iterator>> cash_map;
    int cash_cap;
    
    LRUCache(int capacity) {
        cash_cap = capacity;
    }
    // remove from cash_map and ref_list
    void remove_node(int key){
        // key exist 
        auto it = cash_map[key].second; // pos at the list
        ref_list.erase(it);
        cash_map.erase(key);
    }
    
    int get(int key) {
        auto it = cash_map.find(key);
        if(it==cash_map.end()) return -1;
        int val = cash_map[key].first;
        //remove node from map and list;
        // put node to map and list;
        remove_node(key);
        put(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(ref_list.size()==cash_cap && cash_map.find(key)!=cash_map.end() ){
            remove_node(key);
        }
        if(ref_list.size()==cash_cap){
            int val = ref_list.front();
            ref_list.pop_front();
            cash_map.erase(val);
        }
        if(ref_list.size()!=cash_cap && cash_map.find(key)!=cash_map.end() ){
            remove_node(key);
        }
        ref_list.push_back(key);
        auto it = ref_list.end();
        pair<int,list<int>::iterator> temp = {value,--it};
        cash_map[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
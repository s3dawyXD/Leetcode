class FirstUnique {
public:
    list<int> unique_nums;
    unordered_map<int,pair<bool,list<int>::iterator>> map; 
    FirstUnique(vector<int>& nums) {
        unique_nums.push_back(-1);
        int n = nums.size();
        for(int i =0;i<n;i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(unique_nums.size()>1) {
            auto it = unique_nums.begin();
            return *(++it);
        }
        return unique_nums.front();
    }
    
    void add(int value) {
        if(map.find(value)!=map.end()){ // the namuber exist before
            if(map[value].first){
                map[value].first = 0;
                unique_nums.erase(map[value].second);// remove from the list
            }
            
            return;
        }
        unique_nums.push_back(value);
        map[value] = {1,prev(unique_nums.end())};
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
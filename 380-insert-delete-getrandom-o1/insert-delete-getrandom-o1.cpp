class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        
        mp[val]=nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;

        int idx=mp[val];
        int last=nums.size()-1;
        mp[nums[last]]=idx;
        swap(nums[idx],nums[last]);
        int toremove=nums.back();
        mp.erase(toremove);
        nums.pop_back();

        return true;

    }
    
    int getRandom() {
        int n=nums.size();
        int x=rand()%n;
        return nums[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
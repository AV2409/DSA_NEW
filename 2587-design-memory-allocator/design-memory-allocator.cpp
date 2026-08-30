class Allocator {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<int> mem;
    int blocks;
    Allocator(int n) {
        blocks = n;
        mem.assign(n, 0);
        int x = 1;
        for (int i = n - 1; i >= 0; i--) {
            mem[i] = n - i;
        }
    }

    int allocate(int size, int mID) {
        // find leftmost free block
        bool found = false;
        int stBl = -1;
        for (int i = 0; i < blocks; i++) {
            if (mem[i] >= size) {
                found = true;
                stBl = i;
                break;
            }
        }
        if (!found)
            return -1;
        mp[mID].push_back({stBl, size});

        for (int i = stBl; i < stBl + size; i++) {
            mem[i] = 0;
        }
        return stBl;
    }

    int freeMemory(int mID) {
        if (!mp.count(mID))
            return 0;

        int freed = 0;

        // First mark ALL blocks belonging to mID as free
        for (auto [stBl, size] : mp[mID]) {
            freed += size;

            for (int i = stBl; i < stBl + size; i++) {
                mem[i] = 1;
            }
        }

        // Now rebuild consecutive-free-block information
        for (int i = blocks - 2; i >= 0; i--) {
            if (mem[i] > 0) {
                mem[i] = mem[i + 1] + 1;
            }
        }

        mp.erase(mID);

        return freed;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
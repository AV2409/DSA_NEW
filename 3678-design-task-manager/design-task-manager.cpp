class TaskManager {
public:
    priority_queue<tuple<int,int,int,int>>pq;
    unordered_set<int>removed;
    unordered_map<int,int>updated;
    unordered_map<int,int>uid;
    unordered_map<int,int> version;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &it:tasks){
            int u=it[0];
            int t=it[1];
            int p=it[2];
            version[t] = 1;
            uid[t]=u;
            pq.push({p,t,1,u});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        removed.erase(taskId);
        updated.erase(taskId);
        version[taskId]++;
        pq.push({priority,taskId,version[taskId],userId});
        uid[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        int u=uid[taskId];
        updated[taskId]=newPriority;
        version[taskId]++;
        pq.push({newPriority,taskId,version[taskId],u});
        
    }
    
    void rmv(int taskId) {
        removed.insert(taskId);
        version[taskId]++;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [p,t,v,u]=pq.top();
            pq.pop();
            if(removed.count(t)) continue;
            if(version[t] != v)
                continue;
            if(updated.count(t) && updated[t]!=p) continue;
            removed.insert(t);
            return u;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(pq);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
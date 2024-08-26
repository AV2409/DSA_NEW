class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        unordered_map<int,int> hash;

        for(int i=0;i<arr.size();i++)
        {
            hash[arr[i]]++;
        }

        unordered_set<int> count;

        for(auto i : hash){
            if(count.find(i.second)==count.end()) count.insert(i.second);

            else return false;
        }

        return true;



    }
};
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first=false;
        bool second=false;
        bool third=false;

        for(auto it:triplets){
            int a=it[0];
            int b=it[1];
            int c=it[2];

            if(a==target[0] && b<=target[1] && c<=target[2]) first=true;
            if(a<=target[0] && b==target[1] && c<=target[2]) second=true;
            if(a<=target[0] && b<=target[1] && c==target[2]) third=true;
        }
        return first && second && third;

    }
};
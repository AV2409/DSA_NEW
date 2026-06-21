class Solution {
public:
    int maxDistance(string moves) {
        int n=moves.size();
        int x=0;
        int y=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                x--;
            }
            else if(moves[i]=='D'){
                x++;
            }
            else if(moves[i]=='L'){
                y--;
            }
            else if(moves[i]=='R'){
                y++;
            }
            else z++;
        }
        int ans=abs(x)+abs(y)+z;
        return ans;
    }
};
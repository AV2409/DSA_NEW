class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = cardPoints.size() - 1;

        int sumL = 0;
        int sumR = 0;
        

        for (int i = 0; i < k; i++) {
            sumL += cardPoints[l++];
        }
        l=k-1;
        int res=sumL;
        for(int i=0;i<k;i++){
            sumL-=cardPoints[l--];
            sumR+=cardPoints[r--];
            res=max(res,sumL+sumR);
        }
        return res;
    }
};
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int i=0;
        int j=n-1;
        int capA=capacityA;
        int capB=capacityB;
        int refills=0;
        while(i<j){
            if(plants[i]<=capA){
                capA-=plants[i];
                i++;
            }
            else{
                capA=capacityA-plants[i];
                refills++;
                i++;
            }

            if(plants[j]<=capB){
                capB-=plants[j];
                j--;
            }
            else{
                capB=capacityB-plants[j];
                refills++;
                j--;
            }
        }
        if(i==j){
            if(plants[i]>max(capA,capB)) refills++;
        }
        return refills;

    }
};
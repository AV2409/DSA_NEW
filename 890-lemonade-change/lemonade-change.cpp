class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;

        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }

            else if(bills[i]==10){
                ten++;
                if(five) five--;
                else return false;
            }

            else if(bills[i]==20){
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five>=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};
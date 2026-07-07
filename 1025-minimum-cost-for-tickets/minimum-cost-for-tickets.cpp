class Solution {
public:
    vector<int> dp;

    int f(int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int j = i;

        // 1-day pass
        while (j < days.size() && days[j] < days[i] + 1)
            j++;
        int one = costs[0] + f(j, days, costs);

        // 7-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 7)
            j++;
        int seven = costs[1] + f(j, days, costs);

        // 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30)
            j++;
        int thirty = costs[2] + f(j, days, costs);

        return dp[i] = min({one, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.assign(days.size(), -1);
        return f(0, days, costs);
    }
};
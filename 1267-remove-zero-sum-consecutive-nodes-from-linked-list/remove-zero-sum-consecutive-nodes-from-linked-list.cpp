/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    vector<int> helper(ListNode* head) {
        vector<int> ans;

        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }

        return ans;
    }

    ListNode* helper2(vector<int>& arr) {
        ListNode* dummy = new ListNode(-1001);
        ListNode* curr = dummy;

        for (int i = 0; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return dummy->next;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {

        vector<int> arr = helper(head);

        while (true) {

            int pre = 0;
            int st = -1;
            int end = -1;
            int maxLen = 0;

            unordered_map<int, int> mp;
            mp[0] = -1;

            int n = arr.size();

            for (int r = 0; r < n; r++) {

                pre += arr[r];

                if (mp.count(pre)) {

                    int len = r - mp[pre];

                    if (len > maxLen) {
                        maxLen = len;
                        st = mp[pre] + 1;
                        end = r;
                    }
                }

                mp[pre] = r;
            }

            // No zero-sum subarray left
            if (st == -1)
                break;

            // Remove the longest zero-sum subarray
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                if (i < st || i > end)
                    temp.push_back(arr[i]);
            }

            arr = temp;
        }

        return helper2(arr);
    }
};
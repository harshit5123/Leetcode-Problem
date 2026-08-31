class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* temp = head->next;

        vector<int> nodes;
        int cnt = 1;

        while(temp->next != NULL) {

            ListNode* next = temp->next;

            if((prev->val > temp->val && next->val > temp->val) ||
               (prev->val < temp->val && next->val < temp->val)) {
                nodes.push_back(cnt);
            }

            prev = temp;
            temp = temp->next;
            cnt++;
        }

        if(nodes.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        for(int i = 1; i < nodes.size(); i++) {
            mini = min(mini, nodes[i] - nodes[i-1]);
        }

        int maxi = nodes.back() - nodes.front();

        return {mini, maxi};
    }
};
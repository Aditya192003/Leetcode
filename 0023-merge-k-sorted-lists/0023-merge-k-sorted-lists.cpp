#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        for (auto list : lists) {
            if (list) pq.push(list);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = node;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

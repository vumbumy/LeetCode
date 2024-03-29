#include <iostream>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;

        ListNode* prev = new ListNode(0, head);

        ListNode* node = prev;
        while (node != nullptr) {
            q.push(node);

            node = node->next;
            if (q.size() > n + 1) {
                q.pop();
            }
        }

        ListNode* front = q.front();

        ListNode* d = front->next;

        if (d != nullptr) {
            front->next = d->next;
            delete d;
        }

        return prev->next;
    }
};

int main() {
    Solution s = Solution();

    int src[] = { 1 };
    int n = sizeof(src) / sizeof(src[0]) - 1;

    ListNode* head = nullptr;
    for (int i = n; i >= 0; i--) {
        head = new ListNode(src[i], head);
    }

    head = s.removeNthFromEnd(head, 1);

    while (head != nullptr) {
        printf("%d\n", head->val);

        head = head->next;
    }

    return 0;
}

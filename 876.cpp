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
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;

        vector<ListNode*> list;

        while (node) {
            list.push_back(node);

            node = node->next;
        }

        return list[list.size() / 2];
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

    head = s.middleNode(head);

    while (head != nullptr) {
        printf("%d\n", head->val);

        head = head->next;
    }

    return 0;
}

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> values;

        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = static_cast<int>(values.size()) - 1;

        while (i < j) {
            if (values[i] != values[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};
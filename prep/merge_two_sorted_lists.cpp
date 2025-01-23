struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode();
        ListNode* ptr = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                ptr->next = list2;
                list2 = list2->next;
            } else {
                ptr->next = list1;
                list1 = list1->next;
            }
            ptr = ptr->next;
        }

        if (list1 != nullptr) {
            ptr->next = list1;
        }

        if (list2 != nullptr) {
            ptr->next = list2;
        }

        return dummy.next;
        
    }
};
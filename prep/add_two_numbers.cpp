
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *ptr = dummy;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int initial = l1->val + l2->val + carry;
            int sum = initial % 10;
            if (initial >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr) {
           conclude(l1, ptr, carry); 
        } else if (l2 != nullptr) {
           conclude(l2, ptr, carry);
        } else if (carry == 1) {
            ptr->next = new ListNode(carry);
        }

        return dummy->next;

    
        
    }

private:
    void conclude(ListNode* l, ListNode* ptr, int carry) {
        while (l != nullptr) {
            int initial = l->val + carry;
            int sum = initial % 10;
            if (initial >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l = l->next;
        }

        if (carry == 1) {
            ptr->next = new ListNode(carry);
        }
    }
};
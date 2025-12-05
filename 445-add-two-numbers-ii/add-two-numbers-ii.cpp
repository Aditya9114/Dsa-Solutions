class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *dummyNode = new ListNode(-1);
        ListNode *last = dummyNode;

        int carry = 0;

        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;

            carry = sum / 10;
            sum = sum % 10;

            ListNode *temp = new ListNode(sum);
            last->next = temp;
            last = last->next;

            l1 = l1->next;   
            l2 = l2->next;
        }

       
        while (l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            last->next = new ListNode(sum);
            last = last->next;

            l1 = l1->next;
        }

        while (l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            last->next = new ListNode(sum);
            last = last->next;

            l2 = l2->next;
        }

        
        if (carry > 0) {
            last->next = new ListNode(carry);
        }

        
        ListNode* result = reverse(dummyNode->next);

        return result;
    }

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next1 = NULL;

        while (curr != NULL) {
            next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
};

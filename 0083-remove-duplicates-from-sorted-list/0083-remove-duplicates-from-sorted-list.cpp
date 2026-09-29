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
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle edge case: empty list
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            // Check if duplicates exist
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next; // Skip the duplicate node
                delete temp; // Free memory of the duplicate node
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        
        return head;
    }
};

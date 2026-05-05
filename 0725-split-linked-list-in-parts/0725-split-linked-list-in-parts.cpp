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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>re(k,nullptr);
        int c=0;
        ListNode*te=head;
        while(te){
            c++;
            te=te->next;
        }
        int atleat=c/k;
        int extra=c%k;
        ListNode*curr=head;
        for(int i=0;i<k && curr!=nullptr;i++){
            re[i]=curr;
            int cursize=atleat+(i<extra?1:0);
            for(int j=1;j<cursize;j++){
                curr=curr->next;
            }
            ListNode*next=curr->next;
            curr->next=nullptr;
            curr=next;
        }
        return re;
    }
};
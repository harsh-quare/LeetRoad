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
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        
        int extra = len%k;
        int base = len/k;
        vector<ListNode*> ans(k);
        temp = head;

        for(int i = 0; i<k; i++){
            ans[i] = temp;

            for(int j = 0; j < base + (i < extra ? 1 : 0) - 1; j++){
                if(temp != NULL){
                    temp = temp->next;
                }
            }

            if(temp != NULL){
                ListNode* prev = temp;
                temp = temp->next;
                prev->next= NULL;
            }
        }

        return ans;
    }
};
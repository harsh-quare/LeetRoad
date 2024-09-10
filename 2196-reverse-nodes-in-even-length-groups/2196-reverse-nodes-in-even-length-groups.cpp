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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head->next == NULL) return head;
        int len = 0;
        ListNode* temp = head;

        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        temp = head;
        int i = 1;
        int cnt = 0;
        ListNode* prevT = NULL;

        while(cnt < len && temp != NULL){
            int it = min(i, len-cnt);
            cout << cnt << " " << i << " " << it << endl;
            // cout << it << endl;
            if(it % 2 != 0){
                for(int j = 0; j < it-1 && temp != NULL; j++){
                    temp = temp->next;
                }
                prevT = temp;  //last node ko store kr le, ye use me aayegi jab next even length wala part reverse krenge and uske reversed head ko isse connect krna padega
                if(temp != NULL) temp = temp->next;
                cnt += it;
                i++;
            }
            else{
                //reverse the it number of nodes
                ListNode* tail = temp;  //reverse krne ke baad yahi tail rahegi and isko next part se connect krna padega
                ListNode* nxt = NULL;
                ListNode* prev = NULL;
                int itr = 0;
                while(temp != NULL && itr < it){
                    nxt = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = nxt;
                    itr++;
                }
                ListNode* revHead = prev;
                if(prevT != NULL) prevT->next = revHead;
                if(tail != NULL) tail->next = temp;
                prevT = tail;
                cnt += it;
                i++;
            }
        }
        return head;
    }
};
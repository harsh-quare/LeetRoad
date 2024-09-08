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
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }

        int width = len / k;
        int rem = len % k;

        vector<ListNode*> ans(k, NULL);
        temp = head;

        for(int i = 0; i<k; i++){   //jab tk k parts me divide na ho jaye

            ListNode* node = temp;     //iss head ko store kr lo abhi ke liye, and process kro pahle poori current part ki LL ko

            for(int j = 0; j < width + (i < rem ? 1 : 0)-1; j++){
                if(temp != NULL){
                    temp = temp->next;
                }
            }

            if(temp != NULL){
                ListNode* prev = temp;
                temp = temp->next;
                prev->next = NULL;
            }

            ans[i] = node;  //ab ans me store kr do current part ko
        }
        return ans;
    }
};
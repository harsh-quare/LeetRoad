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
    // int gcd(int a, int b){
    //     if(a == 0) return b;
    //     if(b == 0) return a;

    //     if(a == b) return a;

    //     if(a > b) return gcd(a-b, b);
    //     else return gcd(a, b-a);
    // }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head->next;
        ListNode* prev = head;

        while(temp != NULL){
            int a = prev->val;
            int b = temp->val;
            int val = __gcd(a, b);
            ListNode* newNd = new ListNode(val);

            prev->next = newNd;
            newNd->next = temp;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
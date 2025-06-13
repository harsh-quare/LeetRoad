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
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left != NULL && right != NULL){
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while(left != NULL){  // left me bache hue ho agar
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right != NULL){  // left me bache hue ho agar
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        // can we do something like merge sort
        // we divide the list until only one guy is left, and then while merging, we put elements to their correct positions
        if(head == NULL || head->next == NULL) return head;  // single guy left, return that

        // we need to point to mid, so find the mid pointer, using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }

        // slow is pointing to mid
        ListNode* mid = slow->next;
        slow->next = NULL;

        // recursive merge sort
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }
};

// mergeSort(arr, 0, n-1);
// void mergeSort(vector<int>& arr, int low, int high){
//     if(low < high){
//         int mid = low + (high - low) / 2;

//         mergeSort(arr, low, mid);
//         mergeSort(arr, mid+1, high);

//         merge(arr, low, mid, high);
//     }
// }
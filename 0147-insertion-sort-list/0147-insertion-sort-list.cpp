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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* i = head;
        while(i != NULL){
            ListNode* j = head;
            while(i != j){
                if(i->val < j->val){
                    swap(i->val, j->val);
                }
                j = j->next;
            }
            i = i->next;
        }

        return head;
    }
};

// insertion sort on a normal array =>
// void insertionSort(vector<int>& arr, int n){
//     for(int i = 0; i < n; i++){
//         int j = i;
//         while(j > 0 && arr[j] < arr[j-1]){
//             //swap(arr[j], arr[j-1]);
//             int temp = arr[j-1];
//             arr[j-1] = arr[j];
//             arr[j] = temp;
//             j--;
//         }
//     }
// }
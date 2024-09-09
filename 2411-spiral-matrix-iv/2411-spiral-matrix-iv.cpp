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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));

        int rs = 0, re = m-1;
        int cs = 0, ce = n-1;

        while(head != NULL){
            for(int i = cs; i <= ce && head != NULL; i++){
                mat[rs][i] = head->val;
                head = head->next;
            }
            rs++; //next row me aa ja

            for(int i = rs; i <= re && head != NULL; i++){
                mat[i][ce] = head->val;
                head = head->next;
            }
            ce--; //last col ka koi kaam nhi ab

            for(int i = ce; i >= cs && head != NULL; i--){
                mat[re][i] = head->val;
                head = head->next;
            }
            re--;

            for(int i = re; i >= rs && head != NULL; i--){
                mat[i][cs] = head->val;
                head = head->next;
            }
            cs++;
        }

        return mat;
    }
};
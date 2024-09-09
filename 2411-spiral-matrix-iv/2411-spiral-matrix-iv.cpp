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
        ListNode* temp = head;
        int i = 0, j = 0;
        int c = n, r = m-1;

        while(temp != NULL){
            //top-L to top-R move
            for(int l = 0; l < c && temp != NULL; l++){
                mat[i][j] = temp->val;
                j++;
                temp = temp->next;
            }
            i++;
            j--;
            c--;

            cout << i << "," << j << " ";
             
            //top-R to bottom-R move
            for(int k = 0; k < r && temp != NULL; k++){
                mat[i][j] = temp->val;
                i++;
                temp = temp->next;
            }
            i--;
            j--;
            r--;

            cout << i << "," << j << " ";
            
            //bottom-R to bottom-L move
            for(int l = 0; l < c && temp != NULL; l++){
                mat[i][j] = temp->val;
                j--;
                temp = temp->next;
            }
            j++;
            i--;
            c--;

            cout << i << "," << j << " ";
            
            //bottom-L to top-L move
            for(int k = 0; k < r && temp != NULL; k++){
                mat[i][j] = temp->val;
                i--;
                temp = temp->next;
            }
            i++;
            j++;
            r--;
            
            cout << i << "," << j << " ";
            cout << endl;
        }

        return mat;
    }
};
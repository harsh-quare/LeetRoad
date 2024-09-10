class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head->next == NULL) return head;
        
        int len = 0;
        ListNode* temp = head;
        
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        
        temp = head;
        int groupSize = 1;
        int cnt = 0;
        ListNode* prevT = NULL;

        while(cnt < len && temp != NULL){
            int groupLength = min(groupSize, len - cnt);
            // cout << cnt << " " << groupSize << " " << groupLength << endl;

            if(groupLength % 2 != 0){
                //move the pointer to the end of the current group
                for(int j = 0; j < groupLength-1 && temp != NULL; j++){
                    temp = temp->next;
                }
                prevT = temp; //store the last node of the current group
                if(temp != NULL) temp = temp->next; //move to the next group

                cnt += groupLength;
                groupSize++;
            } 
            
            else{
                //reverse the even-length group
                ListNode* tail = temp; //mark the beginning of the group (before reversing)
                ListNode* prev = NULL;
                ListNode* nxt = NULL;
                int itr = 0;
                
                //reverse groupLength nodes
                while (temp != NULL && itr < groupLength) {
                    nxt = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = nxt;
                    itr++;
                }

                ListNode* revHead = prev; //new head of the reversed group
                
                //connect the previous group with the reversed group
                if (prevT != NULL) prevT->next = revHead;
                
                //connect the tail (original head of the group before reversal) to the rest of the list
                if (tail != NULL) tail->next = temp;

                //update prevT to the current tail (after reversal)
                prevT = tail;
                
                cnt += groupLength;
                groupSize++;
            }
        }

        return head;
    }
};

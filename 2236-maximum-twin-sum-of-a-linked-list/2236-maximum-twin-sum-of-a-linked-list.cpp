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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> st;
        while(fast!=NULL && fast->next!=NULL){
            st.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        int sum = 0;
        while(slow!=NULL){
            sum = max(sum , st.top()+slow->val);
            st.pop();
            slow = slow->next;
        }
        return sum;
    }
};
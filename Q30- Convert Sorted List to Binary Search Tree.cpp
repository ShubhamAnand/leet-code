/*
Link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode *prev = NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        if(slow == head)
            return node;
        prev->next = NULL;
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        return node;
    }
};
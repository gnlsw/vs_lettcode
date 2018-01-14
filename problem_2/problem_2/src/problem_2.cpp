#include <iostream>

using std::cout;
using std::endl;

/* Definition for singly-linked list. */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode *head = new ListNode(0);
		ListNode *tail = head;
		int carry = 0;
		int left;
		int right;
		int sum;
        while((NULL != l1) || (NULL != l2))
		{
			left = (l1 != NULL) ? (l1->val) : 0;
			right = (l2 != NULL) ? (l2->val) : 0;
			sum = left + right + carry;
			ListNode *node = new ListNode(sum % 10);
			tail->next = node;
			tail = node;
			carry = sum / 10;
			if(NULL != l1)
			{
				l1 = l1->next;
			}
			if(NULL != l2)
			{
				l2 = l2->next;
			}
		}
		
		if(carry != 0)
		{
			ListNode *node = new ListNode(carry);
			tail->next = node;
		}

		ListNode *result = head->next;
		delete head;
		return result;
    }
};

int main()
{
	ListNode *left_1 = new ListNode(3);
	ListNode *left_2 = new ListNode(4);
	ListNode *left_3 = new ListNode(2);
	left_1->next = left_2;
	left_2->next = left_3;

	ListNode *right_1 = new ListNode(3);
	ListNode *right_2 = new ListNode(4);
	ListNode *right_3 = new ListNode(2);
	right_1->next = right_2;
	right_2->next = right_3;

	Solution s;
	s.addTwoNumbers(left_1, right_1);
	
	return 0;
}

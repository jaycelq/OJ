#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0), *p = result;
        int carry = 0;

        while(l1 != NULL || l2 != NULL) {
        	if(l1 != NULL) {
        		carry += l1->val;
        		l1 = l1->next;
        	}

        	if(l2 != NULL) {
        		carry += l2->val;
        		l2 = l2->next;
        	}

        	p->next = new ListNode(carry % 10);
        	carry /= 10;
        	p = p->next;
        }

        if(carry == 1)
        	p->next = new ListNode(1);

        return result->next;
    }
};
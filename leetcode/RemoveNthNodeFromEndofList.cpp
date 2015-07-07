//
// Created by Li Qiang on 15/6/1.
//

#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    while(head != NULL) {
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head, *r = head;

        for (int i = 0; i < n; ++i) {
            p = p->next;
        }

        while(p != NULL) {
            p = p->next;
            r = q;
            q = q->next;
        }

        if (r == q) {
            assert(r == head);
            head = r->next;
            delete(r);
        }
        else {
            r->next = q->next;
            delete(q);
        }

        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;

    printList(head);
    head = solution.removeNthFromEnd(head, 4);
    printList(head);
}
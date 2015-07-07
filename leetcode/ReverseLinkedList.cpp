//
// Created by Li Qiang on 15/6/2.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {

    if(head == NULL)
        return NULL;

    ListNode *p = head, *q = head->next;

    while (q != NULL) {
        ListNode *qNext = q->next;
        q->next = p;
        p = q;
        q = qNext;
    }

    return p;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    printList(head);
    head = solution.removeNthFromEnd(head, 4);
    printList(head);
}
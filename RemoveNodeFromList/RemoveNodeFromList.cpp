//
//  main.cpp
//  RemoveNodeFromList
//
//  Created by jsl on 15/5/7.
//  Copyright (c) 2015年 jsl. All rights reserved.
//

#include <iostream>


/*
 
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 
 */


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }
        if (n == 0) {
            return head;
        }
        if (head->next == NULL && n == 1) {
            delete head;
            return NULL;
        } else if (head->next == NULL && n == 0) {
            return NULL;
        }
        
        ListNode* pParentNode = head;
        ListNode* pRemoveNode = head;
        ListNode* pTmp = head;
        int moveCount = 0;
        while((pTmp = pTmp->next) != NULL) {
            ++moveCount;
            if (moveCount >= n) {
                pParentNode = pRemoveNode;
                pRemoveNode = pRemoveNode->next;
            }
        }
        
        if (pRemoveNode == head) {
            ListNode* pNext = head->next;
            delete head;
            return pNext;
        }
        
        ListNode* pNextAfterRemove = pRemoveNode->next;
        pParentNode->next = pNextAfterRemove;
        delete pRemoveNode;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* pHead = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    pHead->next = pNode2;
    ListNode* pNode3 = new ListNode(3);
    pNode2->next = pNode3;
    ListNode* pNode4 = new ListNode(4);
    pNode3->next = pNode4;
    
    ListNode* pPrintNode = pHead;
    while (pPrintNode) {
        std::cout << pPrintNode->val << " -> ";
        pPrintNode = pPrintNode->next;
    }
    
    std::cout << std::endl;
    
    Solution s;
    pPrintNode = s.removeNthFromEnd(pHead, 4);
    while (pPrintNode) {
        std::cout << pPrintNode->val << " -> ";
        pPrintNode = pPrintNode->next;

    }
    
    
    return 0;
}

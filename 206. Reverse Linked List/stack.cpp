#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<int> s;
        ListNode* p = head;
        while(p){
            s.push(p->val);
            p=p->next;
        }

        p = head;
        while(!s.empty()){
            p->val = s.top();
            s.pop();
            p=p->next;
        }

        return head;
    }
};

void printNodes(ListNode* head){
    ListNode* p = head;

    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printNodes(head);
    Solution s;
    printNodes(s.reverseList(head));

    return 0;
}
4. Reverse k elements

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;

        while (head != nullptr) {
            ListNode* groupStart = head;
            ListNode* groupEnd = getGroupEnd(head, k);

            if (groupEnd == nullptr)
                break;

            prevGroupTail->next = reverseList(groupStart, groupEnd->next);
            prevGroupTail = groupStart;
            head = prevGroupTail->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }

private:
    ListNode* getGroupEnd(ListNode* head, int k) {
        while (head != nullptr && --k > 0)
            head = head->next;
        return head;
    }

    ListNode* reverseList(ListNode* head, ListNode* stop) {
        ListNode* prev = stop;
        while (head != stop) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// Helper function to create a linked list from user input
ListNode* createLinkedList() {
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;
    ListNode* head = new ListNode(x);
    head->next = createLinkedList();
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main() {
    // Input: Create a linked list from user input
    cout << "Enter the linked list values (enter -1 to stop):" << endl;
    ListNode* head = createLinkedList();

    // Input: Get the value of k
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    ListNode* reversedHead = sol.reverseKGroup(head, k);

    // Output: Print the reversed linked list
    cout << "Reversed linked list:" << endl;
    printList(reversedHead);

    // Clean up memory (delete nodes)
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}

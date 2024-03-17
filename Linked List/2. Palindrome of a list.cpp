2. Palindrome of a list
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Sample Input:
4
1 2 2 1
Sample Output:
True


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
    ListNode* reverse(ListNode* ptr) {
        ListNode* pre = nullptr;
        ListNode* nex = nullptr;
        while (ptr != nullptr) {
            nex = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = nex;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Finding the middle of the linked list
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reversing the second half of the linked list
        slow->next = reverse(slow->next);
        slow = slow->next;

        // Comparing values
        ListNode* dummy = head;
        while (slow != nullptr) {
            if (dummy->val != slow->val) {
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    // Example usage
    ListNode* head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    Solution sol;
    bool result = sol.isPalindrome(head);
    cout << (result ? "True" : "False") << endl;

    // Clean up memory (delete nodes)
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


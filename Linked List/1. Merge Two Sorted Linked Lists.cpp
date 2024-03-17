1. Merge Two Sorted Linked Lists
Write a program to merge two sorted linked lists. Given two sorted linked lists let's say list1 and list2, merge list2 with list1. Insertion has to be done at the end of list1.
Input Format:
The first line consists of the size of the first linked list.
The second line consists of a sorted linked list separated by space.
The third line consists of the size of the second linked list.
The fourth line consists of a sorted linked list separated by space.
Output Format:
The output should be the merged list of two linked lists.
Example:
Input:
3
1 3 5
3
2 4 6
Output:
1->2->3->4->5->6->NULL

code- 
  #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* mergeSortedLists(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data < list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        return list2;
    }
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    int size1, size2, val;

    // Input for list1
    cin >> size1;
    for (int i = 0; i < size1; ++i) {
        cin >> val;
        append(list1, val);
    }

    // Input for list2
    cin >> size2;
    for (int i = 0; i < size2; ++i) {
        cin >> val;
        append(list2, val);
    }

    // Merge and print the result
    Node* mergedList = mergeSortedLists(list1, list2);
    printList(mergedList);

    return 0;
}

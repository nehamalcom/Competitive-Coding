/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL)
            return NULL;
        Node *copyHead, *ptr1, *ptr2;
        // mapping for each of the initial nodes to their random nodes
        unordered_map<Node*, Node*> m1;
        // mapping for each of the initial nodes to their deep copies
        unordered_map<Node*, Node*> m2;

        copyHead = new Node(head->val);
        copyHead->next = NULL;
        m1[head] = head->random;
        m2[head] = copyHead;

        ptr1 = head;
        ptr2 = copyHead;
        // creating the deep copies and filling in the hash maps
        while(ptr1->next!=NULL) {
            ptr1 = ptr1->next;
            ptr2->next = new Node(ptr1->val);
            ptr2 = ptr2->next;
            ptr2->next = NULL;
            m1[ptr1] = ptr1->random;
            m2[ptr1] = ptr2;
        }

        ptr1 = head;
        ptr2 = copyHead;
        // mapping the deep copies to their corresponding deep copy randoms
        while(ptr2!=NULL) {
            ptr2->random = m2[m1[ptr1]];
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        return copyHead;
    }
};

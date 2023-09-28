#include <iostream>
#include <string>
#include <stack>
#include <typeinfo>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* a = list1;
      ListNode* b = (a) ? a->next : nullptr;
      ListNode* prev = list1;        // a - 1 node

      while(list2) {
        ListNode* tmp = list2->next;
        if (!list1) {
          list1 = list2;
          list2 = nullptr;
          return list1;
        }
        if (list2->val <= a->val) {             // Stick list2 head in front of list1 current node (a)
          if (list1 == a) {
            ListNode* tmp2 = list1;
            list1 = list2;
            list1->next = tmp2;
            a = list1;
            b = list1->next;
          } else {
            prev->next = list2;
            list2->next = a;
            prev = list2;
            a = list2->next;
            b = a->next;
          }
          list2 = tmp;
        } else if (b == nullptr || list2->val < b->val) {   // Stick list2 head behind list1 current node (a)
          ListNode* tmp2 = a->next;
          a->next = list2;
          list2->next = tmp2;
          prev = a;
          a = list2;
          b = a->next;
          list2 = tmp;
        } else {
          prev = a;
          if (b) {
            a = b;
            b = b->next;
          }
        }
        //cout << a->val << " " << b->val << endl;
      }
//	  printList(list1);
//    printList(list2);
      return list1;
    }
//    void printList(ListNode* list) {
//      while(list) {
//        cout << list->val;
//        list = list->next;
//      }
//      cout << endl;
//    }
};

int main() {
  Solution sol;
  ListNode list1 = ListNode(1);
  //ListNode tmp = ListNode(2);
  //list1.next = &tmp;
  //ListNode tmp1 = ListNode(4);
  //tmp.next = &tmp1;
  ListNode list2 = ListNode(2);
  //ListNode tmp2 = ListNode(3);
  //list2.next = &tmp2;
  //ListNode tmp3 = ListNode(4);
  //tmp2.next = &tmp3;
  ListNode* p = sol.mergeTwoLists(&list1, &list2);
  sol.printList(p);
  return 0;
}

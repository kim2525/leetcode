#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL, *cur = NULL;
		int c = 0;
		while(l1 != NULL || l2 != NULL)
		{
			ListNode* temp;
			int val0;
			if(l1 == NULL) {val0 = (l2->val + c)% 10; c = (l2->val + c)/ 10;} 
			else if(l2 == NULL) {val0 = (l1->val + c)% 10; c = (l1->val + c)/ 10;} 
			else
			{
				val0 = (l1->val + l2->val + c)%10;
				c = (l1->val + l2->val + c)/10;
			}
			temp = new ListNode(val0);
			if(cur == NULL) {root = temp; cur = temp;}
			else 
			{
				cur->next = temp;
				cur = temp;
			}
			if(l1 != NULL)l1 = l1->next;
			if(l2 != NULL)l2 = l2->next;
		}
		if(c != 0)
		{
			ListNode* temp = new ListNode(1);
			cur->next = temp;
			cur = temp;
		}
		return root;
    }
};
int main()
{
	
	ListNode *A, *B, *Temp, *curA, *curB;
	int T;
	A = new ListNode(0);
	curA = A;
	for(int i = 1;i < 3; i++)
	{
		Temp = new ListNode(i);
		curA->next = Temp;
		curA = Temp;
	}
	B = new ListNode(0);
	curB = B;
	for(int i = 1;i < 3; i++)
	{
		Temp = new ListNode(i);
		curB->next = Temp;
		curB = Temp;
	}
	Solution S;
	Temp = S.addTwoNumbers(A,B);
	for(ListNode* T0 = Temp; T0 != NULL; T0= T0->next)
	{
		cout << T0->val << " ";
	}
	return 0;
}
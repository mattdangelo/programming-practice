#include <iostream>

#include "../shared/listnode.h"

int getDecimalValue(ListNode* head) {
	int val = 0;
	while (head != nullptr) {
		val = val << 1;
		val = val | head->val;
		head = head->next;
	}
	return val;
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(0);
	head->next->next = new ListNode(1);

	std::cout << getDecimalValue(head) << std::endl;

	return 0;
}
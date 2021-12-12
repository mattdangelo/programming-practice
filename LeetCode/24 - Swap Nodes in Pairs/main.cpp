#include <iostream>

#include "../shared/listnode.h"

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	else if (head->next == nullptr) {
		return head;
	}

	ListNode* prev = nullptr;
	ListNode* curr = head;
	ListNode* next = curr->next;
	ListNode* ret = next;

	while (curr != nullptr && next != nullptr) {
		// Swap
		curr->next = next->next;
		next->next = curr;

		if (prev) {
			prev->next = next;
		}

		// Update
		prev = curr;
		curr = curr->next;
		if (curr == nullptr) {
			break;
		}
		next = curr->next;
	}

	return ret;
}

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	auto result = swapPairs(head);

	while (result != nullptr) {
		std::cout << result->val << " ";
		result = result->next;
	}

	return 0;
}
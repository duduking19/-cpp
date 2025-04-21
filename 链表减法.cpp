ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2) {
    // 反转链表 l1 和 l2
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    int borrow = 0;
    ListNode* result = nullptr;
    
    while (l1 != nullptr || l2 != nullptr || borrow != 0) {
        int diff = borrow;
        
        // 如果 l1 非空，则加上 l1 的值
        if (l1 != nullptr) {
            diff += l1->val;
            l1 = l1->next;
        }
        
        // 如果 l2 非空，则减去 l2 的值
        if (l2 != nullptr) {
            diff -= l2->val;
            l2 = l2->next;
        }
        
        // 处理借位
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        
        // 创建新的节点，并添加到结果链表
        ListNode* newNode = new ListNode(diff);
        newNode->next = result;
        result = newNode;
    }
    
    // 移除结果前面的零（如果有的话）
    while (result != nullptr && result->next != nullptr && result->val == 0) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    
    return result;
}
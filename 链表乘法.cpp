ListNode* multiplyTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2) return new ListNode(0); // 处理空链表
    
    // 反转链表以便从低位开始计算
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    ListNode* result = nullptr;
    int shift = 0; // 记录当前需要左移的位数
    
    while (l2) {
        int digit = l2->val;
        ListNode* temp = l1;
        ListNode* partial = nullptr;
        ListNode* current = nullptr;
        int carry = 0;
        
        // 计算部分积
        while (temp || carry) {
            int val = (temp ? temp->val : 0) * digit + carry;
            carry = val / 10;
            if (!partial) {
                partial = new ListNode(val % 10);
                current = partial;
            } else {
                current->next = new ListNode(val % 10);
                current = current->next;
            }
            if (temp) temp = temp->next;
        }
        
        // 添加移位零
        for (int i = 0; i < shift; i++) {
            ListNode* zero = new ListNode(0);
            zero->next = partial;
            partial = zero;
        }
        
        // 累加到结果
        result = addTwoNumbers(result, partial);
        
        l2 = l2->next;
        shift++;
    }
    
    // 反转回结果并去除前导零
    result = reverseList(result);
    while (result && result->next && result->val == 0) {
        ListNode* tmp = result;
        result = result->next;
        delete tmp;
    }
    
    return result ? result : new ListNode(0);
}
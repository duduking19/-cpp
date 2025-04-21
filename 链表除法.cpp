// 比较两个链表数字大小 (1: l1>l2, 0: 相等, -1: l1<l2)
int compare(ListNode* l1, ListNode* l2) {
    // 先比较长度
    int len1 = 0, len2 = 0;
    for (ListNode* p = l1; p; p = p->next) len1++;
    for (ListNode* p = l2; p; p = p->next) len2++;
    
    if (len1 != len2) return len1 > len2 ? 1 : -1;
    
    // 长度相同则逐位比较
    while (l1 && l2) {
        if (l1->val != l2->val) 
            return l1->val > l2->val ? 1 : -1;
        l1 = l1->next;
        l2 = l2->next;
    }
    return 0;
}

// 链表除法 (只返回商)
ListNode* divideLists(ListNode* dividend, ListNode* divisor) {
    // 处理除数为0的情况
    if (!divisor || (divisor->val == 0 && !divisor->next)) 
        throw std::runtime_error("Division by zero");
    
    // 处理被除数为0的情况
    if (!dividend || (dividend->val == 0 && !dividend->next)) 
        return new ListNode(0);
    
    // 被除数 < 除数，返回0
    if (compare(dividend, divisor) < 0) 
        return new ListNode(0);
    
    // 被除数 == 除数，返回1
    if (compare(dividend, divisor) == 0) 
        return new ListNode(1);
    
    ListNode* quotient = new ListNode(0); // 初始化商为0
    ListNode* current = dividend;
    ListNode* partial = nullptr;         // 当前部分被除数
    
    while (current) {
        // 构建部分被除数
        if (!partial && current->val != 0) {
            partial = new ListNode(current->val);
        } else if (partial) {
            ListNode* p = partial;
            while (p->next) p = p->next;
            p->next = new ListNode(current->val);
        }
        
        current = current->next;
        
        if (!partial) continue; // 跳过前导零
        
        // 计算当前位的商
        int digit = 0;
        ListNode* temp = copyList(divisor); // 需要实现链表复制
        
        while (compare(partial, temp) >= 0) {
            ListNode* sub = subtractLists(partial, temp); // 使用减法
            deleteList(partial); // 释放旧内存
            partial = sub;
            digit++;
        }
        
        deleteList(temp); // 释放临时内存
        
        // 更新商
        ListNode* q = quotient;
        while (q->next) q = q->next;
        q->next = new ListNode(digit);
    }
    
    // 移除商的前导零
    while (quotient->next && quotient->val == 0) {
        ListNode* temp = quotient;
        quotient = quotient->next;
        delete temp;
    }
    
    return quotient;
}
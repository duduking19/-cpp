ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    
    // 创建新链表的虚拟头节点
    ListNode* newDummy = new ListNode(0);
    ListNode* newCur = newDummy;
    
    // 创建奇数链表的虚拟头节点
    ListNode* oddDummy = new ListNode(0);
    ListNode* oddCur = oddDummy;
    
    // 创建偶数链表的虚拟头节点
    ListNode* evenDummy = new ListNode(0);
    ListNode* evenCur = evenDummy;
    
    int index = 1;  // 从1开始计数
    ListNode* curr = head;
    
    // 分离奇偶节点到两个新链表
    while (curr) {
        if (index % 2 == 1) {  // 奇数位置
            oddCur->next = new ListNode(curr->val);  // 创建新节点
            oddCur = oddCur->next;
        } else {  // 偶数位置
            evenCur->next = new ListNode(curr->val);  // 创建新节点
            evenCur = evenCur->next;
        }
        curr = curr->next;
        index++;
    }
    
    // 合并奇偶链表
    newCur->next = oddDummy->next;  // 连接奇数链表
    while (newCur->next) {  // 找到奇数链表末尾
        newCur = newCur->next;
    }
    newCur->next = evenDummy->next;  // 连接偶数链表
    
    ListNode* result = newDummy->next;
    
    // 释放虚拟头节点
    delete newDummy;
    delete oddDummy;
    delete evenDummy;
    
    return result;
}
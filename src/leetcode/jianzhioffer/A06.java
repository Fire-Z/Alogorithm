package leetcode.jianzhioffer;

import leetcode.jianzhioffer.common.ListNode;

/**
 * 6. 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 示例 1： 输入：head = [1,3,2] 输出：[2,3,1] 限制：
 * 0 <= 链表长度 <= 1000
 */
public class A06 {

    public int[] reversePrint(ListNode head) {
        int[] rtn = new int[] {};
        int count = 0;
        while (head.getNext() != null) {
            rtn[count] = head.getVal();
            count++;
        }
        int len = rtn.length;
        for(int i = 0;i < len / 2;i++){
            int temp = rtn[i];
            rtn[i] = rtn[len - 1 - i];
            rtn[len - 1 - i] = temp;
        }
        return rtn;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(0);
        for(int i = 1;i < 3;i++){
            
        }
        System.out.println("hello world!");
    }
}
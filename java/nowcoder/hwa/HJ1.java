/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-26 23:57:34
 * @LastEditTime: 2021-01-30 02:51:25
 */
package nowcoder.HWA;

import java.util.Scanner;

/**
 * 题目描述 计算字符串最后一个单词的长度，单词以空格隔开。 输入描述: 输入一行，代表要计算的字符串，非空，长度小于5000。 输出描述:
 * 输出一个整数，表示输入字符串最后一个单词的长度。 示例1 输入 hello nowcoder 输出 8
 */
public class HJ1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        in.close();
        int index = str.lastIndexOf(" ");
        System.out.println(str.length() - index - 1);
    }
}
/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-27 00:09:01
 * @LastEditTime: 2021-01-30 02:51:49
 */
package nowcoder.HWA;

import java.util.Scanner;

/**
 * 题目描述 写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字母，然后输出输入字符串中该字母的出现次数。不区分大小写。 输入描述:
 * 第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字母。 输出描述: 输出输入字符串中含有该字符的个数。 示例1 输入 ABCabc A 输出
 * 2
 */
public class HJ2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str1 = in.nextLine().toLowerCase();
        String str2 = in.nextLine().toLowerCase();
        char match = str2.charAt(0);
        int count = 0;
        for (int i = 0; i < str1.length(); i++) {
            char str = str1.charAt(i);
            if (str == match) {
                count++;
            }
        }
        System.out.println(count);
        in.close();
    }

}

/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-30 17:49:53
 * @LastEditTime: 2021-01-30 18:14:45
 */
package nowcoder.HWA;

import java.util.Scanner;

/**
 * 题目描述
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
输入描述:
输入一行，为一个只包含小写字母的字符串。
输出描述:
输出该字符串反转后的字符串。
示例1
输入
abcd
输出
dcba
 */
public class HJ12 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNextLine()){
            String str = in.nextLine();
            if(str.equals("")){
                in.close();
                break;
            }
            char[] charArray = str.toCharArray();            
            int len = str.length();
            for(int i = 0;i < len / 2;i++){
                char temp = charArray[i];
                charArray[i] = charArray[len - i - 1];
                charArray[len - i - 1] = temp;
            }
            String s = String.valueOf(charArray);
            System.out.println(s);
        }
    } 
}

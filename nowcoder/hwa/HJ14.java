/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-30 19:53:39
 * @LastEditTime: 2021-01-30 20:04:44
 */
package nowcoder.HWA;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

/**
 * 题目描述 给定n个字符串，请对n个字符串按照字典序排列。
 * 输入描述:
 * 输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。 
 * 输出描述:
 * 数据输出n行，输出结果为按照字典序排列的字符串。 
 * 示例1 输入 
 * 9 
 * cap
 * to 
 * cat 
 * card 
 * two 
 * too 
 * up 
 * boat 
 * boot 
 * 输出
 * boat 
 * boot 
 * cap 
 * card 
 * cat 
 * to 
 * too 
 * two 
 * up
 */
public class HJ14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> strs = new ArrayList<>();
        int num = Integer.valueOf(sc.nextLine());
        for (int i = 0; i < num; i++) {
            strs.add(sc.nextLine());
        }
        sc.close();
        strs = strs.stream().sorted().collect(Collectors.toList());
        for (String str : strs) {
            System.out.println(str);
        }
    }
}

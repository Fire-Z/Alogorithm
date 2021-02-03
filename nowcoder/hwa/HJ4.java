/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-27 01:11:07
 * @LastEditTime: 2021-01-30 02:52:13
 */
package nowcoder.HWA;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述:
连续输入字符串(输入多次,每个字符串长度小于100)
输出描述:
输出到长度为8的新字符串数组
示例1
输入
abc
123456789
输出
abc00000
12345678
90000000
 */
public class HJ4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<String> strs = new ArrayList<>();
        List<String> res = new ArrayList<>();
        while(in.hasNextLine()){
            strs.add(in.nextLine());
            for (String str : strs) {
                if(str.length() <= 8){
                    for(int i = 0;i < 8 - str.length();i++){
                        str += "0";
                    }
                    res.add(str);
                } else {
                    int reminder = str.length() % 8;
                    int num = (str.length() - reminder);
                    for(int i = 0;i < num;i++){
                        res.add(str.substring(i * 8, (i + 1) * 8));
                    }
                    String remain = str.substring(((num - 1) * 8 -1));
                    for (int i = 0; i < 8 - reminder; i++) {
                        remain += "0";
                    }
                    res.add(remain);
                }
            }
            for(String s : res){
                System.out.println(s);
            }
        }
        in.close();
    }    
}

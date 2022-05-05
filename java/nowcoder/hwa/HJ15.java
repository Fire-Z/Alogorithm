/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-02-01 23:00:35
 * @LastEditTime: 2021-02-01 23:50:17
 */
package nowcoder.HWA;

import java.util.Scanner;

/**
 * 题目描述 输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
 * 
 * 输入描述: 输入一个整数（int类型） 输出描述: 这个数转换成2进制后，输出1的个数
 * 
 * 示例1 输入 5 输出 2
 */
public class HJ15 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        in.close();
        String binaryStr = Integer.toBinaryString(num);
        int count = 0;
        for (int i = 0; i < binaryStr.length(); i++) {
            if(binaryStr.charAt(i) == '1'){
                count++;
            }
        }
        System.out.println(count);
    }
    
}


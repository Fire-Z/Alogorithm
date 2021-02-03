/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-30 08:50:13
 * @LastEditTime: 2021-01-30 12:23:35
 */
package nowcoder.HWA;

import java.util.Scanner;
import java.util.TreeMap;
/**
 * 题目描述 数据表记录包含表索引和数值（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
 * 输入描述: 先输入键值对的个数 然后输入成对的index和value值，以空格隔开 输出描述: 输出合并后的键值对（多行） 
 * 示例1 输入
 * 4 
 * 0 1 
 * 0 2 
 * 1 2 
 * 3 4 
 * 输出 
 * 0 3 
 * 1 2 
 * 3 4
 */
public class HJ8 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
        while (in.hasNextLine()) {
            String num = in.nextLine();
            if(num.equals("")){
                break;
            }
            int counter = Integer.valueOf(num);
            for (int i = 0; i < counter; i++) {
                String str = in.nextLine();
                Scanner in2 = new Scanner(str);
                int key = in2.nextInt();
                int value = in2.nextInt();
                if (map.containsKey(key)) {
                    value += map.get(key);
                    map.put(key, value);
                }
                map.put(key, value);
                in2.close();
            }
        }
        in.close();
        
        for (int key : map.keySet()) {
            System.out.println(key + " " + map.get(key));
        }
    }
}

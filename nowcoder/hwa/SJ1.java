/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-28 00:04:05
 * @LastEditTime: 2021-01-30 02:52:21
 */
package nowcoder.HWA;

import java.util.Scanner;

/**
 * 有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，
 * 方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你
 * 让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
输入描述:
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1<=n<=100），表示小张手上的空汽水瓶数。n=0表示输入结束，你的程序不应当处理这一行。

输出描述:
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

输入例子1:
3
10
81
0
输出例子1:
1
5
40
 */
public class SJ1 {

    public static int getMax(int num){
        int res = 0;
        while(num >= 3){
            int reminder = num % 3;
            res += num / 3;
            num = reminder + num / 3;
        }
        if(num == 2){
            res += 1;
        } else{
            res += 0;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] number = new int[10];
        int counter = 0;
        while(in.hasNext()){
            int num = in.nextInt();
            if(num == 0){
                break;
            }
            number[counter] = num;
            counter++;
        }
        in.close();
        for (int i = 0; i < counter; i++) {
            System.out.println(getMax(number[i]));
        }
        
    }
    
}

package nowcoder.HWA;
/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-30 18:16:31
 * @LastEditTime: 2021-01-30 19:52:36
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
/**
 * 题目描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
输入描述:
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。
输出描述:
得到逆序的句子
示例1
输入
I am a boy
输出
boy a am I
 */
public class HJ13 {

    public static List<String> spiltStringBySpace(String str){
        List<String> res = new ArrayList<>();
        int spaceIndex = str.indexOf(" ");
        int beginIndex = 0;
        while(beginIndex < str.length()){
            if(spaceIndex == -1) { //没有找到空格时，已经遍历到最后一个单词，返回
                res.add(str.substring(beginIndex));
                break;
            }
            String word = str.substring(beginIndex, spaceIndex);
            res.add(word);
            beginIndex = spaceIndex + 1;
            spaceIndex = str.indexOf(" ", beginIndex);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        List<String> words = spiltStringBySpace(str);
        Collections.reverse(words);
        for (String word : words) {
            System.out.print(word + " ");
        }
        in.close();
    }
    
}


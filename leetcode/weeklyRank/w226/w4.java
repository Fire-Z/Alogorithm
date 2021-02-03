/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-31 10:58:57
 * @LastEditTime: 2021-01-31 12:04:30
 */
package leetcode.weeklyRank.w226;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

/**
 * 存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。 给你一个二维整数数组
 * adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在
 * nums 中相邻。 题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs
 * 中，存在形式可能是 [nums[i], nums[i+1]] ， 也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序
 * 出现。 返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
 * 
 * 示例 1： 输入：adjacentPairs = [[2,1],[3,4],[3,2]] 输出：[1,2,3,4] 解释：数组的所有相邻元素对都在
 * adjacentPairs 中。 特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
 * 
 * 示例 2： 输入：adjacentPairs = [[4,-2],[1,4],[-3,1]] 输出：[-2,4,1,-3] 解释：数组中可能存在负数。
 * 另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。 示例 3：
 * 
 * 输入：adjacentPairs = [[100000,-100000]] 输出：[100000,-100000]
 * 
 * 提示： nums.length == n adjacentPairs.length == n - 1 adjacentPairs[i].length ==
 * 2 2 <= n <= 105 -105 <= nums[i], ui, vi <= 105 题目数据保证存在一些以 adjacentPairs
 * 作为元素对的数组 nums
 */
public class w4 {

    // public int removeIndex1;

    // public int removeIndex2;

    public static int[] getOutPair(int[][] adjacentPairs,List<Integer> removeIndexs){
        Map<Integer,Integer> map = new HashMap<>();
        int length = adjacentPairs.length;
        int[] rtn = new int[2];
        for (int i = 0; i < length; i++) {
            int[] pair = adjacentPairs[1];
            int A1 = pair[0];
            int A2 = pair[1];
            if(removeIndexs.get(0) == -1 || removeIndexs.get(1) == -1 || (!removeIndexs.contains(A1) && !removeIndexs.contains(A2))){
                if(map.get(A1) == null){
                    map.put(A1, 1);
                } else {
                    map.put(A1, map.get(A1) + 1);
                }
                if(map.get(A2) == null){
                    map.put(A2, 1);
                } else {
                    map.put(A2, map.get(A2) + 1);
                }
            }
        }
        int count = 0;
        for (Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getValue() == 1 && count < 2){
                rtn[count] = entry.getKey(); 
                count++;
            }
            break;
        }
        return rtn;
    }

    public static int[] findRemoveIndexs(int[][] adjacentPairs,int a,int b){
        int[] removeINdexs = new int[2];
        int count = 0;
        for (int i = 0 ;i < adjacentPairs.length; i++) {
            int[] pair = adjacentPairs[i];
            if(count < 2){
                if(pair[0] == a || pair[1] == a || pair[0] == b || pair[1] == b){
                    removeINdexs[count] = i;
                    count++;
                }
            } else {
                break;
            }
           
        }
        return removeINdexs;
    }

    public static int getInner(int[][] adjacentPairs,List<Integer> removeIndexs){
        Map<Integer,Integer> map = new HashMap<>();
        int length = adjacentPairs.length;
        for (int i = 0; i < length; i++) {
            int[] pair = adjacentPairs[1];
            int A1 = pair[0];
            int A2 = pair[1];
            if(removeIndexs.get(0) == -1 || removeIndexs.get(1) == -1 || (!removeIndexs.contains(A1) && !removeIndexs.contains(A2)) ){
                if(map.get(A1) == null){
                    map.put(A1, 1);
                } else {
                    map.put(A1, map.get(A1) + 1);
                }
                if(map.get(A2) == null){
                    map.put(A2, 1);
                } else {
                    map.put(A2, map.get(A2) + 1);
                }
            }
        }
        for (Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getValue() == 2 ){
                return entry.getKey();
            }
            break;
        }
        return 0;
    }
    public static int[] restoreArray(int[][] adjacentPairs) {
        int n = adjacentPairs.length + 1;
        int[] rtn = new int[n];
        List<Integer> removeIndexs = new ArrayList<>();
        int remain = 0;
        int i = adjacentPairs.length;
        for(; i > 1;i -= 2){
            if(i == adjacentPairs.length){
                removeIndexs.add(-1);
                removeIndexs.add(-1);
                int[] outPair = getOutPair(adjacentPairs, removeIndexs);
                int[] findRemoveIndexs = findRemoveIndexs(adjacentPairs, outPair[0], outPair[1]);
                removeIndexs.remove(1);
                removeIndexs.remove(0);
                removeIndexs.add(findRemoveIndexs[0]);
                removeIndexs.add(findRemoveIndexs[1]);
                rtn[i] = outPair[1];
                rtn[n - i -1] = outPair[0];
                if(i - 2 == 0){
                    remain = getInner(adjacentPairs, removeIndexs);
                }
            } else{
                int[] outPair = getOutPair(adjacentPairs,removeIndexs);
                int[] findRemoveIndexs = findRemoveIndexs(adjacentPairs, outPair[0], outPair[1]);
                removeIndexs.add(findRemoveIndexs[0]);
                removeIndexs.add(findRemoveIndexs[1]);
                rtn[i] = outPair[1];
                rtn[n - i -1] = outPair[0];
                remain = getInner(adjacentPairs, removeIndexs);
            }
        }
        if(i == 1){
            int[] pair = getOutPair(adjacentPairs, removeIndexs);
            rtn[n / 2 - 1] = pair[0];
            rtn[n / 2] = pair[1];
        }
        if(i == 0){
            rtn[(n - 1) / 2] = remain;
        }
        return rtn;
    }

    public static void main(String[] args) {
        
    }
}


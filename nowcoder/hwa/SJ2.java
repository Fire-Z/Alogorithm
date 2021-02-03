/*
 * @Descripttion: 
 * @Author: Lin
 * @Date: 2021-01-28 00:29:29
 * @LastEditTime: 2021-01-30 02:52:29
 */
package nowcoder.HWA;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SJ2 {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<String> vals = new ArrayList<>();
        while(in.hasNextLine()){
            String val = in.nextLine();
            if(val.equals("")){
                break;
            }
           vals.add(val);        
        }
        in.close();
        for (String val : vals) {
            int hexVal = Integer.valueOf(val.substring(2), 16); 
            System.out.println(hexVal);
        }
    }
}

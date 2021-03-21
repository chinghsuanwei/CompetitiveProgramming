// you can also use imports, for example:
import java.util.*;
import java.util.stream.Collectors;
// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");



class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8

        List<Integer> list = Arrays.stream(A).boxed().collect(Collectors.toList());

        List<Integer> sortedList = list.stream().sorted().distinct().collect(Collectors.toList());
        int number = 1;
        
        for(int i=0; i<sortedList.size(); i++)
        {
            if(sortedList.get(i) > 0)
            {
                if(sortedList.get(i) == number)
                {
                    number++;
                }
                else
                {
                    return number;
                }
            }
        }
        
        return number;
    }
}
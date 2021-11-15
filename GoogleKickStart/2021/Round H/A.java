import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Set;

public class Solution {
    public static void main(String[] args) {
        try {

            //Scanner sc = new Scanner(file);
            //Scanner sc = new Scanner(System.in);



            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            //BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));




            int T = Integer.parseInt(br.readLine());
            //System.out.println("T = " + T);
            for(int i=1; i<=T; i++) {
                String S = br.readLine();
                String P = br.readLine();


                char c = S.charAt(0);

                System.out.println("Case #" + i + ": " + solve(S, P));
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static int solve(String s, String P) {

        boolean exist[] = new boolean[26];
        int min[] = new int[26];
        for(int i=0; i<P.length(); i++) {
            exist[ P.charAt(i) - 'a' ] = true;
        }

        for(int i=0; i<26; i++) {

            for(int j=0; j<=13; j++)
            {
                int f = i+j;
                if(f>=26) f -= 26;
                int b = i-j;
                if(b<0) b += 26;

                if(exist[f] || exist[b])
                {
                    min[i] = j;
                    break;
                }
            }
        }

        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            //b 26 - (25 - 1) = 24
            //c - b = 1
            //b - c = -1
            sum += min[s.charAt(i) - 'a'];

        }

        return sum;

    }

}

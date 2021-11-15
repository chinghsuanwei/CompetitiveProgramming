import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Map;
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
                int N = Integer.parseInt(br.readLine());
                String S = br.readLine();

                System.out.println("Case #" + i + ": " + solve(S, N));
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static int solve(String s, int N) {



        //U = 0
        //R = 1
        //Y = 2
        //B = 4
        //O = 3
        //P = 5
        //G = 6
        //A = 7
        int canvas[] = new int[N];
        int paint[] = new int[N];

        int mapping[] = new int[26];
        mapping['U' - 'A'] = 0;
        mapping['R' - 'A'] = 1;
        mapping['Y' - 'A'] = 2;
        mapping['B' - 'A'] = 4;
        mapping['O' - 'A'] = 3;
        mapping['P' - 'A'] = 5;
        mapping['G' - 'A'] = 6;
        mapping['A' - 'A'] = 7;

        for(int i=0; i<s.length(); i++) {
            paint[i] = mapping[s.charAt(i) - 'A'];
        }

        int pre_idx = 0;
        int ans = 0;

        for(int i=0; i<canvas.length; )
        {
            if( canvas[i] != paint[i] )
            {
                int cur = canvas[i] ^ paint[i]; // found one color
                if((cur & 1) > 0)
                {
                    cur = 1;
                }
                else if((cur & 2) > 0)
                {
                    cur = 2;
                }
                else
                {
                    cur = 4;
                }

                ans++;

                for(int j=i; j<canvas.length; j++)
                {
                    if( (cur & paint[j]) > 0  && (canvas[j] & cur) == 0 ) //I have already had, then skip
                    {
                        canvas[j] += cur;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                i++;
            }


        }


        return ans;

    }

}

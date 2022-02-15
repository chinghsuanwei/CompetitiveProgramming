import java.util.Scanner;

/** Starter code for the Kick Start 2022 problem Hex. */
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of test cases.
        int t = scanner.nextInt();
        for (int caseIndex = 1; caseIndex <= t; caseIndex++) {
            // Read the board size.
            int n = scanner.nextInt();
            // Read each row of the board.
            char[][] board = new char[n][];
            for (int i = 0; i < n; i++) {
                board[i] = scanner.next().toCharArray();
            }
            // Determine the game status and display it.
            String status = determineStatus(board);
            System.out.println("Case #" + caseIndex + ": " + status);
        }
    }

    static int n;
    /** Returns a status string as specified by the Hex problem statement. */
    static String determineStatus(char[][] board) {
        // TODO(you): Implement this method to solve the problem!
        //dfs for every node, also record state
        n = board.length;

        int R = 0;
        int B = 0;

        for(int r=0; r<n; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(board[r][c] == 'R')
                {
                    R++;
                }
                else if(board[r][c] == 'B')
                {
                    B++;
                }
            }
        }

        //upper and lower connected is red win

        if(Math.abs(R - B) > 1) return "Impossible";

        //just check top
        boolean redWin = false;

        for(int c=0; c<n; c++)
        {
            if(board[0][c] == 'R')
            {
                boolean result = dfs_R(board, 0, c);
                if(redWin && result)
                {
                    return "Impossible";
                }
                redWin |= result; // two route are available
            }
        }

        boolean blueWin = false;
        for(int r=0; r<n; r++)
        {
            if(board[r][0] == 'B')
            {
                boolean result = dfs_B(board, r, 0);
                if(blueWin && result)
                {
                    return "Impossible";
                }
                blueWin |= result; // two route are available
            }
        }

        if(blueWin && redWin)
        {
            return "Impossible";
        }
        else if(blueWin)
        {
            return "Blue wins";
        }
        else if(redWin)
        {
            return "Red wins";
        }
        else
        {
            return "Nobody wins";
        }
    }

    static boolean dfs_R(char[][] board, int r, int c)
    {
        if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] != 'R')
            return false;

        boolean result = false;
        if(r == n-1)
        {
            board[r][c] = '.';
            result = true;
            return true;
        }

        board[r][c] = '.';

        if( dfs_R(board, r, c-1) ) return true;
        if( dfs_R(board, r+1, c-1) ) return true;
        if( dfs_R(board, r+1, c) ) return true;
        if( dfs_R(board, r, c+1) ) return true;

        return false;
    }

    static boolean dfs_B(char[][] board, int r, int c)
    {
        if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] != 'B')
            return false;

        board[r][c] = '.';

        boolean result = false;
        if(c == n-1)
        {
            result = true;
            return true;
        }



        if( dfs_B(board, r-1, c) ) return true;
        if( dfs_B(board, r-1, c+1) ) return true;
        if( dfs_B(board, r, c+1) ) return true;
        if( dfs_B(board, r+1, c) ) return true;

        return false;
    }
}

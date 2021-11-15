import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.*;

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

    private static class Node{
        Node left;
        Node right;
        int val;

        Node(int val)
        {
            this.val = val;
        }
    }

    private static String solve(String s, int N) {


        Node head = new Node(-1);
        Node cur = head;
        Node node = null;
        Queue<Node> queues[] = new LinkedList[10];
        for(int i=0; i<10; i++)
        {
            queues[i] = new LinkedList<Node>();
        }
        for(int i=0; i<s.length(); i++)
        {
            int val = s.charAt(i) - '0';
            node = new Node( val );
            queues[val].add(node);
            cur.right = node;
            node.left = cur;

            cur = node;
        }

        Node tail = new Node(-1);
        node.right = tail;
        tail.left = node;


        boolean solved = false;
        while(!solved)
        {
            solved = true;

            for(int i=0; i<=9; i++)
            {
                //System.out.println(  dump(head) );
                solved &= remove(queues, i);
            }



        }

        StringBuilder sb = new StringBuilder();
        node = head.right;
        while(node != tail)
        {
            sb.append((char)('0' + node.val));
            node = node.right;
        }

        return sb.toString();
    }

    private static String dump(Node head) {
        StringBuilder sb = new StringBuilder();
        Node node = head.right;
        while(node.val != -1)
        {
            sb.append((char)('0' + node.val));
            node = node.right;
        }

        return sb.toString();
    }

    private static boolean remove(Queue<Node>[] queues, int i) {
        Node node;
        int target = (i +1) % 10;
        int new_val = (i +2) % 10;
        int new_val2 = (i +3) % 10;


        boolean solved = true;

        while(queues[i].size() > 0)
        {
            node = queues[i].poll();
            if( node.val != i || node.right == null || node.left == null) continue;

            if( node.right.val != -1 && node.right.val == target)
            {
                //System.out.println("Solve " + node.val);
                node.val = new_val;

                Node next_node = node.right;
                Node next_next_node = node.right.right;
                next_node.left = null;
                next_node.right = null;

                node.right = next_next_node;
                next_next_node.left = node;


                if(node.left.val == target) queues[target].add(node.left);
                if(node.right.val == new_val2) queues[new_val].add(node);

                solved = false;
            }

        }
        queues[i].clear();

        return solved;
    }

}

import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int n, m, v;
    static int map[][];
    static boolean bfs_check[];
    static boolean dfs_check[];

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();

        map = new int[n + 1][n + 1];

        for (int i = 0; i < m; i++) {
            int from, to;
            from = sc.nextInt();
            to = sc.nextInt();

            map[from][to] = 1;
            map[to][from] = 1;
        }
        bfs_check = new boolean[n + 1];
        dfs_check = new boolean[n + 1];

        dfs(v);
        System.out.println();
        bfs(v);

        sc.close();
    }

    static void dfs(int node) {
        System.out.print(Integer.toString(node) + ' ');
        dfs_check[node] = true;

        for (int i = 1; i <= n; i++) {
            if (map[node][i] == 1 && dfs_check[i] == false) {
                dfs(i);
            }
        }
    }

    static void bfs(int start) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(start);
        bfs_check[start] = true;

        System.out.print(Integer.toString(start) + ' ');

        while (!q.isEmpty()) {
            int cnt = q.remove();

            for (int i = 1; i <= n; i++) {
                if (map[cnt][i] == 1 && bfs_check[i] == false) {
                    bfs_check[i] = true;
                    q.offer(i);
                    System.out.print(Integer.toString(i) + ' ');
                }
            }
        }
    }
}
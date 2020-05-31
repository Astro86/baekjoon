import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int map[][];
    static boolean check[][];
    static int dx[] = { 1, -1, 0, 0 };
    static int dy[] = { 0, 0, 1, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        check = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String row = br.readLine().trim();

            for (int j = 0; j < m; j++) {
                map[i][j] = row.charAt(j) - '0';
            }
        }

        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
        // System.out.print(map[i][j]);
        // }
        // System.out.println();
        // }

        System.out.println(bfs(0, 0));

        br.close();
    }

    static class pair {
        int y;
        int x;

        public pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static int bfs(int y, int x) {
        Queue<pair> q = new LinkedList<>();
        q.offer(new pair(y, x));
        check[y][x] = true;
        int num = 0;

        while (!q.isEmpty()) {
            num++;
            int q_size = q.size();
            while (q_size-- != 0) {
                pair cnt = q.remove();

                if ((cnt.y == n - 1) && (cnt.x == m - 1)) {
                    return num;
                }

                for (int i = 0; i < 4; i++) {
                    int ny = cnt.y + dy[i];
                    int nx = cnt.x + dx[i];

                    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                        if (map[ny][nx] == 1 && check[ny][nx] == false) {
                            check[ny][nx] = true;
                            q.offer(new pair(ny, nx));
                        }
                    }
                }
            }
        }
        return num;
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String s_arr[] = br.readLine().split(" ");
            int a = Integer.parseInt(s_arr[0]);
            int b = Integer.parseInt(s_arr[1]);
            System.out.println(2 + b - a);
        }

        br.close();
    }
}
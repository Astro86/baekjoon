import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine().toUpperCase();

        int check[] = new int[26];
        for (int i = 0; i < s.length(); i++) {
            check[s.charAt(i) - 'A']++;
        }

        int max_num = 0;
        int num = 0;
        int index = 0;

        for (int i = 0; i < 26; i++) {
            if (max_num < check[i]) {
                max_num = check[i];
            }
        }

        for (int i = 0; i < 26; i++) {
            if (max_num == check[i]) {
                index = i;
                num++;
            }
        }

        if (num >= 2) {
            System.out.println('?');
        } else {
            System.out.println((char) ('A' + index));
        }

        br.close();
    }
}
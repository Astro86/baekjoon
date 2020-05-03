import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int num = n;

        while (n-- != 0) {
            boolean arr[] = new boolean[26];
            String word = br.readLine().trim();

            for (int i = 0; i < word.length(); i++) {
                if (arr[word.charAt(i) - 'a'] == false) {
                    arr[word.charAt(i) - 'a'] = true;
                    char cntChar = word.charAt(i);
                    while (i + 1 < word.length() && word.charAt(i + 1) == cntChar) {
                        i++;
                    }
                } else {
                    num--;
                    break;
                }
            }
        }

        System.out.println(num);
        br.close();
    }
}
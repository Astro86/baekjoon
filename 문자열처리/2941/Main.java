import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine().trim();
        String croatia_word[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

        for (int i = 0; i < croatia_word.length; i++) {
            word = word.replace(croatia_word[i], "*");
        }

        System.out.println(word.length());

        br.close();
    }
}
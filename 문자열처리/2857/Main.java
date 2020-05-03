import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean isContain = false;

        for (int i = 1; i <= 5; i++) {
            String code_name = br.readLine();

            if (code_name.contains("FBI")) {
                isContain = true;
                System.out.print(Integer.toString(i) + ' ');
            }
        }

        if (!isContain) {
            System.out.println("HE GOT AWAY!");
        }

        br.close();
    }
}
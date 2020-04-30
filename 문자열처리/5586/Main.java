import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int JOI_num = 0;
        int IOI_num = 0;

        for (int i = 0; i < s.length() - 2; i++) {
            String subString = s.substring(i, i + 3);

            if (subString.equals("JOI")) {
                JOI_num++;
            }

            if (subString.equals("IOI")) {
                IOI_num++;
            }
        }

        System.out.println(JOI_num);
        System.out.println(IOI_num);

        br.close();
    }
}
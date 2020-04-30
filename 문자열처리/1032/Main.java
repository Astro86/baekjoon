import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        String arr[] = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine().trim();
        }
        ;
        char command[] = new char[arr[0].length()];

        for (int i = 0; i < arr[0].length(); i++) {
            command[i] = arr[0].charAt(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < arr[0].length(); j++) {
                if (command[j] != arr[i].charAt(j)) {
                    command[j] = '?';
                }
            }
        }

        for (int i = 0; i < arr[0].length(); i++) {
            System.out.print(command[i]);
        }

        br.close();
    }
}
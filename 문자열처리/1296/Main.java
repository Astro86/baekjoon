import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String minsik = br.readLine().trim();
        int minsik_arr[] = new int[26];

        for (int i = 0; i < minsik.length(); i++) {
            minsik_arr[minsik.charAt(i) - 'A']++;
        }

        int n = Integer.parseInt(br.readLine().trim());
        ArrayList<String> name_list = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            name_list.add(br.readLine().trim());
        }
        Collections.sort(name_list);

        int max_value = -1;
        String max_name = "";
        for (int i = 0; i < name_list.size(); i++) {
            String name = name_list.get(i);
            int arr[] = new int[26];
            for (int j = 0; j < name.length(); j++) {
                arr[name.charAt(j) - 'A']++;
            }

            int L = minsik_arr['L' - 'A'] + arr['L' - 'A'];
            int O = minsik_arr['O' - 'A'] + arr['O' - 'A'];
            int V = minsik_arr['V' - 'A'] + arr['V' - 'A'];
            int E = minsik_arr['E' - 'A'] + arr['E' - 'A'];

            int value = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E));
            value %= 100;

            if (max_value < value) {
                max_value = value;
                max_name = name;
            }
        }

        System.out.println(max_name);

        br.close();
    }
}
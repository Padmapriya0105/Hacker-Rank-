import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TagExtractor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());
        String regex = "<([^>]+)>([^<>]+)</\\1>";
        Pattern p = Pattern.compile(regex);
        while (testCases-- > 0) {
            String line = in.nextLine();
            Matcher m = p.matcher(line);
            boolean found = false;
            while (m.find()) {
                System.out.println(m.group(2));
                found = true;
            }
            if (!found) {
                System.out.println("None");
            }
        }
        in.close();
    }
}

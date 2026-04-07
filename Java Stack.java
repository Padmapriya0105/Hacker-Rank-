import java.util.*;

class Solution {
    public static void main(String []argh) {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext()) {
            String input = sc.next();
            System.out.println(isBalanced(input));
        }
    }
    
    public static boolean isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char current = s.charAt(i);
            if (current == '(' || current == '[' || current == '{') {
                stack.push(current);
            } else {
                if (stack.isEmpty()) return false;
                char last = stack.pop();
                if (current == ')' && last != '(') return false;
                if (current == ']' && last != '[') return false;
                if (current == '}' && last != '{') return false;
            }
        }
        return stack.isEmpty();
    }
}

public class exp1 {
    static class Stack {
        int arr[];
        int top = -1;

        Stack(int size) { // constructor
            arr = new int[size];
        }

        public void push(int value) {
            if (top == arr.length - 1) {
                System.out.println("Stack Overflow");
                return;
            }
            top++;
            arr[top] = value;
        }

        public int pop() {
            if (top == -1) {
                System.out.println("Stack underflow");
                return -1;
            }
            int value = arr[top];
            top--;
            return value;
        }

        public boolean isEmpty() {
            return top == -1;
        }
    }

    public static int evaluate(String exp) {
        Stack stack = new Stack(exp.length());
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp.charAt(i);
            if (Character.isDigit(ch)) {// store it in stack
                int num = ch - '0';// converting char to int
                stack.push(num);
            } else {// pop it out
                int b = stack.pop();
                int a = stack.pop();
                switch (ch) {
                    case '+':
                        stack.push(a + b);
                        break;
                    case '-':
                        stack.push(a - b);
                        break;
                    case '*':
                        stack.push(a * b);
                        break;
                    case '/':
                        stack.push(a / b);
                        break;
                }
            }
        }
        return stack.pop();

    }

    public static void main(String[] args) {
        String exp = "23*54*+9-";
        String exp1 = "82/53*+41-/";
        String exp2 = "82+35*+64/72-*+";
        System.out.println(evaluate(exp));
        System.out.println(evaluate(exp1));
        System.out.println(evaluate(exp2));
    }
}

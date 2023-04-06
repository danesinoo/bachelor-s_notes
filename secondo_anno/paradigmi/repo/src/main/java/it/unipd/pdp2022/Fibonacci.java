package it.unipd.pdp2022;

import java.util.HashMap;
import java.util.Map;

public class Fibonacci {

  static int fibonacciSwitch(int n) {
    return switch (n) {
      case 0 -> 0;
      case 1 -> 1;
      default -> fibonacciSwitch(n - 2) + fibonacciSwitch(n - 1);
    };
  }

  static int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 2) + fibonacci(n - 1);
  }

  private static Map<Integer, Integer> memo = new HashMap<>();

  static {
    memo.put(0, 0);
    memo.put(1, 1);
  }

  public static int fibonacciMemo(int i) {
    return memo.computeIfAbsent(i, n -> fibonacciMemo(n - 2) + fibonacciMemo(n - 1));
  }
}

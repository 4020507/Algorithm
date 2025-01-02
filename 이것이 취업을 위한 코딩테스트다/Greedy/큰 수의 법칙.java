package org.example;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.next());
        int M = Integer.parseInt(scanner.next());
        int K = Integer.parseInt(scanner.next());

        List<Integer> numberList = new ArrayList<>();

        for(int i = 0;i < N;i++) {
            int num = Integer.parseInt(scanner.next());
            numberList.add(num);
        }

        var sortedList = numberList.stream().sorted(Collections.reverseOrder()).toList();
        int sum = M / K * K * sortedList.get(0) + M % K * sortedList.get(1);

        System.out.println(sum);
    }
}

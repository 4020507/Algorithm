package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        
        List<Integer> coins = new ArrayList<>();
        coins.addAll(Arrays.asList(500, 100, 50, 10));

        int cnt = 0;
        for(var coin : coins) {
            cnt += N / coin;
            N = N % coin;
        }

        System.out.println(cnt);
    }
}

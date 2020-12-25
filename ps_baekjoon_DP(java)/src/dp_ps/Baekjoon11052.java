package dp_ps;

import java.util.Scanner;

/* BAEKJOON 11052 PROBLEM */
public class Baekjoon11052 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] num = new int[n+1];
		long[] dp = new long[n+1];
		
		for(int i = 1; i <= n; i++) {
			num[i] = sc.nextInt();
		}
		
		dp[0] = num[0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				dp[i] = Math.max(dp[i], dp[i-j] + num[j]);
			}
		}
		System.out.println(dp[n]);
		sc.close();
	}
}
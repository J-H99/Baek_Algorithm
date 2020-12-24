package dp_ps;

import java.util.Scanner;

/* BAEKJOON 11053 PROLBEM */
public class Baekjoon11053 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] N_ar = new int[n];
		int[] dp = new int[n];
		int max;
		
		for(int i = 0; i < n; i++) {
			N_ar[i] = sc.nextInt();
		}
		
		dp[0] = 1;
		for(int i = 1; i < n; i++) {
			max = 0;
			for(int j = i-1; j >= 0; j--) {
				if(N_ar[j] < N_ar[i]) {
					max = Math.max(dp[j], max);
				}
			}
			dp[i] = max + 1;
		}
		
		max = 0;
		for(int i = 0; i < n; i++) {
			if(max < dp[i]) {
				max = dp[i];
			}
		}
		System.out.println(max);
		sc.close();
	}
}
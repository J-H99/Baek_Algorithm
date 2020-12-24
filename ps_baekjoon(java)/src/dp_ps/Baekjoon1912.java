package dp_ps;

import java.util.Scanner;

/* BAEKJOON 1912 PROBLEM */
public class Baekjoon1912 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] n_ar = new int[n];
		int[] dp = new int[n];
		int max;
		
		for(int i = 0; i < n; i++) {
			n_ar[i] = sc.nextInt();
		}
		
		if(n == 1) {
			System.out.println(n_ar[0]);
		} else if (n >= 2) {
			dp[0] = n_ar[0];
			for(int j = 1; j < n; j++) {	
				if(dp[j-1]> 0) {
					dp[j] = dp[j-1] + n_ar[j];
				} else if(dp[j-1] <= 0) {
					dp[j] = n_ar[j];
				}
			}
			max = dp[0];
			for(int i = 0; i < n; i++) {
				if(max < dp[i]) {
					max = dp[i];
				}
			}	
			System.out.println(max);
		}
		sc.close();
	}
}
package dp_ps;

import java.util.Scanner;

/* BAEKJOON 9461 PROBLEM */
public class Baekjoon9461 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] N_arr = new int[T];

		int max = 0;
		
		for(int i = 0; i < T; i++) {
			N_arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < T; i++) {
			if(max < N_arr[i]) {
				max = N_arr[i];
			}
		}
		long[] dp = new long[max];		
		if(max == 1) {
			dp[0] = 1;
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i]-1]);
			}
		} else if (max == 2) {
			dp[0] = 1;
			dp[1] = 1;
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i]-1]);
			}
		} else if (max == 3) {
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 1;
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i]-1]);
			}
		} else if (max == 4) {
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 1;
			dp[3] = 2;
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i]-1]);
			}
		} else if (max == 5) {
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 1;
			dp[3] = 2;
			dp[4] = 2;
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i]-1]);
			}
		} else if (max >= 6)
			dp[0] = 1;
			dp[1] = 1;
			dp[2] = 1;
			dp[3] = 2;
			dp[4] = 2;
			for(int i = 5; i < max; i ++) {
				dp[i] = dp[i-1] + dp[i-5];
			}
			
			for(int i = 0; i < T; i++) {
				System.out.println(dp[N_arr[i] - 1]);
			}
		sc.close();	
	}
}
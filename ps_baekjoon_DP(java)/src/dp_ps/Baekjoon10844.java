package dp_ps;

import java.util.Scanner;

/* BAEKJOON 10884 PROBLEM */
public class Baekjoon10844 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[][] dp = new long[N][10];
		int answer = 0;
		
		if (N == 1) {
			System.out.println(9);
		} else {
			dp[0][0] = 0;
			for(int i = 1; i < 10; i++) {
				dp[0][i] = 1;
			}
			
			for(int i = 1; i < N; i++) {
				for(int j = 0; j < 10; j++) {
					if(j == 0) {
						dp[i][j] = dp[i-1][j+1]%1000000000;
					} else if (j == 9) {
						dp[i][j] = dp[i-1][j-1]%1000000000;
					} else {
						dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
					}
				}
			}
			
			for(int i = 0; i < 10; i++) {
				answer += dp[N-1][i];
				answer %= 1000000000;
			}
			System.out.println(answer);
			sc.close();
		}
	}
}
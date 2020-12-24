package dp_ps;

import java.util.Scanner;

/* BAEKJOON 1932 PROBLEM */
public class Baekjoon1932 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] int_triangle = new int[N][];
		int[][] dp = new int[N][];
		int max = 0;
		
		for(int i = 0; i < N; i++) {
			int_triangle[i] = new int[i+1];
			dp[i] = new int[i+1];
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < i+1; j++) {
				int_triangle[i][j] = sc.nextInt();
			}
		}
		
		if(N == 1) {
			System.out.println(int_triangle[0][0]);
		} else if(N == 2) {
			System.out.println(Math.max(int_triangle[0][0] + int_triangle[1][0], int_triangle[0][0] + int_triangle[1][1]));
		} else {
			dp[0][0] = int_triangle[0][0];
			dp[1][0] = int_triangle[0][0] + int_triangle[1][0];
			dp[1][1] = int_triangle[0][0] + int_triangle[1][1];
			
			for(int i = 2; i < N; i++) {
				for(int j = 0; j < i + 1; j++) {
					
					if(j == 0) {
						dp[i][j] = dp[i-1][j] + int_triangle[i][j]; 
					} 
					else if (j == i) {
						dp[i][j] = dp[i-1][j-1] + int_triangle[i][j];
					}
					else {
						dp[i][j] = Math.max(dp[i-1][j-1] + int_triangle[i][j], dp[i-1][j] + int_triangle[i][j]);
					}
				}
			}
			for(int i = 0; i < N; i++) {
				if (max < dp[N-1][i]) {
					max = dp[N-1][i];
				}
			}
			System.out.println(max);
			sc.close();
		}
	}
}
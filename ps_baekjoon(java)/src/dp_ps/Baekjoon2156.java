package dp_ps;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/* BAEKJOON 2156 PROBLEM */
public class Baekjoon2156 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[] alchol = new int[n];
		int[] dp = new int [n];
		
		for(int i = 0; i < n; i++) {
			alchol[i] = Integer.parseInt(br.readLine());
		}
		
		if (n == 1) {
			System.out.println(alchol[0]);
		} else if (n == 2) {
			System.out.println(Math.max(alchol[0] + alchol[1], alchol[1]));
		} else if (n == 3) {
			System.out.println(Math.max(alchol[0] + alchol[2], Math.max(alchol[1] + alchol[2], alchol[0] + alchol[1])));
		} else if (n == 4) {
			System.out.println(Math.max(alchol[0] + alchol[1] + alchol[3], Math.max(alchol[0] + alchol[2] + alchol[3], alchol[1] + alchol[2])));
		} else if (n >= 5) {
			dp[0] = alchol[0];
			dp[1] = Math.max(alchol[0] + alchol[1], alchol[1]);
			dp[2] = Math.max(alchol[0] + alchol[2], Math.max(alchol[1] + alchol[2], alchol[0] + alchol[1]));
			dp[3] = Math.max(alchol[0] + alchol[1] + alchol[3], Math.max(alchol[0] + alchol[2] + alchol[3], alchol[1] + alchol[2]));
			
			for(int i = 4; i < n; i ++) {
				dp[i] = Math.max(alchol[i] + alchol[i-1] + dp[i-3], Math.max(alchol[i] + dp[i-2], Math.max(alchol[i-1] + alchol[i-2] + dp[i-4], alchol[i-1] + dp[i-3])));
			}
			System.out.println(dp[n-1]);
		}
		br.close();
	}
}
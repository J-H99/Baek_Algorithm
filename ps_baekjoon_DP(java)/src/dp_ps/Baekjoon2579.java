package dp_ps;

import java.util.Scanner;

/* BAEKJOON 2579 PROBLEM */
public class Baekjoon2579 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int stairnum = sc.nextInt();
		int[] stair_score = new int[stairnum];
		int[] dp = new int[stairnum];
		
		for(int i = 0; i < stairnum; i++) {
			stair_score[i] = sc.nextInt();
		}
		
		dp[0] = stair_score[0];
		dp[1] = Math.max(dp[0] + stair_score[1], stair_score[1]);
		dp[2] = Math.max(stair_score[0] + stair_score[2], stair_score[1] + stair_score[2]);
		
		for(int i = 3; i < stairnum; i++) {
			dp[i] = Math.max(dp[i-2] + stair_score[i], dp[i-3] + stair_score[i-1] + stair_score[i]);
		}
		System.out.println(dp[stairnum-1]);
		sc.close();
	}
}
package dp_ps;

import java.util.Scanner;

/* BAEKJOON 11727 PROBLEM */
public class Baekjoon11727 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] dp = new long[N];
		
		if(N == 1) {
			System.out.println(1);
		} else if (N == 2) {
			System.out.println(3);
		} else {
			dp[0] = 1;
			dp[1] = 3;
			for(int i = 2; i < N; i++) {
				dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
			}
			System.out.println(dp[N-1]%10007);
		}
		sc.close();
	}
}
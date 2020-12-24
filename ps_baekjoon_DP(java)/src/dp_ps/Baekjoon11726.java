package dp_ps;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/* BAEKJOON 11726 PROBLEM */
public class Baekjoon11726 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] dp = new int[N];
		
        if (N == 1){
            System.out.println(1);
        }
        else if (N == 2) {
        	System.out.println(2);
        }
        else if (N > 3) {
    		dp[0] = 1;
    		dp[1] = 2;
        	for(int i = 2; i < N; i++) {
				dp[i]= (dp[i-1] + dp[i-2])%10007;
			}
			System.out.println(dp[N-1]);
        }
        br.close();
	}
}
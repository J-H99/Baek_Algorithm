package dp_ps;

import java.util.Scanner;

public class Baekjoon1149 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[][] distance_rgb = new int[N][3];
		int[][] solution = new int[N][3];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 3; j++) {
				distance_rgb[i][j] = sc.nextInt();
			}
		}
		
		solution[0][0] = distance_rgb[0][0];
		solution[0][1] = distance_rgb[0][1];
		solution[0][2] = distance_rgb[0][2];
		
		for(int i = 1; i < N; i++) {
			solution[i][0] = Math.min(solution[i-1][1], solution[i-1][2]) + distance_rgb[i][0];
			solution[i][1] = Math.min(solution[i-1][0], solution[i-1][2]) + distance_rgb[i][1];
			solution[i][2] = Math.min(solution[i-1][0], solution[i-1][1]) + distance_rgb[i][2];
		}
		int answer = Math.min(solution[N-1][0], Math.min(solution[N-1][1], solution[N-1][2]));
		System.out.println(answer);
		sc.close();
	}
}
package dp_ps;

import java.util.Scanner;

/* BAEKJOON 1003 PROBLEM */
public class Baekjoon1003 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();
		int[] input_arr = new int[number];
		int max = 0;
		
		for(int i = 0; i < number; i++) {
			input_arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < number; i++) {
			if( max < input_arr[i]) {
				max = input_arr[i];
			}
		}
		
		
		int[][] answer = new int[max+1][2];
		answer[0][0] = 1;
		answer[0][1] = 0;
		answer[1][0] = 0;
		answer[1][1] = 1;
		
		for(int i = 2; i <= max; i++) {
			answer[i][0] = answer[i-1][0] + answer[i-2][0];
			answer[i][1] = answer[i-1][1] + answer[i-2][1];
		}
		
		for(int i = 0; i < number; i++) {
			System.out.println(answer[input_arr[i]][0] + " " + answer[input_arr[i]][1]);
		}
		sc.close();
	}
}
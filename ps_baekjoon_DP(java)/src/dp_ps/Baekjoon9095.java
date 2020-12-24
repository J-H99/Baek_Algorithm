package dp_ps;

import java.util.Scanner;

/* BAEKJOON 9095 PROBLEM */
public class Baekjoon9095 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number_of_input = sc.nextInt();
		int[] input_arr = new int[number_of_input];
		int max_num = 0;
		
		for(int i = 0; i < number_of_input; i++) {
			input_arr[i] = sc.nextInt();
		}
		
		for(int i = 0; i < number_of_input; i++) {
			if (max_num < input_arr[i]) {
				max_num = input_arr[i];
			}
		}
		
		int[] answer = new int[max_num + 1];
		
		answer[1] = 1;
		answer[2] = 2;
		answer[3] = 4;
		
		for(int i = 4; i <= max_num; i++) {
			answer[i] = answer[i-1] + answer[i-2] + answer[i-3];
		}
		
		for(int i = 0; i < number_of_input; i++) {
			System.out.println(answer[input_arr[i]]);
		}
		sc.close();
	}
}
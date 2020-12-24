package dp_ps;

import java.util.Scanner;

/* BAEKJOON 1463 PROBLEM */
public class Baekjoon1463 {

	public static void main(String[] args) {
		int intnum;
		Scanner sc = new Scanner(System.in);
		intnum = sc.nextInt();
		int[] minfrequency = new int[intnum+1];
		minfrequency[0] = minfrequency[1] = 0;
		for(int i =2; i<=intnum; i++) {
			minfrequency[i] = i;
		}
		for(int i = 2; i <= intnum; i++) {
			if(i%2 == 0) {
				minfrequency[i] = minfrequency[i/2] +1;
			}
			
			if(i%3 == 0) {
				minfrequency[i] = Math.min(minfrequency[i], minfrequency[i/3]+1);
			}
			
			minfrequency[i] = Math.min(minfrequency[i], minfrequency[i-1]+1);
		}
		System.out.println(minfrequency[intnum]);
		sc.close();
	}
}
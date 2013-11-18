/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10069.java
*  Create Date: 2013-10-25 20:30:52
*  Descripton:  dp, java
*/

import java.util.Scanner;
import java.math.BigInteger;

public class uva10069 {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger dp[][] = new BigInteger[2][10010];
		int t, n, m;
		String a, b;
		t = cin.nextInt();
		while (t > 0) {
			t--;
			a = cin.next();
			b = cin.next();
			n = a.length();
			m = b.length();
			int k = 0;
			dp[0][0] = dp[1][0] = BigInteger.ZERO;
			for (int j = 0; j < n; j++) {
				dp[k][j + 1] = dp[k][j];
				if (a.charAt(j) == b.charAt(0))
					dp[k][j + 1] = dp[k][j + 1].add(BigInteger.ONE);
			}
			for (int i = 1; i < m; i++) {
				k = (k + 1) % 2;
				for (int j = 0; j < n; j++) {
					dp[k][j + 1] = dp[k][j];
					if (a.charAt(j) == b.charAt(i))
						dp[k][j + 1] = dp[k][j + 1].add(dp[(k + 1) % 2][j]);
				}
			}
			System.out.println(dp[k][n]);
		}
	}
}


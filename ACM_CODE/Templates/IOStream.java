/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        IOStream.java
*  Create Date: 2014-10-06 10:40:03
*  Descripton:  InputStream & OutputStream
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		InputStream ins = System.in;
		OutputStream outs = System.out;
		InputReader in = new InputReader(ins);
		PrintWriter out = new PrintWriter(outs);

		int cas = in.nextInt();
		for (int ca = 1; ca <= cas; ++ ca);
			// go

		out.close();
	}
}

class InputReader {
	public BufferedReader r;
	public StringTokenizer t;

	public InputReader(InputStream st) {
		r = new BufferedReader(new InputStreamReader(st),32768);
		t = null;
	}

	// nextLine
	public String next() {
		while (t == null || !t.hasMoreTokens()) {
			try {
				t = new StringTokenizer(r.readLine());
			} catch(IOException e) {
				throw new RuntimeException(e);
			}
		}
		return t.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

}

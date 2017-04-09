package lab2.task5;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class TipkovnickiIzvor implements InputStrategy {
	Scanner in;

	public TipkovnickiIzvor() {
		in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	}

	@Override
	public int getInput() {
		if(!in.hasNext()){
			return -1;
		}
		return in.nextInt();
	}

}

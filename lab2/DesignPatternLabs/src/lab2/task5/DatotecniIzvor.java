package lab2.task5;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class DatotecniIzvor implements InputStrategy {
	Scanner in;
	
	public DatotecniIzvor(String file) {
		try {
			in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File(file)))));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public int getInput() {
		if(!in.hasNext()){
			return -1;
		}
		return in.nextInt();
	}
}

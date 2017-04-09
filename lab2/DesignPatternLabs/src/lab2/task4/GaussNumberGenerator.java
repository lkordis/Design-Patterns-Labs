package lab2.task4;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class GaussNumberGenerator implements NumberListStrategy {
	private int N;
	private int meanValue;
	private int stdDeviation;
	
	public GaussNumberGenerator(int n, int meanValue, int stdDeviation) {
		N = n;
		this.meanValue = meanValue;
		this.stdDeviation = stdDeviation;
	}

	@Override
	public List<Integer> generateNumbersList() {
		Random rand  = new Random();
		List<Integer> numbers = new ArrayList<>();
		
		for(int i = 0; i < N; i++){
			Double number = rand.nextGaussian()*stdDeviation + meanValue;
			numbers.add(number.intValue());
		}
		Collections.sort(numbers);
		return numbers;
	}
}

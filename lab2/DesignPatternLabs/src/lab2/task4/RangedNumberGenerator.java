package lab2.task4;

import java.util.ArrayList;
import java.util.List;

public class RangedNumberGenerator implements NumberListStrategy {
	private int lowerLimit;
	private int upperLimit;
	private int step;	

	public RangedNumberGenerator(int lowerLimit, int upperLimit, int step) {
		this.lowerLimit = lowerLimit;
		this.upperLimit = upperLimit;
		this.step = step;
	}

	@Override
	public List<Integer> generateNumbersList() {		
		List<Integer> numbers = new ArrayList<>();
		for(int i = this.lowerLimit; i <= this.upperLimit; i+=this.step){
			numbers.add(i);
		}
		return numbers;
	}
}

package lab2.task4;

import java.util.ArrayList;
import java.util.List;

public class FibonacciNumberGenerator implements NumberListStrategy {
	private int N;
	
	public FibonacciNumberGenerator(int n) {
		N = n;
	}

	@Override
	public List<Integer> generateNumbersList() {		
		List<Integer> numbers = new ArrayList<>();
		
		for(int i = 0;  i < N; i++){
			numbers.add(fibonacci(i));
		}
		return numbers;
	}
	
	private int fibonacci(int number) {
	      if ((number == 0) || (number == 1)) return number;
	      else return fibonacci(number - 1) + fibonacci(number - 2);
	   }

}

package lab2.task4;

import java.util.ArrayList;
import java.util.List;

public class InterpolationPercentile implements PercentileStrategy {
	private List<Integer> numbers;
	
	public InterpolationPercentile(List<Integer> numbers) {
		this.numbers = numbers;
	}

	@Override
	public double getPercentile(int percentileNumber) {
		List<Double> rankList = generatePercentRanks();
		
		if(percentileNumber < rankList.get(0)){
			return numbers.get(0);
		}
		if(percentileNumber > rankList.get(numbers.size() - 1)){
			return numbers.get(numbers.size() - 1);
		} 
		
		// v(p) = v[i] + N * (p-p(v[i]))*(v[i+1]-v[i])/100;
		for(int i = 0; i < rankList.size(); i++){
			if(i < rankList.size() -1 && percentileNumber > rankList.get(i) && percentileNumber < rankList.get(i+1)){
				return numbers.get(i) + numbers.size() * (percentileNumber - rankList.get(i)) * (numbers.get(i+1) - numbers.get(i))/100;
			}
		}
		
		return 0.0;
	}
	
	private List<Double> generatePercentRanks(){
		List<Double> rankList = new ArrayList<>();
		int N = numbers.size();
		
		for(int i = 0; i < N; i++){
			Double rank = (100 * (i + 0.5)) / N;
			rankList.add(rank);
		}
		
		return rankList;
	}
}

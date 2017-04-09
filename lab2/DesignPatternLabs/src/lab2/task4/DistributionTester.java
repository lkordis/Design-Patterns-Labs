package lab2.task4;

import java.util.ArrayList;
import java.util.List;

public class DistributionTester {
	private NumberListStrategy numberListStrategy;
	private PercentileStrategy percentileStrategy;
	
	public List<Double> generatePercentiles(){
		List<Double> percentiles = new ArrayList<>();
		
		for(int i = 1; i < 10; i++){
			percentiles.add(getPercentile(i*10));
		}
		
		return percentiles;
	}
	
	public List<Integer> generateNumbersList(){
		return numberListStrategy.generateNumbersList();
	}
	
	public double getPercentile(int percentile){
		return percentileStrategy.getPercentile(percentile);
	}
	
	public NumberListStrategy getNumberListStrategy() {
		return numberListStrategy;
	}
	
	public void setNumberListStrategy(NumberListStrategy numberListStrategy) {
		this.numberListStrategy = numberListStrategy;
	}
	
	public PercentileStrategy getPercentileStrategy() {
		return percentileStrategy;
	}
	
	public void setPercentileStrategy(PercentileStrategy percentileStrategy) {
		this.percentileStrategy = percentileStrategy;
	}	
}

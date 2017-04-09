package lab2.task4;

public class Main {

	public static void main(String[] args) {
		DistributionTester dt = new DistributionTester();
		
		dt.setNumberListStrategy(new RangedNumberGenerator(0, 10, 1));
		System.out.println(dt.getNumberListStrategy().generateNumbersList());
		
		dt.setPercentileStrategy(new NearestRankPercentile(dt.generateNumbersList().size()));
		System.out.println(dt.generatePercentiles());
		
		dt.setPercentileStrategy(new InterpolationPercentile(dt.generateNumbersList()));
		System.out.println(dt.generatePercentiles());
	}

}

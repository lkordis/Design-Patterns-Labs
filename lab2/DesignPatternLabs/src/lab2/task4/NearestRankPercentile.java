package lab2.task4;

public class NearestRankPercentile implements PercentileStrategy {
	private int numberOfElements;

	public NearestRankPercentile(int numberOfElements) {
		this.numberOfElements = numberOfElements;
	}

	@Override
	public double getPercentile(int percentileNumber) {
		Double percentile = (percentileNumber*numberOfElements)/100 + 0.5;
		return Math.ceil(percentile);
	}

}

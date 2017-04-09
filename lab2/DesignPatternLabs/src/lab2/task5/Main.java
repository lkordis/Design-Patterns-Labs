package lab2.task5;

public class Main {

	public static void main(String[] args) {
		SlijedBrojeva sb = new SlijedBrojeva();
		sb.setIzvor(new TipkovnickiIzvor());
		
		new NumbersSum(sb);
		new NumbersAverage(sb);
		new NumbersMedian(sb);
		
		sb.kreni();
	}

}

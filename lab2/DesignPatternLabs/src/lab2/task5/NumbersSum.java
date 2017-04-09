package lab2.task5;

public class NumbersSum extends Observer {

	public NumbersSum(SlijedBrojeva slijedBrojeva) {
		this.slijedBrojeva = slijedBrojeva;
		this.slijedBrojeva.subscribe(this);
	}
	
	@Override
	public void doAction() {
		System.out.println("Suma brojeva niza: " + getNumbersSum());
	}
	
	private int getNumbersSum(){
		int sum = 0;
		
		for(int i : slijedBrojeva.getSlijed()){
			sum += i;
		}
		
		return sum;
	}
}

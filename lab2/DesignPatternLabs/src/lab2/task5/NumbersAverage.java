package lab2.task5;

public class NumbersAverage extends Observer {
	
	public NumbersAverage(SlijedBrojeva slijedBrojeva) {
		this.slijedBrojeva = slijedBrojeva;
		this.slijedBrojeva.subscribe(this);
	}

	@Override
	public void doAction() {
		System.out.println("Prosjek brojeva u nizu: " + getAverage());
	}
	
	private double getAverage(){
		double res = 0;
		
		for(int i : this.slijedBrojeva.getSlijed()){
			res += i;
		}
		
		return res/this.slijedBrojeva.getSlijed().size();
	}

}

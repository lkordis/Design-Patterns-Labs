package lab2.task5;

import java.util.Collections;
import java.util.List;

public class NumbersMedian extends Observer {
	
	public NumbersMedian(SlijedBrojeva slijedBrojeva) {
		this.slijedBrojeva = slijedBrojeva;
		this.slijedBrojeva.subscribe(this);
	}

	@Override
	public void doAction() {
		System.out.println("Medijan: " + findMedian());
	}
	
	private double findMedian(){
		int size = this.slijedBrojeva.getSlijed().size();
		List<Integer> list = this.slijedBrojeva.getSlijed();
		Collections.sort(list);
		
		if(size % 2 == 0){
			int middle = (size+1) / 2;
			
			return (list.get(middle-1) + list.get(middle)) / 2;
		} else {
			return list.get((size - 1)/2);
		}
	}

}

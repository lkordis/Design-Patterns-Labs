package lab2.task5;

import java.util.ArrayList;
import java.util.List;

public class SlijedBrojeva {
	private InputStrategy izvor;
	private List<Integer> slijed = new ArrayList<>();
	private List<Observer> observers = new ArrayList<Observer>();

	public void kreni() {
		Runnable r = new Runnable() {
			public void run() {
				int in;
				while ((in = izvor.getInput()) != -1) {
					updateSlijed(in);
					synchronized (this) {
						notifyAll();
					}
				}
			}
		};
		
		r.run();
		
		synchronized (this) {
			try {
				wait(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public void subscribe(Observer observer) {
		observers.add(observer);
	}

	public InputStrategy getIzvor() {
		return izvor;
	}

	public void setIzvor(InputStrategy izvor) {
		this.izvor = izvor;
	}

	public List<Integer> getSlijed() {
		return slijed;
	}

	public void updateSlijed(int number) {
		slijed.add(number);
		notifyObservers();
	}

	public void notifyObservers() {
		for (Observer o : observers) {
			o.doAction();
		}
	}
}

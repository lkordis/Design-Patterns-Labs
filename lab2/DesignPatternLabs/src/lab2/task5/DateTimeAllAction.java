package lab2.task5;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DateTimeAllAction extends Observer {
	File file;
	
	public DateTimeAllAction(SlijedBrojeva slijedBrojeva, File file) {
		this.slijedBrojeva = slijedBrojeva;
		this.slijedBrojeva.subscribe(this);
		
		this.file = file;
	}

	@Override
	public void doAction() {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Date date = new Date();
		System.out.println(dateFormat.format(date));
		
		BufferedWriter bw = null;
		FileWriter fw = null;
		
		try {
			String content = "Vrijeme i datum promjene: " +  dateFormat.format(date) + ", brojevi u slijedu: " + slijedBrojeva.getSlijed();

			fw = new FileWriter(file);
			bw = new BufferedWriter(fw);
			bw.write(content);

			System.out.println("Done");
			
		} catch (IOException e) {
			e.printStackTrace();
			
		} finally {
			try {
				if (bw != null)
					bw.close();

				if (fw != null)
					fw.close();
				
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}

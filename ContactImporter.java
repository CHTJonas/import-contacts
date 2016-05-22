package importContacts;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.URL;
import java.net.URLConnection;
import java.util.LinkedList;
import java.util.List;

public class ContactImporter {
	
	private String filepath = null;
	private int rows = -1;
	private int columns = -1;
	private String[][] table = null;
	
	public ContactImporter(String path) {
		filepath = path;
		Object[] lines;
		try {
			if (filepath.startsWith("http://") || filepath.startsWith("https://")) {
				lines = loadFromURL(filepath).toArray();
			}
			else {
				lines = loadFromDisk(filepath).toArray();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		
		// there is no way in which these casting can fail?
		rows = lines.length;
		columns = ((String) lines[0]).split(",").length;
		table = new String[rows][columns];
		for (int i = 0 ; i < lines.length ; i++) {
			table[i] = ((String) lines[i]).split(",");
		}
	}
	
	private static List<String> loadFromDisk(String filename) throws IOException {
		return load(new FileReader(filename));
	}
	
	private static List<String> loadFromURL(String url) throws IOException {
		URL destination = new URL(url);
		URLConnection conn = destination.openConnection();
		return load(new InputStreamReader(conn.getInputStream()));
	}
	
	private static List<String> load(Reader r) throws IOException {
		List<String> CSVlines = new LinkedList<String>();
		BufferedReader buff = new BufferedReader(r);
		String readString = buff.readLine();
		while (readString != null) {
			CSVlines.add(readString);
			readString = buff.readLine();
		}
		return CSVlines;
	}
	
	public void iread() {
		System.out.println(TextStrings.I_READ_MESSAGE);
		for (String[] row : table) {
			String output = "";
			for (String cell : row) {
				output += cell;
				output += ",";
			}
			output = output.substring(0, output.length() - 1);
			System.out.println(output);
		}
	}
	
	public String[] getColumn(int col) {
		String[] result = new String[rows];
		for (int i = 0 ; i < rows ; i++) {
			result[i] = table[i][col];
		}
		return result;
	}
	
	public String[] getColumn(int col, boolean omitFirst) {
		if (omitFirst = false) return getColumn(col);  
		String[] result = new String[rows - 1];
		for (int i = 1 ; i < rows ; i++) {
			result[i - 1] = table[i][col];
		}
		return result;
	}
}
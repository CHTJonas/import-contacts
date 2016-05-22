package importContacts;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	/*
	 * /Users/charlie/Downloads/twt.csv
	 */
	
	private static BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
	private static String[] fullNames = null;
	private static String[] firstNames = null;
	private static String[] lastNames = null;
	private static String[] mobileNumbers = null;
	private static String[] crsids = null;
	private static String[] emails = null;
	
	public static void main(String[] args) throws java.io.IOException {
		
		// deal with any command line arguments
		try {
			// no command line argument specified
			if (args.length != 0) {
				String exceptionMessage = TextStrings.EXCEPTION_MESSAGE;
				// add each argument to the error message
				for (int i = 0; i < args.length; i++) {
					exceptionMessage += args[i];
				}
				// and raise the exception
				throw new ArgsException(exceptionMessage);
			}
		} catch (ArgsException e) {
			// print error to user
			System.out.println(e.getMessage());
			// quit
			System.out.println(TextStrings.EXITING_MESSAGE);
			return;
		}
		
		
		System.out.print(TextStrings.READPATH_ENTRY_MESSAGE);
		// declare a new object instance
		ContactImporter importer = new ContactImporter(consoleReader.readLine());
		
		blankLine();
		
		// print out the stuff
		importer.iread();
		
		blankLine();
		
		// establish which columns have the stuff in
		BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
		System.out.print(TextStrings.NAMES_ENTRY_MESSAGE);
		int namesCol = Integer.parseInt(consoleReader.readLine());
		System.out.print(TextStrings.CRSID_ENTRY_MESSAGE);
		int crsidCol = Integer.parseInt(consoleReader.readLine());
		System.out.print(TextStrings.MOBILE_ENTRY_MESSAGE);
		int mobileCol = Integer.parseInt(consoleReader.readLine());

		// initialise arrays
		fullNames = importer.getColumn(namesCol, true);
		crsids = importer.getColumn(crsidCol, true);
		mobileNumbers = importer.getColumn(mobileCol, true);
		firstNames = new String[fullNames.length];
		lastNames = new String[fullNames.length];
		for (int i = 0 ; i < fullNames.length ; i++) {
			String[] split = fullNames[i].split(" ");
			firstNames[i] = split[0];
			lastNames[i] = split[split.length - 1];
		}
		emails = new String[crsids.length];
		for (int i = 0 ; i < crsids.length ; i++) {
			emails[i] = crsids[i] + "@cam.ac.uk";
		}
		
		blankLine();
		
		System.out.print(TextStrings.SAVEPATH_ENTRY_MESSAGE);
		String savePath = consoleReader.readLine();
		
		// pause for development
		while (true) {}
	}
	
	private static void blankLine() {
		System.out.println();
	}
}
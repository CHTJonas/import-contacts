#!/usr/local/bin/python3

import csv
import sys

version      = "1b"
revisionDate = "20160509T2139"

print ()
print ("CSVCI (Comma-Separated Values Contact Importer)")
print ("Copyright (C) 2016  Charles Henry Tiquet Jonas.")
print ()
print ("This program comes with ABSOLUTELY NO WARRANTY; for details type 'show warr'.")
print ("This is free software, and you are welcome to redistribute it")
print ("under certain conditions; type 'show cond' for details.")
print ()
print ("For help type 'show help'.")
print ("For more information type 'ver'.")
print ("To get started importing data type 'import'.")
print ()
option = input("CSVCI> ")

if option == "show warr" :
	print ("show warr")
elif option == "show cond" :
	print ("show cond")
elif option == "show help" :
	print ("show help")
elif option == "ver" :
	print ("Version {} released {}".format(version, revisionDate))
elif option == "import" :
	print ("import")
else :
	print ("Unknown option, try 'show help'.")

input = input("Enter something: ")
print ("you entered " + input) 



# res = int(input("Enter a number: "))




# filename = '/Users/charlie/Downloads/twt.csv'
# with open(filename, 'rb') as file:
#     reader = csv.reader(file)
#     try:
#         for row in reader:
#             print row
#     except csv.Error as e:
#         sys.exit('file %s, line %d: %s' % (filename, reader.line_num, e))
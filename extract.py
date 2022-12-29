#load file for extracting data
import os
import sys
import csv

#load text file for extracting data
def load_file(filename):
    file = open(filename, "r")
    text = file.read()
    file.close()
    return text

file = load_file("./English-Protocol-Aphasia/ACWT/ACWT01a.cha")
#print intial lines
# print(file[:1000])



#remove all words of the form 6810_9380 and others like it using regex for example - <4-digit-number> in string format + '_' + <4-digit-number> in string format
def remove_numbers(file):
    import re
    file = re.sub(r'\d{4,5}_\d{4,5}', '', file)
    return file

#replace "+..?" with ?
def replace_plus(file):
    import re
    file = re.sub(r'\+\.\.\?', '?', file)
    return file

#replace "+/?" with ?
def replace_plus_slash(file):
    import re
    file = re.sub(r'\+\/\?', '?', file)
    return file

#replace "+//?" with ?
def replace_plus_slash_slash(file):
    import re
    file = re.sub(r'\+\/\/\?', '?', file)
    return file


file = remove_numbers(file)
#print file after removing numbers
print(file[:1000])





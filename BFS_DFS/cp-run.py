#! /usr/bin/python3
# for competitive programing

import os, sys

try:
	file_name = sys.argv[1]
	program, file_type = map(str, file_name.split('.'))
	path = ''
	if file_type == 'cpp':
		cpp = f"g++ -std=c++20 {file_name} -o {program} && timeout 10s ./{program}<{path}inputf.txt>{path}outputf.txt"
		try:
			os.system(cpp)
			print("Compile done!")
		except:
			print("Compile failed!")
	else:
		py = f"timeout 4s python3 {file_name} <{path}inputf.txt>{path}outputf.txt"
		try:
			os.system(py)
			print("Python worked!")
		except:
			print("Python failed!")
except:
	print("Failed!")
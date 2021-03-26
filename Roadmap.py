#!/usr/bin/env python3

####################################################################################################
# TODO
#
# - progress bar for each dir
# - Ok icon
# - ignores
# - draw "brances"
#
####################################################################################################


import os
import os.path
import fnmatch
import re

from pathlib import Path
####################################################################################################
## prefix components:
# space =  '    '
# branch = '│   '
## pointers:
# tee =    '├── '
# last =   '└── '

####################################################################################################
def dirProcess(level, dirPath, files):
	if (level == 1):
		isRootSubDir = True
	else:
		isRootSubDir = False

	indent    = ' ' * 3 * (level - 1)
	subindent = ' ' * 2 * (level + 1)

	# print('dirPath: {}'.format(dirPath))

	# dir
	print('{}* <details>'.format(indent))

	if (isRootSubDir):
		print('{}  <summary><b>{}/</b></summary>'.format(indent, os.path.basename(dirPath)))
	else:
		print('{}  <summary>{}/ ({})</summary>'.format(indent, os.path.basename(dirPath), len(files)))


	# files
	print('\n')
	for f in files:
		print('{}* `{}`'.format(subindent, Path(f).name))
	print('\n')

	print('{}  </details>'.format(indent))
	print('\n')

####################################################################################################
def rootDirProcess():
	rootPath = str(Path.cwd());

	filesIncludes = ['*.h', '*.inl', '*.hpp', '*.cpp', '*.sql', '*.txt', '*.html', '*.htm', '*.js']
	dirsExcludes  = ['.git', 'StdStream', 'StdTest', 'res']

	# glob patterns -> regular expressions
	filesIncludes = r'|'.join([fnmatch.translate(x) for x in filesIncludes])

	isRootSubDir = False

	for dirPath, dirs, files in os.walk(rootPath):
		# exclude dirs
		dirs[:] = [d for d in dirs if d not in dirsExcludes]

		# exclude/include files
		files = [os.path.join(dirPath, f) for f in files]
		files = [f for f in files if re.match(filesIncludes, f)]

		level = dirPath.replace(rootPath, '').count(os.sep)
		if (level == 0):
			continue
		# print('level: {}'.format(level))

		dirProcess(level, dirPath, files)
	# for

####################################################################################################
def main():
	# <style>
	# r { color: Red }
	# o { color: Orange }
	# g { color: Green }
	# </style>

	print('# C++ Roadmap')
	print('')
	print('<div style="background-color:black">')
	print('')

	rootDirProcess()

	print('</div>')

####################################################################################################
if __name__ == "__main__":
    main()
####################################################################################################
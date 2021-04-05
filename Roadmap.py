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
import math

from pathlib     import Path
from collections import defaultdict
from functools   import partial
from itertools   import repeat
####################################################################################################
def nested_defaultdict(default_factory, depth=1):
    result = partial(defaultdict, default_factory)

    for _ in repeat(None, depth - 1):
        result = partial(defaultdict, result)

    return result()
####################################################################################################
## prefix components:
# space =  '    '
# branch = '│   '

## pointers:
# tee =    '├── '
# last =   '└── '

tree = nested_defaultdict(list, 10)

filesIncludes = ['*.h', '*.inl', '*.hpp', '*.cpp', '*.sql', '*.txt', '*.html', '*.htm', '*.js']
dirsExcludes  = ['.git', 'StdStream', 'StdTest', 'res']

# glob patterns -> regular expressions
filesIncludes = r'|'.join([fnmatch.translate(x) for x in filesIncludes])

todoLabel = 'note  [todo]'
####################################################################################################
def _dirInfo(a_currentDirPath):
	allFiles  = 0
	doneFiles = 0
	todoFiles = 0
	filesPct  = 0

	for currentDirPath, dirs, files in os.walk(a_currentDirPath):
		# exclude dirs
		dirs[:] = [d for d in dirs if d not in dirsExcludes]
		dirs.sort(reverse=False)

		# exclude/include files
		files = [os.path.join(currentDirPath, f) for f in files]
		files = [f for f in files if re.match(filesIncludes, f)]

		# Read files - find todoLabel
		for file in files:
			allFiles += 1

			fileContent = ''

			try:
				f = open(file, "r")
				fileContent = f.read()
			except:
				print("Error: {}\n".format(file))

			isTodo = fileContent.find(todoLabel)
			if (isTodo == -1) :
				doneFiles += 1
			else:
				todoFiles += 1
		# for
	# for

	filesPct = 0.0
	if (allFiles != 0.0) :
		filesPct = math.ceil(doneFiles * 100.0 / allFiles)

	# [out]
	tree[a_currentDirPath] = (allFiles, doneFiles, todoFiles, filesPct)

####################################################################################################
def dirProcess(level, dirPath, dirs, files):
	if (level == 0):
		return

	if (level == 1):
		isRootSubDir = True
	else:
		isRootSubDir = False

	indent    = ' ' * 2 * (level - 1)
	subindent = ' ' * 2 * (level + 1)

	# print('dirPath: {}'.format(dirPath))

	# dir
	print('{}* <details>'.format(indent))

	if (isRootSubDir):
		print('{}  <summary><b>{}/</b></summary>'
			.format(indent, os.path.basename(dirPath)))
	else:
		info = tree[dirPath]
		# print('{}: <{}, {}, {}, {}>'.format(dirPath, info[0], info[1], info[2], info[3]))

		allfilesNum  = info[0]
		doneFilesPct = info[3]

		print('{}  <summary>{}/ (<b>{}%</b> of {})</summary>'
			.format(indent, os.path.basename(dirPath), doneFilesPct, allfilesNum))

	# dirs
	# print('')
	# for d in dirs:
		# print('{}* `::: {} :::`'.format(subindent, Path(d).name))
	# print('')

	# files
	print('')
	for f in files:
		print('{}* `{}`'.format(subindent, Path(f).name))
	print('')

	print('{}  </details>'.format(indent))
	print('')

####################################################################################################
def rootDirProcess():
	rootPath = str(Path.cwd());

	for currentDirPath, dirs, files in os.walk(rootPath):
		# exclude dirs
		dirs[:] = [d for d in dirs if d not in dirsExcludes]
		dirs.sort(reverse=False)

		# exclude/include files
		files = [os.path.join(currentDirPath, f) for f in files]
		files = [f for f in files if re.match(filesIncludes, f)]

		level = currentDirPath.replace(rootPath, '').count(os.sep)

		_dirInfo(currentDirPath)

		dirProcess(level, currentDirPath, dirs, files)
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
#!/usr/bin/env python3

####################################################################################################
# FAQ
#
# https://theasciicode.com.ar/
# https://stackoverflow.com/questions/24768630/is-there-a-way-to-show-a-progressbar-on-github-wiki
#
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

from pathlib     import Path
from collections import defaultdict
from functools   import partial
from itertools   import repeat
####################################################################################################
## prefix components:
# space =  '    '
# branch = '│   '

## pointers:
# tee =    '├── '
# last =   '└── '

file = open("./Roadmap.md", "w")
tree = _nestedDictDefault(list, 10)

filesIncludes = [
	'*.h', '*.inl', '*.hpp', '*.cpp', '*.cc', '*.c', '*.cpp.off',
	'*.sql',
	'*.txt', '*.md', '*.htm','*.html',
	'*.js', '*.java']
dirsExcludes  = ['.git', 'StdStream', 'StdTest', 'res']

# glob patterns -> regular expressions
filesIncludes = r'|'.join([fnmatch.translate(x) for x in filesIncludes])

####################################################################################################
def _nestedDictDefault(default_factory, depth=1):
    result = partial(defaultdict, default_factory)

    for _ in repeat(None, depth - 1):
        result = partial(defaultdict, result)

    return result()
####################################################################################################
def _writeLine(a_line):
	file.write(a_line + '\n')

####################################################################################################
def _isFileTodo(a_filePath):
	isTodo = True

	todoLabel = '\\todo'

	try:
		f = open(a_filePath, "r")
		fileContent = f.read()

		isTodo = (fileContent.find(todoLabel) != -1)
	except:
		_writeLine("Error: {}\n".format(a_filePath))

	return isTodo

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

			if ( _isFileTodo(file) ) :
				todoFiles += 1
			else:
				doneFiles += 1
		# for
	# for

	filesPct = 0.0
	if (allFiles != 0.0) :
		filesPct = round(doneFiles * 100.0 / allFiles)

	# [out]
	tree[a_currentDirPath] = (allFiles, doneFiles, todoFiles, filesPct)

####################################################################################################
def _progressBar(a_doneFilesPct, a_allfilesNum):
	# [████████░░] 78% (12)

	valueDone = '█'
	valueToDo = '░'

	valueToDos = valueToDo * round((100 - a_doneFilesPct) / 10.0)
	valueDones = valueDone * round(a_doneFilesPct / 10.0)

	return '[{}{}] {}% ({})'.format(valueDones, valueToDos, a_doneFilesPct, a_allfilesNum)

####################################################################################################
def _dirProcess(level, dirPath, dirs, files):
	if (level == 0):
		return

	indent    = ' ' * 2 * (level - 1)
	subindent = ' ' * 2 * (level + 1)

	# _writeLine('dirPath: {}'.format(dirPath))

	# dir
	_writeLine('{}* <details close>'.format(indent))

	info = tree[dirPath]
	# _writeLine('{}: <{}, {}, {}, {}>'.format(dirPath, info[0], info[1], info[2], info[3]))

	allfilesNum  = info[0]
	doneFilesPct = info[3]

	# root dir
	if (level == 1):
		# _writeLine('{}  <summary><b>{}/</b> (<b>{}%</b> of {})</summary>'
		# 	.format(indent, os.path.basename(dirPath), doneFilesPct, allfilesNum))

		_writeLine('{}  <summary><b>{}/</b> {}</summary>'
			.format(indent, os.path.basename(dirPath), _progressBar(doneFilesPct, allfilesNum)))

		# _writeLine('{}  <summary><b>{}/</b> ![{}%](https://progress-bar.dev/{})</summary>'
		# 	.format(indent, os.path.basename(dirPath), doneFilesPct, doneFilesPct))
	else:
		_writeLine('{}  <summary>{}/ {}% ({})</summary>'
			.format(indent, os.path.basename(dirPath), doneFilesPct, allfilesNum))

	# dirs - n/a

	# files
	_writeLine('')
	for file in files:
		fileName = Path(file).name

		if ( _isFileTodo(file) ):
			fileName = '❌ {}'.format(fileName)
			# fileName = '<span style="color:red">{}</span>'.format(fileName)
		else:
			fileName = '✅ `{}`'.format(fileName)

		_writeLine('{}* {}'.format(subindent, fileName))
	_writeLine('')

	_writeLine('{}  </details>'.format(indent))
	_writeLine('')

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

		_dirProcess(level, currentDirPath, dirs, files)
	# for

####################################################################################################
def main():
	# <style>
	# r { color: Red }
	# o { color: Orange }
	# g { color: Green }
	# </style>

	_writeLine('# C++ Roadmap')
	_writeLine('')
	_writeLine('<div style="background-color:black">')
	_writeLine('')

	rootDirProcess()

	_writeLine('</div>')

####################################################################################################
if __name__ == "__main__":
    main()
####################################################################################################
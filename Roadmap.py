#!/usr/bin/env python3

################################################################################################
# FAQ
#
# https://theasciicode.com.ar/
# https://www.vertex42.com/ExcelTips/unicode-symbols.html
# https://stackoverflow.com/questions/24768630/is-there-a-way-to-show-a-progressbar-on-github-wiki
#
# TODO
#
# + Progress bar for each dir
# + Done/Todo icons
# + Ignores dirs/files
# ? Draw "brances"
# - Clickable files
# - todo labels list
#
################################################################################################


import os
import os.path
import fnmatch
import re

from pathlib     import Path
from collections import defaultdict
from functools   import partial
from itertools   import repeat
####################################################################################################
class RoadmapGen:
	## prefix components:
	# space  = '    '
	# branch = '│   '
	# tee    = '├── '
	# last   = '└── '
	# label1 = '⌛'

	mdPath        = ''
	file          = ''
	tree          = partial(defaultdict, list)

	dirsExcludes  = []
	filesIncludes = []

	################################################################################################
	# ctr
	def __init__(self):
		self.mdPath = os.path.dirname(os.path.realpath(__file__)) + '/Roadmap.md';
		self.file   = open(self.mdPath, 'w')
		self.tree   = self._nestedDictDefault(list, 10)

		self.dirsExcludes  = ['.git', 'StdStream', 'StdTest', 'res']
		self.filesIncludes = [
			'*.h', '*.inl', '*.hpp', '*.cpp', '*.cxx', '*.cc', '*.c', '*.cpp.off',
			'*.sql',
			'*.txt', '*.md', '*.htm','*.html',
			'*.js', '*.java']
		self.filesIncludes = r'|'.join([fnmatch.translate(x) for x in self.filesIncludes])

	################################################################################################
	# Construct dic
	def _nestedDictDefault(self, default_factory, depth = 1):
		result = partial(defaultdict, default_factory)

		for _ in repeat(None, depth - 1):
			result = partial(defaultdict, result)

		return result()
	################################################################################################
	# Write line to file
	def _writeLine(self, a_line):
		self.file.write(a_line + '\n')

	################################################################################################
	# Check file for 'todo' labels
	def _isFileTodo(self, a_filePath):
		isTodo = True

		todoLabel = '\\todo'

		try:
			f = open(a_filePath, "r")
			fileContent = f.read()

			isTodo = (fileContent.find(todoLabel) != -1)
		except:
			self._writeLine("Error: {}\n".format(a_filePath))

		return isTodo

	################################################################################################
	# Collect dirs info
	def _dirInfo(self, a_currentDirPath):
		allFiles  = 0
		doneFiles = 0
		todoFiles = 0
		filesPct  = 0

		for currentDirPath, dirs, files in os.walk(a_currentDirPath):
			# exclude dirs
			dirs[:] = [d for d in dirs if d not in self.dirsExcludes]
			dirs.sort(reverse=False)

			# exclude/include files
			files = [os.path.join(currentDirPath, f) for f in files]
			files = [f for f in files if re.match(self.filesIncludes, f)]

			# Read files - find todoLabel
			for file in files:
				allFiles += 1

				if ( self._isFileTodo(file) ) :
					todoFiles += 1
				else:
					doneFiles += 1
			# for
		# for

		filesPct = 0.0
		if (allFiles != 0.0) :
			filesPct = round(doneFiles * 100.0 / allFiles)

		# [out]
		self.tree[a_currentDirPath] = (allFiles, doneFiles, todoFiles, filesPct)

	################################################################################################
	# [████████░░] 78% (12)
	def _progressBar(self, a_doneFilesPct, a_allfilesNum):
		valueDone = '█'
		valueToDo = '░'

		valueToDos = valueToDo * round((100 - a_doneFilesPct) / 10.0)
		valueDones = valueDone * round(a_doneFilesPct / 10.0)

		return '[{}{}] {}% ({})'.format(valueDones, valueToDos, a_doneFilesPct, a_allfilesNum)

	################################################################################################
	def _dirProcess(self, level, dirPath, dirs, files):
		if (level < 0):
			return

		iconCurrent    = ''
		iconToDo       = '❌'
		iconDone       = '✅'
		iconInProgress = '⌛'
		iconDir        = '📁'

		indent    = '  ' * level
		subindent = '    ' * level

		# _writeLine('dirPath: {}'.format(dirPath))

		# dir

		info = self.tree[dirPath]
		# _writeLine('{}: <{}, {}, {}, {}>'.format(dirPath, info[0], info[1], info[2], info[3]))

		allfilesNum  = info[0]
		doneFilesPct = info[3]

		if   (doneFilesPct == 100):
			iconCurrent = iconDone
		elif (doneFilesPct == 0):
			iconCurrent = iconToDo
		else:
			iconCurrent = iconInProgress

		if (level == 0):
			# Dir
			self._writeLine('{}<details close>'.format(indent))

			# Root dir
			# self._writeLine('{}  <summary><b>{}/</b> (<b>{}%</b> of {})</summary>'
			# 	.format(indent, os.path.basename(dirPath), doneFilesPct, allfilesNum))

			self._writeLine('{}<summary><b>{}</b> {}</summary>'
				.format(indent, os.path.basename(dirPath), self._progressBar(doneFilesPct, allfilesNum)))

			# self._writeLine('{}  <summary><b>{}/</b> ![{}%](https://progress-bar.dev/{})</summary>'
			# 	.format(indent, os.path.basename(dirPath), doneFilesPct, doneFilesPct))
		else:
			# Dir
			self._writeLine('{}* <details close>'.format(indent))

			self._writeLine('{}  <summary>{} {} {} {}% ({})</summary>'
				.format(indent, iconDir, iconCurrent, os.path.basename(dirPath), doneFilesPct, allfilesNum))

		# files
		self._writeLine('')
		for file in files:
			fileName = Path(file).name

			if ( self._isFileTodo(file) ):
				fileName = '{} {}'.format(iconToDo, fileName)
				# fileName = '<span style="color:red">{}</span>'.format(fileName)
			else:
				fileName = '{} `{}`'.format(iconDone, fileName)

			self._writeLine('{}* {}'.format(subindent, fileName))
		self._writeLine('')

		# Dir  (close)
		if (level == 0):
			self._writeLine('{}</details>'.format(indent))
		else:
			self._writeLine('{}  </details>'.format(indent))

		self._writeLine('')

	################################################################################################
	# root dir - process
	def run(self):
		# <style>
		# r { color: Red }
		# o { color: Orange }
		# g { color: Green }
		# </style>

		# Title
		self._writeLine('# C++ Roadmap')
		self._writeLine('')
		self._writeLine('<div style="background-color:black">')
		self._writeLine('')

		rootPath = str(Path.cwd());

		for currentDirPath, dirs, files in os.walk(rootPath):
			level = currentDirPath.replace(rootPath, '').count(os.sep) - 1

			# exclude dirs
			dirs[:] = [d for d in dirs if d not in self.dirsExcludes]
			dirs.sort(reverse=False)

			# exclude/include files
			files = [os.path.join(currentDirPath, f) for f in files]
			files = [f for f in files if re.match(self.filesIncludes, f)]

			self._dirInfo(currentDirPath)
			self._dirProcess(level, currentDirPath, dirs, files)
		# for

		# Title - ends
		self._writeLine('</div>')

################################################################################################
if __name__ == "__main__":
	gen = RoadmapGen()
	gen.run()
################################################################################################
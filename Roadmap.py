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
	def _nestedDictDefault(self, a_default_factory, a_depth = 1):
		result = partial(defaultdict, a_default_factory)

		for _ in repeat(None, a_depth - 1):
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

		for it_currentDirPath, it_dirs, it_files in os.walk(a_currentDirPath):
			# exclude dirs
			it_dirs[:] = [d for d in it_dirs if d not in self.dirsExcludes]
			it_dirs.sort(reverse=False)

			# exclude/include files
			it_files = [os.path.join(it_currentDirPath, f) for f in it_files]
			it_files = [f for f in it_files if re.match(self.filesIncludes, f)]

			# Read files - find todoLabel
			for file in it_files:
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
	def _dirProcess(self, a_level, a_dirPath, a_dirs, a_files):
		if (a_level < 0):
			return

		iconCurrent    = ''
		iconToDo       = '❌'
		iconDone       = '✅'
		iconInProgress = '⌛'
		iconDir        = '📁'

		indent    = '  ' * a_level
		subindent = '    ' * a_level

		# _writeLine('dirPath: {}'.format(dirPath))

		# dir

		info = self.tree[a_dirPath]
		# _writeLine('{}: <{}, {}, {}, {}>'.format(dirPath, info[0], info[1], info[2], info[3]))

		allfilesNum  = info[0]
		doneFilesPct = info[3]

		if   (doneFilesPct == 100):
			iconCurrent = iconDone
		elif (doneFilesPct == 0):
			iconCurrent = iconToDo
		else:
			iconCurrent = iconInProgress

		if (a_level == 0):
			# Dir
			self._writeLine('{}<details close>'.format(indent))

			# Root dir
			# self._writeLine('{}  <summary><b>{}/</b> (<b>{}%</b> of {})</summary>'
			# 	.format(indent, os.path.basename(a_dirPath), doneFilesPct, allfilesNum))

			self._writeLine('{}<summary><b>{}</b> {}</summary>'
				.format(indent, os.path.basename(a_dirPath), self._progressBar(doneFilesPct, allfilesNum)))

			# self._writeLine('{}  <summary><b>{}/</b> ![{}%](https://progress-bar.dev/{})</summary>'
			# 	.format(indent, os.path.basename(a_dirPath), doneFilesPct, doneFilesPct))
		else:
			# Dir
			self._writeLine('{}* <details close>'.format(indent))

			self._writeLine('{}  <summary>{} {} {} {}% ({})</summary>'
				.format(indent, iconDir, iconCurrent, os.path.basename(a_dirPath), doneFilesPct, allfilesNum))

		# files
		self._writeLine('')

		for it_file in a_files:
			fileName = Path(it_file).name

			if ( self._isFileTodo(it_file) ):
				fileName = '{} {}'.format(iconToDo, fileName)
				# fileName = '<span style="color:red">{}</span>'.format(fileName)
			else:
				fileName = '{} `{}`'.format(iconDone, fileName)

			self._writeLine('{}* {}'.format(subindent, fileName))
		# for

		self._writeLine('')

		# Dir  (close)
		if (a_level == 0):
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

		for it_currentDirPath, it_dirs, it_files in os.walk(rootPath):
			level = it_currentDirPath.replace(rootPath, '').count(os.sep) - 1

			# exclude dirs
			it_dirs[:] = [d for d in it_dirs if d not in self.dirsExcludes]
			it_dirs.sort(reverse=False)

			# exclude/include files
			it_files = [os.path.join(it_currentDirPath, f) for f in it_files]
			it_files = [f for f in it_files if re.match(self.filesIncludes, f)]

			self._dirInfo(it_currentDirPath)
			self._dirProcess(level, it_currentDirPath, it_dirs, it_files)
		# for

		# Title - ends
		self._writeLine('</div>')

################################################################################################
if __name__ == "__main__":
	gen = RoadmapGen()
	gen.run()
################################################################################################
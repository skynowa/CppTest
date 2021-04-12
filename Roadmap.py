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
# + todo labels list
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
		self.mdPath = os.path.dirname(os.path.realpath(__file__)) + '/Readme.md';
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
		todoLabels = [r'\\todo', r'\[todo\]']

		try:
			f = open(a_filePath, "r")
			fileContent = f.read()

			for it_todoLabel in todoLabels:
				match = re.search(it_todoLabel, fileContent, re.IGNORECASE)
				if (match):
					return True
			# for
		except:
			self._writeLine("Error: {}\n".format(a_filePath))

		return False

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

		return '{}{} {}% ({})'.format(valueDones, valueToDos, a_doneFilesPct, a_allfilesNum)

	################################################################################################
	# Back to top link
	def _backToTop(self):
		# ▴ ⬆ ⇧
		return '<a href="#" title="Back to top">{}</a>'.format('⇧')

	################################################################################################
	# TOC
	def _tocProcess(self, a_dirPath):
		info = self.tree[a_dirPath]

		allfilesNum  = info[0]
		doneFilesPct = info[3]

		dirName = os.path.basename(a_dirPath)

		self._writeLine('- [{}](#{}) {}'
			.format(dirName, dirName.lower(), self._progressBar(doneFilesPct, allfilesNum)))

	################################################################################################
	def _dirProcess(self, a_level, a_dirPath, a_dirs, a_files):
		if (a_level < 0):
			return

		iconCurrent    = ''
		iconToDo       = '❌'
		iconDone       = '✅'
		iconInProgress = '⌛'
		iconDir        = '📁'
		# 🕵

		indent    = '  ' * a_level
		subindent = (indent * 2) * a_level

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

		dirName = os.path.basename(a_dirPath)

		# Dir (begin)
		if (a_level == 0):
			# self._writeLine('{}<details close>'.format(indent))
			# self._writeLine('{}<summary><b>{}</b> {}</summary>'
			# 	.format(indent, dirName, self._progressBar(doneFilesPct, allfilesNum)))

			self._writeLine('##  <a id="{}">{} {}</a> {}'.format(
				dirName.lower(),
				dirName,
				self._progressBar(doneFilesPct, allfilesNum),
				self._backToTop()))
		else:
			self._writeLine('{}* <details close>'.format(indent))
			self._writeLine('{}  <summary>{} {} {} {}% ({})</summary>'.format(
				indent,
				iconDir,
				iconCurrent,
				dirName,
				doneFilesPct,
				allfilesNum))

		# files
		self._writeLine('')

		for it_file in a_files:
			fileName = Path(it_file).name

			if ( self._isFileTodo(it_file) ):
				fileName = '{} {}'.format(iconToDo, fileName)
			else:
				fileName = '{} `{}`'.format(iconDone, fileName)

			self._writeLine('{}* {}'.format(subindent, fileName))
		# for

		self._writeLine('')

		# Dir (end)
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

		rootPath = str(Path.cwd());

		# Title
		self._writeLine('# C++ Roadmap')
		self._writeLine('')

		for it_currentDirPath, it_dirs, it_files in os.walk(rootPath):
			level = it_currentDirPath.replace(rootPath, '').count(os.sep) - 1

			# exclude dirs
			it_dirs[:] = [d for d in it_dirs if d not in self.dirsExcludes]
			it_dirs.sort(reverse=False)

			# exclude/include files
			it_files = [os.path.join(it_currentDirPath, f) for f in it_files]
			it_files = [f for f in it_files if re.match(self.filesIncludes, f)]

			self._dirInfo(it_currentDirPath)

			if (level != 0):
				continue

			self._tocProcess(it_currentDirPath)
		# for

		self._writeLine('')

		# Content
		# self._writeLine('<div style="background-color:black">')
		self._writeLine('')

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
		# self._writeLine('</div>')

################################################################################################
if __name__ == "__main__":
	gen = RoadmapGen()
	gen.run()
################################################################################################
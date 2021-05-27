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
# + Done/Todo/Faq(md) icons
# + Remark/Review (as Done) icon
# + Ignores dirs/files
# ? Draw "branches"
# + Clickable files
# + Todo labels list
# + Hint from Doxygen "\brief" comment
# - Priority label
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

	appName       = ''
	mdPath        = ''
	file          = ''
	tree          = partial(defaultdict, list)

	dirsExcludes  = []
	filesIncludes = []

	lableTitle    = ''

	iconToDo       = '❌'
	iconRemark     = '🖊' # '🕵' '📝' '🏳' '⮕' '🤔' '❓'
	iconFaq        = '📝'
	iconDone       = '✅'
	iconInProgress = '⌛'
	iconDir        = '📁'
	iconTocHot     = '🔥'
	iconTocDone    = '🚩'

	################################################################################################
	# ctr
	def __init__(self):
		self.appName = 'C++ Roadmap'
		self.mdPath  = os.path.dirname(os.path.realpath(__file__)) + '/Readme.md';
		self.file    = open(self.mdPath, 'w')
		self.tree    = self._nestedDictDefault(list, 10)

		self.dirsExcludes  = ['.git', 'StdStream', 'StdTest', 'res']
		self.filesIncludes = [
			'*.h', '*.inl', '*.hpp', '*.cpp', '*.cxx', '*.cc', '*.c', '*.cpp.off',
			'*.sql',
			'*.txt', '*.md', '*.htm','*.html',
			'*.js', '*.java',
			'*.py']
		self.filesIncludes = r'|'.join([fnmatch.translate(x) for x in self.filesIncludes])

		self.labelTitle = 'cpp-roadmap'

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
	# Check file for 'todo', 'remark' labels + brief comment
	def _fileInfo(self, a_filePath):
		isFileTodo   = False
		isFileRemark = False
		isFileFaq    = False
		commentBrief = ''

		##################################################
		# Read file
		fileContent = ''

		try:
			f = open(a_filePath, "r")
			fileContent = f.read()
		except:
			self._writeLine("Error: {}\n".format(a_filePath))
			return (isFileTodo, commentBrief)

		##################################################
		# isFileTodo
		todoLabels = [r'\\todo', r'\[todo\]']

		try:
			for it_todoLabel in todoLabels:
				match = re.search(it_todoLabel, fileContent, re.IGNORECASE)
				if (match):
					isFileTodo = True
			# for
		except:
			self._writeLine("Error: {}\n".format(a_filePath))

		##################################################
		# isFileRemark
		remarkLabels = [r'\\remark', r'\[remark\]', r'\\review', r'\[review\]']

		try:
			for it_remarkLabel in remarkLabels:
				match = re.search(it_remarkLabel, fileContent, re.IGNORECASE)
				if (match):
					isFileRemark = True
			# for
		except:
			self._writeLine("Error: {}\n".format(a_filePath))

		##################################################
		# isFileFaq
		fileExt = os.path.splitext(a_filePath)[1][1:].strip().lower()
		if (fileExt == 'md') :
			isFileFaq = True

		##################################################
		# commentsBrief
		pattern = r'\\brief(.*?)' + os.linesep

		match = re.search(pattern, fileContent)
		if (match):
			commentBrief = match.group(1).strip()

		return (isFileTodo, isFileRemark, isFileFaq, commentBrief)

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

				isFileTodo, isFileRemark, isFileFaq, commentBrief = self._fileInfo(file)
				if   (isFileTodo) :
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

		# hot point
		if (a_doneFilesPct < 100.0 and a_doneFilesPct > 50.0):
			a_doneFilesPct = '{}{}'.format(self.iconTocHot, a_doneFilesPct)
		# done point
		elif (a_doneFilesPct == 100.0):
			a_doneFilesPct = '{}{}'.format(self.iconTocDone, a_doneFilesPct)

		return '{}{} {}% ({})'.format(valueDones, valueToDos, a_doneFilesPct, a_allfilesNum)

	################################################################################################
	# Back to label
	def _label(self, a_id, a_title, a_text):
		return '<a id="{}" title="{}">{}</a>'.format(a_id, a_title, a_text)

	def _goToLabel(self, a_id, a_title, a_text):
		# ▴ ⬆ ⇧ [↩]
		return '<a href="#{}" title="{}">{}</a>'.format(a_id, a_title, a_text)

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

		iconCurrent = ''

		indent    = '  '   * a_level
		subindent = '    ' * a_level

		info = self.tree[a_dirPath]
		# _writeLine('{}: <{}, {}, {}, {}>'.format(dirPath, info[0], info[1], info[2], info[3]))

		allfilesNum  = info[0]
		doneFilesPct = info[3]

		if   (doneFilesPct == 100):
			iconCurrent = self.iconDone
		elif (allfilesNum == 0):
			iconCurrent = ''
		elif (doneFilesPct == 0):
			iconCurrent = self.iconToDo
		else:
			iconCurrent = self.iconInProgress

		dirName = os.path.basename(a_dirPath)

		# Dir (begin)
		if (a_level == 0):
			self._writeLine('##  <a id="{}">{} {}</a> {}'.format(
				dirName.lower(),
				dirName,
				self._progressBar(doneFilesPct, allfilesNum),
				self._goToLabel(self.labelTitle, 'Back to top', '⇧')))
		else:
			self._writeLine('{}* <details close>'.format(indent))
			self._writeLine('{}  <summary>{} {} {} {}% ({})</summary>'.format(
				indent,
				self.iconDir,
				iconCurrent,
				dirName,
				doneFilesPct,
				allfilesNum))

		# files
		self._writeLine('')

		for it_file in a_files:
			fileUrl = it_file.replace('/home/skynowa/Projects/CppTest/', '/')

			fileName = Path(it_file).name

			isFileTodo, isFileRemark, isFileFaq, commentBrief = self._fileInfo(it_file)
			if (isFileFaq) :
				fileName = '{} {}'.format(self.iconFaq, fileName)

			if   (isFileTodo):
				fileName = '{} {}'.format(self.iconToDo, fileName)
			elif (isFileRemark):
				fileName = '{} `{}`'.format(self.iconRemark, fileName)
			else:
				fileName = '{} `{}`'.format(self.iconDone, fileName)

			self._writeLine('{}* <a href="{}" title="{}">{}</a>'.format(subindent, fileUrl,
				commentBrief, fileName))
		# for

		self._writeLine('')

		# Dir (end)
		if (a_level == 0):
			self._writeLine('{}</details>'.format(indent))
		else:
			self._writeLine('{}  </details>'.format(indent))

		self._writeLine('')

	################################################################################################
	# FAQ
	def faq(self):
		self._writeLine('---')
		self._writeLine('## FAQ')
		self._writeLine('')
		self._writeLine(
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			'  - {} - {}\n'
			.format(
				self.iconDir,        'Dir',
				self.iconFaq,        'FAQ',
				self.iconDone,       'Done',
				self.iconInProgress, 'In-progress',
				self.iconRemark,     'Remark',
				self.iconToDo,       'Todo',
				self.iconTocHot,     'TOC - hot',
				self.iconTocDone,    'TOC - done'))

	################################################################################################
	# root dir - process
	def run(self):
		print('[{}] start'.format(self.appName))
		print('[{}] {}'.format(self.appName, self.mdPath))

		# <style>
		# r { color: Red }
		# o { color: Orange }
		# g { color: Green }
		# </style>

		rootPath = str(Path.cwd());

		# Title
		self._writeLine('# {}'.format(self._label(self.labelTitle, '', self.appName)))
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

		print('[{}] stop'.format(self.appName))

		self.faq()

################################################################################################
if __name__ == "__main__":
	gen = RoadmapGen()
	gen.run()
################################################################################################
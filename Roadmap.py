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
from datetime    import date
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

	# todos
	iconToDo       = '❌'
	iconRemark     = '🖊' # '🕵' '📝' '🏳' '⮕' '🤔' '❓'
	iconFaq        = '📝'
	iconDone       = '✅'
	iconInProgress = '⌛'
	iconDir        = '📁'
	iconTocHot     = '🔥'
	iconTocDone    = '🚩'

	# labels
	todoLabels     = [r'\\todo', r'\[todo\]', r'\[ \]']
	remarkLabels   = [r'\\remark', r'\[remark\]', r'\\review', r'\[review\]', r'\[\?\]']

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
			'*.py',
			'.github']
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
			return (isFileTodo, False, False, commentBrief)

		##################################################
		# isFileTodo
		try:
			for it_todoLabel in self.todoLabels:
				match = re.search(it_todoLabel, fileContent, re.IGNORECASE)
				if (match):
					isFileTodo = True
					break
			# for
		except:
			self._writeLine("Error: {}\n".format(a_filePath))

		##################################################
		# isFileRemark
		try:
			for it_remarkLabel in self.remarkLabels:
				match = re.search(it_remarkLabel, fileContent, re.IGNORECASE)
				if (match):
					isFileRemark = True
					break
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
	# Info from FAQ.md
	def _faqInfo(self, a_dirPath):
		commentBrief = ''

		filePath = a_dirPath + "/FAQ.md"
		if (not os.path.isfile(filePath)):
			return ''

		##################################################
		# Read file
		fileContent = ''

		try:
			f = open(filePath, "r")
			fileContent = f.read()
		except:
			self._writeLine("Error: {}\n".format(filePath))
			return ''

		##################################################
		# commentsBrief
		posStart = fileContent.find("\n")
		posEnd   = fileContent.find("\n#", posStart)

		commentBrief = fileContent[posStart:posEnd].strip()
		commentBrief = commentBrief.replace('"','')
		commentBrief = commentBrief.replace('\n','. ')

		# print('::::: filePath: {} :::::'.format(filePath))
		# print("Pos: {}:{}".format(start, end))
		# print('commentBrief: \n{}'.format(commentBrief))
		# print('')

		return commentBrief

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

		# done point
		if   (a_doneFilesPct >= 90.0 and a_doneFilesPct < 100.0):
			a_doneFilesPct = '{}{}'.format(self.iconTocDone, a_doneFilesPct)
		# done point
		elif (a_doneFilesPct == 100.0):
			a_doneFilesPct = '{}{}'.format(self.iconTocDone, a_doneFilesPct)
		# hot point
		elif (a_doneFilesPct >= 50.0 and a_doneFilesPct < 100.0):
			a_doneFilesPct = '{}{}'.format(self.iconTocHot, a_doneFilesPct)

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

		dirName      = os.path.basename(a_dirPath)
		commentBrief = self._faqInfo(a_dirPath)

		self._writeLine('- [{}](#{} "{}") {}'
			.format(dirName, dirName.lower(), commentBrief, self._progressBar(doneFilesPct, allfilesNum)))

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
			commentBrief = self._faqInfo(a_dirPath)

			self._writeLine('##  <a title="{}" id="{}">{} {}</a> {}'.format(
				commentBrief,
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

		self._writeLine('### Icons')
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
				self.iconTocDone,    'TOC - done / nearly done'))

		self._writeLine('### Labels')
		self._writeLine('')

		separator = ', '

		_todoLabels = self.todoLabels
		for i in range(len(_todoLabels)):
			_todoLabels[i] = _todoLabels[i].replace("\\\\", "\\")
			_todoLabels[i] = _todoLabels[i].replace("\[", "[")
			_todoLabels[i] = _todoLabels[i].replace("\]", "]")

		_remarkLabels = self.remarkLabels
		for i in range(len(_remarkLabels)):
			_remarkLabels[i] = _remarkLabels[i].replace("\\\\", "\\")
			_remarkLabels[i] = _remarkLabels[i].replace("\[", "[")
			_remarkLabels[i] = _remarkLabels[i].replace("\]", "]")

		self._writeLine(
			'  - `{}` - {}\n'
			'  - `{}` - {}\n'
			'  - Brief comments from `FAQ.md` files used as dir titles'
			.format(
				separator.join(_todoLabels),   'Todo',
				separator.join(_remarkLabels), 'Review'))

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
		dateNow        = date.today().strftime("%d-%b-%Y")

		ghWatchers           = "![GitHub Watchers](https://img.shields.io/github/watchers/skynowa/CppTest)"
		ghCiStatus           = "![GitHub Workflow Status](https://img.shields.io/github/workflow/status/skynowa/CppTest/CI)"

		ghCommitActivity     = "![GitHub commit activity](https://img.shields.io/github/commit-activity/w/skynowa/cpptest)"
		ghCommitLast         = "![GitHub last commit](https://img.shields.io/github/last-commit/skynowa/cpptest)"

		ghIssuesOpened       = "![GitHub issues](https://img.shields.io/github/issues-raw/skynowa/cpptest?color=red)"
		ghIssuesClosed       = "![GitHub closed issues](https://img.shields.io/github/issues-closed-raw/skynowa/cpptest?color=green)"

		ghPullRequestsOpened = "![GitHub pull requests](https://img.shields.io/github/issues-pr-raw/skynowa/cpptest?color=red)"
		ghPullRequestsClosed = "![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed-raw/skynowa/cpptest?color=green)"

		self._writeLine('# {} **{}**'.format(self._label(self.labelTitle, '', self.appName), dateNow))
		self._writeLine('')
		self._writeLine('{} {} {} {} {} {} {} {}'.format(ghWatchers, ghCiStatus, ghCommitActivity, ghCommitLast, ghIssuesOpened, ghIssuesClosed, ghPullRequestsOpened, ghPullRequestsClosed))
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
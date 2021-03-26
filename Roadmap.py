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
def dirLevel1(level, root, files):
	indent    = ' ' * 3 * (level - 1)
	subindent = ' ' * 2 * (level + 1)

	# dir
	print('{}* <details>'.format(indent))
	print('{}  <summary>{}/</summary>'.format(indent, os.path.basename(root)))

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

	for root, dirs, files in os.walk(rootPath):
		# exclude dirs
		dirs[:] = [d for d in dirs if d not in dirsExcludes]

		# exclude/include files
		files = [os.path.join(root, f) for f in files]
		files = [f for f in files if re.match(filesIncludes, f)]

		level = root.replace(rootPath, '').count(os.sep)
		if (level == 0):
			continue
		# print('level: {}'.format(level))

		dirLevel1(level, root, files)
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
	print('<div style="background-color:grey">')
	print('')

	rootDirProcess()

	print('</div>')

####################################################################################################
if __name__ == "__main__":
    main()
####################################################################################################
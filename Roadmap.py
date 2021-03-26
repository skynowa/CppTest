#!/usr/bin/env python3

####################################################################################################
# TODO
#
# - progress bar for each dir
# - Ok icon
# - ignores
# -
####################################################################################################


import os
import os.path
import fnmatch
import re

from pathlib import Path
####################################################################################################
# prefix components:
space =  '    '
branch = '│   '
# pointers:
tee =    '├── '
last =   '└── '

def tree(dir_path: Path, prefix: str=''):
	"""A recursive generator, given a directory Path object
	will yield a visual tree structure line by line
	with each line prefixed by the same characters
	"""
	contents = list(dir_path.iterdir())

	# contents each get pointers that are ├── with a final └── :
	pointers = [tee] * (len(contents) - 1) + [last]
	for pointer, path in zip(pointers, contents):
		yield prefix + pointer + path.name
		if path.is_dir(): # extend the prefix and recurse:
			extension = branch if pointer == tee else space
			# i.e. space because last, └── , above so no more |
			yield from tree(path, prefix=prefix+extension)

# for line in tree(Path.cwd()):
#     print(line)

####################################################################################################
def list_files(startpath):
	dirsExcludes  = ['.git', 'StdStream', 'StdTest']
	filesIncludes = ['*.h', '*.inl', '*.hpp', '*.cpp', '*.sql', '*.txt', '*.html', '*.htm',]

	# glob patterns -> regular expressions
	dirsExcludes  = r'|'.join([fnmatch.translate(x) for x in dirsExcludes]) or r'$.'
	filesIncludes = r'|'.join([fnmatch.translate(x) for x in filesIncludes])

	for root, dirs, files in os.walk(startpath):
		# exclude dirs
		dirs[:] = [os.path.join(root, d) for d in dirs]
		dirs[:] = [d for d in dirs if not re.match(dirsExcludes, d)]

		# exclude/include files
		files = [os.path.join(root, f) for f in files]
		# files = [f for f in files if not re.match(filesIncludes, f)]
		files = [f for f in files if re.match(filesIncludes, f)]


		level = root.replace(startpath, '').count(os.sep)
		if (level == 0):
			continue

		indent    = ' ' * 3 * (level - 1)
		subindent = ' ' * 2 * (level + 1)

		# dir
		print('{}* <details>'.format(indent))
		print('{}  <summary>{}/</summary>'.format(indent, os.path.basename(root)))

		# files
		print('\n')
		for f in files:
			print('{}* {}'.format(subindent, Path(f).name))
		print('\n')

		print('{}  </details>'.format(indent))
		print('\n')
	# for
####################################################################################################
# <style>
# r { color: Red }
# o { color: Orange }
# g { color: Green }
# </style>

print('# C++ Roadmap')
print('')
print('<div style="background-color:grey">')
print('')

list_files(str(Path.cwd()))

print('</div>')
####################################################################################################

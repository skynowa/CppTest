

#!/usr/bin/env python
#
# \file  SubprocessCommunicateAsync.py
# \brief Constantly print Subprocess output while process is running
#
# https://newbedev.com/constantly-print-subprocess-output-while-process-is-running
# https://www.endpoint.com/blog/2015/01/getting-realtime-output-using-python/
#


import sys
import subprocess
#--------------------------------------------------------------------------------------------------
def run(self, a_cmd):
	proc = subprocess.Popen(a_cmd, shell = False, bufsize = 0, stdout = subprocess.PIPE, stderr = subprocess.STDOUT, encoding='utf8')

	# Poll process for new output until finished
	while True:
		nextLine = proc.stdout.readline()
		if (nextLine == "" and
			proc.poll() is not None
		):
			break

		sys.stdout.write(nextLine)
		sys.stdout.flush()

	stdOut, stdErr = proc.communicate()

	return proc.returncode, stdOut, stdErr
#--------------------------------------------------------------------------------------------------

#!/usr/bin/env python
#
# \file  InheritentCtorDtor.py
# \brief
#


#--------------------------------------------------------------------------------------------------
class A():
	def __init__(self):
		print('A - Ctor')

	def __del__(self):
		print('A - Dtor')
#--------------------------------------------------------------------------------------------------
class B(A):
	def __init__(self):
		super(B, self).__init__()

		print('B - Ctor')

	def __del__(self):
		print('B - Dtor')

		super(B, self).__del__()
#--------------------------------------------------------------------------------------------------
b = B()
del b
#--------------------------------------------------------------------------------------------------

"""
A - Ctor
B - Ctor
B - Dtor
A - Dtor
"""
#--------------------------------------------------------------------------------------------------
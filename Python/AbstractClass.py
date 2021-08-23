#!/usr/bin/env python
#
# \file  AbstractClass.py
# \brief
#
# [2.7]
#


import abc
#--------------------------------------------------------------------------------------------------
class IInretface(object):
	__metaclass__ = abc.ABCMeta

	@abc.abstractmethod
	def foo(self):
		pass

class A(IInretface):
	pass

class B(A):
	def foo(self):
		return super(B, self).foo()
#--------------------------------------------------------------------------------------------------
a = A()

# Traceback (most recent call last):
#   File "./AbstractClass.py", line 21, in <module>
#     a = A()
# TypeError: Can't instantiate abstract class A with abstract methods foo

#--------------------------------------------------------------------------------------------------
interface = IInretface()

# Traceback (most recent call last):
#   File "./AbstractClass.py", line 20, in <module>
#     interface = IInretface()
# TypeError: Can't instantiate abstract class IInretface with abstract methods foo
#--------------------------------------------------------------------------------------------------

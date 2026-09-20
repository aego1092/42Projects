#!/usr/bin/env python

class Ciccio:
	def __init__(self, name):
		self.name = name
		
class Cicco:
	def __init__(self, name):
		self.name = name

l = [Ciccio(9), Cicco("luigi"), Ciccio("pippo")]

# for i, nome in enumerate(l):
# 	print(i)
# 	print(nome.name)

# for i in range(len(l)):
print(l[0].__class__.__name__)
print(isinstance(l, list))

class Element:
	def __init__(self,value):
		self.value=value
		self.prox=None

	def element_Get_Value(self):
		return self.value

	def element_Get_Prox(self):
		return self.prox

	def element_Add_Prox(self,proxElement):
		self.prox=proxElement
		return	

	def element_Print(self):
		print("valor: "+str(self.value))
		if self.prox != None:
			print("valor do prox: "+str(self.prox.element_Get_Value()))
		print("-------------------------------")
		return
			

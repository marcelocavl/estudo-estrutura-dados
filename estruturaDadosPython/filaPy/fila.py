from element import Element

class Fila:
	def __init__(self,rootElement):
		self.rootElement=rootElement
		self.currentElement=rootElement
		self.numElements=1
		return

	def fila_Get_RootElement(self):
		return self.rootElement

	def fila_Get_CurrentElement(self):
		return self.currentElement

	def fila_Go_To_Root_Element(self):
		self.currentElement=self.rootElement
		return
	def fila_Go_To_Second_Element(self):
		self.fila_Go_To_Root_Element()	
		self.currentElement=self.currentElement.prox
		return	
	
	def fila_Go_To_Last_Element(self):
		self.fila_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement=self.currentElement.prox	
		return	

	def fila_Alocate(self,elementToAlocate):
		self.fila_Go_To_Last_Element()
		self.currentElement.prox=elementToAlocate
		return
	def fila_Print(self):
		self.fila_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement.element_Print()
			self.currentElement=self.currentElement.prox
		self.currentElement.element_Print()
		return

	def fila_Delete(self):	
		self.fila_Go_To_Second_Element()
		self.rootElement=self.currentElement
		return


from element import Element

class Pilha:
	def __init__(self,rootElement):
		self.rootElement=rootElement
		self.currentElement=rootElement
		self.numElement=1
	def pilha_Get_RootElement(self):
		return self.rootElement

	def pilha_Get_CurrentElement(self):
		return self.currentElement

	def pilha_Go_To_Root_Element(self):
		self.currentElement=self.rootElement
		return
	def pilha_Go_To_Penultime_Element(self):
		self.pilha_Go_To_Last_Element()
		self.pilha_Go_To_Father_Of_Element(self.currentElement)
		return	
	
	def pilha_Go_To_Last_Element(self):
		self.pilha_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement=self.currentElement.prox	
		return	
	def pilha_Go_To_Father_Of_Element(self,elementTarget):
		self.pilha_Go_To_Root_Element()
		while self.currentElement.prox != elementTarget:
			self.currentElement=self.currentElement.prox
		return self.currentElement

	def pilha_Alocate(self,elementToAlocate):
		self.pilha_Go_To_Last_Element()
		self.currentElement.prox=elementToAlocate
		return

	def pilha_Print(self):
		self.pilha_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement.element_Print()
			self.currentElement=self.currentElement.prox
		self.currentElement.element_Print()
		return

	def pilha_Delete(self):	
		self.pilha_Go_To_Penultime_Element()
		self.currentElement.prox=None
		return


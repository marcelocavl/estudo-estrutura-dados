from element import Element

class List:
	def __init__(self,rootElement):
		self.rootElement=rootElement
		self.currentElement=rootElement
		self.numElements=1	
		return	

	def list_Get_RootElement(self):
		return self.rootElement

	def list_Get_CurrentElement(self):
		return self.currentElement

	def list_Go_To_Root_Element(self):
		self.currentElement=self.rootElement
		return
	
	def list_Go_To_Last_Element(self):
		self.list_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement=self.currentElement.prox	
		return	
	def list_Go_To_Father_Of_Element(self,elementTarget):
		self.list_Go_To_Root_Element()
		while self.currentElement.prox != elementTarget:
			self.currentElement=self.currentElement.prox
		return self.currentElement

	def list_Alocate(self,elementToAlocate):
		self.list_Go_To_Last_Element()
		self.currentElement.prox=elementToAlocate
		return
	def list_delete_Element(self,elementToDelete):
		elementFather=self.list_Go_To_Father_Of_Element(elementToDelete)		
		elementSon=elementFather.prox
		elementFather.prox=elementSon.prox
		
	def list_Print(self):
		self.list_Go_To_Root_Element()
		while self.currentElement.prox != None:
			self.currentElement.element_Print()
			self.currentElement=self.currentElement.prox
		self.currentElement.element_Print()
		return
		
	
	

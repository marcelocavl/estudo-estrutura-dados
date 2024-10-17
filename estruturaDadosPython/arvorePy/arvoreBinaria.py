from elementTree import ElementTree

class ArvoreBinaria:
	def __init__(self,rootElement):
		self.rootElement=rootElement
		self.numElements=1
	def arvoreBinaria_Get_RootElement(self):
		return
	
	def arvoreBinaria_Get_NumElements(self):
		return

	def arvoreBinaria_Alocar(self,element,rootElement):
		if element.elementTree_Get_Value()<rootElement.elementTree_Get_Value() and rootElement.elementTree_Get_LeftElementTree()== None:
			rootElement.leftElementTree=element;
			return
		if element.elementTree_Get_Value()>rootElement.elementTree_Get_Value() and rootElement.elementTree_Get_RightElementTree()== None:
			rootElement.rightElementTree=element;
			return
		if element.elementTree_Get_Value()<rootElement.elementTree_Get_Value() and rootElement.elementTree_Get_LeftElementTree()!=None:
			self.arvoreBinaria_Alocar(element,rootElement.elementTree_Get_LeftElementTree())	

		if element.elementTree_Get_Value()>rootElement.elementTree_Get_Value() and rootElement.elementTree_Get_RightElementTree()!=None:
			self.arvoreBinaria_Alocar(element,rootElement.elementTree_Get_RightElementTree())	
	def arvoreBinaria_Print(self,elementRoot):
		if(elementRoot.elementTree_Is_Leaf()):
			elementRoot.elementTree_Print()
			print("||||||||||||||||||||||||||||||||||||||||||||||||||")
			return
		if(elementRoot.rightElementTree!=None):
			elementRoot.elementTree_Print()
			print("||||||||||||||||||||||||||||||||||||||||||||||||||")
			self.arvoreBinaria_Print(elementRoot.rightElementTree)

		if(elementRoot.leftElementTree!=None):
			elementRoot.elementTree_Print()
			print("||||||||||||||||||||||||||||||||||||||||||||||||||")
			self.arvoreBinaria_Print(elementRoot.leftElementTree)
	
	



			

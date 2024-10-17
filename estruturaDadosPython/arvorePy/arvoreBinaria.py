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
	
	def arvoreBinaria_Delete_Node(self,element):
		elementFather=self.arvoreBinaria_Search_For_father(element,self.rootElement)
		print("O PAI TA ON!")
		elementFather.elementTree_Print()
		if(elementFather.rightElementTree!=None and element.elementTree_Get_Value()==elementFather.rightElementTree.elementTree_Get_Value()):
			self.arvoreBinaria_Delete(elementFather.rightElementTree)
			elementFather.rightElementTree=None
			return

		if(elementFather.leftElementTree!=None and element.elementTree_Get_Value()==elementFather.leftElementTree.elementTree_Get_Value()):
			self.arvoreBinaria_Delete(elementFather.leftElementTree)
			elementFather.leftElementTree=None
			return


		
	def arvoreBinaria_Delete(self,rootElement):
		if(rootElement.elementTree_Is_Leaf()):
			rootElement=None
			return;
		if(rootElement.rightElementTree!=None):	
			self.arvoreBinaria_Delete(rootElement.rightElementTree)

		if(rootElement.leftElementTree!=None):	
			self.arvoreBinaria_Delete(rootElement.leftElementTree)
		rootElement=None
		return



		
					
			
		
		

	def arvoreBinaria_Search_For_father(self,element,rootElement):
		if(rootElement.rightElementTree!=None and element.elementTree_Get_Value()==rootElement.rightElementTree.elementTree_Get_Value()):
			return rootElement
		if(rootElement.leftElementTree!=None and element.elementTree_Get_Value()==rootElement.leftElementTree.elementTree_Get_Value()):
			return rootElement
		if(element.elementTree_Get_Value()<rootElement.leftElementTree.elementTree_Get_Value() and rootElement.leftElementTree!=None):
			return self.arvoreBinaria_Search_For_father(element,rootElement.leftElementTree)
		if(element.elementTree_Get_Value()>rootElement.rightElementTree.elementTree_Get_Value() and rootElement.rightElementTree!=None):
			return self.arvoreBinaria_Search_For_father(element,rootElement.rightElementTree)
		
	



			

class ElementTree:
	def __init__(self,value):
		self.value=value
		self.rightElementTree=None
		self.leftElementTree=None
		return
	def elementTree_Get_Value(self):
		return self.value

	def elementTree_Get_RightElementTree(self):
		if self.rightElementTree==None:
			return None
		return self.rightElementTree

	def elementTree_Get_LeftElementTree(self):
		if self.leftElementTree==None:
			return None
		return self.leftElementTree

	def elementTree_Print(self):
		print(int(self.value))
		if self.elementTree_Get_RightElementTree() != None:
			print("valor do elemento direito: "+str(self.elementTree_Get_RightElementTree().elementTree_Get_Value()))
		if self.elementTree_Get_LeftElementTree() != None:
			print("valor do elemento esquerdo: "+str(self.elementTree_Get_LeftElementTree().elementTree_Get_Value()))
		
	def elementTree_Alocate_Right(self,elementTree):
		self.rightElementTree=elementTree
		return			
	def elementTree_Alocate_Left(self,elementTree):
		self.leftElementTree=elementTree
		return		
	def elementTree_Is_Leaf(self):
		if(self.rightElementTree==None and self.leftElementTree==None):
			return True
		return False
	


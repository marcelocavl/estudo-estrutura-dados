from list import List	
from element import Element	

e1=Element(8)
e2=Element(12)
e3=Element(3)
e4=Element(4)


list1=List(e1)

list1.list_Alocate(e2)
list1.list_Alocate(e3)
list1.list_Alocate(e4)
list1.list_Print()
print("==================================================")
list1.list_delete_Element(e4)
list1.list_Print()
	
	


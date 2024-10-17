from elementTree import ElementTree
from arvoreBinaria import ArvoreBinaria

element=ElementTree(32)
element2=ElementTree(20)
element3=ElementTree(7)


arvore=ArvoreBinaria(element)
	
arvore.arvoreBinaria_Alocar(element2,arvore.rootElement)
arvore.arvoreBinaria_Alocar(element3,arvore.rootElement)
element3=ElementTree(12)
arvore.arvoreBinaria_Alocar(element3,arvore.rootElement)
element3=ElementTree(40)
arvore.arvoreBinaria_Alocar(element3,arvore.rootElement)
element3=ElementTree(45)
arvore.arvoreBinaria_Alocar(element3,arvore.rootElement)

arvore.arvoreBinaria_Print(arvore.rootElement)
element3=ElementTree(40)

arvore.arvoreBinaria_Delete_Node(element3)
print("OUTRO PRINT--------------------")

arvore.arvoreBinaria_Print(arvore.rootElement)

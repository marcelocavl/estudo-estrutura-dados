from fila import Fila
from element import Element

e1=Element(12)	
pilha=Fila(e1)

e1=Element(8)	
pilha.fila_Alocate(e1)
	
e1=Element(4)	
pilha.fila_Alocate(e1)

pilha.fila_Print()
print("|||||||||||||||||||||||||||||||||||||||||||||")
pilha.fila_Delete()
	
pilha.fila_Print()



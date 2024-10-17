from pilha import Pilha
from element import Element

e1=Element(12)
pilha=Pilha(e1)

e1=Element(3)
pilha.pilha_Alocate(e1)
e1=Element(24)
pilha.pilha_Alocate(e1)

e1=Element(89)
pilha.pilha_Alocate(e1)

e1=Element(5)
pilha.pilha_Alocate(e1)

e1=Element(45)
pilha.pilha_Alocate(e1)




pilha.pilha_Print()

print("|||||||||||||||||||||||||||||||||||||||||||||||")
pilha.pilha_Delete()
pilha.pilha_Print()


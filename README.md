# EuroRobocup junior 2019

No repositório encontram se todos os ficheiros para o Eurobocup junior 2019.
Incluí:
	

 - Modelos 3d;
 - libraria;
 - Programação para arduino;
 - Programas base dos varios módulos;



## Como usar a libraria

 1. Importar a libraria `#include <base.h>`
 2. declarar os pinos dos motores da seguinte forma: `base Base(13,12,11,10,9,8,7,6);`
 3. no loop inserir as funções pretendidas listadas em **Funções**
## Funções

- Funções de movimento:
    - Movimentar para a frente: `Base.andarfrente(tempo);` 
    - Movimentar para trás: `Base.andartras(tempo);`
    - Parar o movimento: `Base.parar(tempo);`
    - Rodar no sentido dos ponteiros do relogio: `Base.rodarCW(tempo);`
    - Rodar no sentido contrario dos ponteiros do relogio: `Base.rodarCCW(tempo);`
    - Movimentar para a direita: `Base.andardireita(tempo);`
    - Movimentar para a esquerda: `Base.andaresquerda(tempo);`
    
    
     \* "tempo" deve ser substituido pelo tempo de movimento em ms

 - Sonar:
    -Verificar se existe obstaculo na frente do sonar: `Base.medir();` 
    
	 Notas: 

	 - Retorna uma boolean (True ou False);
	 - Se "True" existe obstaculo;
	 - Distancia que define existencia de obstaculo predefinida na libraria para 40cm;
	
     
    - Movimentar para a esquerda: `Base.andaresquerda(tempo);`
    
    	Notas: -retorna uma boolean (True ou False);
	       -se "True" existe obstaculo;
	       -distancia que define existencia de obstaculo predefinida na libraria para 40cm;
	
     

# EuroRobocup junior 2019

No repositório encontram se todos os ficheiros para o Eurobocup junior 2019.
Incluí:
	

 - Modelos 3d;
 - libraria;
 - Programação para arduino;
 - Programas base dos varios módulos;



## Como usar a libraria

 - Importar a libraria `#include <base.h>`
 - declarar os pinos dos motores da seguinte forma: `base Base(13,12,11,10,9,8,7,6);`
 - no loop inserir as funções pretendidas listadas em **Funções**
## Funções

 - Funções de movimento:
    - Movimentar para a frente: `Base.andarfrente(tempo);` 
    - Movimentar para trás: `Base.andartras(tempo);`
    - Parar o movimento: `Base.parar(tempo);`
    - Rodar no sentido dos ponteiros do relogio: `Base.rodarCW(tempo);`
    - Rodar no sentido contrario dos ponteiros do relogio: `Base.rodarCCW(tempo);`
    - Movimentar para a direita: `Base.andardireita(tempo);`
    - Movimentar para a esquerda: `Base.andaresquerda(tempo);`
    
    
     \* "tempo" deve ser substituido pelo tempo de movimento em ms

 - Sonar:
    -Verificar se existe obstaculo na frente do sonar: `Base.medir();` 
    
	 Notas: 

	 - Retorna uma boolean (True ou False);
	 - Se "True" existe obstaculo;
	 - Distancia que define existencia de obstaculo predefinida na libraria para 40cm;
	
     
    - Movimentar para a esquerda: `Base.andaresquerda(tempo);`
    
    	Notas:

		 - Retorna uma boolean (True ou False);
		 - Se "True" existe obstaculo;
		 - Distancia que define existencia de obstaculo predefinida na libraria para 40cm;

	
     

        

        

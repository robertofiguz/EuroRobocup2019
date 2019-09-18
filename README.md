# EuroRobocup junior 2019

No repositório encontram se todos os ficheiros para o Eurobocup junior 2019.
Incluí:
	

 - Modelos 3d;
 - Libraria;
 - Programação para arduino;
 - Programas base dos varios módulos;



## Como usar a libraria

 - Importar a libraria `#include <base.h>`
 - Declarar os pinos dos motores da seguinte forma: `base Base(13,12,11,10,9,8,7,6);`
 - O setup pode ficar vazio
 - No loop inserir as funções pretendidas listadas em **Funções**
## Funções

 - Funções de movimento:
    - Movimentar para a frente: `Base.andarfrente(tempo, velocidade);` 
    - Movimentar para trás: `Base.andartras(tempo, velocidade);`
    - Parar o movimento: `Base.parar(tempo, velocidade);`
    - Movimentar para a direita: `Base.andardireita(tempo, velocidade);`
    - Movimentar para a esquerda: `Base.andaresquerda(tempo, velocidade);`
    - Rodar no sentido dos ponteiros do relogio: `Base.rodarCW(tempo);`
    - Rodar no sentido contrario dos ponteiros do relogio: `Base.rodarCCW(tempo);`    
    
    
     \* "tempo" deve ser substituido pelo tempo de movimento em ms

 - Sonar:
    -Verificar se existe obstaculo na frente do sonar: `Base.medir();` 
    
	 Notas: 

	 - Retorna uma boolean (True ou False);
	 - Se "True" existe obstaculo;
	 - Distancia que define existencia de obstaculo predefinida na libraria para 40cm;
	
     
   
     

        

        

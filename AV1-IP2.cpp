//Gabriel de Vasconcelos Bandeira

#include <stdio.h> 
#include <string.h> 
#include <windows.h> 
#include <locale.h>

char menu(){
 	
char escolha;

fflush(stdin);
system("cls");
	
printf(" Revendedora de Automoveis \n");
printf(" 1 - Cadastro              \n");
printf(" 2 - Pesquisa(preço)       \n");
printf(" 3 - Listagem              \n");
printf(" 4 - Pesquisa(automovel)       \n");
printf(" 0 - Sair                  \n");
printf("Escolha uma opção: "); scanf(" %c", &escolha);
system("cls");
fflush(stdin);
return escolha;
}

struct cadastro{
	
	char codigo[5];
	char marca[25];
	char cor[20];
	int ano;
	float preco;
};

void pesquisaValor(struct cadastro vetorCadastro[50], int CadastrosTotal){
	
	int i;
	char valor, Vpreco[50];
	valor = 's';	
	float valorPreco;
	
	while (valor == 's'){
		int valorP=0;
		
		printf("Preço: "); scanf("%f", &valorPreco);	
		
			for	(i=0; i < CadastrosTotal; i++){
				if(valorPreco >= vetorCadastro[i].preco){
					
					Vpreco[valorP]=i;
					valorP++;
					
				}
			}fflush(stdin);
			int soma=1;

			printf(" Automoveis com preço de %.2f ou menor \n", valorPreco);
			
			for (i=0; i < valorP; i++){
				printf("             Automovel %d            \n", soma);
				printf(" Codigo: %s\n",vetorCadastro[Vpreco[i]].codigo);
				printf(" Marca: %s\n",vetorCadastro[Vpreco[i]].marca);
				printf(" Cor: %s\n",vetorCadastro[Vpreco[i]].cor);
				printf(" Ano: %d\n",vetorCadastro[Vpreco[i]].ano);
				soma++;
			}

			printf("Digite (s) para continuar pesquisando e (n) para sair: "); scanf(" %c", &valor);
				system("cls");
				fflush(stdin);
		}
	
}

void listaGeral(struct cadastro vetorCadastro[50], int CadastrosTotal){
	
	int i;
	char valor;
	
	valor = 's';	
		while (valor == 's'){
			int soma=1;
			printf("             Lista de automoveis            \n");
			for (i=0; i < CadastrosTotal; i++){
				printf("Automovel%d \n", soma);
				printf(" Codigo: %s\n",vetorCadastro[i].codigo);
				printf(" Marca: %s\n",vetorCadastro[i].marca);
				printf(" Preço: %.2f\n",vetorCadastro[i].preco);
				printf(" Ano: %d\n",vetorCadastro[i].ano);
				printf(" Cor: %s\n",vetorCadastro[i].cor);
				
				soma++;
			}
			printf("          Quantidade total de automoveis %d             \n",soma-1);
			printf("Digite (s) para verificar lista novamente e (n) para sair: "); scanf(" %c", &valor);
			system("cls");
			fflush(stdin);
		}
}

int main(){
	
  setlocale(LC_ALL, "Portuguese");
  
	int CadastrosTotal = 0, novoAutomovel, i, aux,cod=1;
	char valor, ValorCodigo[5];
	char valorMenu='A';
	
	int valorAno, z;
	char valorMarca[25], valorCor[20];
		
	while (valorMenu != '0'){
		valorMenu = menu();
		
		struct cadastro vetorCadastro[50];
		
		switch(valorMenu){
		case '1':
			valor = '0';
			while (valor == '0'){
				
				printf("Digite o numero de automoveis a ser cadastrado: "); scanf("%d", &novoAutomovel);			
				
				if(novoAutomovel + CadastrosTotal <= 50){		
					for (i=(0+CadastrosTotal); i<(novoAutomovel+CadastrosTotal); i++){		
									
						while (cod == 1){
						
							printf("Digite o codigo: ");
							scanf(" %s", &ValorCodigo);
							
							cod = 0;
								for (aux=0; aux < i; aux++){
									if (strcmp(ValorCodigo,vetorCadastro[aux].codigo)==0){
										cod = 1;
										
										break;
									}
									
								}
								
							if(cod == 1){
						    	printf("Codigo ''%s'' existente\n", ValorCodigo);
						    	
							}else{
								 
	            				strcpy(vetorCadastro[i].codigo,ValorCodigo); 	            				
							}
						}
						cod = 1;
											
						printf("Digite a marca: ");
						scanf(" %s", &vetorCadastro[i].marca);
						printf("Digite a cor: ");
						scanf(" %s", &vetorCadastro[i].cor);
						printf("Digite o ano: ");
						scanf("%d", &vetorCadastro[i].ano);
						printf("Digite o preço: ");
						scanf("%f", &vetorCadastro[i].preco);
						
						}
					CadastrosTotal+=novoAutomovel;		
					}else{
						
					printf("Maximo de cadastros excedido, favor cadastrar 50 ou menos automoveis\n");
					
					}
					
					
					printf("Digite (s) para continuar adicionando automoveis e (n) para sair: "); scanf(" %c", &valor);
					
				}
				system("cls");
				fflush(stdin);
				break;
		
		case '2':
			pesquisaValor(vetorCadastro, CadastrosTotal);
			system("cls");
			fflush(stdin);
			break;
			

		case '3':
			listaGeral(vetorCadastro, CadastrosTotal);
			
			system("cls");
			fflush(stdin);
			break;
		

        case '4':
            valor = '0';
            while (valor == '0'){
                printf("        Pesquisa por automovel        \n");

                printf(" Insira a marca:"); scanf(" %s", &valorMarca);
                printf(" Insira o ano:");   scanf(" %d", &valorAno);
                printf(" Insira a cor:");   scanf(" %s", &valorCor);
                printf("           Automoveis           \n");
                
                for(i=0; i<CadastrosTotal; i++){

                       if((strcmp(valorMarca,vetorCadastro[i].marca)==0) && (valorAno==vetorCadastro[i].ano) && (strcmp(valorCor,vetorCadastro[i].cor)==0)){

                        printf(" codigo automovel: %s               \n", vetorCadastro[i].codigo);
                        printf(" preço do automovel: %.2f             \n", vetorCadastro[i].preco);
                    }

                }
            printf("Digite (s) para continuar pesquisando e (n) para sair: "); scanf(" %c", &valor);
            }
            system("cls");
			fflush(stdin);
	        break;
	        
	    case '0':
	    	valorMenu = '0';
	    	printf("Fechando sistema...");
			fflush(stdin);
	    	break;
	    		
		}
	}		
}

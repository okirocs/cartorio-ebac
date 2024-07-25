#include <stdio.h> //biblioteca de comunicacao
#include <stdlib.h> //biblioteca de alocacao de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar da string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE  *file; //cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo no banco de dados
	fprintf (file,cpf);  //salva o valor da variavel
	fclose (file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",Nome);

	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);	

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, Cargo);
	fclose(file);
	
	system("pause");
}


int consultar()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			printf("Não foi possivel abrir o arquivo, não localizado!. \n");
			
		}
	
	while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("\n essas são as informaçoes do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
	
		system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	 printf("Digite o cpf que gostaria de deletar(somente numeros): "); //caso encontre o cadastro solicitado
	 scanf("%s", cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r");
	
	if(file == NULL) //caso o usuario nao seja encontrado
	{	
		printf("o usuario não se encontra no sistema!. \n");	
		system("pause");
		fclose(file);
	}
	  
	 
}


int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("escolha a opção desejada no menu\n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system ("cls");

	
		switch(opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
 			break;
 			
 				
 			default:
 				printf("essa opção nao está disponivel, tente novamente!\n");
			system("pause");
			break;
			
		}
		
		
	
	
}
	
}

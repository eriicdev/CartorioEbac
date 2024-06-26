#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //bibliot�ca de aloca��es de texto poe regi�o
#include <string.h> //biblioteca respons�vel por fazer a string funcionar

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//incio da cir��o das v�riaveis ou seja,mais de uma=strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cri��o das vari�veis
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // scanf=salvando na vari�ve e %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); // fopen= abrindo o arquivo
	fprintf(file,","); //adicionando a ,
	fclose(file); //fechando o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s" , nome);//scanf=salvando na vari�vel e %s refere-se a string
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, nome);//adicionando a palavra "nome"
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, ","); //adicionando a ,
	fclose(file); //fechando o arquivo
	
	printf("Digite o Sobrenome a ser Cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s" , sobrenome);   // scanf=salvando na vari�ve e %s refere-se a string
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, sobrenome);//adicionando a palavra "sobrenome"
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, ","); //adicionando a ,
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser Cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s" , cargo); // scanf=salvando na vari�ve e %s refere-se a string
	
	file  = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, cargo);//adicionando a palavra "cargo"
	fclose(file);//fechando o arquivo
	
	system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");      //definindo a linguagem
	
	//incio da cir��o das v�riaveis ou seja,mais de uma=strings
	char cpf[40];
	char conteudo[200];
	//final das vari�veis
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usu�rio
	scanf("%s",cpf);// scanf=salvando na vari�ve e %s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o Arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do sus�rio ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! .\n");
		system("pause");
	}
}



int main()	
{
	int opcao=0;       //definindo as vari�veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");  
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{

			setlocale(LC_ALL,"Portuguese");      //definindo a linguagem
		
	
			printf("### Cart�rio da EBAC ###\n\n");      //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar os nomes\n");
			printf("\t3 - Deletar os nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");    
			printf("Op��o:"); //fim do menu
		
			
			scanf("%d" , &opcao);    //armazenando a escolha do usu�rio
		
			system("cls");
		
			switch(opcao)	
			{
				case 1:
				registro(); 
				break;
				
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por ultilizar este sistema!\n");
				return 0;
				break;
			
			
			
				default:
				printf("Essa Op��o n�o est� Dispon�vel!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf(" Senha incorreta!");
				
}

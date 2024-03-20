#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //bibliotéca de alocações de texto poe região
#include <string.h> //biblioteca responsável por fazer a string funcionar

int registro() // função responsável por cadastrar os usuários no sistema
{
	//incio da cirção das váriaveis ou seja,mais de uma=strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da crição das variáveis
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // scanf=salvando na variáve e %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); // fopen= abrindo o arquivo
	fprintf(file,","); //adicionando a ,
	fclose(file); //fechando o arquivo
	
	printf("Digite o Nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s" , nome);//scanf=salvando na variável e %s refere-se a string
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, nome);//adicionando a palavra "nome"
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, ","); //adicionando a ,
	fclose(file); //fechando o arquivo
	
	printf("Digite o Sobrenome a ser Cadastrado: "); //coletando informação do usuário
	scanf("%s" , sobrenome);   // scanf=salvando na variáve e %s refere-se a string
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, sobrenome);//adicionando a palavra "sobrenome"
	fclose(file);//fechando o arquivo
	
	file = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, ","); //adicionando a ,
	fclose(file);//fechando o arquivo
	
	printf("Digite o cargo a ser Cadastrado: ");  //coletando informação do usuário
	scanf("%s" , cargo); // scanf=salvando na variáve e %s refere-se a string
	
	file  = fopen(arquivo, "a");// fopen= abrindo o arquivo
	fprintf(file, cargo);//adicionando a palavra "cargo"
	fclose(file);//fechando o arquivo
	
	system("pause"); 
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");      //definindo a linguagem
	
	//incio da cirção das váriaveis ou seja,mais de uma=strings
	char cpf[40];
	char conteudo[200];
	//final das variáveis
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuário
	scanf("%s",cpf);// scanf=salvando na variáve e %s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o Arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do susário ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! .\n");
		system("pause");
	}
}



int main()
{
	int opcao=0;       //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL,"Portuguese");      //definindo a linguagem
		
	
		printf("### Cartório da EBAC ###\n\n");      //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");     
		printf("Opção:"); //fim do menu
		
			
		scanf("%d" , &opcao);    //armazenando a escolha do usuário
		
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
			
			default:
			printf("Essa Opção não está Disponível!\n");
			system("pause");
			break;
				
		}
		
	}	
}

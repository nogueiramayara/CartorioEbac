#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim cria��o de vari�veis

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respos�vel por copiar os valores das string// estamos copiando o valor que o usu�rio colocar em cpf para tamb�m ser o nome do arquivo
	
	FILE *file; //aqui estamos pedindo para o computador procurar um arquivo chamado file porque queremos criar um file
	file = fopen(arquivo, "w"); //abre um arquivo novo, por isso W de write
	fprintf(file,"\nCPF: ");
	fprintf(file, cpf); //aqui estamos pedindo pro computador salvar o valor da vari�vel
	fclose(file);
	
	file=fopen(arquivo, "a"); //aqui estamos pedindo para o computador abrir o arquivo que j� criamos para atualizar informa��es
	fprintf(file, "\n"); //teste quebra de linha
	fclose(file);//fecha arquivo para salvar
	
	printf("Digite o nome a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", nome);
	
	file= fopen(arquivo,"a");//atualiza informa��es
	fprintf(file,"NOME: ");
	fprintf(file, nome);
	fclose(file);//fecha e salva
		
	file= fopen(arquivo, "a"); //atualiza informa��es
	fprintf(file, " "); 
	fclose(file);//fecha e salva
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", sobrenome);//%s refere-se a string, salva na vari�vel sobrenome
	
	file= fopen(arquivo,"a");//abre arquivo para atualizar
	fprintf(file, sobrenome);
	fclose(file);//fecha e salva
		
	file= fopen(arquivo, "a"); //abre arquivo para atualizar
	fprintf(file, "\n");
	fclose(file);//fecha e salva

	printf("Digite o cargo a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", cargo);//%s refere-se a string, salva na vari�vel cargo
	
	file= fopen(arquivo,"a");//abre arquivo para atualizar
	fprintf(file,"CARGO: ");
	fprintf(file, cargo);
	fprintf(file,"\n\n");
	fclose(file);//fecha e salva
	
	system("pause");
			
}

int consulta()
{
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//%s porque � string e no caso estamos salvando na variavel cpf
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, cpf n�o localizado!\n\n");
	}

	else
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//looping!fgets vai buscar la no arquivo, busca na variavel conteudo, 200 � o tamanho m�ximo do conteudo, file � o aquivo onde est� o conteudo, depois que n�o achar mais caracteres (ou seja, diferente de nulo, ele para de buscar
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	int opcao=0;
	
	printf("Digite o CPF do usu�rio que deseja deletar: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		{
		FILE *file;
		file = fopen(cpf,"r");
		printf("\nEssas s�o as informa��es do usu�rio a ser deletado:\n");
			
		while(fgets(cpf,40, file) !=NULL)
			{
				printf("%s", cpf);
			}
		fclose(file);
		}
		
		printf("Digite novamente o cpf do usu�rio para confirmar a a��o ou 0 para cancelar:\n");
		scanf("%s",cpf);
		remove(cpf);//essa fun��o j� existe nas nossas bibliotecas, por isso aqui apenas chamamos um fun��o que j� est� importada
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		system("cls");
		
		printf("A��o conclu�da!\n\n");
		system("pause");
	
	}
		
}

int main() //funcao princiapal
{
	int opcao=0; //alocamento de espa�o para armazenar a escolha do usuario//Definindo vari�veis
	int laco=1; //definindo a vari�vel de repeti��o
	
	for(laco=1; laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //scanf � respons�vel por escanear a resposta do usu�rio e %d por armazenar a vari�vel inteira em op��o
	
		system("cls"); //apaga a tela ap�s o usu�rio fazer a sua escolha, o que deixa o layout mais amig�vel para o usu�rio
		
			
		switch(opcao)
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n\n");
			return 0;//retorna ao valor 0, quebra la�o, fun��o, tudo! Ou seja, sai do sistema.
			break;
			
			default: //o default funciona como se fosse um else
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;	
		}
	
    }

}

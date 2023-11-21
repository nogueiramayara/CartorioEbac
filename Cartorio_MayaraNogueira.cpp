#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string

int registro()// função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criação de variáveis

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //resposável por copiar os valores das string// estamos copiando o valor que o usuário colocar em cpf para também ser o nome do arquivo
	
	FILE *file; //aqui estamos pedindo para o computador procurar um arquivo chamado file porque queremos criar um file
	file = fopen(arquivo, "w"); //abre um arquivo novo, por isso W de write
	fprintf(file,"\nCPF: ");
	fprintf(file, cpf); //aqui estamos pedindo pro computador salvar o valor da variável
	fclose(file);
	
	file=fopen(arquivo, "a"); //aqui estamos pedindo para o computador abrir o arquivo que já criamos para atualizar informações
	fprintf(file, "\n"); //teste quebra de linha
	fclose(file);//fecha arquivo para salvar
	
	printf("Digite o nome a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", nome);
	
	file= fopen(arquivo,"a");//atualiza informações
	fprintf(file,"NOME: ");
	fprintf(file, nome);
	fclose(file);//fecha e salva
		
	file= fopen(arquivo, "a"); //atualiza informações
	fprintf(file, " "); 
	fclose(file);//fecha e salva
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", sobrenome);//%s refere-se a string, salva na variável sobrenome
	
	file= fopen(arquivo,"a");//abre arquivo para atualizar
	fprintf(file, sobrenome);
	fclose(file);//fecha e salva
		
	file= fopen(arquivo, "a"); //abre arquivo para atualizar
	fprintf(file, "\n");
	fclose(file);//fecha e salva

	printf("Digite o cargo a ser cadastrado: ");//coletando infos do usuario
	scanf("%s", cargo);//%s refere-se a string, salva na variável cargo
	
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
	scanf("%s", cpf);//%s porque é string e no caso estamos salvando na variavel cpf
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, cpf não localizado!\n\n");
	}

	else
	{
		printf("\nEssas são as informações do usuário:\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//looping!fgets vai buscar la no arquivo, busca na variavel conteudo, 200 é o tamanho máximo do conteudo, file é o aquivo onde está o conteudo, depois que não achar mais caracteres (ou seja, diferente de nulo, ele para de buscar
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
	
	printf("Digite o CPF do usuário que deseja deletar: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		{
		FILE *file;
		file = fopen(cpf,"r");
		printf("\nEssas são as informações do usuário a ser deletado:\n");
			
		while(fgets(cpf,40, file) !=NULL)
			{
				printf("%s", cpf);
			}
		fclose(file);
		}
		
		printf("Digite novamente o cpf do usuário para confirmar a ação ou 0 para cancelar:\n");
		scanf("%s",cpf);
		remove(cpf);//essa função já existe nas nossas bibliotecas, por isso aqui apenas chamamos um função que já está importada
		
		FILE *file;
		file = fopen(cpf,"r");
		fclose(file);
		
		system("cls");
		
		printf("Ação concluída!\n\n");
		system("pause");
	
	}
		
}

int main() //funcao princiapal
{
	int opcao=0; //alocamento de espaço para armazenar a escolha do usuario//Definindo variáveis
	int laco=1; //definindo a variável de repetição
	
	for(laco=1; laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("\t4- Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //scanf é responsável por escanear a resposta do usuário e %d por armazenar a variável inteira em opção
	
		system("cls"); //apaga a tela após o usuário fazer a sua escolha, o que deixa o layout mais amigável para o usuário
		
			
		switch(opcao)
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema!\n\n");
			return 0;//retorna ao valor 0, quebra laço, função, tudo! Ou seja, sai do sistema.
			break;
			
			default: //o default funciona como se fosse um else
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;	
		}
	
    }

}

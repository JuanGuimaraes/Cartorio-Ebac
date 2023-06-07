#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/strings
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variáveis/strings
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");// cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel 
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");// abre o arquivo e "a" atualiza 
    fprintf(file,",NOME: ");// adiciona uma virgula 
    fclose(file);// fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//Coletando infrmação do usuário
    scanf("%s",nome); // %s refere-se a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,nome);//Qual arquivo atualizar
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,",Sobrenome: ");//Adiciona uma virgula
    fclose(file);// Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//Coletando informação do usuário
    scanf ("%s",sobrenome);//Rwferece a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,sobrenome);//Qual arquivo abrir
    fclose(file);//Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Letra A atualiza as informaçoes dentro da pasta
    fprintf(file,",Cargo: ");//Adiciona uma virgula
    fclose(file);//Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//Coletando informações do usuário
    scanf ("%s", cargo);//Refere-se a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,cargo);//Qual arquivo abrir
    fclose(file);//Fecha o arquivo
    
    system("pause");//PAusa o sistema
}


int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);// Salva na string
	
	FILE *file;
	file = fopen(cpf, "r"); // r para ler o arquivo
	if(file== NULL) // Caso o arquivo não seja encontrado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL);//Enquanto,buscar no arquivo, até 200 valores no arquivo, enquanto for diferente de nulo
	{
		printf("\nEssas são as informaçãoes do usuário: ");
		printf("\nCPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	
	}
	
    system("pause");
	
	
}

int deletar()
{
    char cpf [40]; //cria a variavel (string) cpf
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);// escaneia e salva na string cpf
    
    remove(cpf);
    
    FILE *file; //puxa os arquivos
    file = fopen(cpf, "r");// acessar o arquivo cpf, "r" para ler
    
    if(file == NULL )// se o arquivo for nulo
    {
		printf("Usuário não se enconta no sistema!.\n");
    	system("pause");
    }
    
    
}

int main()
{
	int opcao=0; //Definindo variáveis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("###Cartório da EBAC###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha:");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
    {
	
        system ("cls");
	    for(laco=1;laco=1;) // indicando para voltar ao menu
       {
	
	        system("cls"); // limpar tela a segur
	
	        setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
    	    printf("###Cartório da EBAC###\n\n"); // Inicio do menu
	        printf("Escolha a opção desejada no menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Opção:");// Fim do menu
	
    	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
        	system("cls");// responsavel por limpar a tela
    
            switch(opcao) //inicio da seleção do menu
        {
            	case 1:
    		    registro();// chama de funções
		    	break;	
			
		    	case 2:
			    consulta();
			    break;
			
		        case 3:
		        deletar();	
    	        break;
    	    
    	        case 4:
    	        printf("Obrigado por utilizar o sistema\n");
    	        return 0;
    	        break;
    	    
    	        default:
    	        printf("Essa opção não está disponivel!\n");
    		    system("pause");	
    	        break;	
		}// Fim da seleção
		
	   }
	   
   }
   
   else
        printf("Senha incoreta!");
}
     
  

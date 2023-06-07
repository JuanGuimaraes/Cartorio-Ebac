#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/strings
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/strings
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");// cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel 
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");// abre o arquivo e "a" atualiza 
    fprintf(file,",NOME: ");// adiciona uma virgula 
    fclose(file);// fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//Coletando infrma��o do usu�rio
    scanf("%s",nome); // %s refere-se a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,nome);//Qual arquivo atualizar
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,",Sobrenome: ");//Adiciona uma virgula
    fclose(file);// Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//Coletando informa��o do usu�rio
    scanf ("%s",sobrenome);//Rwferece a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e atualiza
    fprintf(file,sobrenome);//Qual arquivo abrir
    fclose(file);//Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Letra A atualiza as informa�oes dentro da pasta
    fprintf(file,",Cargo: ");//Adiciona uma virgula
    fclose(file);//Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//Coletando informa��es do usu�rio
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
	if(file== NULL) // Caso o arquivo n�o seja encontrado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL);//Enquanto,buscar no arquivo, at� 200 valores no arquivo, enquanto for diferente de nulo
	{
		printf("\nEssas s�o as informa��oes do usu�rio: ");
		printf("\nCPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	
	}
	
    system("pause");
	
	
}

int deletar()
{
    char cpf [40]; //cria a variavel (string) cpf
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);// escaneia e salva na string cpf
    
    remove(cpf);
    
    FILE *file; //puxa os arquivos
    file = fopen(cpf, "r");// acessar o arquivo cpf, "r" para ler
    
    if(file == NULL )// se o arquivo for nulo
    {
		printf("Usu�rio n�o se enconta no sistema!.\n");
    	system("pause");
    }
    
    
}

int main()
{
	int opcao=0; //Definindo vari�veis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("###Cart�rio da EBAC###\n\n");
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
	
    	    printf("###Cart�rio da EBAC###\n\n"); // Inicio do menu
	        printf("Escolha a op��o desejada no menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Op��o:");// Fim do menu
	
    	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
        	system("cls");// responsavel por limpar a tela
    
            switch(opcao) //inicio da sele��o do menu
        {
            	case 1:
    		    registro();// chama de fun��es
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
    	        printf("Essa op��o n�o est� disponivel!\n");
    		    system("pause");	
    	        break;	
		}// Fim da sele��o
		
	   }
	   
   }
   
   else
        printf("Senha incoreta!");
}
     
  

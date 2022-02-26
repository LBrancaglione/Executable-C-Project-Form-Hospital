#include <stdio.h>
#include <stdlib.h>

FILE* AbreArquivo (char mode, char location[50])
{
    FILE *arquivo;
    switch(mode){
    case 'W':
        arquivo = fopen (location,"wt");
    break;
    case 'R':
         arquivo = fopen (location,"rt");
    break;
    case 'A':
        arquivo = fopen (location,"a");
    break;
    }
    if(arquivo==NULL){
        printf("Não foi possivel abrir o arquivo.");
        exit(0);
    }
    return arquivo;
}

typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas



void ArquivoFechar (FILE*arquivo){
fclose(arquivo);
}

int main()
{

    int idade = 0;
    char cd[100];
    char rua[100];
    char numCasa[3];
    char estado[100];
    char anoNascimento[5];
    char diaNascimento[6];
    char cep[8];
    char email[100];
    char dataDiagnostico[11];
    char comorbidade[50];
    char nome[100];
    char opcao;
    char opcao2;
    char opcao3;
    char opcao4;
    char anoAtual[4];
    char locate[50];
    char locate2[50];
    char str_int[10];
    char login[30]; // responsável por armazenar a senha inserida pelo usuário
    char senha[30]; // responsável por armazenar a senha inserida pelo usuário
    printf("\n\n\n\f\f Seja Bem vindo ao programa \f\f\n");
    FILE *arquivo;
    FILE *grupoRisco;


    strcpy(p[0].login, "Administrador"); // Definindo o login "David" na struct
    strcpy(p[0].senha, "adm"); // Definindo a senha "123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A função strcmp é responsável por comparar string com string
        printf("Usuario logado \n\n"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
        printf("Digite o ano atual: (0000) ");
        scanf("%s", &anoAtual);
        printf("\nDeseja abrir ou criar o arquivo de cadastro de pacientes ? \n");
        printf("\n Digite s para Sim\n Digite n para Nao \n");
        scanf("%s", &opcao);
        if(opcao == 's'){
        printf("Por favor informe o que sera feito no arquivo.\n");
        printf("\n Digite Digite W para registrar dados\n Digite R para ler dados \n Digite A para criar um documento ou adicionar dados. \n");
        scanf("%s", &opcao2);
        printf("Agora infome o nome do arquivo e sua extensao, e informe tambem seu caminho. \n");
        scanf("%s", &locate);
        arquivo = AbreArquivo(opcao2, locate);
        if(opcao2 == 'A'){
        do{
        printf("Por Favor informe o Nome do paciente: " );
        fflush(stdin);
        fgets( nome, 100, stdin);
        fprintf(arquivo,"Nome do Paciente: %s \n" , &nome);
        printf("Por Favor informe a Cidade do paciente: " );
        fflush(stdin);
        fgets( cd, 100, stdin);
        fprintf(arquivo,"Cidade do paciente: %s \n" , &cd);
        printf("Por Favor informe a Rua do paciente: " );
        fflush(stdin);
        fgets( rua, 100, stdin);
        fprintf(arquivo,"Rua da moradia do paciente: %s \n" , &rua);
        printf("Por Favor informe o numero da casa do paciente: " );
        fflush(stdin);
        fgets( numCasa, 100, stdin);
        fprintf(arquivo,"Número da casa do paciente: %s \n" , &numCasa);
        printf("Por Favor informe a Estado do paciente: " );
        fflush(stdin);
        fgets( estado, 100, stdin);
        fprintf(arquivo,"Estado do paciente: %s \n" , &estado);
        printf("Por Favor informe o CEP do paciente: " );
        fflush(stdin);
        fgets( cep, 100, stdin);
        fprintf(arquivo,"CEP do paciente: %s \n\n" , &cep);
        printf("Por Favor informe a data do diagnostico (00/00/0000): " );
        fflush(stdin);
        fgets( dataDiagnostico, 11, stdin);
        fprintf(arquivo,"Data do diagnostico: %s \n\n" , &dataDiagnostico);
        printf("Por Favor informe o ano de nacimento do paciente (0000): " );
        fflush(stdin);
        fgets( anoNascimento, 5, stdin);
        printf("Por Favor informe o dia de nacimento do paciente (00/00): " );
        fflush(stdin);
        fgets( diaNascimento, 6, stdin);
        fprintf(arquivo,"Data de Nacimento do Paciente: %s/%s \n\n" , &diaNascimento, &anoNascimento);
        printf("Por Favor informe o Email do Paciente: " );
        fflush(stdin);
        fgets( email, 100, stdin);
        fprintf(arquivo,"Email do Paciente: %s \n" , &email);
        printf("O paciente possui alguma comorbidade ? Se sim qual:  " );
        fflush(stdin);
        fgets( comorbidade, 50, stdin);
        fprintf(arquivo,"Comorbidade: %s \n" , &comorbidade);
        fprintf(arquivo, " ------------------------------------------ \n");
        int nacimento = atoi(anoNascimento);
        int ano = atoi(anoAtual);
        idade = ano - nacimento;
        if(idade >= 65){
        printf("O paciente e do grupo de risco. \n");
        printf("Por Favor informe novamente o nome do paciente com uma extensao .txt e um caminho para a criação de outro arquivo. \n");
        scanf("%s", &locate2);
        grupoRisco = fopen (locate2,"wt");
        fprintf(grupoRisco,"CEP do paciente: %s \n" , &cep);
        fprintf(grupoRisco,"Idade do Paciente: %i" , idade);
        printf("%i \n", idade);
        fclose(grupoRisco);
        }
        printf("Deseja cadastrar Outro paciente ? ");
        printf("S para sim e N para nao.");
        scanf("%s", &opcao3);
        } while(opcao3 != 'N');
        }
        if(opcao2 == 'W'){
        do{
        printf("Por Favor informe o Nome do paciente: " );
        fflush(stdin);
        fgets( nome, 100, stdin);
        fprintf(arquivo,"Nome do Paciente: %s \n" , &nome);
        printf("Por Favor informe a Cidade do paciente: " );
        fflush(stdin);
        fgets( cd, 100, stdin);
        fprintf(arquivo,"Cidade do paciente: %s \n" , &cd);
        printf("Por Favor informe a Rua do paciente: " );
        fflush(stdin);
        fgets( rua, 100, stdin);
        fprintf(arquivo,"Rua da moradia do paciente: %s \n" , &rua);
        printf("Por Favor informe o numero da casa do paciente: " );
        fflush(stdin);
        fgets( numCasa, 100, stdin);
        fprintf(arquivo,"Número da casa do paciente: %s \n" , &numCasa);
        printf("Por Favor informe a Estado do paciente: " );
        fflush(stdin);
        fgets( estado, 100, stdin);
        fprintf(arquivo,"Estado do paciente: %s \n" , &estado);
        printf("Por Favor informe o CEP do paciente: " );
        fflush(stdin);
        fgets( cep, 8, stdin);
        fprintf(arquivo,"CEP do paciente: %s \n\n" , &cep);
        printf("Por Favor informe a data do diagnostico (00/00/0000): " );
        fflush(stdin);
        fgets( dataDiagnostico, 11, stdin);
        fprintf(arquivo,"Data do diagnostico: %s \n\n" , &dataDiagnostico);
        printf("Por Favor informe o ano de nacimento do paciente (0000): " );
        fflush(stdin);
        fgets( anoNascimento, 5, stdin);
        printf("Por Favor informe o dia de nacimento do paciente (00/00): " );
        fflush(stdin);
        fgets( diaNascimento, 6, stdin);
        fprintf(arquivo,"Data de Nacimento do Paciente: %s/%s \n\n" , &diaNascimento, &anoNascimento);
        printf("Por Favor informe o Email do Paciente: " );
        fflush(stdin);
        fgets( email, 100, stdin);
        fprintf(arquivo,"Email do Paciente: %s \n" , &email);
        printf("O paciente possui alguma comorbidade ? Se sim qual:  " );
        fflush(stdin);
        fgets( comorbidade, 50, stdin);
        fprintf(arquivo,"Comorbidade: %s \n" , &comorbidade);
        fprintf(arquivo, " ------------------------------------------ \n");
        int nacimento = atoi(anoNascimento);
        int ano = atoi(anoAtual);
        idade = ano - nacimento;
        if(idade >= 65){
        printf("O paciente e do grupo de risco. \n");
        printf("Por Favor informe novamente o nome do paciente com uma extensao .txt e um caminho para a criação de outro arquivo. \n");
        scanf("%s", &locate2);
        grupoRisco = fopen (locate2,"wt");
        fprintf(grupoRisco,"CEP do paciente: %s \n" , &cep);
        fprintf(grupoRisco,"Idade do Paciente: %i" , idade);
        fclose(grupoRisco);
        }
        printf("Deseja cadastrar Outro paciente ? ");
        printf("S para sim e N para nao.");
        scanf("%s", &opcao3);
        }while(opcao3 != 'N');
        }
        if(opcao2 == 'R'){
            printf("\n");
            while(fscanf(arquivo,"%[^\n]s %[^\n]s %[^\n]s %[^\n]s %[^\n]s %[^\n]s %[^\n]s %[^\n]s %[^\n]s", &nome, &cd, &rua, &numCasa, &estado, &anoNascimento, &dataDiagnostico, &cep, &email )!= EOF){
                 printf("%s %s %s", &nome);
                 break;
            }
        }
        }
    }else{
        printf("Login e/ou senha incorretos"); // senão, login ou senha incorreta.

    }
    system("PAUSE");
return 0;
}

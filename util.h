#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AND &&
#define OR  ||
#define OP 3

#if    OP==1
    #define VERSAO1
#elif  OP==2
    #define VERSAO2
#elif  OP==3
    #define VERSAO3    
#endif

typedef struct _{
    char nome[50];   
    int  idade;    
    char telefone[14]; // +55 81 9 9999-9999
    struct _ *proximo;
} Aluno; 

void inserirAluno(Aluno **lista, char *nome, int idade, char *telefone);
void removerAluno(Aluno ** lista, char *nome);
void listar(Aluno **lista);
void atualizarAluno(Aluno **lista, char *nome, char *nome_novo, int idade_novo, char *telefone_novo);
void procurarAluno(Aluno **lista, char *nome);
void menu();
void limparTela();

void menu(){
    Aluno *lista = NULL;
    int n, escolha = 0;
    char nome_aux[50], tel_aux[14], nome_procurar[50], nome_deletar[50], nome_atualizar[50];

    do{ 
        #ifdef VERSAO3
            printf("\n-------------VERSAO3-------------\n");
            printf("1 - Inserir alunos\n");
            printf("2 - Deletar um aluno\n");
            printf("3 - Atualizar um aluno\n");
            printf("4 - Procurar um aluno\n");
            printf("5 - Listar alunos\n");
            printf("0 - Sair\n");
        #endif
        #ifdef VERSAO2
            printf("\n-------------VERSAO2-------------\n");
            printf("1 - Inserir alunos\n");
            printf("2 - Deletar um aluno\n");
            printf("0 - Sair\n");
        #endif
        #ifdef VERSAO1
            printf("\n-------------VERSAO1-------------\n");
            printf("1 - Inserir alunos\n");
            printf("0 - Sair\n");
        #endif

        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        
        while(escolha < 0 OR escolha > 5){
            printf("\nDigite sua escolha: ");
            scanf("%d", &escolha);
        }

        switch(escolha){
            #ifdef VERSAO3
            case 1:
                printf("Quantos alunos deseja inserir: ");
                scanf("%d", &n);
                
                int idade_aux;

                for(int i=0; i<n; i++){
                    limparTela();
                    printf("Digite o nome do aluno %d: ", i+1);
                    scanf(" %[^\n]", nome_aux);
                    printf("Digite a idade do aluno %d: ", i+1);
                    scanf(" %d", &idade_aux);
                    printf("Digite o telefone do aluno %d: ", i+1);
                    scanf(" %[^\n]", tel_aux);
                    inserirAluno(&lista, nome_aux, idade_aux, tel_aux);
                    limparTela();
                }
                break;
            case 2:
                printf("Digite o nome do aluno para deletar: ");
                scanf(" %[^\n]", nome_deletar);
                removerAluno(&lista, nome_deletar);
                listar(&lista);
                break;
            case 3:
                printf("Digite o nome do aluno para ser atualizado: ");
                scanf(" %[^\n]", nome_atualizar);
                printf("Digite o novo nome do aluno para atualizar: ");
                scanf(" %[^\n]", nome_aux);
                printf("Digite a nova idade do aluno: ");
                scanf(" %d", &idade_aux);
                printf("Digite o novo telefone do aluno: ");
                scanf(" %[^\n]", tel_aux);

                atualizarAluno(&lista, nome_atualizar, nome_aux, idade_aux, tel_aux);
                listar(&lista);
                break;
            case 4:
                printf("Digite o nome do aluno procurado: ");
                scanf(" %[^\n]", nome_procurar);
                procurarAluno(&lista, nome_procurar);
                break;
            case 5:
                listar(&lista);
                break;
            case 0:
                limparTela();
                puts("Obrigado! ;)\n");
                exit(0);
                break;
            default:
                limparTela();
                puts("OPÇÃO INVALIDA!!!\n");
                exit(0);
                break;
            #endif   

            #ifdef VERSAO2
                case 1:
                    printf("Quantos alunos deseja inserir: ");
                    scanf("%d", &n);
                    
                    int idade_aux;

                    for(int i=0; i<n; i++){
                        limparTela();
                        printf("Digite o nome do aluno %d: ", i+1);
                        scanf(" %[^\n]", nome_aux);
                        printf("Digite a idade do aluno %d: ", i+1);
                        scanf(" %d", &idade_aux);
                        printf("Digite o telefone do aluno %d: ", i+1);
                        scanf(" %[^\n]", tel_aux);
                        inserirAluno(&lista, nome_aux, idade_aux, tel_aux);
                        limparTela();
                    }
                    break;
                case 2:
                    printf("Digite o nome do aluno para deletar: ");
                    scanf(" %[^\n]", nome_deletar);
                    removerAluno(&lista, nome_deletar);
                    listar(&lista);
                    break;
                case 0:
                    limparTela();
                    puts("Obrigado! ;)\n");
                    exit(0);
                    break;
                default:
                    limparTela();
                    puts("OPÇÃO INVALIDA!!!\n");
                    exit(0);
                    break;
            #endif

            #ifdef VERSAO1
                case 1:
                    printf("Quantos alunos deseja inserir: ");
                    scanf("%d", &n);
                    
                    int idade_aux;

                    for(int i=0; i<n; i++){
                        limparTela();
                        printf("Digite o nome do aluno %d: ", i+1);
                        scanf(" %[^\n]", nome_aux);
                        printf("Digite a idade do aluno %d: ", i+1);
                        scanf(" %d", &idade_aux);
                        printf("Digite o telefone do aluno %d: ", i+1);
                        scanf(" %[^\n]", tel_aux);
                        inserirAluno(&lista, nome_aux, idade_aux, tel_aux);
                        limparTela();
                    }
                    break;
                case 0:
                    limparTela();
                    puts("Obrigado! ;)\n");
                    exit(0);
                    break;
                default:
                    limparTela();
                    puts("OPÇÃO INVALIDA!!!\n");
                    exit(0);
                    break;
            #endif
        }
    }while(escolha != 0);
}

void inserirAluno(Aluno **lista, char nome[], int idade, char telefone[]){
    Aluno *aux, *novo = (Aluno*)malloc(sizeof(Aluno));

    if(novo){
        strcpy(novo->nome, nome);
        novo->idade = idade;
        strcpy(novo->telefone, telefone);

        novo->proximo = NULL;

        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }else{
        printf("\nErro ao alocar memoria.\n");
    }
}

void atualizarAluno(Aluno **lista, char *nome, char *nome_novo, int idade_novo, char *telefone_novo){
    Aluno *p = *lista;
    Aluno *pant = NULL;
    int achei = 0;

    while(p){
        if( !(strcmp(p->nome, nome)) ){
            strcpy(p->nome, nome_novo);
            strcpy(p->telefone, telefone_novo);
            p->idade= idade_novo;
            achei = 1;
            break;
        }
        pant = p;
        p = p->proximo;
    }

    if(achei == 0){
        limparTela();
        printf("\nNão foi possivel achar o aluno %s.\n\n", nome);
        exit(0);
    }
    
}

void removerAluno(Aluno ** lista, char *nome){
    Aluno *p = *lista;
    Aluno *pant = NULL;

    if(p == NULL){
        limparTela();
        printf("\nNão foi possivel o remover aluno %s, lista vazia.\n\n", nome);
        exit(0);
    }

    while(p){
        if( !(strcmp(p->nome, nome)) ){
            if(pant){
                pant->proximo = p->proximo;
            }else{
                *lista = p->proximo;
            }
            free(p);
            break;
        }
        pant = p;
        p = p->proximo;
    }
}

void listar(Aluno **lista){
    Aluno *p = NULL;
    int contador = 0;

    limparTela();

    for(p = *lista; p != NULL; p = p->proximo){
        contador++;
        printf("Dados do aluno %d \n", contador);
        printf("|\t%s\t|\t%d\t|\t%s\t\t|\n", p->nome, p->idade,p->telefone);
    }
}

void procurarAluno(Aluno **lista, char *nome){
    Aluno *p = *lista;
    Aluno *pant = NULL;
    int achei=0;

    while(p){
        if( !(strcmp(p->nome, nome)) ){
            limparTela();
            printf("Dados do aluno ( %s )\n", p->nome);
            printf("|\t%s\t|\t%d\t|\t%s\t\t|\n", p->nome, p->idade,p->telefone);
            achei=1;
            break;
        }
        pant = p;
        p = p->proximo;
    }

    if(achei == 0){
        limparTela();
        printf("\nNão foi possivel achar o aluno %s.\n\n", nome);
        exit(0);
    }

}

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #elif  _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}
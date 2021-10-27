#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
#define TAM 1000
	struct Aluno{
    	char matricula[15];
    	char nome[60];
	char sexo[10];
    	int ID_Curso;
	int idade;
	int Del;
} lista[TAM];

#define CRS 1000
struct Curso {
	int ID;
	char nome;	
} cursos [CRS];

/*----------------------------------------------------------------------------------------------------*/

void inicializaLista() {
    int i;
	for (i = 0; i < TAM; i++) {
		strcpy(lista[i].matricula,"");
		strcpy(lista[i].nome,"");
		lista[i].ID_Curso = 0;
		strcpy(lista[i].sexo,"");    
		lista[i].idade = 0;
		lista[i].Del = 0;
	}
}

void insereAluno() {    
    char matricula[10];
    printf("MATRICULA: ");
    gets(matricula);
    fflush(stdin);
    int i=0;
    // ENCONTRANDO A PRÓXIMA POSIÇÃO DO VETOR DE ALUNOS VAZIA PARA INCLUIR NELA O NOVO ALUNO
    while(strcmp(lista[i].matricula, "") != 0)
    {
        i++;
    }
    // VERIFICANDO SE A MATRICULA INFORMADA JÁ EXISTE. SE EXISTIR, NÃO PODERÁ SER USADA
    int MatriculaAchada = 0;
    for(int j=0;j<i;j++)
    {
    	if(lista[i].Del == 0) // APENAS REGISTROS NÃO DELETADOS SERÃO CONSULTADOS
    	{		
	        if (strcmp(lista[j].matricula, matricula) == 0) 
			{
	            printf("MATRICULA JA CADASTRADA. VOLTANDO PARA O MENU...\n");
	            MatriculaAchada = 1;
	            break;
	        }
   		}
    }    
    if(MatriculaAchada == 0)
    {
        strcpy(lista[i].matricula, matricula);
	    printf("NOME: ");
        gets(lista[i].nome);
        fflush(stdin);
        printf("SEXO (M OU F): ");
        gets(lista[i].sexo);
        fflush(stdin);
        
        // VERIFICANDO SE O ID_CURSO EXISTE NO VETOR DE CURSOS. SE NÃO EXISTIR, O CADASTRO NÃO SERÁ CONTINUADO
        fflush(stdin);
        int cursoAchado = 0;
        
        while (cursoAchado == 0 ){
            printf("ID DO CURSO: ");
            scanf("%d", &lista[i].ID_Curso);
            
            for(int j = 0;  j <= CRS;j++) {
                if(lista[i].ID_Curso == cursos[j].ID) {
                    cursoAchado = 1;
                    break;
                } else {
                	
                	if (j == CRS)
					{
						printf("* CURSO NAO ENCONTRADO. (DIGITE: 1 - ADS | 2 - ENG | 3 - SI) *\n");
					}	 
                    
                }
            }
        }
        
        printf("IDADE: ");
        scanf("%d",&lista[i].idade);
        fflush(stdin);    
    }
}    

void alteraAluno() {    
    char matricula[10];
    printf("MATRICULA: ");
    gets(matricula);
    fflush(stdin);
   
   // VERIFICANDO SE A MATRICULA INFORMADA JÁ EXISTE. SÓ PODE SER ALTERADO, UM ALUNO COM MATRICULA JÁ CADASTRADA
    int MatriculaAchada = 0;
    int i=0;
    for(;i<TAM && strcmp(lista[i].matricula, "") != 0;i++)
    {
    	if(lista[i].Del == 0) // APENAS REGISTROS NÃO DELETADOS SERÃO CONSULTADOS
    	{
	        if (strcmp(lista[i].matricula, matricula) == 0) 
			{
	            MatriculaAchada = 1;
	            break;
	        }
	    }
    }    
    if(MatriculaAchada == 1)
    {
        printf("NOVO NOME: ");
        gets(lista[i].nome);
        fflush(stdin);
        
        printf("NOVO SEXO (M OU F): ");
        gets(lista[i].sexo);
        fflush(stdin);
        
        // VERIFICANDO SE A MATRICULA INFORMADA JÁ EXISTE. SÓ PODE SER ALTERADO, UM ALUNO COM MATRICULA JÁ CADASTRADA
	    fflush(stdin);
        int cursoAchado = 0;
        
        while (cursoAchado == 0 ){
            printf("NOVO ID DO CURSO: ");
            scanf("%d", &lista[i].ID_Curso);
            
            for(int j = 0;  j <= CRS;j++) {
                if(lista[i].ID_Curso == cursos[j].ID) {
                    cursoAchado = 1;
                    break;
                } else {
                	
                	if (j == CRS)
					{
						printf("* CURSO NAO ENCONTRADO. (DIGITE: 1 - ADS | 2 - ENG | 3 - SI) *\n");
					}
                }
			}
		}
        fflush(stdin);
            
        printf("NOVA IDADE: ");
        scanf("%d",&lista[i].idade);
        fflush(stdin);   
		
		printf("\n**************************************");
		printf("\nDADOS DO ALUNO ATUALIZADO COM SUCESSO!\n");
		printf("**************************************\n\n");
    }
    else
    {
    	printf("\n*************************");
		printf("\nMATRICULA NAO ENCONTRADA!\n");
		printf("*************************\n\n");
    }
}    

void exibeAlunos() {
    int i=0;
    
    while(strcmp(lista[i].matricula,"") != 0 && i < TAM) {
    	if(lista[i].Del == 0) // APENAS REGISTROS NÃO DELETADOS IRÃO APARECER
    	{		
	        printf("-----------------------------------\n");
			printf("MATRICULA: %s\n", lista[i].matricula);
	        printf("NOME: %s\n", lista[i].nome);
	        printf("SEXO: %s\n", lista[i].sexo);
	        printf("ID DO CURSO: %d\n", lista[i].ID_Curso);
	        printf("IDADE: %d\n", lista[i].idade);
	        printf("-----------------------------------\n");
    	}
        i++;
    }
}
void remove ()
{
  char matricula[10];
    printf("\nMATRICULA: ");
    gets(matricula);
    fflush(stdin);
   
   // VERIFICANDO SE A MATRICULA INFORMADA JÁ EXISTE. SÓ PODE SER ALTERADO, UM ALUNO COM MATRICULA JÁ CADASTRADA
    int MatriculaAchada = 0;
    int i=0;
    for(;i<TAM && strcmp(lista[i].matricula, "") != 0;i++)
    {
    	if(lista[i].Del == 0) // APENAS REGISTROS NÃO DELETADOS SERÃO CONSULTADOS
    	{
	        if (strcmp(lista[i].matricula, matricula) == 0) 
			{
	            MatriculaAchada = 1;
	            break;
	        }
	    }
    }    
    if(MatriculaAchada == 1)
    {
      lista[i].Del = 1;
        printf("\n***************");
		printf("\nALUNO REMOVIDO!\n");
		printf("***************\n\n");
    }
    else
    {
        printf("\n*************************");
		printf("\nMATRICULA NAO ENCONTRADA!\n");
		printf("*************************\n\n");
    }
}   

void inicializaCurso ()
{
 cursos[1].ID = 1;
 cursos[2].ID = 2;
 cursos[3].ID = 3;
	
}

int main() {
	inicializaCurso();
    int opcao,r;
    inicializaLista();
    do {
    	printf("\n---------- MENU ----------\n");
        printf("1 - INSERIR ALUNO\n");
        printf("2 - LISTAR ALUNOS\n");
        printf("3 - REMOVER ALUNO\n");
        printf("4 - ALTERAR ALUNO\n");
        printf("5 - SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);
        fflush(stdin);
        if(opcao == 1) 
		{
            printf("\n------------------");
			printf("\nINSERCAO DE ALUNO!\n");
			printf("------------------\n\n");
            insereAluno();                    
        }
        else if(opcao == 2)
		{
		 	printf("\n-------------------");
			printf("\nEXIBICAO DE ALUNOS!\n");
			printf("-------------------\n\n");
            exibeAlunos();
            printf("\n\n");
    	}        
        else if(opcao == 3)
		{
			remove();  
        }
        else if(opcao == 4)
		{	
			printf("\n--------------------");
			printf("\nALTERACAO DE ALUNOS!\n");
			printf("--------------------\n\n");
            alteraAluno();            
            printf("\n\n");
        }
        else if(opcao != 5)
        {
        	printf("---------------\n");
			printf("OPCAO INVALIDA!\n");
			printf("---------------\n\n");
		}
    } while (opcao != 5);
}


#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h>
#include<conio2.h>

/*Declaração das structs*/
	struct Datav 
	{
    	int dia;
    	int mes;
    	int ano;
	};


	struct Fornecedor
	{
		int codF;
		char nomeF[35];
		char Cidade[35];
		bool statuts;	
	};
	
	struct Produtos
	{
		int codP,Estoque;
		char nomeP[35];	
		float preco;
		struct Datav DTV;
		int codF;
		bool statuts;
	};
	
	struct Cliente
	{
		char CPF[15];
		char nomeC[35];
		int qtdC;
		bool status;
		float valor;	
	};
	
	struct Vendas
	{
		int codV;
		char CPF[35];
		struct Datav DTV;
		bool status; 
		float total;
	};
	
	struct VendasProd
	{
		int codV;
		int codP;
		int qtde;
		float valorU;	
	};
	
/*Funções de limpeza*/

void limparMenu ()
{
	int c,l;
	
	//Menu
	for(c=51;c<78;c++)
	 for(l=10;l<24;l++)
	 {
	  gotoxy(c,l);
	  printf("%c",32);
	 }	
}

void limparTela (int &linhaC)
{	
	int c,l;
	
	//Código
	if(linhaC>=23)
	{
		linhaC=12;
		for(c=3;c<48;c++)
	 	 for(l=10;l<23;l++)
	   		{
	   		gotoxy(c,l);
	   		printf("%c",32);
	   		}
	}
}

void limparMsg ()
{
	int c=5,l=5;
	
		 //Mensagem
	 	 for(c=5;c<77;c++)
	   		{
	   		gotoxy(c,l);
	   		printf("%c",32);
	   		}
}

void limparTelaAnyway ()
{
	int c,l;
	
	//Código COMPLETO
	for(c=3;c<48;c++)
	 	 for(l=9;l<23;l++)
	   		{
	   		gotoxy(c,l);
	   		printf("%c",32);
	   		}
}
/*Auxiliares de interface*/
void msg()
{
	limparMsg ();
	gotoxy(24,5);
	textcolor(10);
}

void txt(int linha)
{
	textcolor(15);
	gotoxy(8,linha);
	fflush(stdin);
}


/*Todos os menus*/
char menu ()
{	
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[A] Cadastrar fornecedor:");
	gotoxy(51,13);
	printf("[B] Cadastrar produto:");
	gotoxy(51,15);
	printf("[C] Cadastrar cliente:");
	gotoxy(51,17);
	printf("[D] Visualizar:");
	gotoxy(51,19);
	printf("[E] Realizar vendas:");
	gotoxy(51,21);
	printf("[ESC] Sair:");
	gotoxy(51,23);
	printf("%c			    %c",17,16);
	
	tecla=toupper(getch());
	if(tecla==-32)
		{
		tecla=getch();	
			if(tecla==77)
			{
			limparMenu();	
			gotoxy(51,11);
			printf("[F] Atualizar:");
			gotoxy(51,13);
			printf("[G] Excluir:");
			gotoxy(51,15);
			printf("[H] Relatorio geral:");
			tecla=toupper(getch());	
			if(tecla>=72&&tecla<=75)
				return tecla;
			}	
		}	
	
	return tecla;
}

char menu2 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[1] Mostrar fornecedores:");
	gotoxy(51,13);
	printf("[2] Mostrar produtos:");
	gotoxy(51,15);
	printf("[3] Mostrar clientes:");

	tecla=getch();
	
	return tecla;
}

char menu3 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[1] Atualizar fornecedores:");
	gotoxy(51,13);
	printf("[2] Atualizar produtos:");
	gotoxy(51,15);
	printf("[3] Atualizar clientes:");
	gotoxy(51,17);
	printf("[ESC] Voltar:");

	tecla=getch();
	
	return tecla;
}

char menu4 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[1] Excluir fornecedores:");
	gotoxy(51,13);
	printf("[2] Excluir produtos:");
	gotoxy(51,15);
	printf("[3] Excluir clientes:");
	gotoxy(51,17);
	printf("[4] Excluir vendas:");
	gotoxy(51,19);
	printf("[ESC] Voltar:");
	tecla=getch();
	
	return tecla;
}

char menu5 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[1] Alterar codigo:");
	gotoxy(51,13);
	printf("[2] Alterar nome:");
	gotoxy(51,15);
	printf("[3] Alterar estoque:");
	gotoxy(51,17);
	printf("[4] Alterar preco:");
	gotoxy(51,19);
	printf("[5] Alterar validade:");
	gotoxy(51,21);
	printf("[6] Alterar codigo fornecedor:");

	tecla=getch();
	
	return tecla;
}

char menu6 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[A] Alterar codigo:");
	gotoxy(51,13);
	printf("[B] Alterar nome:");
	gotoxy(51,15);
	printf("[C] Alterar cidade:");

	tecla=toupper(getch());	
	
	return tecla;
}

char menu7 ()
{
	char tecla;
	
	limparMenu();
	textcolor(1);
	gotoxy(51,11);
	printf("[A] Alterar CPF:");
	gotoxy(51,13);
	printf("[B] Alterar nome:");
	gotoxy(51,15);
	printf("[C] Alterar qtd compras:");
	gotoxy(51,17);
	printf("[D] Alterar valor comprado:");
	
	tecla=toupper(getch());
	
	return tecla;
}

/*Buscas*/
/*
int BuscaMat(FILE *Ptr,int Mat)
{
	TpFunc R;
	rewind(Ptr);
	fread(&R,sizeof(TpFunc),1,Ptr);
	while (!feof(Ptr) && Mat!=R.Matricula)
		fread(&R,sizeof(TpFunc),1,Ptr);
	
	if (!feof(Ptr))
		return ftell(Ptr)-sizeof(TpFunc);
	else
		return -1;
}*/
	
/*	
void ExcLogicaForn(void) {
    int pos;
    struct Fornecedor fornecedor; //fodase coloquei mesmo uma struct aqui porra para testar mano porra 
    FILE *ptrForn = fopen("fornecedores.dat", "rb+");

    printf("\n### Exclusao Logica de Fornecedor ###\n");

    if (ptrForn == NULL) {
        printf("\nErro de Abertura!\n");
    } else {
        printf("\nCodigo do Fornecedor a excluir: ");
        scanf("%d", &fornecedor.codF);

        while (fornecedor.codF > 0) {
            pos = BuscaCodFornecedor(ptrForn, fornecedor.codF);

            if (pos == -1) {
                printf("Codigo nao encontrado!\n");
            } else {
                fseek(ptrForn, pos, 0);
                fread(&fornecedor, sizeof(struct Fornecedor), 1, ptrForn);

                printf("\n*** Detalhes do Registro ***\n");
                printf("Codigo Fornecedor: %d\n", fornecedor.codF);
                printf("Nome Fornecedor: %s\n", fornecedor.nomeF);
                printf("Cidade Fornecedor: %s\n", fornecedor.Cidade);

                printf("\nConfirma Exclusao Logica (S/N)? ");
                if (toupper(getchar()) == 'S') {
                    printf("\nNovo Codigo Fornecedor: ");
                    scanf("%d", &fornecedor.codF);
                    printf("\nNovo Nome Fornecedor: ");
                    scanf("%s", fornecedor.nomeF);
                    printf("\nCidade Fornecedor: ");
                    scanf("%s", fornecedor.Cidade);
                    fornecedor.status = false;

                    fseek(ptrForn, pos, 0);
                    fwrite(&fornecedor, sizeof(struct Fornecedor), 1, ptrForn);
                    printf("\nRegistro atualizado!!\n");
                }
            }

            printf("\nCodigo do Fornecedor a excluir: ");
            scanf("%d", &fornecedor.codF);
        }

        fclose(ptrForn);
    }
}
*/

// BuscaCodFornecedor(FILE *ptrForn, int codF) hmm nao sei o que por
int BuscaCodF(struct Fornecedor F[TF], int TL,int cod)
{
	int i=0;
	
	while(i<TL && cod!=F[i].codF)
	i++;
	if(i<TL)
	 return i;
	else
	 return -1;
}


/*
void ExclFisica(void){
	int pos, Mat;
	char op;
	TpFunc Reg;
	FILE *PtrFunc = fopen("func.dat","rb");
	printf("\n### Exclusao Fisica de Funcionarios ###\n");
	if (PtrFunc == NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\nMatricula do Funcionario a excluir: ");
			scanf("%d",&Mat);
			if (Mat>0)
			{
				pos = BuscaMat(PtrFunc,Mat);
				
				if (pos==-1)
					printf("\nMatricula nao encontrada!\n");
				else
					{   
						fseek(PtrFunc,pos,0);
						fread(&Reg,sizeof(TpFunc),1,PtrFunc);
						printf("\n*** Detalhes do Registro ***\n");
						printf("Matricula: %d\n",Reg.Matricula);
						printf("Nome: %s\n",Reg.Nome);
						printf("Salario: R$ %.f\n",Reg.Salario);
						
						printf("\nConfirma exclusao (S/N)? ");
						op = toupper(getche());
						if (op=='S')
						{
							FILE *PtrTemp = fopen("Temp.dat", "wb");
							rewind(PtrFunc);
							fread(&Reg,sizeof(TpFunc),1,PtrFunc);
							while(!feof(PtrFunc)){
								if(Reg.Matricula != Mat)
									fwrite(&Reg,sizeof(TpFunc),1,PtrTemp);
									
							}
							fclose(PtrFunc);
							fclose(PtrTemp);
							remove("Func.dat");
							rename("Temp.dat","Func.dat");
							
							printf("\nRegistro deletado!!\n");
						}
						else
							fclose(PtrFunc);
					}
				getch();
								
			}
		}
}
*/

/*Cadastros*/
void cad_forn()
{
	struct Fornecedor F;
	int linhaC=11,qtd,aux;
	
	msg();
	printf("Quantos fornecedores deseja cadastrar?");
	txt(linhaC);
	scanf("%d",&qtd);
	linhaC++;
	if(qtd<=0)
	return;
	else
	{
		FILE *frn = fopen("fornecedores.dat","ab+");
		if(frn==NULL)
		{
			msg();
			printf("--[ARQUIVO INVALIDO]--");
			getch();	
			exit(1);
		}
		else
		{
			for(int i=0;i<qtd;i++)
			{
				msg();
				printf("Digite o codigo do fornecedor: ");
				txt(linhaC);
				scanf("%d",&aux);
				linhaC++;
				if(cod<=0)
				{
					msg();
					printf("***Codigo Invalido!***");
					getch();	
					return;
				}
				else
				{
					fwrite(&F,sizeof(F),1,FILE*ptr); 
					
					status = true;
				}
				printf("Digite o nome do fornecedor: ");
				printf("Digite a cidade do fornecedor: ");
			}
		}
	}
	msg();
	printf("**Cadastro Finalizado**");
	
}

/*Borda*/

void borda (int CI, int LI, int CF, int LF, int cor)
{
	int i;
	
		textcolor(cor);
		gotoxy(CI,LI);
	printf("%c",201);
		gotoxy(CF,LI);
	printf("%c",187);
		gotoxy(CI,LF);
	printf("%c",200);
		gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
}

void msgEstatica ()
{
	textcolor(10);
	gotoxy(33,3);
	printf("***MENSAGEM***");
	textcolor(1);
	gotoxy(60,9);
	printf("***MENU***");
}

void Executar ()
{
	char op,opR;
	struct Fornecedor F;
	struct Produtos P;
	struct Cliente C;
	struct Datav DTV;
	struct Vendas V;
	struct VendasProd VP;
	
	do
	
	{
		limparMsg();
		limparTelaAnyway();
		op=menu();
		
		switch(op)
		{
			case 'A': textcolor(15);
			gotoxy(14,9);
			printf("Cadastro do Fornecedor.");
			cad_forn(F);
			break;
			/*
			case 'B':textcolor(15);
			gotoxy(14,9);
			printf("Cadastro do Produto.");
			cad_Produtos();
			break;
			
			case 'C':textcolor(15);
			gotoxy(14,9);
			printf("Cadastro do Cliente.");
			cad_Cliente();
			break;
			
			case 'D':textcolor(15);
			gotoxy(14,9);
			printf("Relatorio Simples.");
		
			opR=menu2();
			
				if(opR=='1')
					VisuForn();
				
				else if(opR=='2')
					VisuProd();
				
				else if(opR=='3')
					VisuCli();			
				break;
			 
			case 'E':textcolor(15);
			gotoxy(14,9);
			printf("Venda de produtos.");
			Vendendo();
			break;
			
			case 'F':textcolor(15);
			gotoxy(14,9);
			printf("Atualizar dados.");
			
			opR=menu3();	
			
			do
			{
			
				if(opR=='1')
					AtualizaForn();
				
				else if(opR=='2')
					VisuProd();
				
				else if(opR=='3')
					AtualizaCliente();	
					
				opR=menu3();	
					
			}while(opR!=27);		
			break;
			
			case 'G':textcolor(15);
			gotoxy(14,9);
			printf("Excluir dados.");
			
			opR=menu4();
			
			do
			{
				if(opR=='1')
					ExcluiForn();
				
				else if(opR=='2')
					ExcluiProd();
				
				else if(opR=='3')
					ExcluiCliente();	
					
				else if(opR=='4')
					ExcluiVenda(V,VP,C,P,TLV,TLVP,TLC,TLP);
					
				opR=menu4();	
			
			}while(opR!=27);
			
			break;
			
			case 'H':textcolor(15);
			gotoxy(14,9);
			printf("Relatorio geral.");
			relatorio();
			break; */
		}
		
	}while(op!=27);
}


int main (void)
{
	int CI,LI,CF,LF,cor;
	
	/*BORDA PRINCIPAL*/
	
	cor=12;
	CI=1,LI=1,CF=80,LF=25;
	borda(CI,LI,CF,LF,cor);
	
	
	/*
	MENSAGENS PARA O USUÁRIO DEVEM
	ESTAR ENTRE:
	CI 4 a 33 / 48 a 78
	LI 4 
	CF 78 
	LF 6
	*/
	
	cor=10;
	CI=2,LI=2,CF=79,LF=7;
	borda(CI,LI,CF,LF,cor);
	
	/* 
	MENU DEVE ESTAR ENTRE:
	CI 51 a 60 / 70 a 79
	LI 9
	CF 79
	LF 23
	*/
	
	cor=1;
	CI=50,LI=8,CF=78,LF=24;
	borda(CI,LI,CF,LF,cor);
	
	//BORDA CÓDIGO
	
	cor=15;
	CI=2,LI=8,CF=49,LF=24;
	borda(CI,LI,CF,LF,cor);
	
	//***MENSAGEM*** E ***MENU***
	
	msgEstatica();
	
	Executar();
	
	printf("\n\n\n\n\n\n\n\n\n\n\n");
		
	return 0;
} 


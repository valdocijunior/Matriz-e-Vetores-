/* FACULDADE DOM BOSCO DE PORTO ALEGRE
* Sistemas de Informação – Análise e Desenvolvimento de Sistemas
* Algoritmos
*
* Programa PrimeiroT2:
* -------------------------
* Objetivo do Programa: Primeiro T2, referente à disciplina de Algoritmos, do curso de ADS.
* Autor:
* Data da entrega do arquivo fonte: 10/11/2022
*/

#include <stdio.h>

#define L 12 //máximo de linhas
#define C 12 //máximo de colunas

int main (void)

{
		int m[L][C], v1[L*C], v2[L*C], v3[L*C], v4[L*C]; //MATRIZ E VETORES;
	int i, j; //ITERATORS;
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0; //ITERATORS PARA OS VETORES ACIMA E ABAIXO, PAR E IMPAR;
	int qtdePares = 0, qtdeMaiorqMedia = 0, qtdeMenorqMedia = 0, qtdeImparesDiagonal = 0; //VARIÁVEIS CONTADORAS;
	int soma = 0; //SOMATORIO DA MATRIZ;
	float media; //MEDIA DA MATRIZ;
	
		for (i = 0; i < L; i++) {
			for (j = 0; j < C; j++) {
				printf ("Insira um numero INTEIRO e POSITIVO para a posicao %d,%d: ", i, j);
				scanf ("%d", &m[i][j]);
				v1[(C * i) + j] = m[i][j];       //transformando matriz em array (vetor);
			}
		}

		for (i = 0; i < L; i++) {
			for (j = 0; j < C; j++) {
				soma = soma + m[i][j];       //somatorio;
			}
		}
		
		media = (((float)soma)/(L*C));        //calculo da media;
		
		printf("\nMATRIZ:\n\n");
		
		for (i = 0; i < L; i++) {
			for (j = 0; j < C; j++) {
				printf (" %d ", m[i][j]);     //print da matriz e contabilização da quantidade de numeros maior(e igual), menor que a media, qtde de pares e qtde de impares;
				if (m[i][j] >= media) {
					qtdeMaiorqMedia++;
				}
				if (m[i][j] < media) {
					qtdeMenorqMedia++;
				}
				if (m[i][j] %2 == 0) {
					qtdePares++;
				}
			}
			printf ("\n");
		}
		
		printf("\nDIAGONAL PRINCIPAL DA MATRIZ:\n\n");
		
		for (i = 0; i < L; i++) {
			for (j = 0; j < C; j++) {
				if (i == j) {
					printf ("%d ", m[i][j]);
					v4[(C*i) + j] = m[i][j];
				} else {
					printf ("  ");
					v4[(C*i) + j] = 0;
				}
				if (i == j && m[i][j] %2 != 0) {
					qtdeImparesDiagonal++;
				}
			}
			printf ("\n");
		}
		
		printf("\nMATRIZ TRANSFORMADA EM VETOR:\n\n");
		for (i = 0; i < L * C; i++) {
			printf ("%d ", v1[i]);           //print do array apenas para testes;
			//printf ("%d ", v4[i]);
		}
		printf("\n");
				
		for (i = 0; i < L*C; i++) {
				if(v1[i] >= media) {
					v1[i1] = v1[i];
					i1++;
				}
				if (v1[i] < media) {
					v2[i2] = v1[i];
					i2++;
				}
				if (v1[i] %2 == 0) {
					v3[i3] = v1[i];
					i3++;
				}
				if (v4[i] %2 != 0) {
					v4[i4] = v4[i];
					i4++;
				}
		}

		printf("\nQUESTAO a) \n\nVetor1 com elementos maior e/ou iguais a media:\n\n");
		for (i = 0; i < qtdeMaiorqMedia; i++) {
			printf ("%d ", v1[i]);           
		}
		printf("\n");
		printf("\nQUESTAO b) \n\nVetor2 com elementos menores do que a media: \n\n");
		for (i = 0; i < qtdeMenorqMedia; i++) {
			printf ("%d ", v2[i]);           
		}
		printf("\n");
		printf("\nQUESTAO c) \n\nVetor3 com os elementos pares da matriz: \n\n");
		for (i = 0; i < qtdePares; i++) {
			printf ("%d ", v3[i]);           
		}
		printf("\n");
		printf("\nQUESTAO d) \n\nVetor4 com os elementos impares da DIAGONAL PRINCIPAL: \n\n");
		for (i = 0; i < qtdeImparesDiagonal; i++) {
			printf ("%d ", v4[i]);           
		}
		printf("\n");
		
	
	system("pause");
	return 0;
}

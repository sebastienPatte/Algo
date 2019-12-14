#include <stdio.h>
#include <stdlib.h>

#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||
#define then

typedef enum { false, true } boolean;


typedef struct Noeud 
{
    struct Noeud* gauche;
    struct Noeud* droit;
    int val;
} Noeud;

typedef Noeud* Arbre;

void initArbreAFeuille(Arbre* A)
{
    *A = NULL;
}

int valeurRacine(Arbre A)
{
    return A->val;
}

boolean estFeuille(Arbre A)
{
    return A == NULL;
}


Arbre SAG(Arbre A)
{
    return A->gauche;
}

Arbre SAD(Arbre A)
{
    return A->droit;
}

Arbre* pointeurSAG(Arbre A)
{
    return &(A->gauche);
}

Arbre* pointeurSAD(Arbre A)
{
    return &(A->droit);
}

Arbre cons(int v, Arbre B, Arbre C)
{
    Arbre A = (Arbre) malloc(sizeof(Arbre));
    A->val = v;
    A->gauche = B;
    A->droit = C;
    return A;
}

void affiche_prefixe_aux(Arbre A)
{
    if(!estFeuille(A))
    {
        printf("%d ", A->val);
        affiche_prefixe_aux(A->gauche);
        affiche_prefixe_aux(A->droit);
    }else{
    printf("F ");	
    }
}

void affiche_prefixe(Arbre A)
{
    affiche_prefixe_aux(A);
    printf("\n"); 
}

void affiche_suffixe_aux(Arbre A)
{
    if(!estFeuille(A))
    {
        affiche_suffixe_aux(A->gauche);
        affiche_suffixe_aux(A->droit);
        printf("%d ", A->val);
    }else{
    printf("F ");	
    }
}

void affiche_suffixe(Arbre A)
{
    affiche_suffixe_aux(A);
    printf("\n"); 
}


void affiche_infixe_aux(Arbre A)
{
    if(!estFeuille(A))
    {
        affiche_infixe_aux(A->gauche);
        printf("%d ", A->val);
        affiche_infixe_aux(A->droit);
    }else{
    printf("F ");	
    }
}

void affiche_infixe(Arbre A)
{
    affiche_infixe_aux(A);
    printf("\n"); 
}

//Exam 2018


//1
_Bool AMUPFF(Arbre A, int p){
	if(p==2){
		return estFeuille(A);
	}else{
		return AMUPFF(SAG(A),p+1) OR AMUPFF(SAD(A),p+1);
	}
}

_Bool AuMoinsUnPetitFilsFeuille(Arbre A){
	return AMUPFF(A, 0);
}

//2
int CompteAscVrais(Arbre A){
	if(estFeuille(A)){
		return 0;
	}else{
		if(valeurRacine(A)==1){
			return CompteAscVrais(SAG(A)) + CompteAscVrais(SAD(A)) +1;
		}else{
			return 0;
		}
	}
}

int CompteDescVrais(Arbre A, int* flag){
	if (estFeuille(A)){
		*flag = 1;
		return 0;
	}else{
		int f1 = 0;
		int f2 = 0	;
		int cpt = CompteDescVrais(SAG(A),&f1) + CompteDescVrais(SAD(A),&f2);
		if(valeurRacine(A)==1){
			*flag = 1;
			if(f1==1 && f2==1){
				return cpt+1;
			}else{
				return 1;
			}
		}else{
			*flag = 0;
			return cpt;
		}
	}
}

//4
void ArbreToCode(Arbre A){
	if(estFeuille(A)){
		printf("F");
	}else{
		printf("N");
		ArbreToCode(SAG(A));
		ArbreToCode(SAD(A));
	}
}

Arbre CodeToArbre(){
	char c = getchar();
	if(c == 'F'){
		Arbre res;
		initArbreAFeuille(&res);
		return res;
	}else{
		if(c =='N'){
			return cons(0,CodeToArbre(),CodeToArbre());
		}
	}
}


void RQDCPF(Arbre A, int* flag){
	if(estFeuille(A)){
		*flag = 0;
	}else{
		Arbre* ptrG = pointeurSAG(A);
		Arbre* ptrD = pointeurSAD(A);
		*flag = estFeuille(*ptrG) AND estFeuille(*ptrD);
		int fG = 0;
		int fD = 0;
		RQDCPF(*ptrG,&fG);
		RQDCPF(*ptrD,&fD);

		if(fG)initArbreAFeuille(ptrG);
		if(fD)initArbreAFeuille(ptrD);
	}
}

void RemplaceQueuesDeCeriseParFeuilles(Arbre A){
	int flag = 0;
	RQDCPF(A,&flag);
}

int XaProfDansABR(Arbre A, int x, int p){
	if(estFeuille(A)){
		return 0;
	}else{
		int valRac = valeurRacine(A);
		if(valRac=x && p==0){
			return 1;
		}else{
			if(valRac > x){
				return XaProfDansABR(SAG(A),x,p-1);
			}else{
				return XaProfDansABR(SAD(A),x,p-1);
			}
		}
	}
}

void KF(Arbre A, int* k){
	if(estFeuille(A)){
		*k=*k-1;
	}else{
		KF(SAG(A),k);
		KF(SAD(A),k);
	}
} 

int KFeuille(Arbre A, int k){
	KF(A,&k);
	return k==0;
}



int main()
{ 

    Arbre A;
    Arbre B;
    Arbre C;
    initArbreAFeuille(&A);
    initArbreAFeuille(&B);
    initArbreAFeuille(&C);

    Arbre E = cons(7, B, C);
    Arbre D = cons(9, E, A);

    Arbre G = cons(-4, D, E);
    printf("G prefixe: \n");
    affiche_prefixe(G);

    printf("G suffixe: \n");
    affiche_suffixe(G);

    printf("G infixe: \n");
    affiche_infixe(G);

    printf("AuMoinsUnPetitFilsFeuille(G) = %d\n",AuMoinsUnPetitFilsFeuille(G));

    Arbre CAVG = cons(1,A,B);
    Arbre CAVD = cons(0,CAVG,B);
    Arbre CAV = cons(1,CAVG,CAVD);
	printf("CAV prefixe: \n");
    affiche_prefixe(CAV);
    printf("CompteAscVrais(CAV) = %d\n",CompteAscVrais(CAV));
    int flag=0;
    printf("CompteDescVrais(CAV) = %d\n",CompteDescVrais(CAV,&flag));
    printf("ArbreToCode(CAV) :\n");
    ArbreToCode(CAV);
    printf("\n");
    affiche_prefixe( CodeToArbre());

    RemplaceQueuesDeCeriseParFeuilles(CAV);
	printf("RemplaceQueuesDeCeriseParFeuilles(CAV) :\n");
	printf("CAV prefixe: \n");
    affiche_prefixe(CAV);

    printf("XaProfDansABR :\n%d\n",XaProfDansABR(G,7,1));
    printf("KFeuille G 5 :\n%d\n",KFeuille(G,5));
    return 0;
}

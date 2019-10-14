#include <stdio.h>
#include <stdlib.h>
/*************************************************/
/*                                               */
/*                sucre syntaxique               */
/*                      						 */
/*************************************************/
#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
typedef enum { FALSE, TRUE} bool;
/*************************************************/
/*                         */
/*          definition type liste                */
/*                                               */
/*************************************************/
typedef struct Bloc{
	int nombre;
	struct Bloc *suivant;
} 
Bloc;
typedef Bloc *Liste ;
/*************************************************/
/*                                               */
/*                predeclarations                */
/*                                               */
/*************************************************/
/* initialise une Liste à vide */
void initVide(Liste *L);

/* renvoie 1 si la Liste en parametre est vide, 0 sinon */
bool estVide(Liste l);

/* renvoie le premier element de la Liste en parametre */
int premier(Liste l);

/* renvoie une nouvelle Liste correspondant a celle en parametre,
 avec l'element x ajoute en haut de la pile */
Liste ajoute(int x, Liste l);

/* modifie la Liste en parametre: x est ajoute comme premier element */
void empile(int x, Liste* L);

/* renvoie une nouvelle Liste correspondant a celle en parametre 
sans son premier element */
Liste suite(Liste l);

/* modifie la Liste en parametre: le premier element est retire */
void depile(Liste* l);

/* affichage simple en recursif et en iteratif */
void affiche_rec(Liste l);
void affiche_iter(Liste l);

/* longueur en recursif et en iteratif */
int longueur_rec (Liste l);
int longueur_iter (Liste l);

/*  Elimination du dernier element en recursif et en iteratif  */
/*  VD est la sousprocedure utilitaire de la version recursive */
void VD (Liste *L);
void VireDernier_rec (Liste *L);
void VireDernier_iter (Liste *L);
/*************************************************/
/*                                               */
/*                briques de base                */
/*                                               */
/*************************************************/
void initVide( Liste *L){
	*L = NULL ;
}

bool estVide(Liste l){
	return l == NULL ;
}

int premier(Liste l){
	return l->nombre ; 
}

Liste ajoute(int x, Liste l){
	Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
	tmp->nombre = x ;
	tmp->suivant = l ;
	return tmp ;
}

void empile(int x, Liste *L){
	*L = ajoute(x,*L) ; 
}

Liste suite(Liste l){
	return l->suivant ;
}




void depile(Liste *L){
	Liste tmp = *L ;
	*L = suite(*L) ;
	free(tmp) ;
}

/*************************************************/
/*                                               */
/*     Affiche, avec les briques de base         */
/*                                               */
/*************************************************/

void affiche_rec(Liste l){
	if(estVide(l))printf("\n");
	else{
		printf("%d ", premier(l));
		affiche_rec(suite(l));
	}
}

void affiche_iter(Liste l){
	Liste L2 = l;
	while(NOT estVide(L2)){
		printf("%d ", premier(L2));
		L2 = suite(L2);
	}
	printf("\n");
}

/*************************************************/
/*                                               */
/*     Longueur, sans les briques de base        */
/*                                               */
/*************************************************/
int longueur_rec (Liste l){
	if (l == NULL)return 0 ;
	else return (1 + longueur_rec(l->suivant)) ;
}

int longueur_iter (Liste l){
	Liste P = l;int cpt = 0 ;
	while (P ISNOT NULL){
	   P = P->suivant ;
	   cpt++ ;
	}return cpt ;
}

/*************************************************/
/*                                               */
/*       VireDernier,                            */
/*               sans les briques de base,       */
/*               ni le "->"                      */
/*                                               */
/*************************************************/
void VD (Liste *L)
	// *L non NULL ie liste non vide
{
	if ( ((**L).suivant) == NULL )
		depile(L) ;    // moralement : depile(& (*L)) ;
    else VD (& ( (**L).suivant )) ;
}

void VireDernier_rec (Liste *L){
	if ( (*L) ISNOT NULL )
		VD(L);	// moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L){
	if ( (*L) ISNOT NULL){
		while ( ((**L).suivant) ISNOT NULL )
			L = & ( (**L).suivant ) ;
		free(*L) ;
		*L = NULL ;
	}
}
/*************************************************/
/*                                               */
/*		 Libere la memoire                       */
/*                                               */
/*************************************************/

void VideListe(Liste *L){
	if(NOT(estVide(*L))){
		depile(L);
		VideListe(L);
	}
}
/*************************************************/
/*                                               */
/*          	   Questions                     */
/*                                               */
/*************************************************/

bool ZeroEnDeuxiemePosition(Liste l){
	if(estVide(l)){
		return FALSE;
	}else{
		return premier(suite(l)) == 0;
	}
}

bool ContientZero(Liste l){
	if(estVide(l)){
		return FALSE;
	}else{
		return premier(l)==0 AND ContientZero(suite(l));
	}
}

bool AuMoinsKN(int k, int n, Liste l){
	if(estVide(l)){
		return FALSE;
	}else{
		if(k<=0)return TRUE;
		if(premier(l)==n) k--;
		return AuMoinsKN(k,n,suite(l));
	}
}

void EliminePositionsImpaires(Liste *l){
	// &((*l)->suivant);
	if((NOT estVide(*l)) AND NOT (estVide((*l)->suivant)) ){
		depile(&(*l)->suivant);
		EliminePositionsImpaires(&((*l)->suivant));
	}
}



Liste DifferenceAux(Liste *l1, Liste* l2){
	if( (NOT estVide(*l1)) AND (NOT estVide(*l2)) ){
		//printf("premier(l1): %d\npremier(l2): %d\n",premier(*l1),premier(*l2));
		if(premier(*l1)==premier(*l2)){
			if(estVide((*l2)->suivant)){
				return DifferenceAux(&((*l1)->suivant),l2);
			}else{
				if(estVide((*l1)->suivant)){
					return DifferenceAux(l1,&((*l2)->suivant));		
				}else{
					return DifferenceAux(&((*l1)->suivant),&((*l2)->suivant));		
				}
			}
			
		
		}else{
			if(premier(*l1)>premier(*l2)){
				if(estVide((*l2)->suivant)){
					return ajoute(premier(*l2),DifferenceAux(&((*l1)->suivant),l2));
				}else{
					return ajoute(premier(*l2),DifferenceAux(l1,&((*l2)->suivant)));
				}
			}else{
				if(premier(*l1)<premier(*l2)){
					if(estVide((*l1)->suivant)){
						return ajoute(premier(*l2),DifferenceAux(l1,&((*l2)->suivant)));
					}else{
						return ajoute(premier(*l1), DifferenceAux(&((*l1)->suivant),l2));	
					}
					
				}				
			}
		}

	}else{
		Liste lZero ;
		initVide( &lZero);
		empile(0,&lZero);
		return lZero;
	}

}

Liste Difference(Liste *l1, Liste* l2){
	Liste l = DifferenceAux(l1,l2);
	VireDernier_rec(&l);
	return l;
}

int DernierPositif_rec(Liste l){
	if(estVide(l)){
		return 0;
	} else{
		int resSuite = DernierPositif_rec(suite(l));
	
		if(resSuite == 0){
			if(premier(l)>0){
				return premier(l);		
			}else{
				return 0;
			} 
		}else{
			return resSuite;
		}
	}
	
}

/*************************************************/
/*                                               */
/*           Main                                */
/*                                               */
/*************************************************/

void poup (Liste l){
	printf("Double Affichage \n") ;
	affiche_rec(l) ;
	affiche_iter(l) ;
	printf("Longueur en double %d %d \n\n",
						longueur_rec(l),
						longueur_iter(l)
		  ) ;
}

int main(int argc, char** argv){
	Liste l ;
	initVide (&l) ;
	poup(l) ;
	empile(4, &l) ;
	poup(l) ;
	empile(5, &l) ;
	empile(6, &l) ;
	empile(7, &l) ;
	empile(8, &l) ;
	empile(9, &l) ;
	poup(l) ;
	VireDernier_rec  (&l) ;
	VireDernier_iter (&l) ;
	depile(& l) ;
	poup(l) ;
	//tests 
	printf("ContientZero : %s\n\n", ContientZero(l)?"true":"false");
	empile(0, &l) ;
	poup(l) ;
	printf("ZeroEnDeuxiemePosition : %s\n\n", ZeroEnDeuxiemePosition(l)?"true":"false");
	printf("ContientZero : %s\n\n", ContientZero(l)?"true":"false");
	empile(1, &l) ;
	poup(l) ;
 	printf("ZeroEnDeuxiemePosition : %s\n\n", ZeroEnDeuxiemePosition(l)?"true":"false");
	empile(1, &l) ;
	empile(1, &l) ;
	empile(1, &l) ;
	poup(l) ;
	printf("AuMoinsKN(4,1) : %s\n\n", AuMoinsKN(5,1,l)?"true":"false");
	
	printf("EliminePositionsImpaires\n");
	EliminePositionsImpaires(&l);
	poup(l) ;
	
	VideListe(&l);

	Liste l1;
	Liste l2;
	initVide(&l1);
	initVide(&l2);

	empile(5,&l1);
	empile(4,&l1);
	empile(3,&l1);
	empile(1,&l1);
	
	empile(8,&l2);
	empile(5,&l2);
	empile(4,&l2);
	empile(2,&l2);
	
	
	printf("Difference([2;3;4;5],[2;4;5;8]) = ");
	Liste res=Difference(&l1,&l2);
	affiche_rec(res);
	printf("\n");
	
	
	
	empile(-2,&l);
	empile(2,&l);
	empile(-1,&l);
	empile(8,&l);	
	poup(l);
	printf("DernierPositif_rec(l) = %d\n",DernierPositif_rec(l));
	poup(l);	

	return 0;
}


int hauteur (Arbre A){
	if(estFeuille(A)){
		return 1;
	}else{
		int h_gauche = hauteur(SAG(A));
		int h_droit = hauteur(SAD(A));

		return max(h_gauche, h_droit)+1;
	}
}

Arbre Fmiroir (Arbre A){
	if(estFeuille(A)){
		return A;
	}else{
		return Construit(valeurRacine(A), Fmiroir(SAD(A)), Fmiroir(SAG(A)));
	}
}

void Pmiroir(*Arbre A){
	int tmp;
	if(!estFeuille(A)){
		tmp = pointeurSAG(A);
		pointeurSAG(A) = pointeurSAD(A);
		pointeurSAD(A) = tmp;

		Pmiroir(pointeurSAG(A));
		Pmiroir(pointeurSAD(A));
	}
}

bool sontMiroirs(Arbre A1, Arbre A2){
	if(estFeuille(A1)){
			return estFeuille(A2) && (valeurFeuille(A1) == valeurFeuille(A2));
	}else{
		if(estFeuille(A2)){
			return false;
		}
		return (valeurRacine(A1) == valeurRacine(A2)) && sontMiroirs(SAG(A1),SAG(A2)) && sontMiroirs(SAD(A1),SAD(A2));
	}
}

void affichagePrefixe(Arbre A){
    if(!estFeuille(A)){
    	printf("%d\n",valeurRacine(A));
    	affichagePrefixe(SAG(A));
    	affichagePrefixe(SAD(A));
    }
}
void affichageSuffixe(Arbre A){
	if(!estFeuille(A)){
    	affichagePrefixe(SAG(A));
    	affichagePrefixe(SAD(A));
    	printf("%d\n",valeurRacine(A));
    }	
}

bool J1gagnant (Arbre A){
	if(estFeuille(A)){
		return true;
	}else{
		return !J1gagnant(SAG(A)) || !J1gagnant(SAD(A));   
	}
}

int compteSansAsc (Arbre A){
	if(estFeuille){
		return 0;
	}else{
		if(valeurRacine(A)){
			return 1;
		}else{
			return compteSansAsc(SAG(A)) + compteSansAsc(SAD(A));
		}
	}
}

int compteSansDesc (Arbre A){
	if(estFeuille(A)){
		return 0;
	}else{
		int cpt = compteSansDesc(SAG(A)) + compteSansDesc(SAD(A));
		
		if(cpt > 0){
			return cpt;
		}else{
			if(valeurRacine(A)){
				return 1;
			}else{
				return 0;
			}
		}
	}
}

//Q7
int compteHP (Arbre A){
	int cpt =0;
	Bis(A,0,h,cpt);
	return cpt;
}

void Bis(Arb<re A, int p, int out h, int inout cpt){
	if(estFeuille(A)){
		h = 0
	}else{
		Bis(SAG(A),p+1,hg,cpt);
		Bis(SAD(A),p+1,hd,cpt);
		h = 1+max(hg,hd);
		if(h==p)cpt++;
	}
}

//Q8
bool estComplet(Arbre A){
	return (pFeuille(A,0) != -1);
}

int hFeuille(Arbre A){
	if(estFeuille(A)){
		return 0;
	}else{
		int hg = hFeuille(SAG(A)); 
		int hd = hFeuille(SAD(A));
		if(hg == hd && hg!=-1){
			return hg+1;
		}else{
			return -1;
		}
	}
}
//Correction
bool estComplet(Arbre A){
	estComplet_aux(A,b,h);
	return b;
}

void estComplet_aux(Arbre A, bool out b, int out h){
	si estFeuille(A){
		b = true;
		h=0;
	}else{
		estComplet_aux(SAG,bg,hg);
		estComplet_aux(SAG,bd,hd);
		b = bg && bd && (hg == hd);
		h = max(hg,hd) +1;
	}
}

//Ex2
//prefixe : racine avant
void affichagePrefixe(Arbre A){
	pile = [];
	empiler(A,pile);
	while(!estVide(pile)){
		X = premier(pile);
		depile(pile);
		if(estFeuille(X)){
			printf("%d",valeurFeuille(X));
		}else{
			printf("%d",valeurRacine(X));
			empile(SAD(X),pile);
			empile(SAG(X),pile);
		}
	}
}
//suffixe : racine après
12+3*45*67-8/+9-/

/+-1+23+4-+/567+89
/*
Algo de prefixe a suffixe  :
Pour chaque nouveau caractère (nombre ou symbole)
On le place au niveau de la feuille vide qu'on rencontre en parcours préfixe
Cas 1 : si c'est un symbole : on remplace la feuille par un noeud interne avec FG et FD
Cas 2 : si c'est un nombre : on ranjoute simplement la valeur dans la feuille
*/

bool estDans(Arbre a, int x){
	if(estFeuille){
		return false;
	}else{
		if(valeurRacine(a) == x){
			return true;
		}else{
			if(x < valeurRacine(a)){
				return estDans(SAG(a),x);
			}else{
				return estDans(SAD(a),x);
			}
		}
	}
}

void ajout(int x, inout Arbre a ){
	if(estFeuille(a)){
		a = construire(x,feuille,feuille);
	}else{
		if(valeurRacine(a) < x){
			ajout(pointeurSAD(a));
		}else{
			ajout(pointeurSAG(a))
		}
	}
}










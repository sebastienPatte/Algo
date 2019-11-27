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
	if(estFeuille){
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
		
		return cpt;
	}
}

int compteHEgalP (Arbre A){
	if(estFeuille){
		return 0;
	}else{

	}
}








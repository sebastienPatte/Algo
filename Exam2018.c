//1
fonction AuMoinsUnPetitFilsFeuille (in a : Arbre) : booléen
	retourner AMUPFF(a)

fonction AMUPFF (in a : Arbre, in p : int) : booléen
	Si p >= 2
	Alors retourner estFeuille(a)
	Sinon Si estFeuille (a)
		  Alors retourner faux 
		  Sinon retourner (AMUPFF(SAG(a),p+1) OU AMUPFF(SAG(a))p+1)

//2
fonction CompteAscVrai (in a : Arbre) : int
	Si estFeuille(a)
	Alors retourner 0
	Sinon Si valeurRac(a) 
		  Alors retourner CAV(SAG(a)) + CAV(SAD(a)) + 1
		  Sinon retourner 0

//3
fonction CompteDescVrai(in a : Arbre) : int
	retourner CDV(a,f)
	
fonction CDV (in a : Arbre, out flag : booléen) : int
	Si estFeuille(a)
	Alors 
		flag <- vrai
		retourner 0
	Sinon cpt <- CDV(SAG,f1) + CDV(SAD,f2)
		  Si valeurRac(a)
		  Alors 
		  	flag <- vrai
		  	Si f1 ET f2
		  	Alors retourner cpt+1 
		  	Sinon retourner 1
		  Sinon
		  	flag <- faux
		  	retourner cpt

//4
procédure ArbreToCode(inout a : Arbre)
	Si estFeuille(*a)
	Alors affiche("F")
	Sinon 
		affiche("N")
		ArbreToCode(PointeurSAG(a))
		ArbreToCode(PointeurSAG(a))
//5
fonction CodeToArbre() : Arbre
	lettre <- clavier()
	Si  lettre = 'F'
	Alors retourner Feuille()
	Sinon Si lettre = 'N'
		  Alors 
		  	retourner Cons(CodeToArbre(), CodeToArbre())

//6
procédure RemplaceQueuesDeCeriseParFeuilles(in a : Arbre)
	RQDCPF(a)

procédure RQDCPF(inout a : Arbre, out flag : booléen)
	Si estFeuille(a)
	Alors flag <- faux
	Sinon
		ptrG <- PointeurSAG(a)
		ptrD <- PointeurSAD(a)
		flag <- estFeuille(*ptrG) ET estFeuille(ptD)
		RQDCPF(ptrG,fG)  
		RQDCPF(ptrD,fD)
		Si fG
		Alors *ptrG <- Feuille()
		Si fD
		Alors *ptrD <- Feuille()
		
//7
fonction XaProfDansABR(in a : ABR, in x : int, in p : int) : booléen
	Si estFeuille(a)
	Alors retourner faux
	Sinon 
		Si valeurRac(a) = x ET p=0
		Alors retourner vrai
		Sinon retourner XaProfDansABR(SAG,x,p-1) ET XaProfDansABR(SAD,x,p-1)
//8
fonction KFeuilles(in a : Arbre, inout k : int) : booléen
	KFBis(a,k)
	retourner (k=0)

fonction KFBis(in a : Arbre, inout k: int)
	Si estFeuille(a)
	Alors 
		k <- k-1
	Sinon
		KFeuilles(SAG(a),k) 
		KFeuilles(SAD(a),k)
/*Ex2 : tableaux
Partie 1:
	1/
		l'algo affiche le min et le max d'un tableau T de taille N
	2/
		N assignements, 1 cas : le premier elt est le plus proche de la mediane
	3/
		N/2 assignements, 2 cas : le premier elt est le min ou le max de T
	4/


Partie 2:
*/
procédure Intersection(in T1[1...n1], in T2[1...n2], out T3, out n3)
	TantQue i <= n1 ET j <= n2
		Si T1[i] < T2[j]
		Alors i <- i+1
		Sinon Si T1[i] < T2[j]
			  Alors j <- j+1
			  Sinon 
			  	n3 <- n3 + 1
			  	T3[n3] <- T1[i] 
			  	i <- i+1
			  	j <- j+1 

//Partie 3 :
fonction ComptageApparitions(in T1[1...n1], in T2[1...n2]) : int
	Pour j allant de 1 à n2
		Si T2[j] = T1[1]
		flag <- vrai
		i <- 2
		TantQue flag
			Si i>= n1
			Alors 
				cpt <- cpt + 1
				flag <- faux
			Sinon Si j+i >= n2
				  Alors flag <- faux
				  Sinon flag <- T1[i] = T2[j+i]
			i++
		















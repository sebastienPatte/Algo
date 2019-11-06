
8/
procedure EPO(x, inout L)
	si(not EstVide(L))
	alors si(x=Premier(L))
		 alors depile(L)
		 sinon EPO(x,PointeurSuite(L))
9/
Procedure ETO(x, inout L)
	si(not EstVide(L))
	alors si(x=Premier(L))
		 alors depile(L)
		 ETO(L)
		 sinon ETO(x,PointeurSuite(L))
10/
procedure EDO(x, inout L)
	Bis(x,L,b)

fonction Bis(x, L, out b)
	si (EstVide(L))
	alors b←true
	sinon Bis(x, PointeurSuite(L), b)
		 si (x= Premier ET b)
		 alors depile(L)
		 sinon b←false
11/
fonction DerPos_iter(l, x)
	cpt ← 0
	posX ← 0
	tantque non(EstVide(L))
	faire cpt++
		 si Premier(L) = x alors posX ← cpt
		 L ← suite(L)
	rendre posX

fonction DerPos_rec(l, x)
	si EstVide(L)
	alors rendre 0
	sinon y ← (DerPos_rec(Suite(l),x)
			 si y<>0
		    	 alors rendre y+1
   		      sinon 
				 si Premier(L)=x alors rendre 1
				 sinon rendre 0










fonction DerPos_recTerm(l, x)
	posX ← 0
	DerPos_aux(x, L, 1,inout posX)	
	rendre posX

procedure DerPos_aux(x, L, cpt, inout posX)
	si non(EstVide(L))
	alors si Premier(L)=x
		 alors posX ← cpt
	DerPos_aux(x, Suite(L), cpt+1, posX)
	
6/
fonction CompeApparitions(l1,l2) : int
	si EstVide(l1) alors rendre 1+longueur(l2)
				sinon rendre CA(l1,l2)

fonction CA(l1,l2) : int
	si EstVide(l2) alors rendre 0
			     sinon  rendre Prefixe(l1,l2) + CA(l1,suite(l2))

fonction Prefixe(l1,l2) : int
	si EstVide(l1) alors rendre 1
	sinon 
		si EstVide(l2) alors rendre 0 
		sinon 
			si Premier(l1)=Premier(l2)
			alors rendre Prefixe(suite(l1),suite(l2))
			sinon rendre 0

12/
fonction Pif(l) : int 
	pifAux(l, 1, posD, cpt)
	rendre cpt
	
fonction pifAux(in l, in posG, out posD, out cpt) :
	cpt++
	si (EstVide(l))
	alors posD ← 0 
		cpt ← 0
		
	sinon
		pifAux(suite(l), posG+1 ,posD, cpt)
		posD++
		si (premier(l) = posG * posD)
		alors cpt++

13/
fusion(l1,l2)
	si EstVide(l1
	alors rendre l2
	sinon
		si EstVide(l2)
		alors rendre l1
		sinon
			si Premier(l1) < Premier(l2)
			alors rendre ajoute(Premier(l1),fusion( Suite(l1),l2))
			sinon rendre ajoute(Premier(l2),fusion( l1,Suite(l2))
14/
teste si deux listes sont les mêmes

15/
fonction Fmiroir_rec(l) : liste
	rendre Fmiroir_aux(l,[])

fonction Fmiroir_aux(l1,l2)
	si EstVide(l1)
	alors rendre l2
	sinon rendre Fmiroir_aux(suite(l1), ajoute (premier(l1), l2))

procedure Pmiroir (inout L):
	L2 <- vide
	tant que non(EstVide(L))
		tmp <- suite(L)
		pointeurSuite(L) <- L2
		L2 <- L
		L <- tmp
	L <- L2
procedure Pmirroir_rec(inout L):
	L2 <- vide
	Pmirroir_aux(L,L2)
	L <- L2

procedure Pmirroir_aux(inout L, inout L2)
	si non (EstVide(L))
	alors
		tmp <- Suite(L)
		L2 <- L
		L <- tmp
		Pmiroir_aux(L,L2)

fonction listeinterclassements (L1, L2) : liste de liste
	si EstVide(L1) alors rendre [L2]
	sinon si estVide(L2) alors rendre [L1]
	sinon rendre

void ffa (Liste L)
{
	if(L!= NULL)
	{
		ffa(L -> suivant);
		printf(L -> premier);
	}
}

void echiffa(Liste L)
{
	ffa(L);
	printf("\n");
}

void ajouteTrie(int x, Liste* L)
{
	if(*L == NULL || x<(*L)->premier)
	{
		empiler(x, L);//<==> empiler(x, &(*L))
	}
	else
	{
		ajouteTrie(x,&((*L)->suivant))
	}
}

void swap (Liste* L)
{
	Liste L2;
	Liste tmp;
	while(*L != NULL)
	{
		tmp = (*L) -> suivant;
		(*L) -> suivant = L2;
		L2 = *L;
		*L = tmp;
	}
	*L = L2;
}
/************fichier crible.c************************/



void init_crible (int * c, int n, int tailleMax)
{
	int i = 2;
	c[0] = c[1] = 0;
	if (!(n <= 2))
	{
		while (i <= n)
		{
			c[i] = 1;
			i++;
		}
		while (i < tailleMax)
		{
			c[i] = 0;
			i++;
		}	
	}
}

void construit_crible (int * c, int taille, int n)
{
	int num, numToDel;

	init_crible(c, n, taille);
	num = 2;
	while (num <= n)
	{
		if (present(num, c))
		{
			numToDel = num * 2;
			while(numToDel <= n)
			{
				suppression(numToDel, c);
				numToDel += num;
			}	
		}
		num++;
	}
}
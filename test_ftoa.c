#include "libft/includes/libft.h"
#include <stdio.h>
#include <math.h>

char	*ft_ftoa(double number)
{
	return (ft_ftoap(number, 6));
}

char	*ft_ftoap(double number, double afterpoint)
{
	int		ipart;
	double	fpart;
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ipart = (int)number;
	((fpart = number - (float)ipart) < 0) ? fpart *= -1 : 0;
	if (afterpoint == 0)
		((int)(fpart * ft_powd(10, 1)) % 10 >= 5) ? ipart++ : 0;
	str = ft_strjoin(str, ft_itoa(ipart));
	if (afterpoint > 0 && afterpoint < 21)
	{
		while (str[i] != '\0')
			i++;
		str = ft_strjoin(str, ".");
		fpart = fpart * ft_powd(10, afterpoint);
		if ((long long int)(number * ft_powd(10, afterpoint + 1)) % 10 >= 5)
			fpart += 1.;
		str = ft_strjoin(str, ft_itoa((int)fpart));
	}
	return (str);
}

int		main()
{
	long double pi = 3.1415926535897932384626433832795028841971;
	float nb = 1.23;
	double nbr = 1.23;
	long double e = 2.718281828;

	printf("------\nORIGINAL VERSION\n------\n");

	printf("printf =		%Lf\n", pi);
	printf("precision 1 =		%.1Lf\n", pi);
	printf("precision 2 =		%.2Lf\n", pi);
	printf("precision 3 =		%.3Lf\n", pi);
	printf("precision 4 =		%.4Lf\n", pi);
	printf("precision 5 =		%.5Lf\n", pi);
	printf("precision 6 =		%.6Lf\n", pi);
	printf("precision 7 =		%.7Lf\n", pi);
	printf("precision 8 =		%.8Lf\n", pi);
	printf("precision 9 =		%.9Lf\n", pi);
	printf("precision 10 =		%.10Lf\n", pi);
	printf("true pi =		3.1415926535897932384626433832795028841971\n");
	printf("precision 20 =		%.20Lf (undefined behavior)\n\n", pi);

	printf("nb =			%.6f\n", nb);
	printf("nb =			%.0Lf\n", e);

	printf("------\nMY VERSION\n------\n");

	printf("no afterpoint =		%s\n", ft_ftoa(pi));
	printf("afterpoint 0 =		%s\n", ft_ftoap(pi, 0));
	printf("afterpoint 1 =		%s\n", ft_ftoap(pi, 1));
	printf("afterpoint 2 =		%s\n", ft_ftoap(pi, 2));
	printf("afterpoint 3 =		%s\n", ft_ftoap(pi, 3));
	printf("afterpoint 4 =		%s\n", ft_ftoap(pi, 4));
	printf("afterpoint 5 =		%s\n", ft_ftoap(pi, 5));
	printf("afterpoint 6 =		%s\n", ft_ftoap(pi, 6));
	printf("afterpoint 7 =		%s\n", ft_ftoap(pi, 7));
	printf("afterpoint 8 =		%s\n", ft_ftoap(pi, 8));
	printf("afterpoint 9 =		%s\n", ft_ftoap(pi, 9));
	printf("afterpoint 10 =		%s\n", ft_ftoap(pi, 10));
	printf("afterpoint 11 =		%s (undefined behavior)\n\n", ft_ftoap(pi, 11));

	printf("test float =		%s\n", ft_ftoa(nb));
	printf("test double =		%s\n", ft_ftoa(nbr));

	printf("nb =			%s\n", ft_ftoap(e, 0));

	return (0);
}

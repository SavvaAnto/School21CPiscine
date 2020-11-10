#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**res;
	char	*buf;

	res = argv;
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(res[i],res[j]) > 0)
			{
				buf = res[i];
				res[i] = res[j];
				res[j] = buf;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

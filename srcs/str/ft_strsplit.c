/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:47:25 by tcollard          #+#    #+#             */
/*   Updated: 2018/12/18 12:43:12 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static unsigned int	ft_word_counter(char const *s, char c)
{
	int				i;
	unsigned int	nb_word;

	nb_word = 0;
	i = 0;
	if (s[0] != c && s[0])
		nb_word++;
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			nb_word++;
		i++;
	}
	return (nb_word);
}

static int			ft_position_word(char const *s, char c, unsigned int word_n)
{
	int				i;
	unsigned int	i_word;

	i = 0;
	i_word = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] != c && i_word == word_n)
			return (i);
		if (i > 0 && s[i] == c && s[i + 1] != c)
			i_word++;
		i++;
	}
	return (i);
}

static int			ft_counter_lettre(char const *s, char c,
					unsigned int word_n)
{
	int	pos_word;
	int	nb_lettre;

	nb_lettre = 0;
	pos_word = ft_position_word(s, c, word_n);
	while (s[pos_word] != c && s[pos_word] != '\0')
	{
		pos_word++;
		nb_lettre++;
	}
	return (nb_lettre);
}

static void			ft_fill(char const *s, char c, unsigned int wrd_n,
					char **split)
{
	int	i;
	int	j;

	i = ft_position_word(s, c, wrd_n);
	j = 0;
	while (s[i] != c && s[i])
	{
		split[wrd_n][j] = s[i];
		i++;
		j++;
	}
	split[wrd_n][j] = '\0';
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	nb_word;
	unsigned int	i;
	char			**split;
	int				nb_letter;

	i = 0;
	if (!s)
		return (0);
	nb_word = ft_word_counter(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		nb_letter = ft_counter_lettre(s, c, i);
		if (!(split[i] = (char*)malloc(sizeof(char) * (nb_letter + 1))))
			return (NULL);
		ft_fill((char const *)s, c, i, split);
		i++;
	}
	split[nb_word] = 0;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:24:11 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/11 12:45:44 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

t_shell	*ft_lstlast(t_shell *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_shell	*ft_lstnew(char *content, int type)
{
	t_shell	*x;

	x = malloc(sizeof(t_shell));
	if (!x)
		return (NULL);
	x->cmds = ft_split(content, ' ');
    x->type = type;
	x->next = NULL;
	return (x);
}

void	ft_lstadd_back(t_shell **lst, t_shell *new)
{
	t_shell	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

t_shell *parse_line(char *line)
{
	t_shell	*shell;
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	shell = 0;
<<<<<<< HEAD
	///handle if pipe exist in the begin or in the last of the line
	if(line[0] == '|' || line[ft_strlen(line) - 1] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return(0);
	}
=======
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
	// split line with pipe
	args = ft_split(line, '|');
	i = 0;
	i = 0;
	while (args[i])
	{
		//printf("[%s]\n", args[i]);
		if(!strcmp(args[i], ">>"))
			ft_lstadd_back(&shell, ft_lstnew(args[i++], 4));
		else if(!strcmp(args[i], "<<"))
			ft_lstadd_back(&shell, ft_lstnew(args[i++], 5));
		else if(!strcmp(args[i], ">"))
			ft_lstadd_back(&shell, ft_lstnew(ft_strtrim(args[i++], " "), 1));
		else if(!strcmp(args[i], "<"))
			ft_lstadd_back(&shell, ft_lstnew(ft_strtrim(args[i++], " "), 0));
		// creat new node and add it to shell list(shell)
		ft_lstadd_back(&shell, ft_lstnew(ft_strtrim(args[i], " "), 3));
		//this condition becouse we dont want a pipe after commands
		//if(args[i + 1] && strcmp(args[i + 1], ">>") && strcmp(args[i + 1], "<<") && strcmp(args[i + 1], ">") && strcmp(args[i + 1], "<"))
		//{
		//	// creat new node with pipe type between to command nodes
		//	ft_lstadd_back(&shell, ft_lstnew("|", 2));
		//}
		i++;
	}
	return (shell);
}

int	ft_checkspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int main(int ac, char **av, char **env)
{
	(void)av;
	(void)env;
	char    *read;
	t_shell *shell;

<<<<<<< HEAD
	// shell = NULL;
	shell = malloc(sizeof(t_shell) * 100);
=======
	shell = NULL;
	if(ac != 1)
	{
		ft_error("invalid number of argument");
		return(0);
	}
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
	while(1)
	{
		read = readline("\033[0;32mMinishell>> \033[0m");
		add_history(read);
		read += ft_checkspace(read);
		read = parse_redirect(read);
		shell = parse_line(read);
<<<<<<< HEAD
		//	//ft_execute(shell, env);
		int i;
		while(shell)
		{
			i = 0;
			while(shell->cmds[i])
				printf("%s\n", shell->cmds[i++]);
			printf("***********\n");
			shell = shell->next;
			
		}
=======
<<<<<<< HEAD
		whatever(shell, env);
		// while(shell)
		// {
		// 	printf("%s\t %d\n", shell->cmd, shell->type);
		// 	shell = shell->next;
		// }
=======
		handle_couts(shell);
		//ft_execute(shell, env);
		//while(shell)
		//{
		//	printf("%s\t %d\n", shell->cmd, shell->type);
		//	shell = shell->next;
		//}
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
>>>>>>> 7ebcd45e1e59ad676fdec1fe1ddf6f12c220bb25
	}
	return 0;
}

// variable name -v = split(..., "found: ") to get the variable value !!
// < > ||| << >>

// shell->pipe->input = shell->cmd;
// shell->pipe->input = shell->cmd;
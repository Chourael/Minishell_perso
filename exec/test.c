#include <stdio.h>

void	ft_cmds(char ***cmds)
{
	printf("%s", cmds[0][0]);
}

int	main(void)
{
	char	*cmd[] = {"/usr/bin/ls", "-l", NULL};
	char	*cmd1[] = {"/usr/bin/grep", "chourael", NULL};
	char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};
	char	**cmds[] = {cmd, cmd1, cmd2, NULL};

	ft_cmds(cmds);
}

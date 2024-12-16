#include ".././includes/push_swap.h"

t_list	*ft_new_stack(int ac, char **av)
{
	t_list	*stack;
	int		i;

	stack = ft_calloc(sizeof(t_list), (ac));
	if (!stack)
		return (NULL);
	i = 0;
	ac -= 1;
	while (i <= ac)
	{
	}
	return (stack);
}

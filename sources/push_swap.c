#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**numbers;
    int		i;

    if (argc < 2)
        return (0);
    a = NULL;
    if (argc == 2)
    {
        numbers = ft_split(argv[1], ' ');
        if (!numbers)
            return (0);
        i = 0;
        while (numbers[i])
        {
            push_to_stack(&a, atoi(numbers[i]));
            free(numbers[i]);
            i++;
        }
        free(numbers);
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            push_to_stack(&a, atoi(argv[i]));
            i++;
        }
    }
    if (!a || is_sorted(a))
    {
        free_stack(a);
        return (0);
    }
    b = NULL;
    if (stack_size(a) <= 3)
        sort_three(&a);
    else if (stack_size(a) <= 5)
        sort_four_or_five(&a, &b);
    else
        radix_sort(&a, &b);
    free_stack(a);
    free_stack(b);
    return (0);
}

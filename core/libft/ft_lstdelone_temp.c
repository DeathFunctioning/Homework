#include "libft.h"

// Library function from your provided code
void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
        return;
    if (del)
        del(lst->content);
    free(lst);
}

void deleteString(void *str)
{
    free((char *)str);
}
int main() 
{
    // Create a linked list node with a dynamically allocated string
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node) {
        perror("Memory allocation failed");
        return 1;
    }

    // Create a string to store in the node
    char *str = (char *)malloc(6 * sizeof(char));
    if (!str) {
        perror("Memory allocation failed");
        free(node);
        return 1;
    }
    strcpy(str, "Hello");

    // Set the node's content and next pointer
    node->content = str;
    node->next = NULL;

    // Delete the node and its content using ft_lstdelone
    ft_lstdelone(node, deleteString);

    return 0;
}


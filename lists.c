#include "shell.h"

/**
 * add_node - Adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_node;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(list_t));

    if (!new_node)
        return (NULL);

    new_node->str = (str) ? _strdup(str) : NULL;
    new_node->num = num;
    new_node->next = *head;

    *head = new_node;
    return (new_node);
}

/**
 * add_node_end - Adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(list_t));

    if (!new_node)
        return (NULL);

    new_node->str = (str) ? _strdup(str) : NULL;
    new_node->num = num;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }

    else
    {
        node = *head;

        while (node->next)
        {
            node = node->next;
        }
        node->next = new_node;
    }

    return (new_node);
}

/**
 * print_list_str - Prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts((h->str) ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * delete_node_at_index - Deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return (0);

    if (index == 0)
    {
        list_t *node = *head;
        *head = (*head)->next;
        free(node->str);
        free(node);
        return (1);
    }

    list_t *current = *head;
    list_t *prev = NULL;
    unsigned int i = 0;

    while (current && i < index)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if (i == index && current)
    {
        prev->next = current->next;
        free(current->str);
        free(current);
        return (1);
    }

    return (0);
}

/**
 * free_list - Frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
    if (!head_ptr || !*head_ptr)
        return;

    list_t *current = *head_ptr;
    list_t *next = NULL;

    while (current)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    *head_ptr = NULL;
}

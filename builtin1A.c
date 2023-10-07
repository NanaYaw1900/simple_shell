#include "shell.h"

/**
 * _myhistory - Displays the history list, one command per line, preceded 
 * by line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
		print_list(info->history);
		return (0);
}

/**
 * unset_alias - Unsets an alias to strings
 * @info: parameter struct
 * @str: the alias string to unset
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
		char *equal_sign, temp;
		int ret;

		equal_sign = _strchr(str, '=');

		if (!equal_sign)
		return (1);


		temp = *equal_sign;
		*equal_sign = '\0';

		ret = delete_node_at_index(&(info->alias),
				get_node_index(info->alias, node_starts_with(info->alias, str, -1)));


		*equal_sign = temp;		  
		return (ret);
}

/**
 * set_alias - Sets or updates an alias
 * @info: parameter struct
 * @str: the alias string to set or update
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
		char *p = NULL, *a = NULL;

		if (node)
			{
				p = _strchr(node->str, '=');
				for (a = node->str; a <= p; a++)
				_putchar(*a);
				_putchar('\'');
				_puts(p + 1);
				_puts("'\n");
				return (0);
		}
		return (1);
}

/**
 * _myalias - Manages shell aliases, including listing and setting aliases
 * @info: Structure containing potential arguments. Used to maintain
 *				  constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
		int i;

		if (info->argc == 1)

		{
				list_t *node = info->alias;
				while (node)
				{
						print_alias(node);
						node = node->next;
				}
				return (0);
		}

		for (i = 1; info->argv[i]; i++)

		{
				char *equal_sign = _strchr(info->argv[i], '=');

				if (equal_sign)
				{
						set_alias(info, info->argv[i]);

				}

				else
				{
						print_alias(node_starts_with(info->alias, info->argv[i], '='));
				}
		}

				return (0);
}

		for (i = 1; info->argv[i]; i++)
		{
				char *equal_sign = _strchr(info->argv[i], '=');

				if (equal_sign)
				{
						set_alias(info, info->argv[i]);
				}

				else
				{
						print_alias(node_starts_with(info->alias, info->argv[i], '='));
				}
		}
				return (0);
}

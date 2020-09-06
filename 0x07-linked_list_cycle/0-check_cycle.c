#include "lists.h"
/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: pointer to a list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *pos1 = list;
	listint_t *pos2 = list;

	if (!list)
		return (0);
	pos2 = pos2->next;
	while (pos2 && pos2->next && pos1)
	{
		if (pos2 == pos1)
			return (1);
		pos2 = pos2->next->next;
		pos1 = pos1->next;
	}
	return (0);
}

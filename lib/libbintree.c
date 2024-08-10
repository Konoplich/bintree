#include <stdlib.h>
#include "libbintree.h"
#include <stdio.h>

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

node_t *bintree_get_free (T value, node_t *parent)
{
	node_t *tmp = (node_t *) malloc (sizeof (node_t));
	tmp->low = tmp->hi = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

void bintree_insert (node_t **head, int value)
{
	node_t *tmp = NULL;

	if (*head == NULL)
	{
		*head = bintree_get_free (value, NULL);
		return;
	}

	tmp = *head;

	while (tmp)
	{
		if (CMP_GT (value, tmp->data))
		{
			if (tmp->hi)
			{
				tmp = tmp->hi;
				continue;
			}
			else
			{
				tmp->hi = bintree_get_free (value, tmp);
				return;
			}
		}
		else
			if (CMP_LT (value, tmp->data))
			{
				if (tmp->low)
				{
					tmp = tmp->low;
					continue;
				}
				else
				{
					tmp->low = bintree_get_free (value, tmp);
					return;
				}
			}
			else
				exit (2);
	}
}

node_t *bintree_get_min (node_t *root)
{
	while (root->low)
		root = root->low;

	return root;
}

node_t *bintree_get_max (node_t *root)
{
	while (root->hi)
		root = root->hi;

	return root;
}

node_t *bintree_get_node (node_t *root, T value)
{
	while (root)
	{
		if (CMP_GT (root->data, value))
		{
			root = root->low;
			continue;
		}
		else
			if (CMP_LT (root->data, value))
			{
				root = root->hi;
				continue;
			}
			else
				return root;
	}

	return NULL;
}

void bintree_remove (node_t *target)
{
	if (target->low && target->hi)
	{
		node_t *localMax = bintree_get_max (target->low);
		target->data = localMax->data;
		bintree_remove (localMax);
		return;
	}
	else
		if (target->low)
		{
			if (target == target->parent->low)
				target->parent->low = target->low;

			else
				target->parent->hi = target->low;
		}
		else
			if (target->hi)
			{
				if (target == target->parent->hi)
					target->parent->hi = target->hi;

				else
					target->parent->low = target->hi;
			}
			else
			{
				if (target == target->parent->low)
					target->parent->low = NULL;

				else
					target->parent->hi = NULL;
			}

	free (target);
}

void bintree_delete_value (node_t *root, T value)
{
	node_t *target = bintree_get_node (root, value);
	bintree_remove (target);
}

void bintree_print (node_t *root, const char *dir, int level)
{
	if (root)
	{
		printf ("lvl %d %s = %d\n", level, dir, root->data);
		bintree_print (root->low, "low", level+1);
		bintree_print (root->hi, "hi", level+1);
	}
}


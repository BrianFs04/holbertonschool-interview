#include "binary_trees.h"
avl_t *heap_insert(avl_t **root, int size, int start, int *array);

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: node to add new node
 * @value: value to insert in new node
 * Return: poointer to the new node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
    avl_t *newnode;

    newnode = malloc(sizeof(avl_t));
    if (!newnode)
        return (NULL);

    newnode->n = value;
    newnode->parent = parent;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

/**
 * heap_insert - Inserts a node for a binary tree
 * @root: this is the head of our binary tree
 * @array: This is the array with elements to index in our binary tree
 * @size: this is the end position of the array
 * @start: this is the start of the array
 * Return: pointer to new node or NULL if it fails
 */
avl_t *heap_insert(avl_t **root, int size, int start, int *array)
{
    int mid = (start + size) / 2;
    avl_t *new = NULL;

    if (size < start)
        return (NULL);
    new = binary_tree_node(*root, array[mid]);
    if (mid != start)
        new->left = heap_insert(&new, mid - 1, start, array);
    if (mid != size)
        new->right = heap_insert(&new, size, mid + 1, array);
    return (new);
}

/**
 * sorted_array_to_avl - Sorts array into avl binary tree
 * @array: The array to sorted
 * @size: Size of the array
 * Return: pointer to root node of the created tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;

    root = heap_insert(&root, size - 1, 0, array);
    return (root);
}
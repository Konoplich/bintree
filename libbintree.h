typedef int T;
typedef struct _node
{
	T data;
	struct _node *low;
	struct _node *hi;
	struct _node *parent;
} node_t;
node_t *bintree_get_free (T value, node_t *parent);
void bintree_insert (node_t **head, int value);
node_t *bintree_get_min (node_t *root);
node_t *bintree_get_max (node_t *root);
node_t *bintree_get_node (node_t *root, T value);
void bintree_remove (node_t *target);
void bintree_delete_value (node_t *root, T value);
void bintree_print (node_t *root, const char *dir, int level);


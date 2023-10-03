#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 25
#define MAX(a, b) a>b ? a : b

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* root = NULL;
void insert(int);
void delete(int);
void exit(int);
int search(int);
    struct TreeNode* queue[MAX_SIZE];
    struct TreeNode* new_node = NULL;
    struct TreeNode* queue[MAX_SIZE];
    struct TreeNode* temp = NULL, *last_node = NULL, *key_node = NULL;
    struct TreeNode* queue[MAX_SIZE];

int main()
{
    int n, node_data;
    char user_active = 'Y';

    while(user_active == 'Y' || user_active == 'y')
    {
	printf("\n1. Insert\n2. Delete\n3. Search\n4. Exit ");
	printf("\n\nEnter Your Choice: ");
	scanf("%d", &n);

	printf("\n");
	switch(n)
	{
	    case 1:
		printf("Enter data for new node: ");
		scanf("%d", &node_data);
		insert(node_data);
		break;

	    case 2:
		printf("Enter node data: ");
		scanf("%d", &node_data);
		delete(node_data);
		break;

	    case 3:
		printf("Enter node data: ");
		scanf("%d", &node_data);
		search(node_data);
		break;
	     case 4:
		exit(n);
		break;

	    default:
		printf("Invalid choice");
	}
    }
    return 0;
}

struct TreeNode* create(int data)
{
    struct TreeNode* new_node = (struct TreeNode*) malloc (sizeof(struct TreeNode));    
    if(new_node == NULL)
    {
        printf("\nMemory can't be allocated for new node\n");
        return NULL;
    }

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = data;
 
    return new_node;
}
void insert(int data)
{
    int front = -1;
    int rear = -1;
    if(root == NULL)
    {
	struct TreeNode* new_node = create(data);
	if(new_node)
	{
	    root = new_node;
	    printf("\n * Node with data %d was inserted", data);
	}
	return;
    }
    queue[front+1] = root;
    front = rear = 0;
 
    while(front <= rear)
    {
        struct TreeNode* temp = queue[front];
        front++;
 
	if(temp->left != NULL)
        {
            queue[++rear] = temp->left;
        }
        else
        {
            new_node = create(data);
            if(new_node)
            {
                temp->left = new_node;
                printf("\n* Node with data %d was inserted", data);
	    }
            return;
	}
 
        if(temp->right != NULL)
        {
            queue[++rear] = temp->right;
        }
        else
	{
	    new_node = create(data);
	    if(new_node)
	    {
		temp->right = new_node;
		printf("\n* Node with data %d was inserted", data);
	    }
	    return;
	}
    }
}

void delete(int key)
{
    int front = -1;
    int rear = -1;
    if(root == NULL)
    {
	return;
    }
    if(root->left == NULL && root->right == NULL)
    {
	if(root->val == key)
	{
	    root = NULL;
	    printf("\n* Node with data %d was deleted", key);
	    return;
	}
	else
	{
	    return;
	}
    }

 
    queue[front + 1] = root;
    front = rear = 0;
    while (front <= rear)
    {
        temp = queue[front];
        front++;
 
        if (temp->val == key)
        {
            key_node = temp;
        }
 
        if (temp->left != NULL)
        {
	    last_node = temp;
            queue[++rear] = temp->left;
        }
 
	if (temp->right != NULL)
        {
            last_node = temp;
            queue[++rear] = temp->right;
        }
    }
    if (key_node != NULL)
    {
        key_node->val = temp->val;
        if (last_node->right == temp)
        {
            last_node->right = NULL;
        }
        else
        {
            last_node->left = NULL;
	}
        printf("\n* Node with data %d was deleted", key);
        free(temp);
        return;
    }
    printf("\n* Node with data %d was not found", key);
}   
 
int search(int key)
{
    int front = -1;
    int rear = -1;
    int has_found;
    if(has_found == -1) {
	printf("\nNode was not found!");
    } else {
	printf("\nNode was found");
    }
    if (root == NULL)
    {
	return -1;
    }

    queue[front + 1] = root;
    front = rear = 0;
    while (front <= rear)
    {
	struct TreeNode* temp = queue[front];
	front++;

	if (temp->val == key)
	{
	    return 1;
	}

	if (temp->left != NULL)
	{
	    queue[++rear] = temp->left;
	}

	if (temp->right != NULL)
	{
	    queue[++rear] = temp->right;
	}
    }
    return -1;
}
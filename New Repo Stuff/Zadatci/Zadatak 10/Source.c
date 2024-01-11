#define _CRT_SECURE_NO_WARNINGS
#define C_LEN (30)
#define c_LEN (30)
#define uf_LEN (30)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_;
typedef struct node_* n_pos;
typedef struct node_
{
	char name[c_LEN];
	int br_stan;
	n_pos left;
	n_pos right;

}node;

struct countries_;
typedef struct countries_* c_pos;
typedef struct countries_
{
	char name[C_LEN];
	c_pos c_next;
	node n_head;

}country;
c_pos create_country(char* name);
n_pos sort_city(n_pos root, char* name, int stan);
int usporedi(c_pos c_head, char* name, int br);
int usporedi_st(n_pos current_n, int br);
int ispis(c_pos c_head);
int ispisi_grad(n_pos root);
int sort_country(c_pos head, c_pos new_c);
int read_cities(n_pos root, char* file);
n_pos create_node(char* name, int stan);
n_pos sort_population(n_pos root, char* name, int stan);


int main(void)
{
	country c_head =
	{
		.c_next = NULL,
		.name = " ",
		.n_head =
		{
			.br_stan = 0,
			.name = " ",
			.left = 0,
			.right = 0
		}

	};

	FILE* file = fopen("drzave.txt", "r");
	if (!file) return EXIT_FAILURE;

	while (!feof(file))
	{
		char c_name[C_LEN] = { 0 };
		char u_file[uf_LEN] = { 0 };

		int fsf_r = fscanf(file, " %s %s", c_name, u_file);
		if (fsf_r != 2) break;

		c_pos new_country = create_country(c_name);
		if (!new_country) break;
		read_cities(&new_country->n_head, u_file);

		sort_country(&c_head, new_country);

	}
	fclose(file);

	ispis(&c_head);
	puts("\nUnesite drzavu i br san za usporedbu: ");
	int br = 0;
	char drzava[C_LEN] = { 0 };
	scanf(" %s %d", drzava, &br);
	usporedi(&c_head, drzava, br);

	return EXIT_SUCCESS;
}
int usporedi(c_pos c_head, char* name, int br)
{
	c_pos current = c_head->c_next;
	if (!current) return EXIT_FAILURE;

	while (current != NULL && strcmp(current->name, name) != 0)
	{
		current = current->c_next;
	}

	if (!current) return 0;
	else {

		n_pos current_n = &current->n_head;
		usporedi_st(current_n, br);
	}
	return EXIT_FAILURE;
}
int usporedi_st(n_pos current_n, int br)
{
	n_pos curr = current_n;
	if (curr)
	{
		usporedi_st(curr->left, br);
		if (br < curr->br_stan) printf("\n -to su %s: ", curr->name);
		usporedi_st(curr->right, br);
	}

	return EXIT_SUCCESS;
}


int ispis(c_pos c_head)
{
	c_pos current = c_head->c_next;
	if (!current) return EXIT_FAILURE;

	while (current)
	{
		printf("\n[%s]", current->name);

		ispisi_grad(&current->n_head);
		current = current->c_next;
	}

	return EXIT_SUCCESS;
}
int ispisi_grad(n_pos root)
{
	if (root)
	{
		ispisi_grad(root->left);
		if (strcmp(root->name, "") != 0) printf("\n%s", root->name);
		ispisi_grad(root->right);

	}
	return EXIT_SUCCESS;
}

int sort_country(c_pos head, c_pos new_c)
{

	c_pos current = head;
	if (!current) return 0;
	while (current->c_next != NULL && strcmp(current->c_next->name, new_c->name) < 0)
	{
		current = current->c_next;
	}

	new_c->c_next = current->c_next;
	current->c_next = new_c;

	return EXIT_SUCCESS;
}
int read_cities(n_pos root, char* file)
{
	FILE* file_p = fopen(file, "r");
	if (!file_p) return EXIT_FAILURE;

	while (!feof(file_p))
	{
		char name[c_LEN] = { 0 };
		long int stan = 0;

		int fsf_r = fscanf(file_p, " %[^,],%d", name, &stan);
		if (fsf_r != 2) break;

		root = sort_city(root, name, stan);
		if (!root) break;


	}

	fclose(file_p);
	return EXIT_SUCCESS;
}

n_pos create_node(char* name, int stan)
{
	n_pos new_c = (n_pos)malloc(sizeof(node));
	if (!new_c) return NULL;

	strcpy(new_c->name, name);
	new_c->br_stan = stan;
	new_c->left = NULL;
	new_c->right = NULL;

	return new_c;
}
n_pos sort_population(n_pos root, char* name, int stan)
{

	if (strcmp(root->name, name) < 0)
	{
		root->right = sort_city(root->right, name, stan);
	}
	else if (strcmp(root->name, name) > 0)
	{
		root->left = sort_city(root->left, name, stan);


	}

	return root;
}

n_pos sort_city(n_pos root, char* name, int stan)
{
	if (!root) return create_node(name, stan);

	if (stan < root->br_stan)
		root->left = sort_city(root->left, name, stan);
	else if (stan > root->br_stan)
		root->right = sort_city(root->right, name, stan);
	else
		return sort_population(root, name, stan);


	return root;
}

c_pos create_country(char* name)
{
	c_pos new_c = (c_pos)malloc(sizeof(country));
	if (!new_c) return NULL;

	strcpy(new_c->name, name);
	new_c->c_next = NULL;
	new_c->n_head.left = NULL;
	new_c->n_head.right = NULL;
	strcpy(new_c->n_head.name, " ");

	return new_c;

}
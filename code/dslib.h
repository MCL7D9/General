
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define offsetof(type, member) ((size_t)&((type *)0)->member)
#define container_of(ptr, type, member) ({ \
	const typeof(((type *)0)->member) *__mptr = (ptr); \
	(type *)((char *)__mptr - offsetof(type, member)); \
})

struct node {
	struct node *prev;
	struct node *next;
};

struct node *new_list(void)
{
	struct node *tmp;
	int eno;
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL) {
		eno = errno;
		goto MALLOCFAILURE;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	return tmp;
MALLOCFAILURE:
	printf("Allocation of data has failed\n ERRNO: %d: %s", eno, strerror(eno));
	return NULL;
}

void del_node(struct node *inp)
{
	inp->prev->next = inp->next;
	inp->next->prev = inp->prev;
	free(inp);
}

struct node *traverse_node(const struct node *inp, int dir)
{
	const struct node *tmp;
	if (!dir)
		return NULL;
	tmp = inp;
	if (dir < 0) {
		int i;
		for (i = 0; i < -dir; ++i) {
			tmp = tmp->prev;
		}
	} else {
		int i;
		for (i = 0; i < dir; ++i) {
			tmp = tmp->next;
		}
	}
	return (struct node *)tmp;
}

int ins_node(struct node *inp)
{
	struct node *tmp;
	int eno;
	tmp = malloc(sizeof *tmp);
	if (tmp == NULL) {
		eno = errno;
		goto MALLOCFAILURE;
	}
	tmp->next = inp->next;
	tmp->prev = inp;
	tmp->next->prev = tmp;
	inp->next = tmp;
	return 0;
MALLOCFAILURE:
	printf("Allocation of data has failed\n ERRNO: %d: %s", eno, strerror(eno));
	return -1;
}































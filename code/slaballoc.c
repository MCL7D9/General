#include <sys/mman.h>
#include "dslib.h"
#include <stdint.h>

#define MEM_SIZE 4096
#define BLOCK_SIZE 64
#define BLOCK_NUM (MEM_SIZE / BLOCK_SIZE)

#define E_NOMEM 1
#define E_INVAL 2
#define E_PANIC 3

char *mem = NULL;
struct node *listhead;

int main(void)
{
	mem = mmap(mem, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	char *last = mem + MEM_SIZE - BLOCK_SIZE;
	if (mem == MAP_FAILED) {
		perror("mmap");
		return -E_PANIC;
	}
	struct node *last_node;
	last_node = (struct node *)mem;
	last_node->prev = (struct node*)last;
	last_node->prev->next = last_node;
	for (struct node *tmp = (struct node *)(mem + BLOCK_SIZE); tmp < (struct node*)(mem + MEM_SIZE); tmp = (struct node*)((char *)tmp + BLOCK_SIZE)) {
		tmp->prev = last_node;
		last_node->next = tmp;
		last_node = tmp;
	}
	listhead = (struct node *)mem;
	return 0;
}

void *salloc(void)
{
	struct node *tmp = listhead;
	if (listhead == NULL)
		return NULL;
	if (listhead->next == listhead) {
		listhead = NULL;
		return tmp;
	}
	listhead->prev->next = listhead->next;
	listhead->next->prev = listhead->prev;
	listhead = listhead->next;
	return (void *)tmp;
}

int sfree(void *addr)
{
	struct node *tmp = (struct node *)addr;
	if (addr < (void *)mem || addr >= (void *)(mem + MEM_SIZE))
		return -E_INVAL;
	if (((uintptr_t)addr - (uintptr_t)mem) % 64)
		return -E_INVAL;
	if (listhead == NULL) {
		listhead = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
		return 0;
	}
	tmp->prev = listhead;
	tmp->next = listhead->next;
	listhead->next->prev = tmp;
	listhead->next = tmp;
	return 0;
}


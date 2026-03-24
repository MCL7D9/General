#include <string.h>

#define BLOCK_SIZE 1024
#define BLOCK_NUM  4096
#define DATA_SIZE  BLOCK_SIZE * BLOCK_NUM
#define META_SIZE  BLOCK_SIZE / 8
#define MEM_SIZE   DATA_SIZE + META_SIZEA
#define ERR_NOMEM  -1
#define ERR_2LARGE -2

static char mem[MEM_SIZE];
static const char *const mptr = mem;
static const char *const dptr = mem + META_SIZE;

int main(void)
{
	memset(mptr, 1, META_SIZE);
	return 0;
}

char *mem_req(size_t size)
{
	int tmp = 0, i = 0, j = 8;
	char *tmpptr = NULL;
	if (size > DATA_SIZE)
		return ERR_2LARGE;
	while (tmp < size && i < META_SIZE) {
		tmpptr = mptr + i;
		for (j--) {
			if (*tmpptr & 1 << j)
				tmp++;
			else 
				tmp = 0;
		}
		j = 8;
	}
	if (tmp == size) {

		return i * 8 + j + dptr;
	}
	else 
		return ERR_NOMEM;

}


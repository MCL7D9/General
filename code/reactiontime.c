#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long timelapse(const struct timespec *ta, const struct timespec *tb)
{
	long long tmp = 0, diff = 0;
	if (tb -> tv_sec < ta -> tv_sec || tb -> tv_nsec < ta -> tv_nsec)
		return -1;
	tmp = tb -> tv_nsec - ta -> tv_nsec;
	diff = tmp;
	tmp = tb -> tv_sec - ta -> tv_sec;
	diff += tmp * 1000000000LL;
	return diff;
}

struct coord {
	int x;
	int y;
};

int main()
{
	struct coord pos = {10, 10};
	struct timespec tstart, tend;
	int waittime;
	long long retime;
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	waittime = rand() % 5000;
	mvprintw(pos.y, pos.x,"Wait for Next Line...");
	refresh();
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	++pos.y;
	sleep(waittime / 5000 + 3);
	mvprintw(pos.y, pos.x,"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	refresh();
	getch();
	clock_gettime(CLOCK_MONOTONIC, &tend);
	retime = timelapse(&tstart, &tend);
	++pos.y;
	mvprintw(pos.y, pos.x, "REACTION TIME: %lldms", retime / 1000000LL - 3000);
	refresh();
	getch();
	endwin();
	return 0;
}

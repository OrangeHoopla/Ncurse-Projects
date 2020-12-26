#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <string>
#include <iostream> 

int count(int mm);

int main(void){	
	initscr();			/* Start curses mode 		  */
	//printw("Hello World !!!");	/* Print Hello World		  */
	refresh(); //forces update


	//std::thread t1(count,3);
	//sleep(2);
	//printw("you sicko");
	refresh();			/* Print it on to the real screen */

	int x,y;
	x = 0;
	y = 0;
	char move;
	while(1)
	{
		move = getch();
		if(move == 's')
		{
			x++;
		}
		if(move == 'w')
		{
			x--;
		}
		if(move == 'a')
		{
			y--;
		}
		if(move == 'd')
		{
			y++;
		}
		if(move == 'q'){
			break;
		}

		mvaddch(x, y, 'C');
		refresh();

	}





	getch();			/* Wait for user input */
	//t1.join();
	endwin();			/* End curses mode		  */
	return 0;

	
}


int count(int mm)
{
	mvaddch(5, 5, 'C');
	refresh();
	return 3;

}
#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <string>
#include <iostream> 

int count(int mm);



char dot_placement_map[50][50] = {
{"+------------++------------+"},
{"|............||............|"},
{"|.+--+.+---+.||.+---+.+--+.|"},
{"|*|  |.|   |.||.|   |.|  |*|"},
{"|.+--+.+---+.++.+---+.+--+.|"},
{"|..........................|"},
{"|.+--+.++.+------+.++.+--+.|"},
{"|.+--+.||.+--++--+.||.+--+.|"},
{"|......||....||....||......|"},
{"+----+.|+--+ || +--+|.+----+"},
{"     |.|+--+ ++ +--+|.|     "},
{"     |.||          ||.|     "},
{"     |.|| +--__--+ ||.|     "},
{"-----+.++ |      | ++.+-----"},
{"      .   |      |   .      "},
{"-----+.++ |      | ++.+-----"},
{"     |.|| +------+ ||.|     "},
{"     |.||          ||.|     "},
{"     |.|| +------+ ||.|     "},
{"+----+.++ +--++--+ ++.+----+"},
{"|............||............|"},
{"|.+--+.+---+.||.+---+.+--+.|"},
{"|.+-+|.+---+.++.+---+.|+-+.|"},
{"|*..||.......  .......||..*|"},
{"+-+.||.++.+------+.++.||.+-+"},
{"+-+.++.||.+--++--+.||.++.+-+"},
{"|......||....||....||......|"},
{"|.+----++--+.||.+--++----+.|"},
{"|.+--------+.++.+--------+.|"},
{"|..........................|"},
{"+--------------------------+"},
};















int main(void){	
	initscr();			/* Start curses mode 		  */
	curs_set(0); // invisiable cursor
	//printw("Hello World !!!");	/* Print Hello World		  */
	refresh(); //forces update


	//std::thread t1(count,3);
	//sleep(2);
	//printw("you sicko");
	refresh();			/* Print it on to the real screen */

	int x,y;
	x = 1;
	y = 2;
	
	int len = sizeof(dot_placement_map)/sizeof(dot_placement_map[0]);


	//prints screen
	for(int i = 0 ; i < len; i++)
	{
		mvaddch(i, 0, ' ');
		printw(dot_placement_map[i]);
	}



	char move;
	while(1)
	{
		move = getch();

		if(move == 'w')
		{
			dot_placement_map[x][y]  = ' ';
			x--;
			dot_placement_map[x][y]  = 'C';
			
			
		}

		else if(move == 's')
		{
			dot_placement_map[x][y]  = ' ';
			x++;
			dot_placement_map[x][y]  = 'C';
			
		}

		else if(move == 'a')
		{
			dot_placement_map[x][y]  = ' ';
			y--;
			dot_placement_map[x][y]  = 'C';
			
		}

		else if(move == 'd')
		{
			dot_placement_map[x][y]  = ' ';
			y++;
			dot_placement_map[x][y]  = 'C';
			
		}

		else if(move == 'q')
		{
			break;
		}

		clear();

		for(int i = 0 ; i < len; i++)
		{
			mvaddch(i, 0, ' ');
			printw(dot_placement_map[i]);
		}





	}





	
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
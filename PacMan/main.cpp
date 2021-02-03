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
	nodelay(stdscr, TRUE);  // it doesnt wait for input
	refresh(); //forces update


	//std::thread t1(count,3);
	
	//printw("you sicko");
	refresh();			/* Print it on to the real screen */

	int x,y,xi,yi;
	x = 1;
	y = 2;
	
	int len = sizeof(dot_placement_map)/sizeof(dot_placement_map[0]);


	//prints screen
	for(int i = 0 ; i < len; i++)
	{
		mvaddch(i, 0, ' ');
		printw(dot_placement_map[i]);
	}

	xi = 1;
	yi = 2;



	char move = 'd';
	char state;
	std::string possible_moves = "wasdq";
	int score = 0;

	//user loop
	while(1)
	{
		state = getch();
		if (possible_moves.find(state) != std::string::npos)
		{
			move = state;
		}




		if(move == 'w')
		{
			xi--;	
		}

		else if(move == 's')
		{	
			xi++;	
		}

		else if(move == 'a')
		{
			yi--;	
		}

		else if(move == 'd')
		{
			yi++;	
		}

		else if(move == 'q')
		{
			break;
		}

		//checking next spot and updating map
		if(dot_placement_map[xi][yi] == ' ' || dot_placement_map[xi][yi] == '.' || dot_placement_map[xi][yi] == '*')
		{
			if(dot_placement_map[xi][yi] == '.' || dot_placement_map[xi][yi] == '*')
			{
				score++;
			}
			dot_placement_map[x][y]  = ' ';
			x = xi;
			y = yi;
			dot_placement_map[x][y]  = 'C';
			

			

		}
		xi = x;
		yi = y;

		usleep(300000); // time between moves



		//updating screen
		clear();
		for(int i = 0 ; i < len; i++)
		{
			mvaddch(i, 0, ' ');
			printw(dot_placement_map[i]);
		}

		std::string demo = "Score: " + std::to_string(score);
		printw(demo.data());





	} // end of user loop





	
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
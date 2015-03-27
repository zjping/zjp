// Filename: guess number.cpp
// achievement: design a guess number game can calculate the results of the game
// Username: zhangjianping
//Date: 2015/3/25

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
	int guess_numbers[3], correct_numbers[3], game_times, win_times, A, B, i, j, k, h; //h, i and k represent the three times, and j represents seven opportunities
	char flag;//flag represents whether user will play this game. 
	A = 0, B = 0, game_times = 0, win_times = 0;
	
	cout << "Do you want to play game(Y/N)?";
	cin >> flag;
	cout << endl;
	
	while (flag == 'Y')
	{
		srand(time(NULL));
		
		for (h=0; h<3; ++h)
		{
			correct_numbers[h] = rand() * 10 / (RAND_MAX + 1);
		}
		while(correct_numbers[1] == correct_numbers[0])
				{
					correct_numbers[1] = rand() * 10 / (RAND_MAX + 1);
				}
		while(correct_numbers[2] == correct_numbers[1] || correct_numbers[2] == correct_numbers[0])
				{
					correct_numbers[2] = rand() * 10 / (RAND_MAX + 1);
				}
				
		for (j=0; j<7; ++j)
		{
			cout << "Please enter your guess number";
		    for (i=0; i<3; ++i)
		    {
			    cin >> guess_numbers[i];
		    }
		    for (i=0; i<3; ++i)
		    {
		    	for (k=0; k<3; ++k)
		    	{
		    		if (guess_numbers[i] == correct_numbers[k] && i == k)
		    		{
		    			A += 1;
					}
					else if (guess_numbers[i] == correct_numbers[k] && i != k)
					{
						B += 1;
					}
				    if (A == 3)
				    {
				    	cout << "Congratulation, you guess right!" << endl;
				    	win_times += 1;
				    	goto l;
					}
				}
				k=0;
		    }
			cout << A << "A" << B << "B" << endl;
					A = 0;
					B = 0;
		}
		
		
		cout << "Sorry! you don not finish in the regulate time" << endl;
		l:game_times += 1;
		A=0;
		cout << "the correct numbers are";
		for(i=0; i<3; ++i)
		{
			cout << correct_numbers[i];
			cout << endl;
		}
		cout << "Do you want to play game(Y/N)?";
	    cin >> flag;
	    cout << endl;
	}
	cout << "You play" << game_times << "times win" << win_times << "times lose" << game_times-win_times << "times" << endl;
	return 0;
}

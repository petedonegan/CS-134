#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	using namespace std;

	srand(time(NULL));
	int round = 1;
	int playerHP[4] = {100, 100, 100, 100};
	bool done = false;
	int randNumber = rand() % 1;
	

	while (!done)
	{
		cout << "---------------------------" << endl;
		cout << "ROUND " << round << endl;
		// Displaying Hit Points
		for (int i = 0; i < 4; i++ )
		{
			cout << "Player " << i;
				if (i == 0)
					cout << " (YOU!) ";
				else
					cout << " (NPC)  ";
			cout << "   HP: " << playerHP[i] << endl;
		}
		
		// Declaring Attackers 
		cout << endl << "Who do you want to attack? ";
		int attackWho;
		cin >> attackWho;
		cout << endl << "Player " << attackWho << " hit for 5 damage" << endl;
		playerHP[attackWho] = playerHP[attackWho] - 5;
		for (int i = 1; i < 4; i++)
		{
			attackWho = rand() % 4;
			cout << "Player " << i << " attacks player " << attackWho << " for 5 damage" << endl;
			playerHP[attackWho] = playerHP[attackWho] - 5;
		}
		round++;
		// Checking for Victory or Defeat
		if (playerHP[0] <= 0)
		{
			cout << endl << "YOU LOSE";
			done = true;
		}
		if (playerHP[1] <= 0 && playerHP[2] <= 0 && playerHP[3] <= 0)
		{
			cout << endl << "YOU WIN!";
			done = true;
		}
	}
	return 0;
}
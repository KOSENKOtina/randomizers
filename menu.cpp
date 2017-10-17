#include "rands.h"


int main() {
	cout << "Hello! It's Valia's Kosenko first lab work of the second year" << endl;
	int choice = 0;
	cout << " to choose randomizing method press key 1-10" << endl;

	while(!cin.fail()){
	cin >> choice;
	if (!cin.fail()) {
		switch (choice) {
		case 1: cout << "randomizer1" << endl;
			plot_gisto((*rand_1));
			break;
		case 2: cout << "randomizer2" << endl;
			plot_gisto((*rand_2));
			break;
		case 3: cout << "randomizer3" << endl;
			plot_gisto((*rand_3));
			break;
		case 4: cout << "randomizer4" << endl;
			plot_gisto((*rand_4));
			break;
		case 5: cout << "randomizer5" << endl;
			plot_gisto((*rand_5));
			break;
		case 6: cout << "randomizer6" << endl;
			plot_gisto3((*rand_6));
			break;
		case 7: cout << "randomizer7" << endl;
			plot_gisto3((*rand_7));
			break;
		case 8: cout << "randomizer8" << endl;
			plot_gisto3((*rand_8));
			break;
		case 9: cout << "randomizer9" << endl;
			plot_gisto100((*rand_9));
			break;
		case 10: cout << "randomizer10" << endl;
			plot_gisto100((*rand_10));
			break;
		default: cout << " wrong input, try valid number" << endl;
		}
	}
	else
	{
		system("pause"); return 0;
	}
	}

	/*for (int i = 0; i < 50; ++i)
		cout<< rand_6()<<endl; */
	system("pause");
	return 0;
}
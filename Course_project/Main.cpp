#include"Set.h" 
//#include<boost/algorithm/algorithm.hpp>

int main()
{
	do
	{
		int iSelect; // var for selection
		cout << " With what Container you want to Work ?" << endl << endl;  // menu to select the operatiom
		cout << "  (1)___Work with Container Writter" << endl << endl;
		cout << "  (2)___Work with Container Composition" << endl << endl;
		cout << "  (3)___Exit " << endl << endl;
		cout << endl;
		cout << " Select Container ";
		cin >> iSelect; // input choise
		while(!cin)
		{
			cout << endl << " Error! Input Digit!" << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
			cin >> iSelect; // input choise
		}
		cout << endl;
		while (iSelect != 0)
		{
			switch (iSelect)
			{
			case 1: // Call the function to work with container Writter
			{
				WorkWithWritter();
			};
			break;
			case 2 :// Call the function to work with container Composition 
			{
				WorkWithComposition(); 
			}
			break;
			case 3: // Exit from tool
			{
				return 0;
			};
			break;
			default:cout << "This option is Absent !" << endl;
			}
			cout << endl;
			cout << "Chose Container ";
			
			cin >> iSelect;
			cout << endl;
		}
	} while (true); 

	system("pause");
	return 0;
}


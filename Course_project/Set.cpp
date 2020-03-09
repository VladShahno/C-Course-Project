#include"Set.h"
#include<limits>
									/* Functions for work with std::set<> for class	 CWritter and class CComposition  */

												/* set<CWritter, CWritter::test_less> */

// Write object to container set<CWritter, CWritter::test_less>
void WriteContainerWritter(set<CWritter, CWritter::test_less>&Ar)
{
	ofstream fout("Writter.txt"); // Var for stream
	copy(Ar.begin(), Ar.end(), ostream_iterator<CWritter>(fout, "\n")); // Streaming iterative record
}

// Read object from file to container set<CWritter, CWritter::test_less>
void ReadContainerWritter(set<CWritter, CWritter::test_less>&Ar)
{
	fstream fin("Writter.txt");
	for (istream_iterator<CWritter> it(fin); it != istream_iterator<CWritter>(); ++it)
	{
		const CWritter &val = *it;
		Ar.insert(val);
	}
	if (!Ar.empty())
		cout << " The Data successfully read from the file" << endl;
	else
	{
		cout << " No Data to read!" << endl;
	}
}

// Show container set<CWritter, CWritter::test_less> contents to console
void ShowContainerWritter(set<CWritter, CWritter::test_less>&Ar)
{
	if (Ar.empty())
	{
		cout << " Container is empty!" << endl;
	}
	else
	{
		cout << " Show Container Writter" << endl;
		for (auto &item : Ar)
		{
			cout << item << endl;
		}
	}
}

// Add to container set<CWritter, CWritter::test_less> contents 
void AddToContainerWritter(set<CWritter, CWritter::test_less>&Ar)
{
	cout << " Input the members of class Writter" << endl;  
	cout << " Input ID - "; 
	int g_iID;
	cin >> g_iID;
	while (!cin)
	{
			cout << endl << " Error! Input Digit!" << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
			cin >> g_iID;
	}
	cout << " Input First Name - ";
	string g_strFirstName;
	cin >> g_strFirstName;
	cout << " Input Last Name -  ";
	string g_strLastName;
	cin >> g_strLastName;
	cout << " Input Middle Name - ";
	string g_strMiddleName;
	cin >> g_strMiddleName;
	cout << " Input Sex - ";
	char g_chSex;
	cin >> g_chSex;
	if(g_chSex=='W'||g_chSex=='M')
	cout << " Input the Day of Birth - ";
	int g_iDay;
	cin >> g_iDay;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Day!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iDay; // input date
	}
	cout << " Input the Month of Birth - ";
	int g_iMonth;
	cin >> g_iMonth;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Month!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iMonth; // input date
	}
	cout << " Input the Year of Birth - ";
	int g_iYear;
	cin >> g_iYear;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Year!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iYear; // input date
	}
	cout << " Input Country - ";
	string g_strCountry;
	cin >> g_strCountry;
	cout << " Input Place of Birth - ";
	string g_strPlaceBirth;
	cin >> g_strPlaceBirth;
	cout << " Input Genre - ";
	string g_strGenre;
	cin >> g_strGenre;
	cout << " Input Famous Work - ";
	string g_strFamousWork;
	cin >> g_strFamousWork;
	Ar.insert(CWritter(g_iID, g_strFirstName.c_str(), g_strLastName.c_str(), g_strMiddleName.c_str(), g_chSex, g_iDay, g_iMonth, g_iYear,
		g_strCountry.c_str(), g_strPlaceBirth.c_str(), g_strGenre.c_str(), g_strFamousWork.c_str()));
	cout << " The Data is successfully added" << endl;
}
	
//Edit Container set<CWritter, CWritter::test_less>
void EditContainerWritter(set < CWritter, CWritter::test_less> &Arr)
{
	int iRecord;
	char chrYN;
	cout << " What ID Number you want to find and edit -" << endl;  // Визначити  елемент екземпляру класу Vehicle
	cin >> iRecord;
	auto it = Arr.find(iRecord);
	if (it != Arr.end())
	{
		auto obj = *it;
		obj.getFirstName();
		cout << " Edit First Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input First Name - ";
			string g_strFirstName;
			cin >> g_strFirstName;
			obj.setFirstName(g_strFirstName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getLastName();
		cout << "Edit Last Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Last Name  - ";
			string g_strLastName;
			cin >> g_strLastName;
			obj.setLastName(g_strLastName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getMiddleName();
		cout << " Edit Middle Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Middle Name -  ";
			string g_strMiddleName;
			cin >> g_strMiddleName;
			obj.setMiddleName(g_strMiddleName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getSex();
		cout << " Edit Sex (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Sex - ";
			char g_chSex;
			cin >> g_chSex;
			obj.setSex(g_chSex);
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getDateBirth();
		cout << " Edit the Date of Birth (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{

			cout << " Input the Date of Birth (D, M, Y) - ";
			int iDay, iMonth, iYear;
			cout << " Input the Day of Birth" << endl;
			cin >> iDay;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Day!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iDay; // input date
			}
			cout << " Input the Month of Birth" << endl;
			cin >> iMonth;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Month!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iMonth; // input date
			}
			cout << " Inout the Year of Birth" << endl;
			cin >> iYear;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Year!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iYear; // input date
			}
			obj.setDateBirth(iDay, iMonth, iYear);
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
		}
		obj.getCountry();
		cout << " Edit Country (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Country - ";
			string g_strCountry;
			cin >> g_strCountry;
			obj.setCountry(g_strCountry.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getPlaceBirth();
		cout << " Edit the Place of Birth (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input the Place of Birth - ";
			string g_strPlaceBirth;
			cin >> g_strPlaceBirth;
			obj.setPlaceBirth(g_strPlaceBirth.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getGenre();
		cout << " Edit Genre (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Genre - ";
			string g_strGenre;
			cin >> g_strGenre;
			obj.setGenre(g_strGenre.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getFamousWork();
		cout << " Edit the Famous Work (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input the Famous Work - ";
			string g_strFamousWork;
			cin >> g_strFamousWork;
			obj.setFamousWork(g_strFamousWork.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		Arr.erase(it);
		Arr.insert(obj);
	}
	else
	{
		cout << " ID Number - " << iRecord << " is Missing!" << endl;
	}
}

												/* set<CComposition, CComposition::test_less> */

// Write object to container set<CComposition, CComposition::test_less>
void WriteContainerComposition(set<CComposition, CComposition::test_less>&Ar)
{
	ofstream fout("Composition.txt"); // Var for stream
	copy(Ar.begin(), Ar.end(), ostream_iterator<CComposition>(fout, "\n")); // Streaming iterative record 
}

// Read object from file to container set<CComposition, CComposition::test_less>
void ReadContainerComposition(set<CComposition, CComposition::test_less>&Ar)
{
	fstream fin("Composition.txt");
	for (istream_iterator<CComposition> it(fin); it != istream_iterator<CComposition>(); ++it)
	{
		const CComposition &val = *it;
		Ar.insert(val);
	}
	if (!Ar.empty())
		cout << " The Data successfully read from the file" << endl;
	else
	{
		cout << " No Data to read!" << endl;
	}
}

// Show container set<CComposition, CComposition::test_less> contents to console
void ShowContainerComposition(set<CComposition, CComposition::test_less>&Ar)
{
	if (Ar.empty())
	{
		cout << " Container is empty!" << endl;
	}
	else
	{
		cout << " Show Container Composition" << endl;
		for (auto &item : Ar)
		{
			cout << item << endl;
		}
	}
}

// Add to container set<CComposition, CComposition::test_less> contents
void AddToContainerComposition(set<CComposition, CComposition::test_less>&Ar)
{
	cout << " Input the members of class Writter" << endl;  
	cout << " Input ID - "; 
		int g_iID;
	cin >> g_iID;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of ID Number!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iID; // input ID
	}
	cout << " Input the Work Title - ";
		string g_strWorkTitle;
	cin >> g_strWorkTitle;
	cout << " Input the Creation Year - ";
		int g_iCreationYear;
	cin >> g_iCreationYear;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of the Year!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iCreationYear; // input date
	}
	cout << " Input Genre - ";
		string g_strGen;
	cin >> g_strGen;
	cout << " Input the Original Language - ";
		string g_strOrigLanguage;
	cin >> g_strOrigLanguage;
	cout << " Input First Name - ";
		string g_strFirstName;
	cin >> g_strFirstName;
	cout << " Input Last Name -  ";
		string g_strLastName;
	cin >> g_strLastName;
	cout << " Input Middle Name - ";
		string g_strMiddleName;
	cin >> g_strMiddleName;
	cout << " Input Sex - ";
		char g_chSex;
	cin >> g_chSex;
	cout << " Input the Day of Birth - ";
		int g_iDay;
	cin >> g_iDay;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Day!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iDay; // input date
	}
	cout << " Input the Month of Birth - ";
		int g_iMonth;
	cin >> g_iMonth;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Month!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iMonth; // input date
	}
	cout << " Input the Year of Birth - ";
		int g_iYear;
	cin >> g_iYear;
	while (!cin)
	{
		cout << endl << " Error! Input Correct Digit of Year!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> g_iYear; // input date
	}

	Ar.insert(CComposition(g_iID, g_strWorkTitle.c_str(), g_iCreationYear, g_strGen.c_str(),
		g_strOrigLanguage.c_str(), g_strFirstName.c_str(), g_strLastName.c_str(),
		g_strMiddleName.c_str(), g_chSex, g_iDay, g_iMonth, g_iYear));
}

// Edit Container set < CComposition, CComposition::test_less>
void EditContainerComposition(set < CComposition, CComposition::test_less> &Arr)
{
	int iRecord;
	char chrYN;
	cout << " What ID Number you want to find and edit -" << endl;  // Визначити  елемент екземпляру класу Vehicle
	cin >> iRecord;
	auto it = Arr.find(iRecord);
	if (it != Arr.end())
	{
		auto obj = *it;
		obj.getWorkTitle();
		cout << " Edit the Work Titile (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input the Work Title - ";
			string strWorkTitle;
			cin >> strWorkTitle;
			obj.setWorkTitle(strWorkTitle.c_str());
		}
		else
		{
			cout << endl<< " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getCreationYear();
		cout << " Edit the Creation Year (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input the Creation Year - ";
			int iCreationYear;
			cin >> iCreationYear;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Year!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iCreationYear; // input date
			}
			obj.setCreationYear(iCreationYear);
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
		}
		obj.getGenre();
		cout << " Edit Genre (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Genre - ";
			string strGenre;
			cin >> strGenre;
			obj.setGenre(strGenre.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getOrigLanguage();
		cout << " Edit Original Language (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Original Language - ";
			string  strOriginalLang;
			cin >> strOriginalLang;
			obj.setOrigLanguage(strOriginalLang.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getFirstName();
		cout << " Edit First Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input First Name - ";
			string strFirstName;
			cin >> strFirstName;
			obj.setFirstName(strFirstName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getLastName();
		cout << "Edit Last Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Last Name  - ";
			string strLastName;
			cin >> strLastName;
			obj.setLastName(strLastName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getMiddleName();
		cout << " Edit Middle Name (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Middle Name -  ";
			string strMiddleName;
			cin >> strMiddleName;
			obj.setMiddleName(strMiddleName.c_str());
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
			cin.clear(); // Remove the error flag. Now the thread state is again good
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		}
		obj.getSex();
		cout << " Edit Sex (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Input Sex - ";
			char g_chSex;
			cin >> g_chSex;
			obj.setSex(g_chSex);
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
		}
		obj.getDateBirth();
		cout << " Edit the Date of Birth (Y/N)?  -  ";
		cin >> chrYN;
		if (chrYN == 'Y' || chrYN == 'y')
		{
			cout << " Please Input the Date of Birth (D, M, Y) " << endl;
			int iDay,iMonth,iYear;
			cout << " Input the Day of Birth" << endl;
			cin >> iDay;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Day!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iDay; // input date
			}
			cout << " Input the Month of Birth" << endl;
			cin >> iMonth;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Month!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iMonth; // input date
			}
			cout << " Inout the Year of Birth" << endl;
			cin >> iYear;
			while (!cin)
			{
				cout << endl << " Error! Input Correct Digit of Year!" << endl;
				cin.clear(); // Remove the error flag. Now the thread state is again good
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
				cin >> iYear; // input date
			}
			obj.setDateBirth(iDay, iMonth, iYear);
		}
		else
		{
			cout << endl << " The Data not changed!" << endl << endl;
		}
		Arr.erase(it);
		Arr.insert(obj);
		cout << " The data if changed " << endl;
	}
	else
	{
		cout << " ID Number - " << iRecord << " is Missing!" << endl;
	}
}

mutex mtx; // Mutex obj
// Print char for mutex
void Print(char ch)
{
	lock_guard<mutex> lock(mtx); // Lock this mutex for synchronization
	for (int i = 0; i < 60; i++)
	{
		cout << ch; // Print symbol
		this_thread::sleep_for(chrono::milliseconds(10)); // Work emulation, thread 
	}
}

// Call function for work with Container Writter
int WorkWithWritter()
{
	typedef set<CWritter, CWritter::test_less> Writter; // Rename of type 
	Writter Persona; // New name of cotainer set - Writter

	// Work with thread, perfomance evaluation when using multithreading
	{
		CTimer time; cout << endl;
		
		thread t1(Print, '*');
		thread t2(Print, '#');
		t1.join();
		t2.join();
	}

	int iSelect;
	cout << endl;
	cout << " Chose the Item from Menu of Container Writter" << endl;
	cout << "  Menu :" << endl;
	cout << "  (0)___Choose another Container " << endl;
	cout << "  (1)___Clear Set<> " << endl;
	cout << "  (2)___Add to Set<> " << endl;
	cout << "  (3)___Show Set<>" << endl;
	cout << "  (4)___Edit Set<> [i] " << endl;
	cout << "  (5)___Exit and Save" << endl;
	cout << "  (6)___Read from file to Set<> " << endl;
	cout << endl;
	cout << " Select Item ";
	cin >> iSelect;
	while(!cin)
	{
		cout << endl << " Error! Input Digit!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> iSelect;
	}
	cout << endl;
	while (iSelect != 0)
	{
		switch (iSelect)
		{
		case 1: // Clear container
		{
			Persona.clear();
			if (Persona.empty())
				cout << " Container is Clear" << endl;
			else
			{
				cout << " Error!" << endl;
			}
		};
		break;
		case 2: // Add contents to container 
		{
			AddToContainerWritter(Persona);
		};
		break;
		case 3:// Show container to console 
		{
			ShowContainerWritter(Persona);
		};
		break;
		case 4: // Edit container contents
		{
			EditContainerWritter(Persona);
		};
		break;
		case 5: // Write container contents to .txt file
		{
			WriteContainerWritter(Persona);
			return 0;
		};
		break;
		case 6: // Read file contents to container
		{
			ReadContainerWritter(Persona);
		};
		break;
		default:cout << "You chose nothing !" << endl; 
		}
		cout << endl;
		cout << "Choose Item ";
		cin >> iSelect;
		cout << endl;
	}
}

// Call function for work with Container Composition
int WorkWithComposition()
{
	typedef set<CComposition, CComposition::test_less> Composition;
	Composition Work;

	{
		CTimer time; cout << endl;

		thread t1(Print, '*');
		thread t2(Print, '#');
		t1.join();
		t2.join();
	}

	int iSelect;
	cout << endl;
	cout << " Chose the Item from Menu of Container Composition" << endl;
	cout << "  Menu :" << endl;
	cout << "  (0)___Choose another Container " << endl;
	cout << "  (1)___Clear Set<> " << endl;
	cout << "  (2)___Add to Set<> " << endl;
	cout << "  (3)___Show Set<>" << endl;
	cout << "  (4)___Edit Set<> [i] " << endl;
	cout << "  (5)___Exit and Save" << endl;
	cout << "  (6)___Read from file to Set<> " << endl;
	cout << endl;
	cout << " Select Item ";
	cin >> iSelect;
	while (!cin)
	{
		cout << endl << " Error! Input Digit!" << endl;
		cin.clear(); // Remove the error flag. Now the thread state is again good
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Release all that entered the user to the end of the line
		cin >> iSelect;
	}
	cout << endl;

	while (iSelect != 0)
	{
		switch (iSelect)
		{
		case 1: // Clear container
		{
			Work.clear();
			if (Work.empty())
				cout << " Container is Clear" << endl;
			else
			{
				cout << " Error!" << endl;
			}
		};
		break;
		case 2: // Add contents to container 
		{
			AddToContainerComposition(Work);
		};
		break;
		case 3: // Show container to console 
		{
			ShowContainerComposition(Work);
		};
		break;
		case 4: // Edit container contents
		{
			EditContainerComposition(Work);
		};
		break;
		case 5: // Write container contents to .txt file
		{
			WriteContainerComposition(Work);
			return 0;
		};
		break; 
		case 6: // Read file contents to container
		{
			ReadContainerComposition(Work);
		};
		break;
		default:cout << "You chose nothing !" << endl;
		}
		cout << endl;
		cout << "Choose Item ";
		cin >> iSelect;
		cout << endl;
	}
}
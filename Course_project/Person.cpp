#include"Person.h"

														/*		Basic Class  CPerson		*/

													/* Constructor's */

// Default constructor
CPerson::CPerson()
{
	//cout << "Default constructor class CPerson is run" << endl;  
}

// Constructor with parameters
CPerson::CPerson(int ID, const char*FirstName, const char*LastName, const char*MiddleName,  char Sex, int Day, int Month, int Year)
{
	setID(ID);
	setPerson(FirstName, LastName, MiddleName);
	setSex(Sex);
	setDateBirth(Day, Month, Year);
	//cout << "Constructor with Parameters Class CPerson is run" << endl;
}

// Copy constructor
CPerson::CPerson(const CPerson&Other):m_iID(Other.m_iID),m_strFirstName(Other.m_strFirstName),m_strLastName(Other.m_strLastName),
				 m_strMiddleName(Other.m_strMiddleName),m_chSex(Other.m_chSex),m_iDay(Other.m_iDay),m_iMonth(Other.m_iMonth),m_iYear(Other.m_iYear) 
{
	//cout << "Copy constructor class CPerson is run" << endl;
}

// Destructor
CPerson::~CPerson()
{
	//cout << "Destructor class CPerson is run" << endl;
}

// Operator =
CPerson &CPerson::operator=(const CPerson&Other)
{
	//cout << "Operator = class CPerson is run" << endl;
	this->m_iID = Other.m_iID;
	this->m_strFirstName = Other.m_strFirstName;
	this->m_strLastName = Other.m_strLastName;
	this->m_strMiddleName = Other.m_strMiddleName;
	this->m_chSex = Other.m_chSex;
	this->m_iDay = Other.m_iDay;
	this->m_iMonth = Other.m_iMonth;
	this->m_iYear = Other.m_iYear;
	return *this;
}

												/* Methods */

// Show the object to console
void CPerson:: ShowAll()	
{	
	cout << " Show from class CPerson" << endl;
	cout<< " ID Number - " << getID() << endl
		<< " First Name - " << getFirstName() << endl
		<< " Last Name - " << getLastName() << endl
		<< " Middle Name - " << getMiddleName() << endl
		<< " Sex - " << getSex() << endl
		<< " Date of Birth (D.M.Y) - " << getDateBirth()<< endl <<endl;
}

												/* Seters */

// set FirstName, LastNAme, MiddleName
void CPerson::setPerson(const char*FirstName, const char*LastName, const char*MiddleName)
{
	bool b = isValidPerson(FirstName, LastName, MiddleName);
	try
	{
		if (b)
		{
			setFirstName(FirstName);     // Writting members to object
			setLastName(LastName);
			setMiddleName(MiddleName);
		}
		else  
			throw b;				// catch the exception
	}

	catch (bool b)					// catch the exception
	{
		cout << "Not valid all Name! " << FirstName << " " << LastName << " " << MiddleName << endl;
	}
}

// set FirstName
void CPerson:: setFirstName(const char*FirstName) 
{
	bool b = isValidName(FirstName);
	try
	{
		if (b) this->m_strFirstName = FirstName;	
		else  
			throw b;					
	}
	catch (bool b)						 
	{
		cout << "Not valid First Name!" << FirstName << endl;
	}
}

// set LastName
void CPerson:: setLastName(const char*LastName)
{
	bool b = isValidName(LastName);
	try
	{
		if (b) this->m_strLastName = LastName;	
		else  
			throw b;					
	}
	catch (bool b)	{
		cout << "Not valid First Last Name!" << LastName << endl;
	}
}

// set MiddleName
void CPerson::setMiddleName(const char*MiddleName)
{
	bool b = isValidName(MiddleName);
	try
	{
		if (b) this->m_strMiddleName = MiddleName;	
		else  
			throw b;					
	}
	catch (bool b)						  
	{
		cout << "Not valid Middle Name!" << MiddleName << endl;
	}
}

// set Sex
void CPerson:: setSex(char Sex)
{
	bool b = isValidSex(Sex);
	try
	{
		if (b)  	this->m_chSex = Sex;   	
		else  
			throw b;					
	}
	catch (bool b)						
	{
		cout << "Not valid Sex! " << Sex << endl;
	}
}

// set Day, Month, Year of birth
void CPerson:: setDateBirth(int Day, int Month, int Year)
{
	bool b = isValidDateBirth(Day,Month,Year);
	try
	{
		if (b)
		{
			this->m_iDay = Day;
			this->m_iMonth = Month;
			this->m_iYear = Year;
		}
		else  throw b;				
	}

	catch (bool b)					
	{
		cout << "Not valid Date of Bith! " << Day << " " << Month << " " << Year << endl;
	}

}

// set ID
void CPerson:: setID(int ID)
{
	m_iID = ID;
}

												/* Geters */

// get FirstName, LastNAme, MiddleName
string CPerson:: getPerson()
{
	return m_strFirstName + " " + m_strLastName + " " + m_strMiddleName;
}

// get FirstName
string CPerson:: getFirstName()
{
	return m_strFirstName;
}

// get LastName
string CPerson:: getLastName()
{
	return m_strLastName;
}

// get MiddleName
string CPerson:: getMiddleName()
{
	return m_strMiddleName;
}

// get Sex
char CPerson:: getSex()
{
	return m_chSex;
}

// get Day, Month, Year of birth
int CPerson:: getDateBirth()
{
	return m_iDay + m_iMonth + m_iYear;
}

// get ID
int CPerson:: getID() const
{
	return m_iID;
}

												/* Verification methods */

// Check the correctness of First, Last and Middle Name
bool CPerson:: isValidPerson(const char*FirstName, const char*LastName, const char*MiddleName)
{
	return isValidName(FirstName) & isValidName(LastName)  & isValidName(MiddleName);
}

// Check the correctness of one of the F, L, M Names
bool CPerson::isValidName(const char* word)
{
	
	char simvol = word[0];
	if ( simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;

}

// Check the correctness of Sex
bool CPerson::isValidSex(char Sex)
{
	if (Sex=='M'|| Sex=='W') 
		return true;
	else 
		return false;
}

// Check the correctness of Day, Month and Year of Birth
bool CPerson::isValidDateBirth(int Day, int Month, int Year)
{
	bool b_isLeap = false;
	bool b_isValidDate = true;
	if (Year % 4 == 0)
	{
		b_isLeap = true;
	}
	if (Day < 1 || Day > 31) 
	{
		b_isValidDate = false;
	}
	if (Month < 1 || Month > 12) 
	{
		b_isValidDate = false;
	}
	if (Month == 2 && Day > 29 && b_isLeap == true)
	{
		b_isValidDate = false;
	}
	if (Month == 2 && Day > 28 && b_isLeap == false)
	{
		b_isValidDate = false;
	}
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) 
	{
		if (Day > 30) 
		{
			b_isValidDate = false;
		}
	}
	if (b_isValidDate == true)
		return true;
	else
		return false;
}


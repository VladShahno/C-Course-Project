#include"Writter.h"
														/* Derived Class CWritter from parent CPerson */

											/* Constructor's */

// Default constructor
CWritter:: CWritter()
{
	//cout << "Default constructor class CWritter is run" << endl;
}

// Constructor with parameters
CWritter:: CWritter(int ID, const char*FirstName, const char*LastName, const char*MiddleName, char Sex, int Day, int Month, int Year,
					const char*Country, const char*PlaceBirth, const char*Gentre, const char*FamousWork)
		  :CPerson(ID, FirstName,LastName,MiddleName, Sex, Day,Month,Year)
{
	setCountry(Country);
	setPlaceBirth(PlaceBirth);
	setGenre(Gentre);
	setFamousWork(FamousWork);
	//cout << "Constructor with Parameters Class CWritter is run" << endl;
}

// Copy constructor
CWritter:: CWritter(const CWritter&Other):CPerson(Other),m_strCountry(Other.m_strCountry),m_strPlaceBirth(Other.m_strPlaceBirth),
					m_strGenre(Other.m_strGenre),m_strFamousWork(Other.m_strFamousWork)
{
	//cout << "Copy constructor class CWritter is run" << endl;
}

// Destructor
CWritter:: ~CWritter()
{
	//cout << "Destructor class CWritter is run" << endl;
}

											/*Overload Operators */

// Overload operator =
CWritter&CWritter:: operator=(const CWritter&Other)
{
	CPerson::operator=(Other);
	this->m_strCountry = Other.m_strCountry;
	this->m_strPlaceBirth = Other.m_strPlaceBirth;
	this->m_strGenre = Other.m_strGenre;
	this->m_strFamousWork = Other.m_strFamousWork;
	cout << endl;
	//cout << "Operator = class CWritter is run" << endl;
	return *this;
}

// Overload operator <
bool  operator< (const CWritter &t1, const CWritter &t2)
{
	return t1.getID() < t2.getID(); //  if t1 less then t2 - true
}

// Overload operator <<
 ostream& operator<<(ostream& os, const CWritter& Obj)
{
	return os << "\n" << Obj.m_iID << "\n" << Obj.m_strFirstName << "\n"
		<< Obj.m_strLastName << "\n" << Obj.m_strMiddleName << "\n"
		<< Obj.m_chSex << "\n" << Obj.m_iDay << "\n" << Obj.m_iMonth << "\n"
		<< Obj.m_iYear << "\n" << Obj.m_strCountry << "\n" << Obj.m_strPlaceBirth << "\n"
		<< Obj.m_strGenre << "\n" << Obj.m_strFamousWork;
}

 // Overload operator >>
  istream& operator>>(istream& is, CWritter& Obj)
 {
	 return is >> Obj.m_iID >> Obj.m_strFirstName >> Obj.m_strLastName >> Obj.m_strMiddleName
		 >> Obj.m_chSex >> Obj.m_iDay >> Obj.m_iMonth
		 >> Obj.m_iYear >> Obj.m_strCountry >> Obj.m_strPlaceBirth
		 >> Obj.m_strGenre >> Obj.m_strFamousWork;
 }

												/* Methods */

  // Show the object to console
  void CWritter::ShowAll()
{
	cout<< " Show from class CWritter" << endl;
	cout<< " ID Number - " << getID() << endl
		<< " First Name - " << getFirstName() << endl
		<< " Last Name - " << getLastName() << endl
		<< " Middle Name - " << getMiddleName() << endl
		<< " Sex - " << getSex() << endl
		<< " Date of Birth (D.M.Y) - " << getDateBirth() << endl << endl
		<< " Country - " << getCountry() << endl
		<< " Place Of Birth - " << getPlaceBirth() << endl
		<< " Genre - " << getGenre() << endl
		<< " Famous Work - " << getFamousWork() << endl <<endl;
}

												/* Seters */

// set Country
void CWritter::setCountry(const char*Country)
{
	bool b = isValidCountry(Country, Country);
	try
	{
		if (b)  	this->m_strCountry = Country;
		else  
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid Country! " << Country << endl;
	}
}

// set Place of Birth
void CWritter:: setPlaceBirth(const char*PlaceBirth)
{
	bool b = isValidPlaceBirth(PlaceBirth, PlaceBirth);
	try
	{
		if (b)  	this->m_strPlaceBirth = PlaceBirth;
		else  
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid Place Of Birth! " << PlaceBirth << endl;
	}
}

// set Genre
void CWritter::setGenre(const char*Genre)
{
	bool b = isValidPlaceBirth(Genre, Genre);
	try
	{
		if (b)  	this->m_strGenre = Genre;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid Place Of Genre! " << Genre << endl;
	}
}

// set Famous Work
void CWritter::setFamousWork(const char*FamousWork)
{
	bool b = isValiFamousWork(FamousWork);
	try
	{
		if (b)  	this->m_strFamousWork = FamousWork;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid Place Of Famous Work! " << FamousWork << endl;
	}
}

													/* Geters */

// get Country
string CWritter:: getCountry()
{
	return m_strCountry;
}

// get Place of Birth
string CWritter:: getPlaceBirth()
{
	return m_strPlaceBirth;
}

// get Genre
string CWritter:: getGenre()
{
	return m_strGenre;
}

// get Famous Work
string CWritter:: getFamousWork()
{
	return m_strFamousWork;
}

												/* Verification methods */

// Check the correctness of Country
bool CWritter:: isValidCountry(const char*word, string Country)
{
	char simvol = word[0];
	if (Country.length() <= 56 && simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;
}

// Check the correctness of Place of Birth
bool CWritter:: isValidPlaceBirth(const char*word,string PlaceBirth)
{
	char simvol = word[0];
	if (PlaceBirth.length() <= 60 && simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;
}

// Check the correctness of Genre
bool CWritter:: isValidGenre(const char*word, string Genre)
{
	char simvol = word[0];
	if (Genre.length() <= 25 && simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;
}

// Check the correctness of Famous Work
bool CWritter:: isValiFamousWork(const char*word)
{
	char simvol = word[0];
	if ( simvol >= 65 && simvol <= 90 || simvol >= 48 && simvol <= 57)
		return true;
	else
		return false;
}
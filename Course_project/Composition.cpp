#include"Composition.h"
											/* Derived Class CComposition from parent CPerson */

											/* Constructor's */

// Default constructor
CComposition::CComposition()
{
	//cout << "Default constructor class CComposition is run" << endl;
}

// Constructor with parameters
CComposition::CComposition(int ID, const char*WorkTitle, int CreationYear, const char* Genre, const char*OrigLanguage,
	const char*Name, const char*LastName, const char*MiddleName, char Sex, int Day, int Month, int Year)
	:CPerson(ID, Name, LastName, MiddleName, Sex, Day, Month, Year)
{
	setWorkTitle(WorkTitle);
	setCreationYear(CreationYear);
	setGenre(Genre);
	setOrigLanguage(OrigLanguage);
	//cout << "Constructor with Parameters Class CComposition is run" << endl;
}

// Copy constructor
CComposition::CComposition(const CComposition&Other) :CPerson(Other), m_strWorkTitle(Other.m_strWorkTitle),
					m_iCreationYear(Other.m_iCreationYear), m_strGenre(Other.m_strGenre), m_strOrigLanguage(Other.m_strOrigLanguage)
{
	//cout << "Copy constructor class CComposition is run" << endl;
 }

// Destructor
CComposition::~CComposition()
{
	//cout << "Destructor class CComposition is run" << endl;
}

													/*Overload Operators */

// Overload operator =
CComposition&CComposition:: operator=(const CComposition&Other)
{
	CPerson::operator=(Other);
	this->m_strWorkTitle = Other.m_strWorkTitle;
	this->m_iCreationYear = Other.m_iCreationYear;
	this->m_strGenre = Other.m_strGenre;
	this->m_strOrigLanguage = Other.m_strOrigLanguage;
	//cout << "Operator = class CComposition is run" << endl;
	return *this;
}

// Overload operator <
bool operator < (const CComposition &t1, const CComposition &t2)
{
	return t1.getID() < t2.getID(); //  if t1 less then t2 - true
}

// Overload operator <<
ostream& operator<<(ostream& os, const CComposition& Obj)
{
	return os << "\n" << Obj.m_iID << "\n" << Obj.m_strWorkTitle
		<< "\n" << Obj.m_iCreationYear << "\n" << Obj.m_strGenre
		<< "\n" << Obj.m_strOrigLanguage << "\n" << Obj.m_strFirstName << "\n"
		<< Obj.m_strLastName << "\n" << Obj.m_strMiddleName << "\n"
		<< Obj.m_chSex << "\n" << Obj.m_iDay << "\n" << Obj.m_iMonth << "\n" << Obj.m_iYear;
}

// Overload operator >>
istream& operator>>(istream& is, CComposition& Obj)
{
	return is >> Obj.m_iID >> Obj.m_strWorkTitle >> Obj.m_iCreationYear >>
		Obj.m_strGenre >> Obj.m_strOrigLanguage >> Obj.m_strFirstName >>
		Obj.m_strLastName >> Obj.m_strMiddleName >> Obj.m_chSex >> Obj.m_iDay >>
		Obj.m_iMonth >> Obj.m_iYear;
}

														/* Methods */

 // Show the object to console
void CComposition::ShowAll()
{
   cout <<" Show from class CComposition" << endl;
   cout << " ID Number - " << getID() << endl
	    << " The Title of the Work - " << getWorkTitle() << endl
		<< " Genre - " << getGenre() << endl
		<< " The Language of the Original - " << getOrigLanguage() << endl
		<< " Year of Creation - " << getCreationYear() << endl
		<< " Author : " << endl
		<< " First Name - " << getFirstName() << endl
		<< " Last Name - " << getLastName() << endl
		<< " Middle Name - " << getMiddleName() << endl
		<< " Sex - " << getSex() << endl
	   << " Date of Birth (D.M.Y) - " << getDateBirth() << endl << endl;
}

													/* Seters */

// set the Title of the Work
void CComposition:: setWorkTitle(const char*WorkTitle)
{
	bool b = isValidWorkTitle(WorkTitle);
	try
	{
		if (b)  	this->m_strWorkTitle = WorkTitle;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid the Title of the Work! " << WorkTitle << endl;
	}
}

// set the Genre
void CComposition:: setGenre(const char*Genre)
{
	bool b = isValidGenre(Genre,Genre);
	try
	{
		if (b)  	this->m_strGenre = Genre;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid the Genre! " << Genre << endl;
	}
}

// set the Language of the Original
void CComposition:: setOrigLanguage(const char*OrigLanguage)
{
	bool b = isValidOrigLanguage(OrigLanguage,OrigLanguage);
	try
	{
		if (b)  	this->m_strOrigLanguage = OrigLanguage;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid the Language of the Original! " << OrigLanguage << endl;
	}
}

// set the Year of Creation
void CComposition:: setCreationYear(int CreationYear)
{
	bool b = isValidCreationYear(CreationYear);
	try
	{
		if (b)  	this->m_iCreationYear = CreationYear;
		else
			throw b;
	}
	catch (bool b)
	{
		cout << "Not valid the Year of Creation! " << CreationYear << endl;
	}
}

													/* Geters */

// get the Title of the Work
string CComposition:: getWorkTitle()
{
	return m_strWorkTitle;
}

// get the Genre
string CComposition:: getGenre()
{
	return m_strGenre;
}

// get the Language of the Original
string CComposition:: getOrigLanguage()
{
	return m_strOrigLanguage;
}

// get the Year of Creation
int CComposition:: getCreationYear()
{
	return m_iCreationYear;
}

												/* Verification methods */

// Check the correctness of the Title of the Work
bool CComposition::isValidWorkTitle(const char*word)
{
	char simvol = word[0];
	if (simvol >= 65 && simvol <= 90 || simvol >= 48 && simvol <= 57)
		return true;
	else
		return false;
}

// Check the correctness of the Genre
bool CComposition:: isValidGenre(const char*word, string Genre)
{
	char simvol = word[0];
	if (Genre.length() <= 25 && simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;
}

// Check the correctness of the Language of the Original
bool CComposition:: isValidOrigLanguage(const char*word, string OrigLanguage)
{
	char simvol = word[0];
	if (OrigLanguage.length() <= 25 && simvol >= 65 && simvol <= 90)
		return true;
	else
		return false;
}

// Check the correctness of Creation Year
bool CComposition:: isValidCreationYear(int Year)
{
	if (Year <= 2019)
		return true;
	else
		return false;
}

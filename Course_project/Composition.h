#include"Person.h"
#pragma once
														/* Derived Class CComposition from parent CPerson */ 

class CComposition : public CPerson
{
public:
										/* Constructor's */

	// Default constructor
	CComposition();

	// Constructor with parameters
	CComposition(int, const char*, int, const char*, const char*, const char*, const char*, const char*, char, int = 0, int = 0, int = 0);

	// Copy constructor
	CComposition(const CComposition&Other);

	// Destructor
	~CComposition();

										/*Overload Operators */

	// Overload operator =
	CComposition&operator=(const CComposition&Other);

	// Overload operator <
	friend bool operator < (const CComposition &t1, const CComposition &t2);

	// Overload operator <<
	friend ostream& operator<<(ostream& os, const CComposition& Obj);

	// Overload operator >>
	friend istream& operator>>(istream& is, CComposition& Obj);

	// Struct for for comparison with type int set<CComposition, CComposition::test_less>
	struct test_less
	{
		using is_transparent = void; // Search by int 
		bool operator()(const CComposition &v1, const CComposition &v2) const
		{
			return v1.m_iID < v2.m_iID;
		}

		bool operator()(const CComposition &v1, const int &v2) const
		{
			return v1.m_iID < v2;
		}

		bool operator()(const int &v1, const CComposition &v2) const
		{
			return v1 < v2.m_iID;
		}
	};

										/* Methods */
	 // Show the object to console
	void ShowAll();

										/* Seters */

// set WorkTitle
	void setWorkTitle(const char*);

// set Genre
	void setGenre(const char*);

// set Original Language
	void setOrigLanguage(const char*);

// set Creation Year
	void setCreationYear(int);

									/* Geters */

// get the Title of the Work
	string getWorkTitle();

// get the Genre
	string getGenre();

// get the Language of the Original
	string getOrigLanguage();

// get the Year of Creation
	int getCreationYear();

protected:

									/* Class members */

	string m_strWorkTitle; // Work Title - from big, with digits 
	string m_strGenre;	// Genre length() <= 25 && from big
	string m_strOrigLanguage; // Original Language length() <= 25 && [0] from big
	int m_iCreationYear; // The Year of Creation 
	
private:

												/* Verification methods */

// Check the correctness of the Title of the Work
	bool isValidWorkTitle(const char*);

// Check the correctness of the Genre
	bool isValidGenre(const char*, string);

// Check the correctness of the Language of the Original
	bool isValidOrigLanguage(const char*, string);

// Check the correctness of Creation Year
	bool isValidCreationYear(int);
};
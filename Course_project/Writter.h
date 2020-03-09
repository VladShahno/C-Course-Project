#include"Person.h"
#pragma once
														/* Derived Class CWritter from parent CPerson */ 

class CWritter: public CPerson
{
public:
												/* Constructor's */

	// Default constructor
	CWritter();

	// Constructor with parameters
	CWritter(int, const char*, const char*, const char*, char, int , int , int, const char*, const char*, const char*, const char*);

	// Copy constructor
	CWritter(const CWritter&Other);

	// Destructor
	~CWritter();

											/*Overload Operators */

	// Overload operator =
	CWritter&operator=(const CWritter&Other);

	// Overload operator <
	friend bool operator < (const CWritter &t1, const CWritter &t2);

	// Overload operator <<
	friend ostream& operator<<(ostream& os, const CWritter& Obj);
	
	// Overload operator >>
	friend istream& operator>>(istream& is, CWritter& Obj);
	
											/* Methods */
	
	// Show the object to console
	void ShowAll();

	// Struct for comparison with type int set<CWritter, CWritter::test_less>
	struct test_less
	{
		using is_transparent = void; // Search by int 
		bool operator()(const CWritter &v1, const CWritter &v2) const
		{
			return v1.m_iID < v2.m_iID;
		}

		bool operator()(const CWritter &v1, const int &v2) const
		{
			return v1.m_iID < v2;
		}

		bool operator()(const int &v1, const CWritter &v2) const
		{
			return v1 < v2.m_iID;
		}
	};
												/* Seters */

	// set Country
	void setCountry(const char*);

	// set Place of Birth
	void setPlaceBirth(const char*);

	// set Genre
	void setGenre(const char*);

	// set Famous Work
	void setFamousWork(const char*);

												/* Geters */

    // get Country
	string getCountry();

	// get the Place of Birth
	string getPlaceBirth();

	// get Genre
	string getGenre();

	// get Famous Work
	string getFamousWork();

protected:
												/* Class members */

	string m_strGenre;		// Genre length() <= 25 && [0] from big
	string m_strCountry;	// Country length() <= 56 && [0] from big
	string m_strPlaceBirth; // Place of Birth length() <= 60 && from big
	string m_strFamousWork; // Famous Work [0] from big with digits
	
private:

												/* Verification methods */

	// Check the correctness of Country
	bool isValidCountry(const char*, string);

	// Check the correctness of Place of Birth
	bool isValidPlaceBirth(const char*, string);

	// Check the correctness of Genre
	bool isValidGenre(const char*, string);

	// Check the correctness of Famous Work
	bool isValiFamousWork(const char*);
};
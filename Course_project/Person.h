#pragma once
#include <string>
#include<set>
#include<iostream>
#include<boost/tokenizer.hpp>
using namespace std;
															/*		Basic Class  CPerson		*/

class CPerson 
{
public: 
														/* Constructor's */
	// Default constructor
	CPerson(); 
	
	// Constructor with parameters
	CPerson(int, const char*, const char*, const char*,  char, int = 0, int = 0, int = 0);

	// Copy constructor
	CPerson(const CPerson&Oher);

	// Destructor
	~CPerson();

	// Operator =
	CPerson&operator=(const CPerson&Other);

														/* Methods */	
	 
	virtual void ShowAll();	// Show the object to console
	
														/* Seters */
	
	// set FirstName, LastNAme, MiddleName
	void setPerson(const char*, const char*, const char*);

	// set FirstName
	void setFirstName(const char*);

	// set LastName
	void setLastName(const char*);

	// set MiddleName
	void setMiddleName(const char*);

	// set Sex
	void setSex(char);

	// set Day, Month, Year of birth
	void setDateBirth(int, int, int);

	// set ID
	void setID(int);
	
											/* Geters */
	
	// get FirstName, LastNAme, MiddleName
	string getPerson();

	// get FirstName
	string getFirstName();	

	// get LastName
	string getLastName();
	
	// get MiddleName
	string getMiddleName();

	// get Sex
	char getSex();

	// get Date of birth
	int getDateBirth();
	
	// get ID
	int getID() const;

protected:
														/* Class members */

	string m_strFirstName;	// First Name [0]- from big && no digit
	string m_strLastName;	// Last Name [0]- from big && no digit
	string m_strMiddleName; // Middle Name [0]- from big && no digit
	char m_chSex;		// Sex -  M or W
	int m_iDay;		// Day of birth from 1 to 31
	int	m_iMonth;   // Month of birth from 1 to 12
	int	m_iYear;	// Year of birth  Leap || not Leap
	int	m_iID;      // ID Number 

private:
										/* Verification methods */

	// Check the correctness of First, Last and Middle Name
	bool isValidPerson(const char*, const char*, const char*);

	// Check the correctness of First, Last and Middle Name
	bool isValidName(const char*);

	// Check the correctness of the Sex
	bool isValidSex(char);

	// Check the correctness of Day, Month and Year of Birth
	bool isValidDateBirth(int, int, int);
};

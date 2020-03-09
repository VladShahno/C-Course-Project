#pragma once
#include<iterator>
#include<fstream>
#include"Writter.h"
#include"Composition.h"
#include<mutex>
#include<thread>
#include"CTimer.h"

									/* Functions for work with std::set<> for class	 CWritter and class CComposition  */

												/* set<CWritter, CWritter::test_less> */

// Write object to container set<CWritter, CWritter::test_less> to the file
void WriteContainerWritter(set<CWritter, CWritter::test_less>&Ar);

//Read object from file to container set<CWritter>
void ReadContainerWritter(set<CWritter, CWritter::test_less>&Ar);

//Show container set<set<CWritter, CWritter::test_less> contents to console
void ShowContainerWritter(set<CWritter, CWritter::test_less>&Ar);

//Add to container set<CWritter> contents to console
void AddToContainerWritter(set<CWritter, CWritter::test_less>&Ar);

// Read object from file to container set<CComposition>
void ReadContainerComposition(set<CComposition, CComposition::test_less>&Ar);

//Edit Container set<CWritter>
void EditContainerWritter(set < CWritter, CWritter::test_less> &Arr);

													/* set<CComposition, CComposition::test_less> */

//Add to container set<CComposition, CComposition::test_less> contents to console
void AddToContainerComposition(set<CComposition, CComposition::test_less>&Ar);

//Show container set<CComposition, CComposition::test_less> contents to console
void ShowContainerComposition(set<CComposition, CComposition::test_less>&Ar);

//Edit Container set < CComposition, CComposition::test_less>
void EditContainerComposition(set < CComposition, CComposition::test_less> &Arr);

// Write object to container set<CComposition, CComposition::test_less> to the file
void WriteContainerComposition(set<CComposition, CComposition::test_less>&Ar);

// Print char for mutex
void Print(char ch);

// Call function for work with Container Writter
int WorkWithWritter();

// Call function for work with Container Composition
int WorkWithComposition();
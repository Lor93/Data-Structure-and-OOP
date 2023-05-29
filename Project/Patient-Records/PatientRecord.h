#ifndef PatientQueue_Record
#define PatientQueue_Record
#include<iostream>
#include"SortedList.h"
#include"PQueue.h"
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;
class PatientRecord
{
private: 
	string firstName;
	string lastName;
	string dateBirth;
	string patientSymptom;
	int pNum;
public:
	string patientRecord;
	PatientRecord();
	PatientRecord(string lastName, string firstName,string dateBirth, string patientSymptom, int pNum);
	void setLastName(string lastName);
	string getLastName();
	void setFirstName(string firstName);
	string getFirstName();
	void setDateBirth(string dateBirth);
	string getDateBirth();
	void setPatientSymptoms(string patientSymptom);
	string getPatientSymptom();
	void setPatientPriorityNum(int pNum);
	double  getPatientPriorityNum();
	bool operator<(PatientRecord anEntry) { return (this->pNum < anEntry.pNum); }
	bool operator>(PatientRecord anEntry) { return (this->pNum > anEntry.pNum); }
	bool operator==(PatientRecord anEntry) {return (this->pNum == anEntry.pNum);}
	void display();
};
PatientRecord::PatientRecord()
{
	firstName = "Unknown";
	lastName = "Unknown";
	dateBirth = "--/--/----";
	patientSymptom = "Unknown";
	pNum = 0;
}
PatientRecord::PatientRecord(string lastName, string firstName, string dateBirth, string patientSymptom, int pNum)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateBirth = dateBirth;
	this->patientSymptom = patientSymptom;
	this->pNum = pNum;
}
void PatientRecord::setLastName(string last)
{
	lastName = last;
}
string PatientRecord::getLastName()
{
	return lastName;
}
void PatientRecord::setFirstName(string first)
{
	firstName = first;
}
string PatientRecord::getFirstName()
{
	return firstName;
}
void PatientRecord::setDateBirth(string dateBirth)
{
	this->dateBirth = dateBirth;
}
string PatientRecord::getDateBirth()
{
	return dateBirth;
}
void PatientRecord::setPatientSymptoms(string patientSymptom)
{
	this->patientSymptom = patientSymptom;
}
string PatientRecord::getPatientSymptom()
{
	return patientSymptom;
}
void PatientRecord::setPatientPriorityNum(int pNum)
{
	pNum = 0;
}
double PatientRecord::getPatientPriorityNum()
{
	return pNum;
}
void PatientRecord::display()
{
	cout << left << endl;
	cout << "===============Priority No. " << pNum << "=====================" << endl;
	cout << setw(30) << left << "Last name: " << lastName <<endl;

	cout << setw(30) << left << "First name: " << firstName <<endl;;

	cout << setw(30) << left << "Date of Bith:(mm/dd/yyyy): " << dateBirth<<endl;

	cout << setw(30) << left << "Symptoms: " << patientSymptom << endl;

	//cout << setw(30) << left << "priority number: " << pNum << endl;

	cout << "\nIf done PLEASE close for patient privacy." <<endl;
	cout << "==================================================" << endl;
}
ostream& operator<<(ostream& out, PatientRecord a)
{
	out << left << endl;
	out << "===============Priority No. " << a.getPatientPriorityNum() << "=====================" << endl;
	out << setw(30) << left << "Last name: " << a.getLastName() << endl;

	out << setw(30) << left << "First name: " << a.getFirstName() << endl;;

	out << setw(30) << left << "Date of Bith:(mm/dd/yyyy): " << a.getDateBirth() << endl;

	out << setw(30) << left << "Symptoms: " << a.getPatientSymptom() << endl;

	//out << setw(30) << left << "priority number: " << pNum << endl;

	out << "\nIf done PLEASE close for patient privacy." << endl;
	out << "==================================================" << endl;
	
	return out;
}
#endif PatientQueue_Record
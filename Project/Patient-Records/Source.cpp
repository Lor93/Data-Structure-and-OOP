#include<iostream>
#include "PQueue.h"
#include "PatientRecord.h"
#include<string>
#include<iomanip>

using namespace std;

int main() {

	PatientRecord* aPatient;
	PQueue<PatientRecord> q;

	aPatient = new PatientRecord("Doe", "John", "01/01/2000", "deceased", 9);
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Lor", "Elvis","01/29/1993", "chest pain and cough", 2 );
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Johnson", "Kevin","11/09/1989", "Broken leg", 3);
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Aaron", "Hank","12/02/1982", "Cut on hand", 5 );
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Lee", "Tyler","05/20/1999", "Knie in stomach", 0 );
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Gonzales", "Tim","08/12/1992", "Unconscious with Head Trama", 1 );
	q.enqueue(*aPatient);
	aPatient = new PatientRecord("Taylor", "James","04/29/2002", "Backpain", 8);
	
		
	

	q.enqueue(*aPatient);
	q.displayQueue();

	return 0;
}

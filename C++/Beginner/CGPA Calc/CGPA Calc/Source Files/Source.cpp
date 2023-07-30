// Source.cpp

// Required Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Required .h files
#include "cgpa_calc.h" // Header file

// main()
int main()
{
	// Declare variables
	// FLOAT
	float cgpa;

	//INT
	int numSemesters;

	// VECTOR
	vector<vector<Course>> allSemesters;

	// Load previous data, if available
	allSemesters = loadStudentData();

	// User Input - # of semesters
	cout << "Enter the number of semesters: "; // User prompts 
	cin >> numSemesters;

	// FOR Loop
	for (int semester = 0; semester < numSemesters; ++semester)
	{
		// Declare variables
		// INT
		int numCourses;

		// VECTOR
		vector<Course> semesterCourses;

		// User input - # of courses in a specific semester
		cout << "Enter the number of courses for Semester " << (semester + 1) << ": ";
		cin >> numCourses;

		// FOR Loop
		for (int course = 0; course < numCourses; ++course)
		{
			cout << "Enter details for Course " << (course + 1) << ": "; 
			semesterCourses.push_back(inputCourseDetails());
		}

		allSemesters.push_back(semesterCourses);
	}

	// Calculate and display GPA for each semester
	// FOR Loop
	for (int semester = 0; semester < allSemesters.size(); ++semester)
	{
		// Declare variables
		// FLOAT
		float semesterGPA = calculateGPA(allSemesters[semester]);
		
		// Output
		cout << "GPA for Semester " << (semester + 1) << ": " << semesterGPA << endl;
	}

	// Calculate and display CGPA
	// Calculate
	cgpa = calculateCGPA(allSemesters);

	// Output
	cout << "CGPA: " << cgpa << endl;

	// Save the data to a file for future use
	saveStudentData(allSemesters);

	return 0;
}
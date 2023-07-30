// cgpa_calc.cpp

// Required Libraries
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Required .h files
#include "cgpa_calc.h"

// Implamentation of functions declared in header file
// Function Definitions
// Function to input details of each course
Course inputCourseDetails()
{
	// Declare Variables
	Course course;

	// User input - Course Name
	cout << "Enter the course name: "; // Prompt for user to enter course name
	cin.ignore();
	getline(cin, course.courseName);
	
	// User input - Grade
	cout << "Enter the grade (A/B/C/D/F): "; // Prompt for user to enter the grade
	cin >> course.grade;

	// User input - Credit Hours
	cout << "Enter the credit hours: "; // Prompt for user to enter credit hours
	cin >> course.creditHours;

	return course;
}

// Function to calculate GPA for a semester
float calculateGPA(const vector<Course>& courses)
{
	// Delcare Variables
	int totalCreditHours = 0;
	int totalGradePoints = 0;

	// FOR loop
	for (const Course& course : courses)
	{
		// Declare variable
		int gradePoints;

		// SWITCH Statement - we are comparing gradePoints
		switch (course.grade) // course.grade comes from user input within inputCourseDetails function
		{
		case 'A':
			gradePoints = 4;
			break;
		case 'B':
			gradePoints = 3;
			break;
		case 'C':
			gradePoints = 2;
			break;
		case 'D':
			gradePoints = 1;
			break;
		default:
			gradePoints = 0;
			break;
		}

		// Calcualte: Calc both totalCreditHours and totalGradePoints
		totalCreditHours += course.creditHours;
		totalGradePoints += (gradePoints * course.creditHours);
	}

	// IF statement
	if (totalCreditHours == 0)
	{
		return 0.0f;
	}

	return static_cast<float>(totalGradePoints) / totalCreditHours;
}

// Function to calculate total hours for a semester
int calculateTotalCreditHours(const vector<Course>& courses)
{
	// Declare variables
	int totalCreditHoours = 0;

	// FOR Loop
	for (const Course& course : courses)
	{
		// Calculation
		totalCreditHoours += course.creditHours;
	}

	// Return value
	return totalCreditHoours;
}

// Function to calculate CGPA
float calculateCGPA(const vector<vector<Course>>& allSemesters)
{
	// Declare Variables
	int totalCreditHours = 0;
	int	totalGradePoints = 0;

	// FOR loop
	for (const vector<Course>& semesterCourses : allSemesters)
	{
		// Declare variables
		// Calculate
		float semesterGPA = calculateGPA(semesterCourses);

		totalCreditHours += calculateTotalCreditHours(semesterCourses);
		totalCreditHours += static_cast<int>(semesterGPA * calculateTotalCreditHours(semesterCourses));
	}

	// IF statement 
	if (totalCreditHours == 0)
	{
		return 0.0f;
	}

	return static_cast<float>(totalGradePoints) / totalCreditHours;
}

// Function to save student data to a file
void saveStudentData(const vector<vector<Course>>& allSemesters)
{
	// Create file
	ofstream outputFile("student_data.txt");

	// IF statement
	// Open file
	if (outputFile.is_open())
	{
		// FOR Loop
		for (const vector<Course>& semesterCourses : allSemesters)
		{
			// FOR Loop
			for (const Course& course : semesterCourses)
			{
				outputFile << course.courseName << "," << course.grade << "," << course.creditHours << "\n";
			}
		}
		// Close file
		outputFile.close();

		cout << "Student Data saved to file.\n";
	}
	else
	{
		cout << "ErrorL Unable to open file for writing.\n";
	}
}

// Function to load student data from a file
vector<vector<Course>> loadStudentData()
{
	// Declare Variables
	vector<vector<Course>> allSemesters;

	// Create file
	ifstream inputFile("student_data.txt");

	// IF statement
	// Open file
	if (inputFile.is_open())
	{
		// Declare Variables
		string line;

		// WHILE Loop
		while (getline(inputFile, line))
		{
			// Declare Variables
			// CHAR
			char grade;

			// INT
			int creditHours;

			// STRING
			stringstream ss(line);
			string courseName;
			string gradeStr;
			string creditHoursStr;

			// getlines
			getline(ss, courseName, ',');
			getline(ss, gradeStr, ',');
			getline(ss, creditHoursStr, ',');

			// stringstream
			stringstream gradeStream(gradeStr);
			gradeStream >> grade;
			stringstream creditHoursStream(creditHoursStr);
			creditHoursStream >> creditHours;

			// Create a new course and add it to the last semester's vector of courses
			// Declare variables
			Course course;
			course.courseName = courseName;
			course.grade = grade;
			course.creditHours = creditHours;

			// IF Statement
			if (!allSemesters.empty())
			{
				allSemesters.back().push_back(course);
			}
			else
			{
				vector<Course> newSemester;
				newSemester.push_back(course);
				allSemesters.push_back(newSemester);
			}
			
		}

		// Close file
		inputFile.close();

		cout << "Student data loaded from file.\n";
	}
	else
	{
		cout << "No previous data found. Starting with an empty record.\n";
	}

	return allSemesters;
}


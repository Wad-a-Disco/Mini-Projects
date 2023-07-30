// cgpa_calc.h

// Guards
#pragma once
#ifndef CGPA_CALC_H
#define CGPA_CALC_H

// Libraries
#include <string>
#include <vector>
using namespace std;

// Course struct to store course details
struct Course
{
	// Declare Variables
	char grade;
	int creditHours;
	string courseName;
};

// Function Prototypes
// Function to input details of each course
Course inputCourseDetails();

// Function to Calculate GPA for a semester
float calculateGPA(const vector<Course>& courses);

// Function to calculate CGPA
float calculateCGPA(const vector<vector<Course>>& allSemesters);

//Function to save student data to a file
void saveStudentData(const vector<vector<Course>>& allSemesters);

// Function to load student sata from a file
vector<vector<Course>> loadStudentData();
#endif CGPA_CALC_H
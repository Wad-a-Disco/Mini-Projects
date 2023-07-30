# CGPA Calculator

CGPA Calculator is a C++ program that allows students to calculate their Cumulative Grade Point Average (CGPA) based on their exam results. The program takes input from the user for the number of courses taken and the grades earned in each course. It can calculate the GPA for each semester, as well as the overall CGPA, and save the student data for future reference.

## Technologies Used
- C++ programming language
- Data Structures (Vectors)
- Basic Arithmetic Operations and Formulas
- File Handling (I/O Streams)

## Features
- Input details of each course, including course name, grade, and credit hours.
- Calculate the GPA for each semester based on the grades and credit hours of the courses.
- Calculate the CGPA by taking into account all the semesters and their respective credit hours and GPAs.
- Save student data to a file for future retrieval.

## How to Use
1. Clone the repository to your local machine or download the source files.
2. Compile the source files using a C++ compiler (e.g., g++, Visual C++).
3. Run the executable to start the CGPA Calculator program.
4. Follow the on-screen prompts to input the number of semesters and details for each course in every semester.
5. The program will display the GPA for each semester and the overall CGPA.
6. The student data will be saved to a file named "student_data.txt" in the current working directory.

## Sample Test Cases
The CGPA Calculator program has been tested with the following sample test cases:

**Test Case 1:**
Number of semesters: 2

Semester 1:
  Number of courses: 3
    - Course 1: Math, Grade: A, Credit Hours: 3
    - Course 2: English, Grade: B, Credit Hours: 4
    - Course 3: Science, Grade: A, Credit Hours: 3

Semester 2:
  Number of courses: 4
    - Course 1: History, Grade: B, Credit Hours: 3
    - Course 2: Physics, Grade: C, Credit Hours: 5
    - Course 3: Art, Grade: A, Credit Hours: 2
    - Course 4: Computer Science, Grade: A, Credit Hours: 4

GPA for Semester 1: 3.66
GPA for Semester 2: 3.05
CGPA: 3.35
Student data saved to file.

**Test Case 2:**
Number of semesters: 3

Semester 1:
  Number of courses: 2
    - Course 1: English, Grade: B, Credit Hours: 4
    - Course 2: Math, Grade: C, Credit Hours: 3

Semester 2:
  Number of courses: 3
    - Course 1: Science, Grade: A, Credit Hours: 4
    - Course 2: History, Grade: A, Credit Hours: 3
    - Course 3: Geography, Grade: B, Credit Hours: 3

Semester 3:
  Number of courses: 2
    - Course 1: Physics, Grade: C, Credit Hours: 4
    - Course 2: Chemistry, Grade: A, Credit Hours: 3

GPA for Semester 1: 2.33
GPA for Semester 2: 3.66
GPA for Semester 3: 2.83
CGPA: 3.06
Student data saved to file.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struct to represent a course
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Function to load courses from a file into a hash table
unordered_map<string, Course> LoadCoursesFromFile(const string& fileName) {
    unordered_map<string, Course> courseMap;
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return courseMap;
    }

    string line;
    // Skip the first line
    getline(file, line);

    // Read each line and parse
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseTitle, prereq1, prereq2;

        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');
        getline(ss, prereq1, ',');
        getline(ss, prereq2, ',');

        // Create a Course object
        Course course;
        course.courseNumber = courseNumber;
        course.courseTitle = courseTitle;

        // Add prerequisites
        if (!prereq1.empty()) course.prerequisites.push_back(prereq1);
        if (!prereq2.empty()) course.prerequisites.push_back(prereq2);

        // Insert the course into the hash table
        courseMap[courseNumber] = course;
    }

    file.close();
    return courseMap;
}

// Function to print all courses in the hash table
void PrintAllCourses(const unordered_map<string, Course>& courseMap) {
    cout << "Here is a sample schedule:" << endl;

    // Print courses in alphanumeric
    for (const auto& pair : courseMap) {
        const Course& course = pair.second;
        cout << course.courseNumber << ", " << course.courseTitle << endl;
    }
    cout << endl;
}

// Function to search for and print course information
void SearchCourse(const unordered_map<string, Course>& courseMap, const string& courseNumber) {
    auto it = courseMap.find(courseNumber);
    if (it != courseMap.end()) {
        const Course& course = it->second;
        cout << course.courseNumber << ", " << course.courseTitle << endl;

        if (course.prerequisites.empty()) {
            cout << "No prerequisites." << endl;
        }
        else {
            cout << "Prerequisites: " << endl;
            for (const string& prereqNumber : course.prerequisites) {
                auto prereqIt = courseMap.find(prereqNumber);
                if (prereqIt != courseMap.end()) {
                    const Course& prereqCourse = prereqIt->second;
                    cout << prereqCourse.courseNumber << ", " << prereqCourse.courseTitle << endl;
                }
                else {
                    cout << prereqNumber << " (Course not found)" << endl; // In case of a missing course
                }
            }
        }
    }
    else {
        cout << "Error: Course " << courseNumber << " not found." << endl;
    }
}

//function to make search non case sensitive
string ToUpper(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

// Main function to handle the menu
int main() {
    unordered_map<string, Course> courseMap;
    int choice;

    cout << "Welcome to the course planner." << endl;

    do {
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string fileName;
            cout << "Enter the file name: ";
            cin >> fileName;
            courseMap = LoadCoursesFromFile(fileName);
            break;
        }
        case 2:
            if (courseMap.empty()) {
                cout << "Error: No courses loaded." << endl;
            }
            else {
                PrintAllCourses(courseMap);
            }
            break;
        case 3: {
            if (courseMap.empty()) {
                cout << "Error: No courses loaded." << endl;
                break;
            }
            string courseNumber;
            cout << "What course do you want to print information about? ";
            cin >> courseNumber;
            SearchCourse(courseMap, ToUpper(courseNumber));
            break;
        }
        case 9:
            cout << "Thank you for using the course planner" << endl;
            break;
        default:
            cout << choice << "Error: Choice is not a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}
#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "Course.h"
#include "Student.h"
#include <string>

class SystemManager {
private: 
    struct CourseNode {
        Course course;
        CourseNode* next;
    };
    
    CourseNode* head;
    std::string adminPassword;
    int totalCourses;
    
    void selectionSortCourses(Course list[], int n, const std::string &field, bool ascending) const;
    void bubbleSortCourses(Course list[], int n, const std::string &field, bool ascending) const;
    void insertionSortCourses(Course list[], int n, const std::string &field, bool ascending) const;
    void addCourse();
    void deleteCourse();
    void saveCoursesToFile(const std::string &filename = "courses.txt");

public: 
    SystemManager();
    ~SystemManager();
    int getTotalCourses() const;
    const Course &getCourseAt(int index) const;

    bool adminLogin();
    void loadCoursesFromFile(const std::string &filename = "courses.txt");
    
    void displayAllCoursesSortedByCourseCode() const;   //Tan Choon Da
    void displayAllCoursesSortedByLecturerName() const; //Lee Ming Da
    void displayAllCoursesSortedByCreditHour() const;   //Gan Rui En               

    int searchCourseByCode(const std::string &code) const;  //Lee Ming Da
    int searchCourseByCourseName(const std::string &name) const; //Gan Rui En
    void manageTimetable(); //Tan Choon Da           
    void adminMenu();   //Tan Choon Da
    void studentMenu(Student &s);   //Tan Choon Da
    
    void studentViewAllCourses() const; //Tan Choon Da      
    
    void studentSearchCourseByCode() const; //Lee Ming Da
    void studentSearchCourseByCourseName() const;  //Gan Rui En
    
    void displayTimetableSortedByCourseCode(const Student &s) const;    //Tan Choon Da
    void displayTimetableSortedByLecturerName(const Student &s) const;  //Lee Ming Da
    void displayTimetableSortedByCreditHour(const Student &s) const;    //Gan Rui En

};

#endif // SYSTEMMANAGER_H

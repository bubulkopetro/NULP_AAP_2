#ifndef Student_hpp
#define Student_hpp

#pragma once

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Speciality { CS, INF, ME, PI, CR };

string SpecialityString[] = { "Computer Science", "Informatics", "Mathematics and Economics", "Physics and Informatics", "Craft" };


struct Student
{
    string surname;
    unsigned course;
    Speciality speciality;
    unsigned Physics;
    unsigned Mathematics;
    union
    {
        unsigned Programming;
        unsigned NumericalAnalysis;
        unsigned Pedagogy;
    };
};


void Create(Student *s, const int N)
{
    int speciality;
    
    for (int i = 0; i < N; i++)
    {
        cout << "Student №" << i + 1 << ":" << endl;
        
        cin.get();
        cin.sync();
        
        cout << "   Surname:  "; getline(cin, s[i].surname);
        cout << "   Course:  "; cin >> s[i].course;
        cout << "   Specialty " << endl;
        cout << "     0 -  Computer Science " << endl;
        cout << "     1 - Informatics " << endl;
        cout << "     2 - Mathematics and Economics " << endl;
        cout << "     3 - Physics and Informatics " << endl;
        cout << "     4 - Craft " << endl;
        cout << "   Enter the value : ";
        cin >> speciality;
        s[i].speciality = (Speciality)speciality;
        
        cout << "   Grade in Physics: "; cin >> s[i].Physics;
        cout << "   Grade in Mathematics: "; cin >> s[i].Mathematics;
        
        if (s[i].speciality == 0)
        {
            cout << "   Grade in Programming: ";
            cin >> s[i].Programming;
        }
        else if (s[i].speciality == 1)
        {
            cout << "   Grade in Numerical Analysis: ";
            cin >> s[i].NumericalAnalysis;
        }
        else
        {
            cout << "   Grade in Pedagogy: ";
            cin >> s[i].Pedagogy;
        }
        cout << endl;
    }
}


void Display(Student *s, const int N)
{
    cout << "===================================================================================================================================="
         << endl;
    cout << "| №  |    Surname    | Course |          Speciality          | Physics | Mathematics | Programming | Numerical Analysis | Pedagogy |"
         << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------"
         << endl;
    
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << right << i + 1
             << "|" << setw(15) << left << s[i].surname
             << "|" << setw(8) << right << s[i].course;
        
        switch (s[i].speciality)
        {
        case Speciality::CS:
            cout << "|" << setw(30) << left << "Computer Science" << "|";
            cout << setw(9) << right << s[i].Physics << "|"
                 << setw(13) << right << s[i].Mathematics << "|"
                 << setw(13) << right << s[i].Programming << "|                    |          |"
                 << endl;
            break;
        case Speciality::INF:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            cout << setw(9) << right << s[i].Physics << "|"
                 << setw(13) << right << s[i].Mathematics
                 << "|             |"<< setw(20) << right << s[i].NumericalAnalysis << "|          |"
                << endl;
            break;
        case Speciality::ME:
            cout << "|" << setw(30) << left << "Mathematics and Economics" << "|";
            cout << setw(9) << right << s[i].Physics << "|"
                 << setw(13) << right << s[i].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[i].Pedagogy << "|"
                 << endl;
            break;
        case Speciality::PI:
            cout << "|" << setw(30) << left << "Physics and Informatics" << "|";
            cout << setw(9) << right << s[i].Physics << "|"
                 << setw(13) << right << s[i].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[i].Pedagogy << "|"
                 << endl;
            break;
        case Speciality::CR:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            cout << setw(9) << right << s[i].Physics << "|"
                 << setw(13) << right << s[i].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[i].Pedagogy << "|"
                 << endl;
            break;
        }
        
        cout << "===================================================================================================================================="
        << endl;
        cout << endl;
        
        
    }
}


void GreaterThanThree(Student *s, const int N)
{
    int number = 0;
    
    cout << "====================" << endl;
    cout << "|      Surname     |" << endl;
    cout << "--------------------" << endl;
    
    for (int i = 0; i < N; i++)
    {
        if ((s[i].Physics == 5 || s[i].Physics == 4) && (s[i].Mathematics == 5 || s[i].Mathematics == 4) && (s[i].Programming == 5 || s[i].Programming == 4))
        {
            number++;
            cout << "|" << setw(18) << left << s[i].surname << "|" << endl;
        }
    }
    
    cout << "====================" << endl;
}


int PhysicsFive(Student *s, const int N)
{
    int number = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].Physics == 5)
        {
            number++;
        }
    }
    return number;
}


#endif /* Student_hpp */

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

double AverageGrade(Student* s, const int i)
{
    double average = 0;
    
    if (s[i].speciality == 0) {
        average = (s[i].Physics + s[i].Mathematics + s[i].Programming) / 3.0;
    }
    else if (s[i].speciality == 1) {
        average = (s[i].Physics + s[i].Mathematics + s[i].NumericalAnalysis) / 3.0;
    }
    else {
        average = (s[i].Physics + s[i].Mathematics + s[i].Pedagogy) / 3.0;
    }
    return average;
}


void Sort(Student* s, const int N)
{
    Student temp;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if ((s[j].speciality > s[j +1].speciality)
                ||
                (s[j].speciality == s[j +1].speciality &&
                AverageGrade(s, j) > AverageGrade(s, j + 1))
                ||
                (s[j].speciality == s[j +1].speciality &&
                AverageGrade(s, j) == AverageGrade(s, j + 1) &&
                s[j].surname < s[j + 1].surname))
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
}


int* IndexSort(Student* s, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;
    int i, j, value;
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((s[I[j]].speciality > s[value].speciality)
                ||
                (s[I[j]].speciality == s[value].speciality &&
                 AverageGrade(s, I[j]) > AverageGrade(s, value))
                ||
                (s[I[j]].speciality == s[value].speciality &&
                AverageGrade(s, I[j]) == AverageGrade(s, value) &&
                s[I[j]].surname > s[value].surname));
        j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}


void PrintIndexSorted(Student* s, int* I, const int N)
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
             << "|" << setw(15) << left << s[I[i]].surname
             << "|" << setw(8) << right << s[I[i]].course;
        
        switch (s[I[i]].speciality)
        {
        case Speciality::CS:
            cout << "|" << setw(30) << left << "Computer Science" << "|";
            cout << setw(9) << right << s[I[i]].Physics << "|"
                 << setw(13) << right << s[I[i]].Mathematics << "|"
                 << setw(13) << right << s[I[i]].Programming << "|                    |          |"
                 << endl;
            break;
        case Speciality::INF:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            cout << setw(9) << right << s[I[i]].Physics << "|"
                 << setw(13) << right << s[I[i]].Mathematics
                 << "|             |"<< setw(20) << right << s[I[i]].NumericalAnalysis << "|          |"
                << endl;
            break;
        case Speciality::ME:
            cout << "|" << setw(30) << left << "Mathematics and Economics" << "|";
            cout << setw(9) << right << s[I[i]].Physics << "|"
                 << setw(13) << right << s[I[i]].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[I[i]].Pedagogy << "|"
                 << endl;
            break;
        case Speciality::PI:
            cout << "|" << setw(30) << left << "Physics and Informatics" << "|";
            cout << setw(9) << right << s[I[i]].Physics << "|"
                 << setw(13) << right << s[I[i]].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[I[i]].Pedagogy << "|"
                 << endl;
            break;
        case Speciality::CR:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            cout << setw(9) << right << s[I[i]].Physics << "|"
                 << setw(13) << right << s[I[i]].Mathematics
                 << "|             |                    |"<< setw (10) << right << s[I[i]].Pedagogy << "|"
                 << endl;
            break;
        }
        
        cout << "===================================================================================================================================="
        << endl;
        cout << endl;
        
        
}
}

int BinarySearch(Student* s, const int N, const string surname, const Speciality speciality, double grade)
{
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (s[m].surname == surname && s[m].speciality == speciality && AverageGrade(s, m) == grade)
            return m;
        
            if ((s[m].speciality > speciality)
                ||
                (s[m].speciality == speciality &&
                AverageGrade(s, m) == grade)
                ||
                (s[m].speciality == speciality &&
                AverageGrade(s, m) == grade &&
                s[m].surname > surname))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}

#endif /* Student_hpp */


//if ((AverageGrade(s, m) < grade)
//    ||
//    (AverageGrade(s, m) == grade &&
//     s[m].speciality < speciality)
//    ||
//    (AverageGrade(s, m) == grade &&
//     s[m].speciality == speciality &&
//     s[m].surname < surname))

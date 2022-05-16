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
    unsigned Informatics;
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
        cout << "   Grade in Informatics: "; cin >> s[i].Informatics;
        cout << endl;
    }

}


void Display(Student *s, const int N)
{
    cout << "===================================================================================================="
         << endl;
    cout << "| №  |    Surname    | Course |          Speciality          | Physics | Mathematics | Informatics |"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------"
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
            break;
        case Speciality::INF:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            break;
        case Speciality::ME:
            cout << "|" << setw(30) << left << "Mathematics and Economics" << "|";
            break;
        case Speciality::PI:
            cout << "|" << setw(30) << left << "Physics and Informatics" << "|";
            break;
        case Speciality::CR:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            break;
        }
        cout << setw(9) << right << s[i].Physics << "|"
             << setw(13) << right << s[i].Mathematics << "|"
             << setw(13) << right << s[i].Informatics << "|"
             << endl;
    }

    cout << "===================================================================================================="
         << endl;
    cout << endl;
}

double AverageGrade(Student* s, const int i)
{
    double average = 0;
    average = (s[i].Physics + s[i].Mathematics + s[i].Informatics) / 3.0;
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
                s[j].surname > s[j + 1].surname))
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
    cout << "===================================================================================================="
         << endl;
    cout << "| №  |    Surname    | Course |          Speciality          | Physics | Mathematics | Informatics |"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------"
         << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << right << i + 1
             << "|" << setw(15) << left << s[I[i]].surname
             << "|" << setw(8) << right << s[I[i]].course;

        switch (s[i].speciality)
        {
        case Speciality::CS:
            cout << "|" << setw(30) << left << "Computer Science" << "|";
            break;
        case Speciality::INF:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            break;
        case Speciality::ME:
            cout << "|" << setw(30) << left << "Mathematics and Economics" << "|";
            break;
        case Speciality::PI:
            cout << "|" << setw(30) << left << "Physics and Informatics" << "|";
            break;
        case Speciality::CR:
            cout << "|" << setw(30) << left << "Informatics" << "|";
            break;
        }
        cout << setw(9) << right << s[I[i]].Physics << "|"
             << setw(13) << right << s[I[i]].Mathematics << "|"
             << setw(13) << right << s[I[i]].Informatics << "|"
             << endl;
    }

    cout << "===================================================================================================="
         << endl;
    cout << endl;
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




//            if ((s[m].speciality > s[m +1].speciality)
//                ||
//                (s[m].speciality == s[m +1].speciality &&
//                AverageGrade(s, m) > AverageGrade(s, m + 1))
//                ||
//                (s[m].speciality == s[m +1].speciality &&
//                AverageGrade(s, m) == AverageGrade(s, m + 1) &&
//                s[m].surname > s[m + 1].surname))

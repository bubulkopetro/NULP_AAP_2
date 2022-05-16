#include "Student.hpp"
#include "source.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    int N, M;
    int specialityNumber, found;
    Speciality speciality;
    string surname;
    double grade;
    cout << "Enter the number of students: ";
    cin >> N;
    Student *s = new Student[N];
    
    do {
        cout << endl << endl << endl;
        cout << "   Select your next action:" << endl << endl;
        cout << "     0 - Enter data " << endl;
        cout << "     1 - Display data " << endl;
        cout << "     2 - Physical sorting " << endl;
        cout << "     3 - Index sorting " << endl;
        cout << "     4 - Binary search " << endl;
        cout << "     5 - Exit " << endl;
        cout << "   Enter the value: "; cin >> M;
        cout << endl << endl << endl;

        switch (M) {
        case 0:
            Create(s, N);
            break;
        case 1:
            Display(s, N);
            break;
        case 2:
            Sort(s, N);
            Display(s, N);
            break;
        case 3:
            PrintIndexSorted(s, IndexSort(s, N), N);
            break;
        case 4:
            cout << "   Enter the data to be searched" << endl;
            cout << "   Surname:  ";
            cin >> surname;
            cout << endl;
            cout << "   Specialty " << endl;
            cout << "     0 -  Computer Science " << endl;
            cout << "     1 - Informatics " << endl;
            cout << "     2 - Mathematics and Economics " << endl;
            cout << "     3 - Physics and Informatics " << endl;
            cout << "     4 - Craft " << endl;
            cout << "   Enter the value: ";
            cin >> specialityNumber;
            speciality = (Speciality)specialityNumber;
            cout << " Average Grade: ";
            cin >> grade;
            cin.get();
            cin.sync();
                
            if ((found = BinarySearch(s, N, surname, speciality, grade)) != -1)
                cout << "Found student in position " << found + 1 << endl;
            else
                cout << "The student you are looking for has not been found" << endl;
            break;
            case 5:
            break;
            default:
                cout << "You have entered an incorrect value! " << endl;
                cout << "Enter the number of the selected menu item" << endl;
        }
    } while (M != 5);

    return 0;
    
}


//1. Вивести прізвища студентів, які вчаться без трійок (на “відмінно” і “добре”).
//
//2. Обчислити кількість студентів, які отримали з фізики оцінку “5”.

#include "Student.hpp"
#include "source.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    int N;
    cout << "Enter the number of students: ";
    cin >> N;
    Student *s = new Student[N];

    Create(s, N);
    Display(s, N);

    cout << "Surnames of students who study 'excellent' and 'good': " << endl;
    GreaterThanThree(s, N);

    int number = PhysicsFive(s, N);
    cout << "Number of students who received '5' in physics: " << number << endl;

    delete[] s;
    return 0;
}

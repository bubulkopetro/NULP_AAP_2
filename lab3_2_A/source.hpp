//////
//////  source.hpp
//////  lab3_2_A
//////
//////  Created by bubulko on 07.04.2022.
//////
////
////#ifndef source_hpp
////#define source_hpp
////
////#include <stdio.h>
////
////#endif /* source_hpp */
//
//
//void Sort(Student *list, const int size)
//{
//    Student tmp;
//    for (int i0 = 0; i0 < size - 1; i0++)
//    {
//        for (int i1 = 0; i1 < size - i0 - 1; i1++)
//        {
//            if ((list[i1].speciality > list[i1 + 1].speciality) ||
//                (list[i1].speciality == list[i1 + 1].speciality && list[i1].gradeProgramming < list[i1 + 1].gradeProgramming) ||
//                (list[i1].speciality == list[i1 + 1].speciality && list[i1].gradeProgramming == list[i1 + 1].gradeProgramming &&
//                    list[i1].surname > list[i1 + 1].surname))
//            {
//                tmp = list[i1];
//                list[i1] = list[i1 + 1];
//                list[i1 + 1] = tmp;
//            }
//        }
//    }
//}
//
//int *IndexSort(Student *list, const int size)
//{
//    int *I = new int[size];
//    for (int i = 0; i < size; i++)
//        I[i] = i;
//    int i, j, value;
//    for (i = 1; i < size; i++)
//    {
//        value = I[i];
//        for (j = i - 1;
//            j >= 0 && ((list[I[j]].speciality > list[value].speciality) ||
//                (list[I[j]].speciality == list[value].speciality && list[I[j]].gradeProgramming < list[value].gradeProgramming) ||
//                (list[I[j]].speciality == list[value].speciality && list[I[j]].gradeProgramming == list[value].gradeProgramming &&
//                    list[I[j]].surname > list[value].surname));
//            j--)
//        {
//            I[j + 1] = I[j];
//        }
//        I[j + 1] = value;
//    }
//    return I;
//}
//
//int BinSearch(Student *list, const int size, const string surname, const Speciality speciality, const unsigned grade)
//{
//    int L = 0, R = size - 1, m;
//    do {
//        m = (L + R) / 2;
//        if (list[m].surname == surname && list[m].speciality == speciality && list[m].gradeProgramming == grade)
//            return m;
//        if ((list[m].speciality < speciality)
//            ||
//            (list[m].speciality == speciality &&
//                list[m].gradeProgramming > grade) || (list[m].speciality == speciality &&
//                    list[m].gradeProgramming == grade && list[m].surname < surname))
//        {
//            L = m + 1;
//        }
//        else
//        {
//            R = m - 1;
//        }
//    } while (L <= R);
//    return -1;
//}
//
//int BinSearch(Student *list, int *I, const int size, const string surname, const Speciality speciality, const unsigned grade)
//{
//    int L = 0, R = size - 1, m;
//    do {
//        m = (L + R) / 2;
//        if (list[I[m]].surname == surname && list[I[m]].speciality == speciality && list[I[m]].gradeProgramming == grade)
//            return m;
//        if ((list[I[m]].speciality < speciality)
//            ||
//            (list[I[m]].speciality == speciality &&
//                list[I[m]].gradeProgramming > grade) || (list[I[m]].speciality == speciality &&
//                    list[I[m]].gradeProgramming == grade && list[I[m]].surname < surname))
//        {
//            L = m + 1;
//        }
//        else
//        {
//            R = m - 1;
//        }
//    } while (L <= R);
//    return -1;
//}

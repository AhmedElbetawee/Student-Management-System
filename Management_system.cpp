#include <bits/stdc++.h>
using namespace std;

class Student
{
    string name;
    int id;
    int grade;
    public:

        Student(string n, int i, int gr)
        {
            name = n;
            id = i;
            grade = gr;
        }

        string get_name()
        {
            return name;
        }

        int get_id()
        {
            return id;
        }

        int get_grade()
        {
            return grade;
        }

        void set_new_grade(int new_grade)
        {
            grade = new_grade;
        }

        void print()
        {
            cout <<"Name is "<<name<<"\n";
            cout <<"ID is "<<id<<"\n";
            cout <<"Grade is "<<grade<<"\n";
        }
};
class Student_Managment_System
{
    vector <Student> students;
    public:
        void show_menu()
        {
            cout <<"1- Add Student\n";
            cout <<"2- Remove Student\n";
            cout <<"3- search Student\n";
            cout <<"4- Display Student\n";
            cout <<"5- update Student\n";
            cout <<"6- sort by ID\n";
            cout <<"7- sort by grade\n";
            cout <<"8- Exit\n";    
        }
        string add_student()
        {
            string name; 
            int id, grade;
            cout <<"Enter name of student: "; cin>>name;
            cout <<"Enter id of student: "; cin>>id;
            cout <<"Enter grade of student: "; cin>>grade;
            Student s(name, id, grade);
            for (int i=0; i<students.size(); ++i)
            {
                if (students[i].get_id() == id)
                {
                    return "the ID already exists\n";
                }
            }
            students.push_back(s);
            return "the student is added\n";
        
        }

        string remove_student()
        {
            int id;
            cout <<"Enter id of student "; cin>>id;

            for (int i=0; i< students.size(); i++)
            {
                if (students[i].get_id() == id)
                {
                    students.erase(students.begin() + i);
                    return "the student is removed\n";
                }
                
            }
            return "the student is not founded\n";
        }

        string search_student()
        {
            int id;
            cout <<"Enter id of student "; cin>>id;
            for (int i=0; i< students.size(); i++)
            {
                if (students[i].get_id() == id)
                {
                    students[i].print();
                    return "the student is founded\n";
                }
                
            }
            return "the student is not founded\n";
        }

        string display_all_student()
        {
            if (students.empty())
            {
                return "there is nO students\n";
            }
            for (int i=0; i<students.size(); i++)
            {
                students[i].print();
            }
            return "this is display of all student\n";
        }

        string update_grade()
        {
            int id;
            int new_grade;
            cout <<"Enter student id "; cin>>id;
            cout <<"Enter new grade "; cin>>new_grade;

            for (int i=0; i< students.size(); i++)
            {
                if (students[i].get_id() == id)
                {
                    students[i].set_new_grade(new_grade);
                    return "your grade is updated\n";
                }
            }
            return "your id is not founded\n";
        }

        void sort_student_ID()
        {
            vector <Student> id = students;
            for (int i=0; i<students.size()-1; ++i)
            {
                for (int j=i+1; j<students.size(); ++j)
                {
                    if (id[i].get_id() > id[j].get_id())
                        swap(id[i], id[j]);
                }
            }
            cout <<"this is sort student by id\n";
            for (int i=0; i<id.size(); i++)
            {
                id[i].print();
            }
        }

        void sort_student_grade()
        {
            vector <Student> grade = students;
            for (int i=0; i<students.size()-1; ++i)
            {
                for (int j=i+1; j<students.size(); ++j)
                {
                    if (grade[i].get_grade() > grade[j].get_grade())
                        swap(grade[i], grade[j]);
                }
            }
            cout <<"this is sort student by grade\n";
            for (int i=0; i<grade.size(); i++)
            {
                grade[i].print();
            }
        }

};
int main()
{
    Student_Managment_System s1;
    int number=0;
    while(number != 8)
    {
        s1.show_menu();
        cout <<"Enter number from 1 to 8 : "; cin>>number;
        
        if (number == 1)
        {
            cout <<s1.add_student();
        }

        else if (number == 2)
        {
            cout <<s1.remove_student();
        }

        else if (number == 3)
        {
            cout <<s1.search_student();
        }

        else if (number == 4)
        {
            cout <<s1.display_all_student();
        }

        else if (number == 5)
        {
            cout <<s1.update_grade();
        }

        else if (number == 6)
        {
            s1.sort_student_ID();
        }

        else if (number == 7)
        {
            s1.sort_student_grade();
        }
    }
}
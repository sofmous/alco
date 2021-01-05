// ανάγνωση δεδομένων από ένα αρχείο προβλήματος (με κατάληξη stu) που περιέχει
// πληροφορίες για τις εξετάσεις μαθημάτων στις οποίες είναι εγγεγραμμένος
// ο κάθε σπουδαστής

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;



void read_data(string fn, int students, int exams)
{
    // ανάγνωση δεδομένων
    vector<set<int>> exam_students(exams + 1);
    fstream fs(fn);
    if (!fs.is_open())
    {
        cerr << "Could not open file " << fn << std::endl;
        exit(-1);
    }
    int student_id = 0;
    string line;
    while (getline(fs, line))
    {
        if (line.empty())
            continue;
        student_id++;
        istringstream iss(line);
        int exam_id;
        while (iss >> exam_id)
        {
            exam_students[exam_id].insert(student_id);
            cout << "Student " << student_id << " is enrolled in exam " << exam_id << endl;
        }
    }
    fs.close();

    cout << "#################################" << endl;

    for (int i = 1; i <= exams; i++)
    {
        cout << "Exam " << i << " Enrolled students: ";
        for (int student_id : exam_students[i]) // range based for
        {
            cout << student_id << " ";
        }
        cout << endl;
    }
}

 

void readfile()
{
    read_data("datasets/car-f-92.stu",18419,543);
    read_data("datasets/car-s-91.stu",16925,682);
    read_data("datasets/ear-f-83.stu",1125,190);
    read_data("datasets/hec-s-92.stu",2823,81);
    read_data("datasets/kfu-s-93.stu",5349,461);
    read_data("datasets/lse-f-91.stu",2726,381);
    read_data("datasets/pur-s-93.stu",30029,2419);
    read_data("datasets/rye-s-93.stu",11483,486);
    read_data("datasets/sta-f-83.stu",611,139);
    read_data("datasets/tre-s-62.stu",4360,261);
    read_data("datasets/uta-s-92.stu",21266,622);
    read_data("datasets/ute-s-92.stu",2749,184);
    read_data("datasets/yor-f-83.stu",941,181);
}


int main()
{
    
    //read_data("datasets/toy_e5_s6.stu", 6, 5);
    readfile();
}

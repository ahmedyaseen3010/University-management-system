#include <iostream>
#include <vector>

using namespace std;
class Person
{
protected:
    int id;
    string name;
    int age;
    char gender;

public:

    // Default constructor
    Person()
    {
        // cout<<"Person Default Constructor"<<endl;
    }

    // Parameterized constructor
    Person(int id,string name, int age,char gender)
    {
        this->id=id;
        this->name=name;
        this->age=age;
        this->gender=gender;
        // cout<<"Person Parameterized Constructor"<<endl;
    }

    // Setters
    void set_id(int id)
    {
        this->id = id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_gender(char gender)
    {
        this->gender = gender;
    }

    // Getters
    int get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    char get_gender()
    {
        return gender;
    }
};
class Department
{
private:
    string name;
    int capacity;
    double required_gpa;

public:
    Department()
    {
        // cout<<"Department Default constructor"<<endl;
    }

    Department(string name, int capacity, double required_gpa)
    {

        this->name = name;
        this->capacity = capacity;
        this->required_gpa = required_gpa;
        // cout<<"Department Parameterized constructor"<<endl;
    }
    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getCapacity()
    {
        return capacity;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }

    double getRequiredGpa()
    {
        return required_gpa;
    }

    void setRequiredGpa(double required_gpa)
    {
        this->required_gpa = required_gpa;
    }
};

class Professor: public Person
{
private:
    // string department;
    Department* department;
    double salary;
    string degree;
public:
    Professor(int id,string name, double age, char gender,Department* department, double salary, string degree)
            : Person(id,name, age, gender)
    {
        this->department = department;
        this->salary = salary;
        this->degree = degree;
        //  cout<<"Professor Parameterized constructor"<<endl;
    }
    Professor()
    {
        //  cout<<"Professor Default constructor"<<endl;
    }
    void set_department(Department* department)
    {
        this->department = department;
    }
    Department* get_department()
    {
        return department;
    }

    void set_salary(double salary)
    {
        this->salary = salary;
    }

    double get_salary()
    {
        return salary;
    }
    void set_degree(string degree)
    {
        this->degree = degree;
    }
    string get_degree()
    {
        return degree;
    }


};

class Student : public Person
{
private:
    int level;
    double gpa;
public:
    // Default constructor
    Student()
    {
        // cout<<"Student Default Constructor"<<endl;
    }
    // Parameterized constructor
    Student(int id,string name, double age, char gender, int level, double gpa)
            : Person(id,name, age, gender)
    {
        this->level = level;
        this->gpa = gpa;
        // cout << "Student Parameterized Constructor" << endl;
    }
    // Setters
    void set_level(int level)
    {
        this->level = level;
    }

    void set_gpa(double gpa)
    {
        this->gpa = gpa;
    }
    // Getters
    int get_level()
    {
        return level;
    }

    double get_gpa()
    {
        return gpa;
    }
};

class Course
{
private:
    string name;
    int course_hours;
    string course_code;
    Professor* professor;
    vector<Student*> students;
    vector<Course*> prerequestes;
public:
    Course()
    {
        //cout<<"Course default Constructor"<<endl;
    }
    Course(string c_name,  string c_code,int c_hours,vector<Course*> pre, Professor* prof,vector<Student*> stu)
    {
        name=c_name;
        course_hours=c_hours;
        course_code=c_code;
        professor=prof;
        students=stu;
        prerequestes=pre;
        // cout << "Parameterized Course Constructor"<<endl;
    }
    ~Course()
    {
        //  cout<<"Course Destructor"<<endl;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    void set_course_hours(int course_hours)
    {
        this->course_hours = course_hours;
    }
    int get_course_hours()
    {
        return course_hours;
    }
    void set_course_code(string course_code)
    {
        this->course_code = course_code;
    }
    string get_course_code()
    {
        return course_code;
    }
    void set_professor(Professor* professor)
    {
        this->professor = professor;
    }

    Professor* get_professor()
    {
        return professor;
    }
    void set_students(vector<Student*> student)
    {
        students=student;
    }

    vector<Student*> get_students()
    {
        return students;
    }

    void set_prerequestes(vector<Course*> prerequeste)
    {
        prerequestes=prerequeste;
    }

    vector<Course*> get_prerequestes()
    {
        return prerequestes;
    }
};

class University{
private:
    vector<Course>courses;
    vector<Student>students;
    vector<Department> departments;
    vector<Professor> professors;
    static University *instance;
    University(){}
public:
    University(const University& obj) = delete;
    static University *get_instance(){
        if(instance == NULL){
            instance = new University();
            return instance;
        }
        else{
            return instance;
        }
    }
    void add_course(string c_name, string c_code, int c_hours, vector<Course*> prerequestes, Professor* prof,vector<Student*> students)
    {

        if(c_hours>6 || c_name=="" || c_code=="")
        {
            cout<<"Cant add course!! "<<endl;
        }

        else
        {
            Course course1(c_name, c_code, c_hours,prerequestes, prof, students);
            courses.push_back(course1);
            cout<<"course added"<<endl;
        }
    }
    bool update_course(int c_hours, string c_code)
    {
        for(int i=0; i<courses.size(); i++)
        {
            if(courses[i].get_course_code()==c_code)
            {
                courses[i].set_course_code(c_code);
                cout<<"Course edited"<<endl;
                return true;
            }
            else
            {
                cout<<"There is no course with that course code to edit!"<<endl;
                return false;
            }
        }
    }
    void delete_course(string c_code)
    {
        int i=0;
        for(auto c = courses.begin(); c != courses.end(); ++c)
        {
            if(c->get_course_code()==c_code)
            {
                courses.erase(c);
                cout<<"Course removed"<<endl;
            }
            else
            {
                cout<<"There is no course with that code to remove!"<<endl;
            }
            i++;
        }
    }
    void add_student(int id, const std::string& name, int age, char gender,int level, double gpa) {
        Student student(id, name, age, gender, level, gpa);

        if (check(student.get_id())) {
            std::cout << "Invalid student ID" << std::endl;
        } else {
            students.push_back(student);
            std::cout << "Student added successfully." << std::endl;
        }
    }

    bool check(int id) {
        for (Student s : students) {
            if (s.get_id() == id) {
                return false;
            }
        }
        return true ;
    }



    void update(int id, double gpa) {
        bool found = false;

        for (Student s : students) {
            if (s.get_id() == id) {
                s.set_gpa(gpa);
                cout << "GPA updated for student with ID " << id <<" with gpa "<<gpa << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with ID " << id << " not found" << endl;
        }
    }

    void remove_student(int id) {
        bool flag = true;

        for (auto d = students.begin(); d != students.end(); ++d) {
            if (d->get_id() == id) {
                students.erase(d);
                cout << "Student with ID " << id << " removed" << endl;
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Student with ID " << id << " not found" << endl;
        }
    }
    void addDepartment(string name, double gpa, int capacity){
        Department department(name, gpa, capacity);
        if(check(department.getName())){
            cout<<"Cant add Department!!"<<endl;
        } else {
            departments.push_back(department);
            cout<<"Department added"<<endl;
        }

    }

    void updateDepartment(const string& name, int cap){
        for(int i=0; i<departments.size(); i++){
            if(departments[i].getName()== name) {
                departments[i].setCapacity(cap);
                cout<<"Department updated"<<endl;
                break;
            } else{
                cout<<"Department not found to be updated!!"<<endl;
            }
        }
    }

    void removeDepartment(string name){
        bool flag = true;
        for(int i=0; i<departments.size(); i++){
            if(departments[i].getName() == name) {
                departments.erase(departments.begin() + i);
                cout<<"Department removed"<<endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Department not found to be removed!!"<<endl;
        }
    }



    bool check(string name){
        for(Department d : departments){
            if(d.getName() == name) {
                return true;
                break;
            }
        }
        return false;
    }


    //Department class functions
    void addProfessor(int id,
                      string name,
                      int age,
                      char gender,
                      Department* &department,
                      double salary,
                      string degree) {
        // create professor obj
        Professor prof(id,name,age,gender,department,salary,degree);

        //check if the  professor is already exist in the vector
        if(checkProf(prof.get_id())){
            cout<<"Cant add prof!!"<<endl;
        } else {
            professors.push_back(prof);
            cout<<"Prof added"<<endl;
        }

    }

    void updateProfessor(int id, int salary){
        for(auto & professor : professors){
            if(professor.get_id() == id) {
                professor.set_salary(salary);
                cout<<"Prof updated"<<endl;
                break;
            } else{
                cout<<"Prof not found to update!!!"<<endl;
            }
        }
    }


    void removeProfessor(int id){
        bool flag2 = true;
        for(int i=0; i<professors.size(); i++){
            if(professors[i].get_id() == id) {
                // Delete department object
                delete professors[i].get_department();

                // Remove professor from vector
                professors.erase(professors.begin() + i);
                cout<<"Prof removed"<<endl;
                flag2 = false;
                break;
            }
        }
        if(flag2){
            cout<<"Can't find prof to remove!!"<<endl;
        }
    }



    bool checkProf(int id){
        for(Professor p : professors){
            if(p.get_id() == id) {
                return true;
                break;
            }
        }
        return false;
    }

    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);

        Student s2(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].getName()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].get_name()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].get_name()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].get_name()<<endl;
        }
    }

};
University* University::instance = NULL;

int main()
{

    vector <Student*> students;
    vector<Course*> prerequestes;
    University *university = University::get_instance();
    university->update_course(6,"MATH101");
    university->update_course(6,"MATH10");
    university->delete_course("MATH101");
    university->delete_course("MA10");
    university->add_student(22, "ahmed", 22, 'm' , 3, 3.3);
    //university->add_student(22, "ahmed", 22, "male", "three", 3.3);
    university->update(2,2.3);
    university->remove_student(22);
    university->update(22,2.3);
    university->addDepartment("test", 3.5, 120);
    //dep->addDepartment("test2", 2.8, 50);
    university->updateDepartment("test", 200);
    university->removeDepartment("test");
    university->removeDepartment("test");

    //Professor function
    Department* department = new Department("Department Name", 3.0, 50);
    university->addProfessor(1125,"mohamed",40,'m',department,5500,"Phd");
    university->updateProfessor(1125, 6000);
    university->updateProfessor(230, 6000);
    // university->printProf(1125);
    university->removeProfessor(1125);
    university->removeProfessor(1125);
    //prof->updateProfessor(1125, 6000);
    cout<<"////////////////////////////";

    university->addData();
    university->printAll();

    return 0;
}

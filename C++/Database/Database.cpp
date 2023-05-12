#include <iostream>
#include<string>
#include <vector>
using namespace std;


/***********************************Abstract class***************************/
class Person 
{
protected://as we can't make it private bec. they are inherited
    string name;
    int id;
public:
virtual string getName()=0;
virtual int getId()=0;
    Person(string name,int id)
    {
        this->name=name;
        this->id=id;
    }
    virtual void display(void)
    {
        cout<<"*********************Person data****************"<<endl;
        cout<<"name:"<<this->name<<endl; //<<name<<endl;
        cout<<"id:"<<this->id<<endl;
    }  
};


class Employee: public Person
{
    private:
    string department;
    double salary;
    public:
    Employee(string name,int id,string department,int salary):Person(name,id)
    {
        this->department=department;
        this->salary=salary;
    }
    string getDepartment()
    {
        return department;
    }
    double getSalary()
    {
        return salary;
    }
    string getName() override
    {
        return name;
    }
    int getId() override
    {
        return id;
    }
    void display(void) //override
    {
         Person::display();
        cout<<"department:"<<department<<endl;
        cout<<"salary:"<<salary<<endl;
    }

};

class Student:public Person
{
    private:
    string courses[10];
    int grades[10];
    bool attendance[10];
    int numCourses;
    public:
    Student(string name,int id):Person(name,id)
    {
        numCourses=0;
    }
    void addCourse(string course)
    {
        if (numCourses<10)
        {
            courses[numCourses]=course;
            grades[numCourses]=0;
            attendance[numCourses]=false;
            numCourses++;

        }
    }

    void updateGrade (string course,int grade)
    {
        for (int i = 0; i < numCourses; i++)
        {
            if(courses[i]==course)
            {
                grades[i]=grade;
                break;
            }
        }
        
    }
    void markAttendance (string course,bool attend)
    {
        for (int i = 0; i < numCourses; i++)
        {
           if(courses[i]==course)
            {
                attendance[i]=attend;
                break;
            }
        }
        
        
    }
    string getCourses(int i)
    {
        return courses[i];
    }
    int getNumOfCourses()
    {
        return numCourses;
    }
    double calculateGpa()
    {
        double sum=0;
        int count=0;
        for (int i = 0; i < numCourses; i++)
        {
            sum+=grades[i];
            count++;
        }
        return sum/count;
        
    }
    string getName() override
    {
        return name;
    }
    int getId() override
    {
        return id;
    }
    
};

class UndergraduateStudent:public Student
{
    private:
    string major;
    public:
    UndergraduateStudent (string name ,int id,string major):Student(name,id)
    {
        this->major=major;
    }
    string getMajor()
    {
        return this->major;
    }
    string getName() override
    {
        return name;
    }
    int getId() override
    {
        return id;
    }
};

class GraduateStudent:public Student
{
    private:
    string researchArea;
    public:
    GraduateStudent(string name,int id,string researchArea):Student(name,id)
    {
        this->researchArea=researchArea;
    }
    string getResearchArea()
    {
        return researchArea;
        
    }
     string getName() override
    {
        return name;
    }
    int getId() override
    {
        return id;
    }
};


int main()
{
// Person A("Omar",5);
// A.display();
// Employee citizen1 ("omar",394,"electrical",5000);
// citizen1.display();
vector<Person*>people;
int choice=0;
while (choice!=5)//as  to exit program  
{
    cout<<"1.Add Employee"<<endl;
    cout<<"2.Add Student"<<endl;
    cout<<"3.show all data"<<endl;
    cout<<"4.Delete person"<<endl;
    cout<<"5.exit"<<endl;    
    cout<<"enter choice"<<endl;
    cin>>choice;  
    switch (choice)
    { 
    case 1:
       {
        string name,department;
        int id;
        double salary; 
        cout<<"enter name:";
        cin>>name;
        cout<<"enter id:";
        cin>>id;
        cout<<"enter department:";
        cin>>department;
        cout<<"enter salary:";
        cin>>salary;
        Employee *emp=new Employee (name,id,department,salary);//create a new employee in the heap with new that returns address of that employee them i save it in the ptr emp
        people.push_back(emp);
        break;
       }
    case 2:
    {
        string name,type,courseOrResearchArea;
        int id;
        cout<<"enter name:";
        cin>>name;
        cout<<"enter id:";
        cin>>id;
        cout<<"enter type:";
        cin>>type;

        if (type=="graduate")      
        {
            cout<<"enter ResearchArea:";
            cin>>courseOrResearchArea;
            GraduateStudent * grad= new GraduateStudent (name,id,courseOrResearchArea);
            people.push_back(grad);
        }
        else if (type=="undergraduate")
        {
             cout<<"enter major:";
            cin>>courseOrResearchArea;
            UndergraduateStudent * undgr= new UndergraduateStudent (name,id,courseOrResearchArea);
            people.push_back(undgr);
        }
        break;
}
    case 3:
    {
        for(Person*Person :people)//a ptr of type person class loop over the vector people of type person class
        {
            cout<<"/********************************/"<<endl;
            cout<<"name:"<<Person->getName()<<endl;
            cout<<"name:"<<Person->getId()<<endl;
            Employee* emp=dynamic_cast<Employee*>(Person);
            if (emp!=NULL)
            {
                cout<<"department:"<<emp->getDepartment()<<endl;
                cout<<"salary:"<<emp->getSalary()<<endl;
            }
            else
            {
                Student* stu=dynamic_cast<Student*>(Person);
                if (stu!=NULL)
                {
                    cout<<"courses:";
                    for (int i = 0; i < stu->getNumOfCourses(); i++)
                    {
                        cout<<stu->getCourses(i)<<" ";
                    }
                    cout<<endl;
                    cout<<stu->calculateGpa()<<endl;
                    
                    UndergraduateStudent*undgrd=dynamic_cast<UndergraduateStudent*>(Person);
                    if(undgrd=NULL)
                    {
                        cout<<"major"<<undgrd->getMajor()<<endl;
                    }
                    else
                    {
                        GraduateStudent*grd=dynamic_cast<GraduateStudent*>(Person);
                        if (grd!=NULL)
                        {
                            cout<<"researchArea:"<<grd->getResearchArea()<<endl;
                        }
                    }
                }
                
            }
            
            

        }
        break;
    }
    case (4):
    {
        int id;
        cout<<"enter id of person to delete";
        cin>>id;
        for (auto it = people.begin(); it !=people.end(); it++)//iterator on people vector  (.end() returns a pointer points next to the last element in vector)
        {
            if ((*it)->getId()==id)
            
            {
               delete *it;//delete the element in that address of it
               people.erase(it);//delete pointer
               cout<<"person with id:"<<id<<"has been deleted"<<endl;
               break;
            }
            
        }
        cout<<endl;
        break;
    }
    }
}
     for (Person* Person: people)
        {
            delete Person;
        }
        people.clear();



return 0;
}




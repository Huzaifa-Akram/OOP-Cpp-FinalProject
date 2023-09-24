#include <iostream>
#include <vector>
#include <cstdlib>  // For generating random numbers
#include <ctime>    // For seeding random number generator
#include <limits>
#include <fstream>
using namespace std;

class AmazonCourse;
class ShopifyCourse;
class OOPCourse;
class GraphicDesignCourse;

// Base class for all courses
class Course {
public:
    virtual void displayCourseDetails() const = 0;
	virtual string courseName() const = 0;
};

// Derived classes for specific courses
class WebDevelopmentCourse : public Course {
	private:
    		string webdvlp_tasks[7] = {"HTML and CSS Fundamentals", "JavaScript Programming", "Responsive Web Design", "Front-End Frameworks",
											"Back-End Development", "Database Integration", "Version Control and Git"};
			string name = "Full Stack Web Development";
	protected:
		string courseName() const override
		{
			return name;
		}

		void displayCourseDetails() const override {
    	    cout << "\t\t Course: Web Development\n";
        	cout << "\t\t Course Code: wd101\n";
        	cout << "\t\t Duration: 8 weeks\n";
    	    cout << "\t\t Fee: $200\n";
	    }
	     
        friend void display_task(WebDevelopmentCourse, AmazonCourse, ShopifyCourse, OOPCourse, GraphicDesignCourse);
};

class AmazonCourse : public Course {
	private:
            string amazon_tasks[7] = {"AWS Fundamentals", "Amazon EC2 (Elastic Compute Cloud)", "Amazon S3 (Simple Storage Service)", 
									"AWS Lambda and Serverless Computing", "Amazon RDS (Relational Database Service)", "Amazon API Gateway",
									"AWS Security and Identity Services"};
			string name = "Amazon Course";
	protected:
	    void displayCourseDetails() const override {
    	    cout << "\t\t Course: Amazon Course\n";
        	cout << "\t\t Course Code: am101\n";
			cout << "\t\t Duration: 6 weeks\n";
    	    cout << "\t\t Fee: $150\n";
    	}

		string courseName() const override
		{
			return name;
		}

        friend void display_task(WebDevelopmentCourse, AmazonCourse, ShopifyCourse, OOPCourse, GraphicDesignCourse);
};

class ShopifyCourse : public Course {
    private:
        	string shopify_tasks[7] = {"Shopify Basics and Store Setup", "Product Management", "Theme Customization", "Shopify App Integration"
										"Order Processing and Fulfillment", "SEO and Online Marketing", "Analytics and Reporting"};
			string name = "Shpify Course";
    protected:
    	void displayCourseDetails() const override {
    	    cout << "\t\t Course: Shopify Course\n";
	        cout << "\t\t Course Code: sh101\n";
			cout << "\t\t Duration: 5 weeks\n";
    	    cout << "\t\t Fee: $120\n";
	    }

		string courseName() const override
		{
			return name;
		}
        friend void display_task(WebDevelopmentCourse, AmazonCourse, ShopifyCourse, OOPCourse, GraphicDesignCourse);
};

class OOPCourse : public Course {
	private:
        string oop_tasks[7] = {"start https://youtu.be/yNKjPgeLANc", "start https://youtu.be/LgpjvU2MCB4", "start https://youtu.be/oVMTRv7hGCY",
								"start https://youtu.be/pIXvFeVAECQ", "start https://youtu.be/JTJhwbamgDk", "start https://youtu.be/jJd55ftNcT8",
								"start https://youtu.be/UUbMDOYe0vU"};
		string name = "Object Oriented Programming By Adeel Ahmad";
	protected:
    	void displayCourseDetails() const override {
    	    cout << "\t\t Course: C++ with OOP\n";
    		cout << "\t\t Course Code: oop101\n";
		    cout << "\t\t Duration: 8 weeks\n";
    	    cout << "\t\t Fee: $180\n";
    	}

		string courseName() const override
		{
			return name;
		}

        friend void display_task(WebDevelopmentCourse, AmazonCourse, ShopifyCourse, OOPCourse, GraphicDesignCourse);
};

class GraphicDesignCourse : public Course {
	private:
            string graphicdsgn_tasks[7] = {"Introduction to Graphic Design", "Typography", "Color Theory", "Layout and Composition",
													"Adobe Creative Suite", "Visual Identity and Branding", "Web and UI/UX Design"};
			string name = "Graphics Designing";
	protected:
		void displayCourseDetails() const override {
        	cout << "\t\t Course: Graphic Designing\n";
		    cout << "\t\t Course Code: gd101\n";
			cout << "\t\t Duration: 7 weeks\n";
        	cout << "\t\t Fee: $160\n";
    	}

		string courseName() const override
		{
			return name;
		}
        friend void display_task(WebDevelopmentCourse, AmazonCourse, ShopifyCourse, OOPCourse, GraphicDesignCourse);
};

// Class to represent enrolled students
class Student : public WebDevelopmentCourse, public AmazonCourse, public ShopifyCourse, public OOPCourse, public GraphicDesignCourse {
    private:
			string name;
			int studentID;
			string password;
			vector<Course*> enrolledCourses;
	public:
			Student(string n) : name(n) {
				// Generate a random student ID (for simplicity, let's use a random number)
				studentID = rand() % 10000;
				// Generate a random password (for simplicity, let's use a fixed password)
				password = "student123";

				fstream myfile;
				myfile.open("student_record.txt", ios::app);
				if(myfile.is_open()){
					myfile << "student name : " << name << endl;
					myfile << "Student ID : " << studentID << endl;
					myfile << "Password : " << password << endl;
				}

			}

			void displayStudentInfo() const {
				cout << "\t\t Student Name: " << name << "\n";
				cout << "\t\t Student ID: " << studentID << "\n";
				cout << "\t\t Enrolled Courses:\n";
				for (const Course* course : enrolledCourses) {
					cout <<"\t\t "  << course->courseName() <<"\n";
				}
			}

			void operator +(Course* obj)
			{
				enrolledCourses.push_back(obj);
			}
};

void display_task(WebDevelopmentCourse obj1, AmazonCourse obj2, ShopifyCourse obj3, OOPCourse obj4, GraphicDesignCourse obj5){
	start:
		string get_course_code, course_codes[5] = {"wd101", "am101", "sh101", "oop101", "gd101"};
		int com_task;
		cout << "\t\t Enter your course code: ";
		cin >> get_course_code;
		if(get_course_code == course_codes[0]){
			cout << "\t\t How many task you have completed: ";
			cin >> com_task;
			cout << "\t\t Your today task is: " << obj1.webdvlp_tasks[com_task] << "\n\n";
		}else if(get_course_code == course_codes[1]){
			cout << "\t\t How many task you have completed: ";
			cin >> com_task;
			cout << "\t\t Your today task is: " << obj2.amazon_tasks[com_task] << "\n\n";
		}else if(get_course_code == course_codes[2]){
			cout << "\t\t How many task you have completed: ";
			cin >> com_task;
			cout << "\t\t Your today task is: " << obj3.shopify_tasks[com_task] << "\n\n";
		}else if(get_course_code == course_codes[3]){
			cout << "\t\t How many task you have completed: ";
			cin >> com_task;
			cout << "\t\t Your today task is Avaible on 'LandLord Academia A.A', Opening link......" << system(obj4.oop_tasks[com_task].c_str()) << "\n\n";
		}else if(get_course_code == course_codes[4]){
			cout << "\t\t How many task you have completed: ";
			cin >> com_task;
			cout << "\t\t Your today task is: " << obj5.graphicdsgn_tasks[com_task] << "\n";
		}else{
			cout << "\t\t incorrect course code\n";
			goto start;
		}
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    cout << "\t\t*************************************\n";
    cout << "\t\t*************************************\n";
    cout << "\t\t* Welcome to Information Technology *\n";
    cout << "\t\t*        Online Institute           *\n";
    cout << "\t\t*************************************\n";
    cout << "\t\t*      LandLord Academia A.A        *\n";
    cout << "\t\t*************************************\n";

    vector<Course*> courses;
    courses.push_back(new WebDevelopmentCourse());
    courses.push_back(new AmazonCourse());
    courses.push_back(new ShopifyCourse());
    courses.push_back(new OOPCourse());
    courses.push_back(new GraphicDesignCourse());
    
    start:
    while (true) {
        cout << "\t\t 1. Enroll for a Course\n";
        cout << "\t\t 2. View Today's Video Task\n";
        cout << "\t\t 3. Exit\n\n";
        cout << "\t\t Enter your choice: ";

        int choice;
        int courseChoice;
        cin >> choice;

        if (choice == 1) {
            cout << "\n\t\t Available Courses:\n";            
            cout << "\t\t 1. Web Development\n";
            cout << "\t\t 2. Amazon\n";
            cout << "\t\t 3. Shopify\n";
            cout << "\t\t 4. C++ with OOP\n";
            cout << "\t\t 5. Graphic Designing\n\n";
            cout << "\t\t In which course do u want to enroll? : ";
            cin >> courseChoice;
            while(courseChoice != 1 && courseChoice != 2 && courseChoice != 3 && courseChoice != 4 && courseChoice != 5)
			{
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input bufferg
                cout << "\t\t Please enter a valid choice : ";
				cin >> courseChoice;
            }
                // Ask for the student's name
                string studentName;
                cout << "\n\t\t Please enter your name: ";
                cin >> studentName;

                // Creating student object
                Student student(studentName);

                // Display course details and ask if the student wants to proceed
                cout << "\n\t\t Course Details:\n";
                courses[courseChoice - 1]->displayCourseDetails();

                char proceed;
                cout << "\n\t\t Do you want to proceed with enrollment? (y/n): ";
                cin >> proceed;

                if (proceed == 'y' || proceed == 'Y') {
                    student + (courses[courseChoice - 1]);
                    cout << "\n\t\t Enrolled successfully!\n\n";
					student.displayStudentInfo();
                } else {
                    cout << "\n\t\t Enrollment cancelled.\n\n";
                }
        } else if (choice == 2) {
            WebDevelopmentCourse obj1;
            AmazonCourse obj2;
            ShopifyCourse obj3;
            OOPCourse obj4;
            GraphicDesignCourse obj5;
            display_task(obj1, obj2, obj3, obj4, obj5);
        } else if (choice == 3) {
            break;
        } else  if (!(choice) || choice !=1 || choice !=2 || choice !=3) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input bufferg
            cout << "\n\t\t Invalid input. Please enter a number.\n\n";
            continue; 
        }
    }

    // Clean up allocated course objects
    for (Course* course : courses) {
        delete course;
    }

}

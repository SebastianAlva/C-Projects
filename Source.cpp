#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class Student
{
	//private variables 
	std::string m_first  = "first";
	std::string m_last   = "last";
	int			m_id     = 0;
	float		m_avg    = 0;

	public:
		//constructors
		Student() {}
		Student(std::string first, std::string last, int id, float avg) :
			m_first	(first),
			m_last	(last),
			m_id	(id),
			m_avg	(avg)
		{	
		}
		//methods
		int getAvg() const
		{
			return m_avg;
		}
		int getId() const
		{
			return m_id;
		}
		std::string getFirst() const 
		{
			return m_first;
		}
		std::string getLast() const
		{
			return m_last;
		}
		std::string getName() const
		{
			return getFirst() + " " + getLast();
		}
		void print() const
		{
			std::string fullInfo = m_first + " " + m_last+ " " + std::to_string(m_id)+ " " + std::to_string(m_avg);
			std::cout << fullInfo << std::endl;
		}
};		

class Course
{
	std::string m_name = "Course";
	std::vector<Student> m_students;

public:
	Course() {}
	Course(const std::string& name): m_name(name)
	{
	}
	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}
	const std::vector<Student>& getStudents() const
	{
		return m_students;
	}
	void print() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}
	void loadFromFiles(const std::string& s)
	{
		std::ifstream fin(s);
		std::string first, last;
		int id;
		float avg;
		while (fin >> first)
		{
			fin >> last >> id >> avg;
			addStudent(Student(first, last, id, avg));
			
		}

	}
};

//this is definition
int main(int argc, char * argv[])
{
	Course c("COMP 4300");
	c.loadFromFiles("C:\\Users\\Sebastian\\Desktop\\studentNames.txt");
	c.print();
	return 0;
}

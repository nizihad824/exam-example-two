#include<bits/stdc++.h>
using namespace std;
class Person;
class Lending;
static Lending *start;

class Medium
{
private:
	int number;
	string title;
public:
	Medium(int number, string title);
	virtual ~Medium() { cout << "Medium destructor" << endl; }
	void set_title(string );
	string get_title() {return title;};
	int get_number() { return number; }
	void virtual print() = 0;
};
Medium::Medium(int number, string title) : number(number),title(title) {}
void Medium::set_title(string t) { title = t; }
class PrintMedium : public Medium
{
public:
	PrintMedium(int number, string title) : Medium(number, title) {};
};

class Book : public PrintMedium
{
private:
	unsigned int isbn;
public:
	Book(int number, string title, unsigned int isbn) : PrintMedium(number, title), isbn(isbn) {};
	void print();
};

void Book::print()
{
	cout << "book number: " << Medium::get_number() << "Title: " << Medium::get_title() << "ISBN: " << isbn << endl;
}

class Person
{
private:
	unsigned int number;
	string name;
public:
	Person(int number, string name) : number(number), name(name) {};

	void print()
	{
		cout << "Person with passport number: " << number << ", name: " << name << endl;
	}
};
class Lending
{
private:
	Medium *medium;
	Person *person;
	Lending *next;
public:
	Lending(Medium *medium, Person *person, Lending *next)
	{
        this->medium=medium;
        this->person=person;
        this->next=next;
	}

	void print()
	{
		cout << "Lending" << endl;
		person->print();
		medium->print();
	}
                        /*public definition of a member function with name printAll without parameters and return value
                                     printing this object and all following ones in a list in a loop and calling member function print for
                               ach object*/
	void printAll()
	{
		Lending *temp = this;
        while (temp !=nullptr)
        {
            temp->print();
            temp = temp->next;
        }
    }
};




int main(void)
{
	Book b1(43, "America", 2222);
	Person p1(66, "Maria");

	Lending *l1  = new Lending(&b1, &p1, nullptr);//Insert into the list a new lending for book b1 and person p1.
	Book *b2 = new Book(63, "Asien", 5555);
	Person p2(88, "Lara");
	//you create an object. polka points to this object. its next points to spoz
	Lending *l2 = new Lending(b2, &p2,l1);
	l2->printAll();
    // l1->printAll();
	return 0;
}
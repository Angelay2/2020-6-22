#include <string>
#include <iostream>
using namespace std;


/*
�̳У�
class/struct �������ƣ��̳з�ʽ ��������
	������������࣬ӵ�и�������г�Ա��������Ա�����ͳ�Ա������
	1. �̳з�ʽ�� public��private��protected
	2. �����Ա������ķ���Ȩ��
		a. ����˽�г�Ա��private���������в��ɼ�
		b. ����������Ա�������еķ���Ȩ��Ϊmin{��Ա�ڻ����б���ķ���Ȩ�ޣ�����ļ̳з�ʽ}
	3. protected��public
		a. ����ʾ�����ⲻ����
		b. protected��Ա���������ǿɼ��ģ�������Ը���protected��Ա
		c. private��Ա��Ȼ�������в��ɼ��������������ǰ���private��
	4. һ��ʹ��public�̳С���Ϊprivate��protected�̳лᵼ�º������ʹ�ô�������
	protected���ڵ�ǰ���ⲻ�ɼ��������������пɼ�
	����private��Ա����������������ʲô��ʽ�̳ж��ǲ��ɼ��ģ� ������ǰ�࣬�����ط������ɼ������ౣ����private�ĳ�Ա ֻ�����ǲ����ö���

��д�̳з�ʽʱ��
	struct��������࣬ Ĭ�ϵļ̳з�ʽΪpublic
	class��������� Ĭ�ϵļ̳з�ʽΪprivate
�����ʽ��д���̳з�ʽ

�������������ͬ�������ĳ�Ա����ʱ�� �ڸ����������У�������Ǹ�������ֱ�ӰѸ�����Ǹ��������ص�������ֱ�ӷ��ʵ�����Ҫ�ڷ���ʱ���ϸ��ࣺ�������Ա����

�������أ� �̳й�ϵ�У���������ͬ�����ɺ�������
�������أ� ͬһ���������У���������ͬ��������ͬ�����ɺ�������
ͬ�����أ� �̳й�ϵ�У������������������ͬ�ĵĳ�Ա����Ա��������Ա������
	�������ܣ� �����Ҫ���ʸ���ͬ���ĳ�Ա����Ҫ�Ӹ��������򣬣����ࣺ�����ຯ������

���๹�죺 Ĭ�Ϻ���ʽ������߼���ͬ
���࿽�����죺 Ĭ�ϵ��ø��࿽�����죬��ʽ����֮���������ʽ���ÿ�������ʱ���������Զ�����Ĭ�Ϲ���
����ĸ�ֵ������� Ĭ�ϵ��ø���ĸ�ֵ���������ʽ����֮�󣬲����Զ����ø���ĸ�ֵ������� ������ʽָ�����ã�����͸���ĸ�ֵ���������ͬ������
����������� Ĭ�Ϻ���ʽ�����߼���ͬ

�̳й�ϵ�µ�������

*/

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//
//	void show(int a)
//	{
//		cout << "Person--> show()" << endl;
//	}
//
//	int _id = 10;
//protected:  //�ڵ�ǰ���ⲻ�ɼ��������������пɼ�
//	string _name = "peter"; // ����
//private: //������ǰ�࣬�����ط������ɼ�
//	int _age = 18; // ����
//};

//student�̳�person
//class/struct  ������ �� ��������
//class Student : public Person
//class Student : protected Person
//class��������࣬Ĭ�ϵļ̳з�ʽΪprivate
//class Student : public Person
//{
//public:
//	//ֻҪ���ຯ���͸���ĺ�������������ͬ���ͻṹ�ɺ�������
//	void show()
//	{
//		cout << "Student-->show()" << endl;
//		Person::show(10);
//	}
//	void showId()
//	{
//		cout << _id << endl;
//		cout << "Person::id:" << Person::_id << endl;
//	}
//
//	void set(int id)
//	{
//		_id = id;
//	}
////private:
//public:
//	int _id = 111111;
//};

//struct��������࣬Ĭ�ϵļ̳з�ʽΪpublic
//struct Student2 : Person
//{
//public:
//
//	void show()
//	{
//		cout << _name << endl;
//	}
//
//	void showId()
//	{
//		cout << _id << endl;
//	}
//
//	void set(int id)
//	{
//		_id = id;
//	}
////private:
//public:
//	int _id = 111111;
//};

//void test()
//{
//	Student st;
//	//st.Print();
//
//	/*Student2 st2;
//	st2.Print();*/
//
//	Person p;
//	p.Print();
//	//st._name = "123";
//
//	/*cout << sizeof(string) << endl;
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;*/
//}

//void test2()
//{
//	Student st;
//	Person p; 
//	//��Ƭ������������ã�ָ�붼����ֱ�Ӹ�ֵ������������ã�ָ�룬����Ҫ������ת��
//	p = st;
//	Person rp = st;
//	Person* ptr = &st;
//
//	int a = 3.5;  //��ʽ����ת��
//	Person p2;
//	//��������ܸ�ֵ���������
//	//st = (Student) p2;
//	//�����ָ��/���ÿ���ͨ��ǿ������ת������ֵ������ָ���������
//	//����������ת������ȫ, �п��ܷ���Խ��
//	//һ����Ҫ����ǿ��ת�������Բ��ð�ȫת����dynamic_cast
//	Student* ptr2 = (Student*)&p2;
//	Student& rs = (Student&)p2;
//	cout << ptr2->_id << endl;
//
//	Student* ptr3 = (Student*)ptr;
//	cout << ptr3->_id << endl;
//}
//
//void test3()
//{
//	Student st;
//	//��ǰ�����������еĳ�Ա����
//	st.show();  //A ���벻ͨ��   B Person->show   C Student->show  ---->  C
//	//�����������еĳ�Ա����
//	st.Person::show(10);
//
//	Person p;
//
//	st.showId();
//	st.set(10000);
//	st.showId();
//}

class Person
{
public:
	Person(int age = 18)
		:_age(age)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		:_age(p._age)
	{
		cout << "Person(const Person&)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_age = p._age;
		}
		cout << "Person& operator=()" << endl;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}

	//private:
protected:
	int _age;
public:
	static int _num;
};

int Person::_num = 10;

class Student : public Person
{
public:
	//���๹����Զ����ø��๹��
	//�����Ҫ�ڳ�ʼ���б��г�ʼ���̳��Ը���ĳ�Ա��������Ҫ���ø��๹�캯����ɳ�ʼ��
	//����ֱ���ڳ�ʼ���б��г�ʼ�������Ա
	Student(int id, int age)
		:_id(id)
		, Person(age)
	{
		_id = id;
		cout << "Student(int)" << endl;
	}
	//1. �������Զ����ɵ����࿽��������Զ����ø���Ŀ�������
	//2. �����ʽ��������Ŀ������죬Ĭ�ϻ��Զ����ø���Ĺ���
	//3. �����ʽ��������Ŀ������죬�����ڳ�ʼ���б���ָ�����ø���Ŀ������죬���ø��࿽������ʱ��������Ƭ����
	Student(const Student& st)
		: _id(st._id)
	{
		cout << "Student(const Student&)" << endl;
	}

	//1. �������Զ����ɵĸ�ֵ��������Զ����ø���ĸ�ֵ�����
	//2. �����ʽ����������ĸ�ֵ������������ڲ������Զ����ø���ĸ�ֵ������� ������ʽָ��
	Student& operator=(const Student& st)
	{
		if (this != &st)
		{
			//�͸��ำֵ���������ͬ�����أ� ��Ҫָ������������
			Person::operator=(st);
			_age = st._age;
			_id = st._id;
		}
		cout << "Student& operator=()" << endl;
		return *this;
	}

	// 1. �������Զ����ɵ������������Զ����ø������������
	// 2. �����ʽ����������������Ҳ���Զ��������������������ִ��˳������ִ�������������������߼����ڵ��ø�����������
	// 3. ���������������������������ڵײ�����ͬ��
	// 4. ����������Ҫ��ʽ���ã������������ᱻ�������Σ����ܻᵼ����Դ����ͷŵ�����
	~Student()
	{
		cout << "~Student()" << endl;
		/*Person::~Person();*/
	}
private:
	int _id = 2;
};

class Teacher : public Person
{

};

void test4()
{
	Student st(10, 30);

	Student st2 = st;
	Student st3(20, 20);
	st2 = st3;
}

void test5()
{
	Student st(10, 20);
}

void test6()
{
	Person p;
	Student s(10, 20);
	Teacher t;
	p._num = 1;
	s._num = 2;
	t._num = 3;
	int* ptr = &p._num;
	ptr = &s._num;
	ptr = &t._num;

}
int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}

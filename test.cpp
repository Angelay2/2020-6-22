#include <string>
#include <iostream>
using namespace std;


/*
继承：
class/struct 子类名称：继承方式 基类名称
	子类就是派生类，拥有父类的所有成员（包括成员变量和成员函数）
	1. 继承方式： public，private，protected
	2. 基类成员在子类的访问权限
		a. 基类私有成员（private）在子类中不可见
		b. 基类其他成员在子类中的访问权限为min{成员在基类中本身的访问权限，子类的继承方式}
	3. protected，public
		a. 都表示在类外不尅建
		b. protected成员在子类中是可见的，子类可以复用protected成员
		c. private成员虽然在子类中不可见，但是子类中是包含private的
	4. 一般使用public继承。因为private、protected继承会导致后面的类使用存在问题
	protected：在当前类外不可见，但是在子类中可见
	基类private成员在派生类中无论以什么方式继承都是不可见的， 除过当前类，其他地方都不可见，子类保存了private的成员 只不过是不可用而已

不写继承方式时：
	struct定义的子类， 默认的继承方式为public
	class定义的子类 默认的继承方式为private
最好显式地写出继承方式

父类和子类有相同函数名的成员函数时， 在各自作用域中，子类的那个函数会直接把父类的那个函数隐藏掉，不能直接访问到，需要在访问时加上父类：：父类成员函数

函数隐藏： 继承关系中，函数名相同，构成函数隐藏
函数重载： 同一个作用域中，函数名相同，参数不同，构成函数重载
同名隐藏： 继承关系中，父类和子类有名字相同的的成员（成员变量、成员函数）
	在子类总， 如果需要访问父类同名的成员，需要加父类作用域，（父类：：父类函数名）

子类构造： 默认和显式定义的逻辑相同
子类拷贝构造： 默认调用父类拷贝构造，显式定义之后，如果不显式调用拷贝构造时，编译器自动调用默认构造
子类的赋值运算符： 默认调用父类的赋值运算符。显式定义之后，不会自动调用父类的赋值运算符， 除非显式指定调用，子类和父类的赋值运算符构成同名隐藏
子类的析构： 默认和显式定义逻辑相同

继承关系下的析构：

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
//protected:  //在当前类外不可见，但是在子类中可见
//	string _name = "peter"; // 姓名
//private: //除过当前类，其它地方都不可见
//	int _age = 18; // 年龄
//};

//student继承person
//class/struct  类名称 ： 基类名称
//class Student : public Person
//class Student : protected Person
//class定义的子类，默认的继承方式为private
//class Student : public Person
//{
//public:
//	//只要子类函数和父类的函数，函数名相同，就会构成函数隐藏
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

//struct定义的子类，默认的继承方式为public
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
//	//切片：子类对象，引用，指针都可以直接赋值个父类对象，引用，指针，不需要做类型转换
//	p = st;
//	Person rp = st;
//	Person* ptr = &st;
//
//	int a = 3.5;  //隐式类型转换
//	Person p2;
//	//父类对象不能赋值给子类对象
//	//st = (Student) p2;
//	//父类的指针/引用可以通过强制类型转换，赋值给子类指针或者引用
//	//但是这样的转换不安全, 有可能访问越界
//	//一般需要进行强制转换，可以采用安全转换：dynamic_cast
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
//	//当前子类作用域中的成员函数
//	st.show();  //A 编译不通过   B Person->show   C Student->show  ---->  C
//	//父类作用域中的成员函数
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
	//子类构造会自动调用父类构造
	//如果需要在初始化列表中初始化继承自父类的成员变量，需要调用父类构造函数完成初始化
	//不能直接在初始化列表中初始化父类成员
	Student(int id, int age)
		:_id(id)
		, Person(age)
	{
		_id = id;
		cout << "Student(int)" << endl;
	}
	//1. 编译器自动生成的子类拷贝构造会自动调用父类的拷贝构造
	//2. 如果显式定义子类的拷贝构造，默认会自动调用父类的构造
	//3. 如果显式定义子类的拷贝构造，可以在初始化列表中指明调用父类的拷贝构造，调用父类拷贝构造时，发生切片操作
	Student(const Student& st)
		: _id(st._id)
	{
		cout << "Student(const Student&)" << endl;
	}

	//1. 编译器自动生成的赋值运算符会自动调用父类的赋值运算符
	//2. 如果显式定义了子类的赋值运算符，在其内部不会自动调用父类的赋值运算符， 除非显式指定
	Student& operator=(const Student& st)
	{
		if (this != &st)
		{
			//和父类赋值运算符构成同名隐藏， 需要指明父类作用域
			Person::operator=(st);
			_age = st._age;
			_id = st._id;
		}
		cout << "Student& operator=()" << endl;
		return *this;
	}

	// 1. 编译器自动生成的析构函数，自动调用父类的析构函数
	// 2. 如果显式定义了析构函数，也会自动调动父类的析构函数，执行顺序是先执行完子类析构函数的逻辑，在调用父类析构函数
	// 3. 父类析构和子类析构函数名，在底层是相同的
	// 4. 父类析构不要显式调用，否则父类析构会被调用两次，可能会导致资源多次释放的问题
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

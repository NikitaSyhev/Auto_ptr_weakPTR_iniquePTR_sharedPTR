//Этот проект создан с помощью классического шаблона
#include <iostream>
#include <memory>

class A {
public:
	//A(A& a) = delete;  - конструктор копирования
	A() {
		std::cout << "Constructor A" << std::endl;
	}
	~A() {
		std::cout <<  "Destructor A" << std::endl;
	}
};

class Point {
public:
	Point(int x, int y) : _x(x), _y(y) {
		std::cout << "Point constructor" << std::endl;
	}
	int getX() const {
		return _x;

	}
	~Point() {
		std::cout << "Point constructor" << std::endl;
	}
private:
	int _x;
	int _y;

};


template<class T>
class SmartPtr
{
	T* _ptr;
public:
	SmartPtr(T* t) :_ptr(t) {}
	T* operator->() {
		return _ptr;
	}
	~SmartPtr() {
		delete _ptr;
	}

};



//unique_ptr почти как и любой пользователький тип можно передавать в параметры функции по ссылке
void basicFunc(std::unique_ptr<Point>& p) {    //юник птр нельзя копировать, но передавать по ссылке можно
	std::cout << p->getX() << std::endl;

}


//class Parent{};
//class Child{};
//
//std::shared_ptr<Parent>SomeMetohod() {
//	Child b;
//	std::shared_ptr<Parent> a = std::make_shared<Parent>(b);
//	return a;
//
//}


//dynamic_cast<point*>


class IVehicle {
public:
	virtual int getSpeed() const = 0;
	virtual const std::string& getType() const = 0;
	virtual ~IVehicle(){}
};

class Car : public IVehicle
{
public:
	Car (int speed): _speed(speed) {}
	int getSpeed() const override {
		return _speed;
	}
	const std::string& getType() const override {
		return _type;
	}

private:
	int _speed;
	std::string _type = "Car";

};

class Van :public Car {
public:

	Van(int speed) : Car(speed) {}
	const std::string& getType() const override {
		return _type;
	}
private:
	int _speed;
	std::string _type = "Van";
};

void funcCar(std::shared_ptr<Car> carPtr) {
	std::cout << "Inside funcCar" << std::endl;
	std::cout << carPtr->getSpeed() << std::endl;
	std::cout << carPtr->getType() << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	//C++ 11 Depricated; C++17 deleted ( это про auto_ptr)
	//new A() - возвращает указатель на объект класса А
	//std::auto_ptr<A> p(new A());  // auto забирает у р обычное поведение ( ошибки в динамической памяти, можем из получить, nullptr ref
	//std::auto_ptr<A> p2 = p; // он опасный

	//A*a - newA();
	// 
	// Виды указателей
	//shared_ptr - имеет контрольный блок, в котором поимио прочего лежит счетчик указателей, когда удаляется shared удаляется объект
	//unique_ptr - гарантирует, что только 1 указатель будет владеть 1 объектом ( поэтому он уник ) 



	//std::unique_ptr<A>utpr(new A());
	//std::unique_ptr<A>uptr2 = unpr; // не может копироваться, из за конструктора копирования


	std::unique_ptr<Point> pPoint(new Point(5, 4));
	std::cout << pPoint->getX() << std::endl; // обращаемся через -> потому что, указатель, + перегруженный оператор
	//pPoint.get()->getX;   эта строка равна предыдущей строке
	//pPoint.release();
	//pPoint.redet();
	//cppreference

//	SmartPtr<Point>sm(new Point(5, 4));
	//std::cout << sm->getX() << std::endl;    - так создавать указатели не нужно, это не выгодно

	std::unique_ptr<Point> p5 = std::make_unique<Point>(5, 4); // правильный способ создания

	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);




	//работа с классами IVehicle -> Car - > Van
	
	std::shared_ptr<Van> v = std::make_shared<Van>(50);
	std::cout << v->getType() << std::endl;
	std::cout << v->getSpeed() << std::endl;
	std::cout << "-----------" << std::endl;
	std::shared_ptr<Car> c = std::dynamic_pointer_cast<Car>(v); // Car* c = dynamic_cast<Car*>(v) - слева умный указатель, справа обычный 

	std::cout << c->getSpeed() << std::endl;
	std::cout << c->getType() << std::endl;
	std::cout << "-----------" << std::endl;
	funcCar(c);    //cast изменения типа указателя, объект остается тот же самый

	//embedded  - встроенные системы, это факультатив для тех, кто с железом работать хочет











	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <algorithm>

using namespace std;
//створюємо абстрактний клас
class absClass
{
public:
	 //чисто віртуальні функції
	virtual string ToFile() = 0;
	virtual void WriteToConsole() = 0;
	virtual void setting() = 0;
	virtual string GetObjModel() = 0;

};


class Parent :public absClass {
protected:
	//лічильник для id контракту
	static int counter;
	// інформація про контракт
	string cName;
	int* cId = new int;
	//інформація про об'єкт
	string objModel;
	int objAge;
	string objOwner;


public:

	//переоприділення методів з абстрактного класу


	void setting() {}

	string GetcName() {
		return cName;
	}
	string GetObjModel() {
		return objModel;
	}
	int GetObjAge() {
		return objAge;
	}
	string GetObjOwner() {
		return objOwner;
	}
	int GetcId() {
		return *cId;
	}

	// оголошуєм пустий конструктор без параметрів 
	Parent() {
		cName = "";
		*cId = ++counter;
		objModel = "";
		objAge = NULL;
		objOwner = "";

	}
	//конструктор з параметрами
	Parent(string cName, string objName, int objPrice, string objDate) {
		this->cName = cName;
		*cId = ++counter;
		this->objModel = objName;
		this->objAge = objPrice;
		this->objOwner = objDate;

	}
	// конструктор копіювання
	Parent(const Parent& c) {
		cName = c.cName;
		cId = c.cId;
		objModel = c.objModel;
		objAge = c.objAge;
		objOwner = c.objOwner;
	}

	~Parent() {
		cout << "Object From Class Container : " << cName << " done\n";
		delete cId;
	}
	//перекритий метод
	void SetAge() {
		objAge = 100;
	}
	//метод виводу об'єкта для запису в файл
string ToFile() { return cName + " " + objModel + " " + to_string(objAge) + " " + objOwner ; }
//метод виводу а консоль
	void WriteToConsole() {
		cout << "\nCode of Car  : " << *cId << "\nName of Car : " << cName << "\nName of model : " << objModel << " |Age : " << objAge << " |Name of owner : " << objOwner << endl;
	}


};
//ініціалізуємо статичну змінну для визначення id контракту
int Parent::counter = 0;

// дочірній клас контракту-об'єкт постачання "Material"
class Derived : public Parent {
protected:
	//додаткове поле відносно батьківського класу-обсяг 
	string objDate_Register;
public:

	//3 конструктори(пустий без параметрів,з параметрами,копіювання)
	Derived() :Parent() {
		objDate_Register = "";
	}

	Derived(string cName, string objName, int objPrice, string objDate, string objAmount) :Parent(cName, objName, objPrice, objDate) {
		this->objDate_Register = objAmount;
	}

	Derived(const Derived& c) :Parent(c) {
		objDate_Register = c.objDate_Register;
	}
	//перекритий метод
	void SetAge() {
		objAge = 200;
	}
	//перевантажений віртуальний метод класу Contract
	string ToFile() { return cName + " " + objModel + " " + to_string(objAge) + " " + objOwner + " " +objDate_Register; }
	// деструктор
	~Derived() {
		cout << "\n\nObject From Class Material : " << cName << " done\n";
	}
	//новий метод відносно батьківського
	string GetObjDate() {
		return objDate_Register;
	}
	//метод редагування об'єкта
	void setting() {
		
		char op;
		while (true) {
			system("CLS");
			//за допомогою оператора switch вибираємо поле об'єкта і змінюємо
			cout << "1. Change name of car;\t(" << cName << ")" << endl;
			cout << "2. Change model.\t(" << objModel << ")" << endl;
			cout << "3. Change date of the car.\t(" << objDate_Register << ")" << endl;
			cout << "4. Change age.\t(" << objAge << ")" << endl;
			cout << "5. Change owner.\t(" << objOwner << ")" << endl;
			cout << "6. Exit" << endl;
			cin >> op;
			if (op == '6') {
				break;
			}
			switch (op) {
			case '1': {
				cout << "Name of car: " << cName << endl;
				string tmp;
				cout << "Enter new name of car : ";
				cin >> tmp;
				cName = tmp;
				break;
			}
			case '2': {
				cout << "Model : " << objModel << endl;
				string tmp;
				cout << "Enter new model : ";
				cin >> tmp;
				objModel = tmp;
				break;
			}
			case '3': {
				cout << "Date : " << objDate_Register << endl;
				string tmp;
				cout << "Enter new date : ";
				cin >> tmp;
				objDate_Register = tmp;
				break;
			}
			case '4': {
				cout << "Age : " << objAge << endl;
				int tmp;
				cout << "Enter new age : ";
				cin >> tmp;
				objAge = tmp;
				break;
			}

			case '5': {
				cout << "owner : " << objOwner << endl;
				string tmp;
				cout << "Enter owner : ";
				cin >> tmp;
				objOwner = tmp;
				break;
			}
			default: {
				cerr << "Error: wrong operation" << endl;
				system("Pause");
				break;
			}
			}
		}
	}
	//перевантажений віртуальний метод виводу на консоль
	void WriteToConsole() {
		cout << "\nCode of car  : " << *cId << "\nName of car : " << cName << "\nName of model : " << objModel << " |Age : " << objAge << " |Owner : " << objOwner << " |Date : " << objDate_Register << endl;
	}

	
};
//// Functor
class Functor {

public:
	// перевантажуємо оператор ()
	bool operator()(Parent* v1, Parent* v2) {
		//проходимось по цінах об'єкта
		return v1->GetObjAge() > v2->GetObjAge();
	}

};
//клас для зберігання об'єктів і виконань певних операцій
class Operation {
	//створюємо вектор динамічного масиву типу Contract 
	vector<Parent*> data;
public:
	//в конструторі зчитуємо об'єкти з файлу,в деструкторі записуєм в файл
	Operation() {
				ReadFromStorage();
	}
		
			~Operation() {
				WriteToStorage();
			
				
			}
			//метод зчитування з файлу
	void ReadFromStorage()
	{
		//відкриваєм файл
		ifstream myfile("file.txt");
		string _cName;
		string _objName;
		int _objPrice;
		string _ObjOwner;
		string _objDate;
	
		//якщо не відкривається,видає помилку
		if (!myfile)
		{
			throw("Error: file.txt not found");

		}
		//зчитуєм через пробіл поля об'єкту,записуєм дані в дин. змінну дочірнього класу і зикидаєм в масив
		for (int i = 0; myfile; i++) {
			if (myfile >> _cName >> _objName >> _objPrice >> _ObjOwner >> _objDate)
			{
				Derived* tmp = new Derived(_cName, _objName, _objPrice, _ObjOwner, _objDate);
				data.push_back(tmp);
			}
		}
		myfile.close();
	}
	 //метод запису в файл
	void WriteToStorage() {
		ofstream outf("OUT.txt", ios::out);
		if (!outf)
		{
			throw("Error: fileOut.txt not found");

		}
		else {
			for (int i = 0; i < data.size(); i++) {
				outf << data[i]->ToFile() << endl;
			}
		}
		outf.close();
	}
	//метод для виводу на консоль
	void Write() {
		for (int i = 0; i < data.size(); i++) {
			data[i]->WriteToConsole();
		}
	}

	
	
	//метод для редагування об'єкту
	void setting() {
		cout << "- - - - - - - - - - - - - - - "<<endl;
		Write();
		cout << "Enter code of car : ";
		vector<Parent*>::iterator it;
		int i;
		cin >> i;
		//знаходимо ітератор об'єкта,який шукаєм по id
		it = find_if(data.begin(), data.end(), [&](Parent* tmp) {return tmp->GetcId() == i; });
		//знахолимо індекс потрібного контракту і виликаєм метод setting 
		data[it - data.begin()]->setting();
		

	}
	//метод знаходження елементу
	void Findelem() {
	
		cout << endl;
		cout << "- - - - - - - - - - - - - -"<<endl;
		cout << "Enter the model of car you want to find:" << endl;
		string tmp;
		cin >> tmp;
		//знаходимо ітератор потрібного об'єкту,який знаходим за назвою
		auto q = find_if(data.begin(), data.end(), [&](absClass * c) {
			return c->GetObjModel() == tmp;
		
		});
		cout << "Here is the info of object you seeked for: " << endl;
		//записуєм на консоль
		(*q)->WriteToConsole();
		
	}
	//реалізовуєм оператор додавання 
	Operation& operator+(Derived*& other)
	{

		data.push_back(other);

		return *this;
	}
	
	// реєстрація
	void Registration() {
				string _cName;
				string _objName;
				int _objPrice;
				string _objOwner;
				string _objDate;
				cout << "- - - - - - - -  - - -"<<endl;
				cout << "Enter name of car : ";
				cin >> _cName;
				cout << "Enter model of the car : ";
				cin >> _objName;
				cout << "Enter age : ";
				cin >> _objPrice;
				cout << "Enter owner : ";
				cin >> _objOwner; 
				cout << "Enter date : ";
				cin >> _objDate;
		
				Derived *m=new Derived(_cName, _objName, _objPrice, _objOwner, _objDate);
				
		
				//додаєм новий об'єкт до масиву
				
			
				
				  data.push_back(m);
			
				WriteToStorage();
				cout << "The registration has been made\n";
			}
	//статистика об'єктів за віком
	void Statistics() {
				Functor f;
				//для сортування використовуємо функтор
				sort(data.begin(), data.end(), f);
				cout << "- - - - - - - - - - - - - -" << endl;
				cout << "\nStatistic of products: " << endl;
				Write();
			}
		
	};
	//інтерфейс користувача
void ForUSER() {
	Operation op;
	short tmp = NULL;
	while (true) {
		//вибираємо опціі,які хочемо виконати
		cout << 
			"\t\tSelect option: \n" <<
			"1.Show Available Cars\n" <<
			"2.Register a car\n" <<
			"3.Show statistics of products by age\n" <<
			"4.Find the info of the car by model\n" <<
			"5.Edit the product\n"<<
			"0.Exit\n\n";
		cin >> tmp;
		switch (tmp)
		{
		case 1: {
		
			op.Write();
			system("Pause");
			break;

		}
		case 2: {
			system("CLS");
			op.Registration();
			system("Pause");
			break;
		}
		case 0: {
			op.~Operation();
			exit(1);
			break;
		}
		case 3: {

			op.	Statistics();
			system("Pause");
			break;
		}
		case 4: {
		
			op.Findelem();
			system("Pause");
			break;
		}
		case 5: {

			op.setting();
			system("Pause");
			break;
		}
		
		default:
			cerr << "Error" << endl;
			system("Pause");
			break;
		}
	}
}

	int main() {
		//використовуємо перевірку на помилки
		try {
			// викликаєм функцію інтерфейсу користувача
			ForUSER();

		}
		catch (const char* err) {
			cerr << err << endl;
		}

		return 0;
	}

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility> 
#include <iterator>
#include <stdio.h>
#include <algorithm>
#include <istream>
using namespace std;

class Product {
public:

	Product() {
	}

	Product(int code, string model, string builder, string photo, string description, float price, int value) {
		this->code = code;
		this->model = model;
		this->builder = builder;
		this->photo = photo;
		this->description = description;
		this->price = price;
		this->value = value;
	}

	int getCode() {
		return code;
	}

	void setCode(int code) {
		this->code = code;
	}

	string getModel() {
		return model;
	}

	void setModel(string model) {
		this->model = model;
	}
	string getBuilder() {
		return builder;
	}

	void setBuilder(string builder) {
		this->builder = builder;
	}
	string getPhoto() {
		return photo;
	}

	void setPhoto(string photo) {
		this->photo = photo;
	}
	string getDescription() {
		return description;
	}

	void setDescription(string description) {
		this->description = description;
	}
	float getPrice() {
		return price;
	}

	void setPrice(float price) {
		this->price = price;
	}
	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}
	

private:
	int code, value;
	string builder, model, description, photo;
	float price;
	
};

class Laptops : public Product {
public:

	Laptops() {
	}

	Laptops(int ram, int speedCPU, string disk, int disksize, string graphicard, int code, string model, string builder, string photo, string description, float price, int value) :
		Product(code, model, builder, photo, description, price, value)
	{
		this->ram = ram;
		this->speedCPU = speedCPU;
		this->disk = disk;
		this->disksize = disksize;
		this->graphicard = graphicard;
	}
	Laptops(string strLaptops) {
		istringstream issin(strLaptops);
		string split[12];
		int i = 0;

		while (getline(issin, split[i], '|')) {
			i++;
		}
		setCode(stoi(split[0]));
		setModel(split[1]);
		setBuilder(split[2]);
		setPhoto(split[3]);
		setDescription(split[4]);
		setPrice(stof(split[5]));
		setValue(stoi(split[6]));
		this->ram = stoi(split[7]);
		this->speedCPU = stoi(split[8]);
		this->disk = split[9];
		this->disksize = stoi(split[10]);
		this->graphicard = split[11];
	}
	void save(ofstream &outfile) {
		outfile << this->toString() << endl;
	}

	string toString() {
		string str = to_string(getCode()) + "|" + getModel() + "|" + getBuilder() + "|" + getPhoto() + "|" + getDescription() + "|" + to_string(getPrice()) + "|" + to_string(getValue()) + "|" + to_string(ram) + "|" + to_string(speedCPU) + "|" + disk + "|" + to_string(disksize) + "|" + graphicard;
		return str;
	}

	int getRam() {
		return ram;
	}

	void setRam(int ram) {
		this->ram = ram;
	}

	int getSpeedCPU() {
		return speedCPU;
	}

	void setSpeedCPU(int speedCPU) {
		this->speedCPU = speedCPU;
	}

	string getDisk() {
		return disk;
	}

	void setDisk(string disk) {
		this->disk = disk;
	}


	int getDiskSize() {
		return disksize;
	}

	void setDiskSize(int disksize) {
		this->disksize = disksize;
	}

	string getGraphiCard() {
		return graphicard;
	}

	void setGraphiCard(string graphicard) {
		this->graphicard = graphicard;
	}
private:
	int ram, speedCPU, disksize;
	string disk, graphicard;

};
class SmartPhones : public Product {
public:

	SmartPhones() {
	}

	SmartPhones(string  screensize, int batterylife, string video4d, int code, string model, string builder, string photo, string description, float price, int value) :
		Product(code, model, builder, photo, description, price, value)
	{
		this->screensize = screensize;
		this->batterylife = batterylife;
		this->video4d = video4d;
	}

	SmartPhones(string strSmartphones) {
		istringstream issin(strSmartphones);
		string split[10];
		int i = 0;

		while (getline(issin, split[i], '|')) {
			i++;
		}
		setCode(stoi(split[0]));
		setModel(split[1]);
		setBuilder(split[2]);
		setPhoto(split[3]);
		setDescription(split[4]);
		setPrice(stof(split[5]));
		setValue(stoi(split[6]));
		this->screensize = split[7];
		this->batterylife = stoi(split[8]);
		this->video4d = split[9];

	}
	void save(ofstream &outfile) {
		outfile << this->toString() << endl;
	}

	string toString() {
		string str = to_string(getCode()) + "|" + getModel() + "|" + getBuilder() + "|" + getPhoto() + "|" + getDescription() + "|" + to_string(getPrice()) + "|" + to_string(getValue()) + "|"  + screensize + "|" + to_string(batterylife) + "|" + video4d;
		return str;
	}

	string getScreenSize() {
		return screensize;
	}

	void setScreenSize(string screensize) {
		this->screensize = screensize;
	}

	int getBatteryLife() {
		return batterylife;
	}

	void setBatteryLife(int batterylife) {
		this->batterylife = batterylife;
	}

	string getVideo4d() {
		return video4d;
	}

	void setVideo4d(string video4d) {
		this->video4d = video4d;
	}

private:
	string screensize, video4d;
	int  batterylife;  
};
class TV : public Product {
public:

	TV() {
	}

	TV(int  inches, string company, string video4d, int code, string model, string builder, string photo, string description, float price, int value) :
		Product(code, model, builder, photo, description, price, value)
	{
		this->inches = inches;
		this->company = company;
		this->video4d = video4d;
	}

	TV(string strTvs) {
		istringstream issin(strTvs);
		string split[10];
		int i = 0;

		while (getline(issin, split[i], '|')) {
			i++;
		}
		setCode(stoi(split[0]));
		setModel(split[1]);
		setBuilder(split[2]);
		setPhoto(split[3]);
		setDescription(split[4]);
		setPrice(stof(split[5]));
		setValue(stoi(split[6]));
		this->inches = stoi(split[7]);
		this->company = split[8];
		this->video4d = split[9];

	}
	void save(ofstream &outfile) {
		outfile << this->toString() << endl;
	}

	string toString() {
		string str = to_string(getCode()) + "|" + getModel() + "|" + getBuilder() + "|" + getPhoto() + "|" + getDescription() + "|" + to_string(getPrice()) + "|" + to_string(getValue()) + "|"  + to_string(inches) + "|" + company + "|" + video4d;
		return str;
	}

	int getInches() {
		return inches;
	}

	void setInches(int inches) {
		this->inches = inches;
	}

	string getCompany() {
		return company;
	}

	void setCompany(string company) {
		this->company = company;
	}

	string getVideo4d() {
		return video4d;
	}

	void setVideo4d(string video4d) {
		this->video4d = video4d;
	}

private:
	string company, video4d;
	int inches;
};

typedef struct pro_basket {
	Product product;
	int qty;
	float tk;
};

class Users {
public:

	Users() {
	}

	Users(string username, string password) {
		this->username = username;
		this->password = password;

	}
	Users(string strUsers) {
		istringstream issin(strUsers);
		string split[2];
		int i = 0;

		while (getline(issin, split[i], '|')) {
			i++;
		}

		this->username = split[0];
		this->password = stoi(split[1]);
	}
	void save(ofstream &outfile) {
		outfile << this->toString() << endl;
	}

	string toString() {
		string str = username + "|" + password;
		return str;
	}
	string getUsername() {
		return username;
	}

	void setUsername(string username) {
		this->username = username;
	}

	string getPassword() {
		return password;
	}

	void setPassword(string password) {
		this->password = password;
	}

private:
	string username, password;

};
class Admins : public Users {
public:

	Admins() {
	}

	Admins(int accessid, string username, string password) : Users(username, password)
	{
		this->accessid = accessid;
	}

	int getAccessId() {
		return accessid;
	}

	void setAccessId(int accessid) {
		this->accessid = accessid;
	}

private:
	int accessid;
};

class Customers : public Users {
public:

	Customers() {
	}

	Customers(string afm, string phonenumber, string address, string username, string password) :
		Users(username, password)
	{
		this->afm = afm;
		this->phonenumber = phonenumber;
		this->address = address;

	}


	Customers(string strCustomer) {
		istringstream issin(strCustomer);
		string split[3];
		int i = 0;

		while (getline(issin, split[i], '|')) {
			i++;
		}

		this->afm = split[0];
		this->phonenumber = split[1];
		this->address = split[2];
	}
	void save(ofstream &outfile) {
		outfile << this->toString() << endl;
	}

	string toString() {
		string str = afm + "|" + phonenumber + "|" + address;
		return str;
	}

	string getAfm() {
		return afm;
	}

	void setAfm(string afm) {
		this->afm = afm;
	}

	string getPhoneNumber() {
		return phonenumber;
	}

	void setPhoneNumber(string phonenumber) {
		this->phonenumber = phonenumber;
	}

	string getAddress() {
		return address;
	}

	void setAddress(string address) {
		this->address = address;
	}

private:
	string address, afm , phonenumber;
};
class CustomersPhisical : public Customers {
public:

	CustomersPhisical() {
	}

	CustomersPhisical(string name, string nickname, string at, string afm, string phonenumber, string address, string username, string password) :
		Customers(afm, phonenumber, address, username, password)
	{
		this->name = name;
		this->nickname = nickname;
		this->at = at;

	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getNickName() {
		return nickname;
	}

	void setNickName(string nickname) {
		this->nickname = nickname;
	}

	string getAT() {
		return at;
	}

	void setAT(string at) {
		this->at = at;
	}



private:
	string name, nickname, at;
};
class CustomersCompany : public Customers {
public:

	CustomersCompany() {
	}

	CustomersCompany(string name, string contact, float discount, int fax, string afm, string phonenumber, string address, string username, string password) :
		Customers(afm, phonenumber, address, username, password)
	{
		this->name = name;
		this->contact = contact;
		this->discount = discount;
		this->fax = fax;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	string getContact() {
		return contact;
	}

	void setContact(string contact) {
		this->contact = contact;
	}

	float getDiscount() {
		return discount;
	}

	void setDiscount(float discount) {
		this->discount = discount;
	}
	int getFax() {
		return fax;
	}

	void setFax(int fax) {
		this->fax = fax;
	}

private:
	string name, contact;
	int fax;
	float discount;
};


class ProductCataloge {
public:

	ProductCataloge() {
	}

	ProductCataloge(int available)
	{
		this->available = available;

	}

	int getAvailable() {
		return available;
	}

	void setAvailable(bool available) {
		this->available = available;
	}
	/*string DisplayProduct()
	{
	ostringstream ss;
	ss <<  Product.getCode() << "\t" << available;
	return ss.str();
	}*/
private:

	int available;

};
class Basket {
public:

	Basket() {
	};

	void addProduct(pro_basket p) {
		basket.push_back(p);
	};

	vector<pro_basket> getBasket() {
		return basket;
	};
private:
	vector<pro_basket> basket;
};
class Order {
public:
	enum STATUS {
		PENDING,
		IN_SEND,
		FINISHED,
		CANCELLED
	};
	Order() {
	}
	
	Order(STATUS status, pair < Customers , vector<pro_basket> > orderItem) {
		this->status = status;
		this->orderItem = orderItem;
	}

	//Order(const Order &orig) {
	//}
	STATUS Order::getStatus() {
		return status;
	}
	void setStatus(Order::STATUS status) {
		this->status = status;
	}
	pair<Customers , vector <pro_basket> > getOrderItem() {
		return orderItem;

	}
	void setOrderItem(pair<Customers , vector<pro_basket> > orderItem) {
		this->orderItem = orderItem;
	}
	/*Order(Basket basket , Customers customer) {
	this->basket = basket;
	this->customer = customer;
	}
	Basket getBasket() {
	return basket;
	}
	void setBasket() {
	this->basket = basket;
	}
	Customers getCustomer() {
	return customer;
	}
	void setCustomer() {
	this->customer = customer;
	}
	void newOrder(Order o) {
	orders.push_back(o);
	}

	vector<Order> getOrder() {
	return orders;
	}
	/*Order::STATUS getStatus() {
	return status;
	}

	void setStatus(Order::STATUS status) {
	this->status = status;
	}*/
private:
	STATUS status;
	pair <Customers , vector<pro_basket> >  orderItem;
};

void writeUsers() {

	ofstream outfile;
	outfile.open("user.dat", ios::app);

	bool read = true;
	while (read) {
		Users user = Users();
		cout << "Please enter Username: " << endl;
		string username;
		cin >> username;
		user.setUsername(username);
		cout << "Please enter the Password: " << endl;
		string pass;
		cin >> pass;
		user.setPassword(pass);


		user.save(outfile);
		char action;
		cout << "Would you like to add another User? (y/n): ";
		cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	outfile.close();
}
void add_Product() {
	
	bool read = true;	
			while (read) {

				int act;
				cout << "Please type the letter for the action you want to do" << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "1: laptops                                          " << endl;
				cout << "2: smartphone                                       " << endl;
				cout << "3: tv                                               " << endl;
				cout << "----------------------------------------------------" << endl;
				cin >> act;

				if (act == 1)
				{
					ofstream outfile;
					outfile.open("laptop.dat", ios::app);

					Laptops laptops = Laptops();

					cout << "Please enter Ram " << endl;
					int ram;
					cin >> ram;
					laptops.setRam(ram);

					cout << "Please enter the SpeedCPU : " << endl;
					int speedCPU;
					cin >> speedCPU;
					laptops.setSpeedCPU(speedCPU);

					cout << "Please enter the Disk : " << endl;
					string disk;
					cin >> disk;
					laptops.setDisk(disk);

					cout << "Please enter the DiskSize  : " << endl;
					int disksize;
					cin >> disksize;
					laptops.setDiskSize(disksize);

					cout << "Please enter the GraphiCard : " << endl;
					string graphicard;
					cin >> graphicard;
					laptops.setGraphiCard(graphicard);

					cout << "Please enter the Code : " << endl;
					int code;
					cin >> code;
					laptops.setCode(code);

					cout << "Please enter the Model: " << endl;
					string model;
					cin >> model;
					laptops.setModel(model);

					cout << "Please enter the Builder : " << endl;
					string builder;
					cin >> builder;
					laptops.setBuilder(builder);

					cout << "Please enter the Photo : " << endl;
					string photo;
					cin >> photo;
					laptops.setPhoto(photo);

					cout << "Please enter the Description : " << endl;
					string description;
					cin >> description;
					laptops.setDescription(description);

					cout << "Please enter the Price : " << endl;
					float price;
					cin >> price;
					laptops.setPrice(price);

					cout << "Please enter the Value : " << endl;
					int value;
					cin >> value;
					laptops.setValue(value);

					laptops.save(outfile);
					outfile.close();
				}

				if (act == 2)
				{
					ofstream outfile;
					outfile.open("smartphone.dat", ios::app);

					SmartPhones smartphones = SmartPhones();

					cout << "Please enter ScreeSize " << endl;
					string  screensize;
					cin >> screensize;
					smartphones.setScreenSize(screensize);

					cout << "Please enter the  BatteryLife : " << endl;
					int batterylife;
					cin >> batterylife;
					smartphones.setBatteryLife(batterylife);

					cout << "Please enter the  Video4d : " << endl;
					string video4d;
					cin >> video4d;
					smartphones.setVideo4d(video4d);

					cout << "Please enter the Code : " << endl;
					int code;
					cin >> code;
					smartphones.setCode(code);

					cout << "Please enter the Model: " << endl;
					string model;
					cin >> model;
					smartphones.setModel(model);

					cout << "Please enter the Builder : " << endl;
					string builder;
					cin >> builder;
					smartphones.setBuilder(builder);

					cout << "Please enter the Photo : " << endl;
					string photo;
					cin >> photo;
					smartphones.setPhoto(photo);

					cout << "Please enter the Description : " << endl;
					string description;
					cin >> description;
					smartphones.setDescription(description);

					cout << "Please enter the Price : " << endl;
					float price;
					cin >> price;
					smartphones.setPrice(price);

					cout << "Please enter the value : " << endl;
					int value;
					cin >> value;
					smartphones.setValue(value);

					smartphones.save(outfile);
					outfile.close();
				}

				if (act == 3)
				{
					ofstream outfile;
					outfile.open("tv.dat", ios::app);

					TV  tv = TV();

					cout << "Please enter inches " << endl;
					int  inches;
					cin >> inches;
					tv.setInches(inches);

					cout << "Please enter the  company name : " << endl;
					string company;
					cin >> company;
					tv.setCompany(company);

					cout << "Please enter the  Video4d : " << endl;
					string video4d;
					cin >> video4d;
					tv.setVideo4d(video4d);

					cout << "Please enter the Code : " << endl;
					int code;
					cin >> code;
					tv.setCode(code);

					cout << "Please enter the Model: " << endl;
					string model;
					cin >> model;
					tv.setModel(model);

					cout << "Please enter the Builder : " << endl;
					string builder;
					cin >> builder;
					tv.setBuilder(builder);

					cout << "Please enter the Photo : " << endl;
					string photo;
					cin >> photo;
					tv.setPhoto(photo);

					cout << "Please enter the Description : " << endl;
					string description;
					cin >> description;
					tv.setDescription(description);

					cout << "Please enter the Price : " << endl;
					float price;
					cin >> price;
					tv.setPrice(price);

					cout << "Please enter the Code : " << endl;
					int value;
					cin >> value;
					tv.setValue(value);

					tv.save(outfile);
					outfile.close();
				}

				char action;
				cout << "Would you like to add another Product? (y/n): ";
				cin >> action;

				if (action == 'y') {
					continue;
				}
				else {
					break;
				}
			}
}
void remove_Product(vector<Laptops> &laptop, vector<SmartPhones> &smartphone, vector<TV> &tv) {

	bool read = true;
		while (read) {

			int act;
			cout << "Please type the letter for the action you want to do" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "1: laptops                                          " << endl;
			cout << "2: smartphone                                       " << endl;
			cout << "3: tv                                               " << endl;
			cout << "----------------------------------------------------" << endl;
			cin >> act;

			if (act == 1) {
				int i;
				cout << "Please type the number to remove Laptop" << endl;
				cin >> i;
				laptop.erase(laptop.begin() + i);
			}
			if (act == 2) {
				int i;
				cout << "Please type the number to remove SmartPhone" << endl;
				cin >> i;
				smartphone.erase(smartphone.begin() + i);
			}
			if (act == 3) {
				int i;
				cout << "Please type the number to remove TV" << endl;
				cin >> i;
				tv.erase(tv.begin() + i);
			}

			char action;
			cout << "Would you like to remove another Product? (y/n): ";
			cin >> action;

			if (action == 'y') {
				continue;
			}
			else {
				break;
			}
		}
}
/*void saveNewFile(vector<Laptops> &laptop) {
	vector<Laptops> &laptop, vector<SmartPhones> &smartphone, vector<TV> &tv
	remove("laptop.dat");
	ofstream outfile;
	outfile.open("laptop.dat", ios::app);
	outfile.write(static_cast<vector<Laptops *>>(&laptop), laptop.size()*sizeof(int));
	ostream_iterator<vector<Laptops>> out_iter(outfile);
	copy(laptop.begin(), laptop.end(), ostream_iterator<Laptops>(outfile));
	laptop.save(outfile);
	outfile.close(); 
	for (int i = 0; i < laptop.size(); i++)
	{
		copy(laptop.begin(), laptop.end(), ostream_iterator<float>(outfile, "|"));
	}
	lapt.save(outfile);
	outfile.close();

	remove("smartphone.dat");
	ofstream outfile1;
	outfile1.open("smartphone.dat", ios::app);
	 SmartPhones smart = SmartPhones();
	for (int i = 0; i < smartphone.size(); i++)
	{
		copy(smartphone.begin(), smartphone.end(), ostream_iterator<float>(outfile1, "|"));
	}
	smart.save(outfile1);
	outfile1.close();

	remove("tv.dat");
	ofstream outfile2;
	outfile2.open("tv.dat", ios::app);
	TV tvs = TV();
	for (int i = 0; i < tv.size(); i++)
	{
		copy(tv.begin(), tv.end(), ostream_iterator<float>(outfile2, "|"));
	}
	tvs.save(outfile2);
	outfile2.close();
}*/
Customers addCustomers() {
	ofstream outfile;
	outfile.open("Customers.dat", ios::app);


	Customers customer = Customers();
	
	cout << "Please enter the afm: " << endl;
	string afm;
	cin >> afm;
	customer.setAfm(afm);

	cout << "Please enter the phonenumber: " << endl;
	string phonenumber;
	cin >> phonenumber;
	customer.setPhoneNumber(phonenumber);

	cout << "Please enter the aderss: " << endl;
	string address;
	cin >> address;
	customer.setAddress(address);

	
	customer.save(outfile);
	outfile.close();
	return customer;
}
void printCustomers(vector<Customers> &customers) {

	ifstream infile;
	infile.open("Customers.dat");

	string strCustomers;
	cout << "Reading from the file" << endl;

	while (infile.good()) {
		getline(infile, strCustomers);
		if (strCustomers.length() > 1) {
			customers.push_back(Customers(strCustomers));
		}
	}

	infile.close();

	for (int i = 0; i < customers.size(); i++) {
		cout << " afm: " << customers[i].getAfm() << " phonenumber: " << customers[i].getPhoneNumber() <<  " adress: " << customers[i].getAddress() << endl;
	}
}
Basket add_basket(vector<Laptops> &laptop, vector<SmartPhones> &smartphone, vector<TV> &tv) {
	bool read = true;
	Basket basket;
	pro_basket element;
	int qty, i;
	while (read)
	{
		
			int act;
			cout << "Please type a number to add" << endl;
			cout << "---------------------------" << endl;
			cout << "1: laptops                 " << endl;
			cout << "2: smartphone              " << endl;
			cout << "3: tv                      " << endl;
			cout << "---------------------------" << endl;
			cin >> act;
			
			if (act == 1)
			{

				cout << "Please type the id of object you want to add in basket" << endl;
				cin >> i;

				cout << "Please type the quantity you want " << endl;
				cin >> qty;
				element.qty = qty;
				element.product = laptop[i];
				element.tk = laptop[i].getPrice() * element.qty;
				basket.addProduct(element);
			}
			if (act == 2)
			{
				cout << "Please type the id of object you want to add in basket" << endl;
				cin >> i;

				cout << "Please type the quantity you want " << endl;
				cin >> qty;
				element.qty = qty;
				element.product = smartphone[i];
				element.tk = smartphone[i].getPrice() * element.qty;
				basket.addProduct(element);
				//basket.getBasket().push_back(element);
			}
			if (act == 3)
			{
				cout << "Please type the id of object you want to add in basket" << endl;
				cin >> i;

				cout << "Please type the quantity you want " << endl;
				cin >> qty;
				element.qty = qty;
				element.product = tv[i];
				element.tk = tv[i].getPrice() * element.qty;
				basket.addProduct(element);
				//basket.getBasket().push_back(element);
			}
			char action;
			cout << "Would you like to add another Product? (y/n): ";
			cin >> action;

			if (action == 'y') {
				continue;
			}
			else {
				return basket;
				break;
			}

	}	
}
void print_basket(Basket &basket) {
	vector<pro_basket> ptrbasket = basket.getBasket();
	float sumto=0.0;
	for (int i = 0; i < ptrbasket.size(); i++) {
		cout << "ID: " << i << "\tPRODUCT Code: " << ptrbasket[i].product.getCode() << "\tQUANTITY: " << ptrbasket[i].qty << "\tTELIKO KOSTOS: " << ptrbasket[i].tk << endl;
		sumto += ptrbasket[i].tk;
	}
	cout << "\t\t\t\t\t\tTELIKO KOSTOS: " << sumto << endl;
}
Basket remove_basket(Basket &basket) {

	int i;
	bool read = true;
	pro_basket element;
	while (read) {

		cout << "Please type the code to remove a product from basket" << endl;
		cin >> i;
		vector<pro_basket> ptrbasket = basket.getBasket();
		vector<pro_basket>::iterator ptr = ptrbasket.begin();
		while (ptr != ptrbasket.begin()) {

			if (ptr->product.getCode() == i)
			{
				ptr = ptrbasket.erase(ptr); // Will return next valid iterator
				return basket;
			}
			else
			{
				ptr++;
			}
		}

		//ptrbasket.erase(ptrbasket.begin() + i);
		//ptrbasket.erase(std::remove(ptrbasket.begin(), ptrbasket.end(), element), ptrbasket.end());

		char action;
		cout << "Would you like to add remove Product from basket? (y/n): ";
		cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			return basket;
		}
}
	}
void print_productCatalogue(vector<Laptops> &laptop , vector<SmartPhones> &smartphone , vector<TV> &tv)
{
	cout << "<----------------LAPTOPS----------------->" << endl;
	for (int i = 0; i < laptop.size(); i++) {
		cout << laptop[i].toString() << endl;
	}
	cout << "<--------------SMARTPHONES--------------->" << endl;
	for (int i = 0; i < smartphone.size(); i++) {
		cout << smartphone[i].toString() << endl;
	}
	cout << "<------------------TVS------------------->" << endl;
	for (int i = 0; i < tv.size(); i++) {
		cout << tv[i].toString() << endl;
	}
}
void product_update(vector<Laptops> &laptop, vector<SmartPhones> &smartphone, vector<TV> &tv) {

	int value,i;

	  bool read = true;
	  while (read) {
		  int act;
		  cout << "Please type a number to update a product" << endl;
		  cout << "----------------------------------------" << endl;
		  cout << "1: laptops                              " << endl;
		  cout << "2: smartphone                           " << endl;
		  cout << "3: tv                                   " << endl;
		  cout << "----------------------------------------" << endl;
		  cin >> act;

		  if (act == 1)
		  {
			  cout << "Please type a laptop to update" << endl;
			  cin >> i;
			  cout << "Please type a new value to update" << endl;
			  cin >> value;
			  laptop[i].setValue(value);
		  }
		  if (act == 2)
		  {
			  cout << "Please type a smartphone to update" << endl;
			  cin >> i;
			  cout << "Please type a new value to update" << endl;
			  cin >> value;
			  smartphone[i].setValue(value);
		  }
		  if (act == 3)
		  {
			  cout << "Please type a tv to update" << endl;
			  cin >> i;
			  cout << "Please type a new value to update" << endl;
			  cin >> value;
			  tv[i].setValue(value);
		  }

		  char action;
		  cout << "Would you like to update another Product ? (y/n): ";
		  cin >> action;

		  if (action == 'y') {
			  continue;
		  }
		  else {
			  break;
		  }
	  }
}
Order neworder(Basket &basket, Customers &cst) {
	
	Order ord;
	pair <Customers , vector<pro_basket> > pelatis = ord.getOrderItem();
	
	cout << "Please type your AFM : " << endl;
	string afm;
	cin >> afm;
	while (1) {
		if (afm.compare(cst.getAfm()) == 0) {
			pelatis.first = cst;
			pelatis.second = basket.getBasket();
			ord.setStatus(Order::PENDING);
			ord.setOrderItem(pelatis);
			return ord;

		}
		else {
			cout << "Please type Your correct AFM";
			cin >> afm;
		}
	}
	

}
void update_order(Order &ord) {
	
	 
	bool read = true;
	while (read) {
		int act;
		cout << "Please type a number to update a product" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1: IN_SEND                              " << endl;
		cout << "2: FINISHED                             " << endl;
		cout << "3: CANCELLED                            " << endl;
		cout << "----------------------------------------" << endl;
		cin >> act;
		if (act == 1) {
			cout << "status changed IN_SEND" << endl;
			ord.setStatus(Order::IN_SEND);
		}
		if (act == 2) {
			cout << "status changed FINISHED" << endl;
			ord.setStatus(Order::FINISHED); 
		}
		if (act == 3) {
			cout << "status changed CANCELLED" << endl;
			ord.setStatus(Order::CANCELLED);
		}
		char action;
		cout << "Would you like to a change status again? (y/n): ";
		cin >> action;
		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	 }
}
void print_order(Order &ord) {
	pair <Customers , vector<pro_basket> > pelatis = ord.getOrderItem();
	float to = 0.0;
	cout << "CUSTOMER AFM : " << pelatis.first.getAfm() << "\n";
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < pelatis.second.size(); i++) {
		to += pelatis.second[i].tk;
		cout << "PRODUCT CODE: " << pelatis.second[i].product.getCode() << "\tPRODUCT PRICE  : " << pelatis.second[i].tk;
		if (ord.getStatus() == 0) {
			cout << "\t\tORDER STATUS: PENDING" << "\n";
		}
		if (ord.getStatus() == 1) {
			cout << "\t\tORDER STATUS: IN_SENDING" << "\n";
		}
		if (ord.getStatus() == 2) {
			cout << "\t\tORDER STATUS: FINISHED" << "\n";
		}
		if (ord.getStatus() == 3) {
			cout << "\t\tORDER STATUS: CANCELLED" << "\n";
		}
	}
	cout << "TELIKO KOSTOS PARAGGELIAS: " << to << endl;
}

Users loginUser() {
	Users user;

	cout << "Please enter your username: ";
	string inputUsername;
	cin >> inputUsername;
	cout << "Please enter your password: ";
	string inputPassword;
	cin >> inputPassword;
	string userAndPass = inputUsername + "|" + inputPassword; // Search pattern 
	string line;
	ifstream usersFile;
	usersFile.open("user.dat");
	bool found = false;
		if (usersFile.is_open()) {
			while (getline(usersFile, line) && !found) {
				if (line.compare(userAndPass) == 0) { //match strings exactly! 
					found = true; // found is true => break loop 
				}
			}
			usersFile.close(); //close the file before recursivly opening it again later 
			if (found) {
				cout << "Welcome " << inputUsername << '\n';
				user.setUsername(inputUsername);
				//user.setPassword(inputPassword);
				return user;
			}
			else {
				cout << "\nUsername and/or password incorrect!\n\n\n\n";
				user=loginUser(); //ok we didn't find them, lets redue this! 
			}
		}
}
void loginAdmin() {

	Admins admin;

	cout << "Please enter your username: ";
	string inputUsername;
	cin >> inputUsername;
	cout << "Please enter your password: ";
	string inputPassword;
	cin >> inputPassword;
	string userAndPass = inputUsername + "|" + inputPassword; // Search pattern 
	string line;
	ifstream adminsFile;
	adminsFile.open("admin.dat");
	bool found = false;
	if (adminsFile.is_open()) {
		while (getline(adminsFile, line) && !found) {
			if (line.compare(userAndPass) == 0) { //match strings exactly! 
				found = true; // found is true => break loop 
			}
		}
		adminsFile.close(); //close the file before recursivly opening it again later 
		if (found) {
			cout << "Welcome " << inputUsername << '\n';
		}
		else {
			cout << "\nUsername and/or password incorrect!\n\n\n\n";
			loginAdmin(); //ok we didn't find them, lets redue this! 
		}
	}
}
vector<Users> loadUsers() {
	vector<Users> user;
	ifstream infile;
	infile.open("user.dat");

	string strUser;
	cout << "Reading from the file" << endl;



	while (infile.good()) {
		getline(infile, strUser);
		if (strUser.length() > 1) {
			user.push_back(Users(strUser));
		}
	}
	infile.close();
	
	return user;
}
vector<Customers> loadCustomers() {
	vector<Customers> customers;
	ifstream infile;
	infile.open("customers.dat");

	string strCustomers;
	cout << "Reading from the file" << endl;



	while (infile.good()) {
		getline(infile, strCustomers);
		if (strCustomers.length() > 1) {
			customers.push_back(Customers(strCustomers));
		}
	}
	infile.close();

	return customers;
}
vector<Laptops> loadLaptop()
{
	vector<Laptops> lapt;

	ifstream infile;
	infile.open("laptop.dat");

	string strLaptops;
	cout << "Reading from the file" << endl;

	while (infile.good()) {
		getline(infile, strLaptops);
		if (strLaptops.length() > 1) {
			lapt.push_back(Laptops(strLaptops));
		}
	}

	infile.close();

	return lapt;
}
vector<SmartPhones> loadSmartphone()
{
	vector<SmartPhones> smartphone;

	ifstream infile;
	infile.open("smartphone.dat");

	string strSmartphones;
	cout << "Reading from the file" << endl;

	while (infile.good()) {
		getline(infile, strSmartphones);
		if (strSmartphones.length() > 1) {
			smartphone.push_back(SmartPhones(strSmartphones));
		}
	}

	infile.close();

	return smartphone;
}
vector<TV> loadTv()
{
	vector<TV> tvs;

	ifstream infile;
	infile.open("tv.dat");

	string strTvs;
	cout << "Reading from the file" << endl;

	while (infile.good()) {
		getline(infile, strTvs);
		if (strTvs.length() > 1) {
			tvs.push_back(TV(strTvs));
		}
	}

	infile.close();

	return tvs;
}
Customers checkCustomer(Users &usertmp) {
	Customers cst;
	Users tmp = usertmp;
	cout << "Please enter your AFM: ";
	string inputAfm;
	cin >> inputAfm;
	cout << "Please enter your THL: ";
	string inputThl;
	cin >> inputThl;
	cout << "Please enter your ADDRESS: ";
	string inputAddress;
	cin >> inputAddress;

	string afmANDthlANDaddress = inputAfm + "|" + inputThl + "|" + inputAddress; // Search pattern 
	string line;
	ifstream cstFile;
	cstFile.open("Customers.dat");
	bool found = false;
	if (cstFile.is_open()) {
		while (getline(cstFile, line) && !found) {
			if (line.compare(afmANDthlANDaddress) == 0) { //match strings exactly! 
				found = true; // found is true => break loop 
			}
		}
		cstFile.close(); //close the file before recursivly opening it again later 
		if (found) {
			string tmp = usertmp.getUsername();
			cout << "Welcome " << tmp << '\n';
			cst.setAfm(inputAfm);
			cst.setPhoneNumber(inputThl);
			cst.setAddress(inputAddress);
			return cst;
		}
		else {
			cout << "\nAFM and/or THL and/or ADDRESS incorrect!\n\n\n\n";
			cst=checkCustomer(tmp); //ok we didn't find them, lets redue this! 
		}
	}
}

int main()
{
	vector<Users> users;
	Users usertmp;
	vector<Customers> customers;
	vector<Product> product;
	vector<Laptops> laptop;
	vector<SmartPhones> smartphone;
	vector<TV> tv;
	Basket basket , removebask;
	Order ord;
	vector<Order> allord;
	Customers cst;
	do
	{
		char action;
		cout << "Please type the letter for the action you want to do" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "A: Log In Admin                                     " << endl;
		cout << "B: Log In User                                      " << endl;
		cout << "C: Exit the program                                 " << endl;
		cout << "----------------------------------------------------" << endl;
		cin >> action;


		if (action == 'A') {
			loginAdmin();
			do
			{
				cout << "Please type the letter for the action you want to do          " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << "A: Create Account User                                        " << endl;
				cout << "B: Prosthikh/afairesh prointwn                                " << endl;
				cout << "C: Update Order STATUS                                        " << endl;
				cout << "D: Update Product                                             " << endl;
				cout << "E: Ektipwsh pelatologiou                                      " << endl;
				cout << "F: Ektipwsh paragkeleias ana pelath kai katastash paragkeleias" << endl;
				cout << "G: Log Out Admin                                              " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cin >> action;
				if (action == 'A') {
					writeUsers();
				}
				else if (action == 'B') {
					bool read = true;
					while (read) {
						int action;
						cout << "Please type the letter for the action you want to do" << endl;
						cout << "----------------------------------------------------" << endl;
						cout << "1: add_product                                      " << endl;
						cout << "2:  remove_product                                  " << endl;
						cout << "----------------------------------------------------" << endl;
						cin >> action;
						if (action == 1) {
							add_Product();
						}
						if (action == 2) {
							laptop = loadLaptop();
							smartphone = loadSmartphone();
							tv = loadTv();
							remove_Product(laptop, smartphone, tv);
							//saveNewFile(laptop, smartphone, tv);
						}
						char action1;
						cout << "Would you like to add or remove another Product? (y/n): ";
						cin >> action1;

						if (action1 == 'y') {
							continue;
						}
						else {
							break;
						}
					}
				}
				else if (action == 'C') {
					update_order(ord);
				}
				else if (action == 'D') {
					product_update(laptop, smartphone, tv);
				}

				else if (action == 'E') {
					customers=loadCustomers();
					printCustomers(customers);
				}
				else if (action == 'F') {
					print_order(ord);
				}
				else if (action == 'G') {
					break;
				}
				else {
					cout << "This code is not supported" << endl;
				}
			} while (1);
		}
		else if (action == 'B') {
			usertmp = loginUser();
			while (1) {
				int action;
				cout << "Please type the letter for the action you want to do" << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "1: Dwse afm-thl-address                             " << endl;
				cout << "2: Exw dwsei                                        " << endl;
				cout << "----------------------------------------------------" << endl;
				cin >> action;
				if (action == 1) {
					cst = addCustomers();
					break;
				}
				if (action == 2) {
					cst = checkCustomer(usertmp);
					break;
				}
			}
			do
			{
				cout << "Please type the letter for the action you want to do          " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << "A: Ektipwsh katalogou proiontwn                               " << endl;
				cout << "B: Prosthikh proiontwn sto basket & posotita                  " << endl;
				cout << "C: Print Basket                                               " << endl;
				cout << "D: Diagrafh proiontwn apo basket                              " << endl;
				cout << "E: Dimiourgia Neas Paragkeleias                               " << endl;
				cout << "F: print status ORDER                                         " << endl;
				cout << "G: Log Out User                                               " << endl;
				cout << "--------------------------------------------------------------" << endl;
				cin >> action;
				if (action == 'A') {
					while (1) {
						int action;
						cout << "Please type the letter for the action you want to do" << endl;
						cout << "----------------------------------------------------" << endl;
						cout << "1: AN EXEIS MPEI ME ADMIN PRWTA                     " << endl;
						cout << "2: AN EXEIS MPEI KATEYTHEIAN ME USER                " << endl;
						cout << "----------------------------------------------------" << endl;
						cin >> action;
						if (action == 1) {
							print_productCatalogue(laptop, smartphone, tv);
							break;
						}
						if (action == 2) {
							laptop = loadLaptop();
							smartphone = loadSmartphone();
							tv = loadTv();
							print_productCatalogue(laptop, smartphone, tv);
							break;
						}
					}
				}
				else if (action == 'B') {
					while (1) {
						int action;
						cout << "Please type the letter for the action you want to do" << endl;
						cout << "----------------------------------------------------" << endl;
						cout << "1: AN EXEIS KANEI REMOVE PRODUCT ME ADMIN           " << endl;
						cout << "2: AN DEN EXEIS KANEI REMOVE                        " << endl;
						cout << "----------------------------------------------------" << endl;
						cin >> action;
						if (action == 1) {
							basket = add_basket(laptop, smartphone, tv);
							break;
						}
						if (action == 2) {
							laptop = loadLaptop();
							smartphone = loadSmartphone();
							tv = loadTv();
							basket = add_basket(laptop, smartphone, tv);
							break;
						}
					}
					
				}
				else if (action == 'C') {
					print_basket(basket);
				}
				else if (action == 'D') {
					basket = remove_basket(basket);
				}
				else if (action == 'E') {
					ord=neworder(basket,cst);
				}
				else if (action == 'F') {
					if (ord.getStatus() == 0) {
						cout << "ORDER STATUS  : PENDING" << endl;
					}
					if (ord.getStatus() == 1) {
						cout << "ORDER STATUS  : IN_SENDING" << endl;
					}
					if (ord.getStatus() == 2) {
						cout << "ORDER STATUS  : FINISHED" << endl;
					}
					if (ord.getStatus() == 3) {
						cout << "ORDER STATUS  : CANCELLED" << endl;
					}
				}
				else if (action == 'G') {
					break;
				}
				else {
					cout << "This code is not supported" << endl;
					 
				}
			} while (1);
		}
		else if (action == 'C') {
			break;
		}
		else {
			cout << "This code is not supported" << endl; 
		}
	} while (1);
	return 0;
}


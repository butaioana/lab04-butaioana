#pragma once
#include"Service.h"
class UI {
private:
	Service service;
	void add();
	void print();
	void update_shop();
	void delete_shop();
public:
	void run();
};
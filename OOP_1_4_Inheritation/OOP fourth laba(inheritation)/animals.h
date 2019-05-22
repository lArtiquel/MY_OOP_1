#pragma once

class Animals
{
public:
	Animals(double age, double weigth) : age(age), weigth(weigth) {};
private:
	double age;
	double weigth;
protected:
	//age getter/setter 
	double getAge() const;
	void setAge(double);

	//weigth getter/setter
	double getWeigth() const;
	void setWeigth(double);
};

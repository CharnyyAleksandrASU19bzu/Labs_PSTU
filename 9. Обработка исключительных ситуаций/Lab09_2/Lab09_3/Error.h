#pragma once
#include <string>
#include <iostream>

class Error
{
public:
	virtual void what()
	{
	};
};

class IndexError :public Error //ошибка в индексе вектора
{
protected:
	string msg;
public:
	IndexError()
	{
		msg = "Ошибка индекса\n";
	}
	virtual void what()
	{
		cout << msg;
	}
};

class SizeError :public Error //ошибка в размере вектора
{
protected:
	string msg;
public:
	SizeError()
	{
		msg = "Ошибка размера\n";
	}
	virtual void what()
	{
		cout << msg;
	}

};

class MaxSizeError :public SizeError //превышение максимального размера
{
protected:
	string msg_;
public:
	MaxSizeError()
	{
		msg_ = "Вектор больше максимального значения\n";
	}
	virtual void what()
	{
		cout << msg << msg_;
	}

};

class EmptySizeError :public SizeError //вектор пустой
{
protected:
	string msg_;
public:
	EmptySizeError()
	{
		SizeError();
		msg_ = "Вектор пустой\n";
	}
	virtual void what()
	{
		cout << msg << msg_;
	}
};

class IndexError1 :public IndexError //индекс меньше нуля
{
protected:
	string msg_;
public:
	IndexError1()
	{
		msg_ = "Индекс меньше нуля\n";
	}
	virtual void what()
	{
		cout << msg << msg_;
	}
};

class IndexError2 :public IndexError //индекс больше текущего размера вектора
{
protected:
	string msg_;
public:
	IndexError2()
	{
		msg_= "Размер индекса больше размера вектора\n";
	}
	virtual void what()
	{
		cout << msg << msg_;
	}
};
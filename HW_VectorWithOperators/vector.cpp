#include"library.h"
#include"vector.h"
Vector::Vector()
{
	cur_size = 0;
	buf_size = 0;
	els = nullptr;
	count = 0;
}
int & Vector::push_back(int el)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new int[buf_size];
	}
	else if (buf_size <= cur_size)
	{
		buf_size *= 2;
		int *tmp = new int[buf_size];
		for (int i = 0; i < cur_size; i++)
		{
			tmp[i] = els[i];
		}
		delete[]els;
		els = tmp;
	}
	els[cur_size] = el;
	cur_size++;
	return els[cur_size - 1];
}
Vector & Vector::operator+(const Vector & obj)
{
	for (int i = 0; i < cur_size; i++)
	{
		this->els[i] += obj.els[i];
	}
	return *this;
}
int Vector::size()
{
	return cur_size;
}
//Vector & Vector::operator-(const Vector & obj) //first version
//{
//	int f_size = cur_size;
//	for (int i = 0;i < cur_size;i++)
//	{
//		for (int j = 0;j < f_size;j++)
//		{
//			if (this->els[i] == obj.els[j])
//			{
//				deleteEl(i);
//				if (i = 0)
//					i = i;
//				else
//					i--;
//			}
//		}
//	}
//	
//	return *this;
//}
Vector& Vector :: operator-(const Vector & obj)
{
	buf_size = cur_size;
	for (int i = 0; i < buf_size; i++)
	{
		for (int j = 0; j < buf_size; j++)
		{
			if (this->els[i] == obj.els[j])
			{
				for (int t = i; t < cur_size; t++)
				{
					this->els[t] = this->els[t + 1];
				}
				cur_size--;
			}
		}
	}
	return *this;
}

void Vector::print()
{
	for (int i = 0; i < cur_size; i++)
		cout << setw(4) << els[i];
}
Vector Vector::deleteEl(int index)
{
	if (index == cur_size - 1)
		cur_size -= 1;
	else
	{
		int*tmp = new int[cur_size];
		int i = 0;

		for (; i < index; i++)
		{
			tmp[i] = els[i];
		}
		for (int j = i; j < cur_size; j++)
		{
			tmp[j] = els[j + 1];
		}

		cur_size--;
		delete[] els;
		els = tmp;

	}
	return *this;
}

int & Vector::operator[](int index)
{
	return els[index];
}

int  Vector:: operator<<(int index)
{
	int tmp = els[index];
	for (int i = index; i < cur_size; i++)
	{
		this->els[i] = this->els[i + 1];
	}
	cur_size--;
	return tmp;
}

int Vector:: operator>>(int el)
{
	if (buf_size <= cur_size)
	{
		buf_size *= 2;
		int *tmp = new int[buf_size];
		for (int i = 0; i < cur_size; i++)
		{
			tmp[i] = els[i];
		}
		delete[]els;
		els = tmp;
	}
	els[cur_size++] = el;

	return els[cur_size - 1];
}
bool  Vector::operator==(const Vector & obj)
{
	if (this->cur_size != obj.cur_size)
		return false;
	else {
		for (int i = 0; i < cur_size; i++)
			if (this->els[i] != obj.els[i])
				return false;
	}
	return true;

}
bool Vector::operator!=(const Vector & obj)
{
	if (this->cur_size != obj.cur_size)
		return true;
	else {
		for (int i = 0; i < cur_size; i++)
			if (this->els[i] != obj.els[i])
				return true;
	}
	return false;
}

//istream & operator>>(istream & is, Vector & s)
//{
//	is >> s.push_back;
//	return is;
//}
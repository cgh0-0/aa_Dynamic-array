#include<iostream>

class myvec

{

	int* m_pdata;

	int m_count;

	int m_capacity;
	void resize()
	{
		if (m_count >= m_capacity)
		{
			// 만약 현재 용량이 0이라면 1로, 아니라면 2배로 
			int new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;

			int* new_arr = new int[new_capacity];
			for (int i = 0; i < m_count; ++i)
			{
				new_arr[i] = m_pdata[i];
			}
			delete[] m_pdata;
			m_pdata = new_arr;
			m_capacity = new_capacity; 
		}
	}

public:

	myvec()

		:m_pdata(nullptr), m_count(0), m_capacity(0)

	{

		m_pdata = new int[10];
		m_capacity = 10;

	}
	~myvec()
	{
		if (m_pdata != nullptr)
		{
			delete[] m_pdata;
			m_pdata = nullptr;
		}
	}
	
	void pushback(int pdata)

	{
		resize();




		m_pdata[m_count] = pdata;

		m_count += 1;
	}


	void pushfront(int data)
	{
		resize();
		for (int i = m_count - 1; i >= 0; --i)
		{
			m_pdata[i + 1] = m_pdata[i];
		}
		m_pdata[0] = data;
		++m_count;
	}
	void bubblesort()
	{
		for (int j = 0; j <= m_count - 1; ++j)
		{
			for (int i = 0; i < m_count - 1 - j; ++i)
			{
				if (m_pdata[i] > m_pdata[i + 1])
				{
					int a = m_pdata[i];
					m_pdata[i] = m_pdata[i + 1];
					m_pdata[i + 1] = a;
				}

			}
		}
	}
	void popback()
	{

		--m_count;
	}
	void print()
	{
		for (int i = 0; i < m_count; ++i)
		{
			std::cout << m_pdata[i] << std::endl;
		}
	}
	void shrink_to_fit()
	{
		int* newarr = new int[m_count];
		for (int i = 0; i < m_count; ++i)
		{

			newarr[i] = m_pdata[i];
		}
		delete[] m_pdata;
		m_pdata = newarr;
		m_capacity = m_count;
	}

};
int main()
{
	myvec arr;

	arr.pushback(2);
	arr.pushback(4);
	arr.pushback(5);
	arr.pushback(1);
	arr.pushback(9);
	arr.pushback(0);
	arr.print();
	arr.bubblesort();
	std::cout << "bubble sort" << std::endl;
	arr.print();


	std::cout << "push back" << std::endl;
	arr.pushback(1);

	arr.print();
	std::cout << "push front" << std::endl;
	arr.pushfront(999);
	arr.print();
	std::cout << "pop back" << std::endl;
	arr.popback();
	arr.print();
	std::cout << "bubblesort" << std::endl;
	arr.bubblesort();
	arr.print();
	std::cout << "popback" << std::endl;
	arr.popback();
	arr.popback();
	arr.print();
	arr.shrink_to_fit();
	std::cout << "after shrink to fit and bubble sort" << std::endl;
	arr.bubblesort();
	arr.print();
	return 0;
}

#include<iostream>

class myvec

{

	int* m_pdata;

	int m_count;

	int m_capacity;

public:

	myvec()

		:m_pdata(nullptr), m_count(0), m_capacity(0)

	{

		m_pdata = new int[10];

	}

	void pushback(int* pdata)

	{

		if (m_count >= m_capacity)

		{
			int* newparr;
			newparr = new int[m_capacity * 2];
			for (int i = 0; i <= m_count-1; ++i)
			{
				newparr[i]=m_pdata[i] ;
				/*delete m_pdata[i]; 얘 왜 안됨*/
			}
			delete[] m_pdata;
			m_pdata = newparr;
			m_capacity = m_capacity * 2;
			

		}

		m_pdata[m_count] = *pdata;

		m_count += 1;


	}
	void pushfront(int* data)
	{
		if (m_count >= m_capacity)

		{
			int* newparr;
			newparr = new int[m_capacity * 2];
			for (int i = 0; i <= m_count; ++i)
			{
				newparr[i] = m_pdata[i];
				/*delete m_pdata[i]; 얘 왜 안됨*/
			}
			delete[] m_pdata;
			m_pdata = newparr;
			m_capacity = m_capacity * 2;
			
		}
		for (int i =m_count -1; i >=0; --i)
		{
			m_pdata[i + 1] = m_pdata[i];
		}
		m_pdata[0] = *data;
	}
	void bubblesort()
	{	for(int j=1;j<=m_count-1;++j)
		{
			for (int i = 0; i < m_count-1-j; ++i)
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
		m_pdata[m_count-1]=0;
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
	int c = 453;
	int a = 5345;
	int b = 324;
	int d = 12;
	int v = 2;
	int o = 21;
	arr.pushback(&a);
	arr.pushback(&b);
	arr.pushback(&c);
	arr.pushback(&d);
	arr.pushback(&v);
	arr.pushback(&o);
	arr.print();
	arr.bubblesort();
	std::cout << "bubble sort" << std::endl;
	arr.print();
	a = 1;
	arr.pushback(&a);
	std::cout << "push back" << std::endl;
	b = 999;
	arr.pushfront(&b);
	arr.print();
	std::cout << "push front" << std::endl;
	arr.print();
	std::cout << "pop back" << std::endl;
	arr.popback();
	arr.print();
	std::cout << "bubblesort" << std::endl;
	arr.bubblesort();
	arr.print();
	arr.popback();
	arr.popback();
	arr.print();
	arr.shrink_to_fit();
	std::cout << "after shrink to fit and bubble sort" << std::endl;
	arr.bubblesort();
	arr.print();
	return 0;
}

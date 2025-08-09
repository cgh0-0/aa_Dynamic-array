#include<iostream>

class myvec

{

	int* m_pdata;

	int m_count;

	int m_capacity;

public:

	myvec()

		:m_pdata(nullptr), m_count(0), m_capacity(10)

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

};

#pragma once
class big_integer
{
private:
	std::vector<int> _value{};

	void to_vector(std::string value)
	{
		for (const auto& s : value)
		{
			_value.push_back(static_cast<int>(s - '0'));
		}
	}
	std::vector<int> plus(const std::vector<int>& one, const std::vector<int>& two)
	{
		std::vector<int> k{};
		std::vector<int> v1{};
		std::vector<int> v2{};

		v1.assign(one.begin(), one.end());
		v2.assign(two.begin(), two.end());

		size_t max_len = std::max(v1.size(), v2.size());//максимальная длина из двух чисел
		//заполняем нулями если длина меньше максимальной
		if (v1.size() < max_len)
		{
			for (size_t i = v1.size(); i < max_len; i++)
			{
				auto it = v1.begin();
				v1.insert(it, 0);
			}
		}
		//заполняем нулями если длина меньше максимальной
		if (v2.size() < max_len)
		{
			for (size_t i = v2.size(); i < max_len; i++)
			{
				auto it = v2.begin();
				v2.insert(it, 0);
			}
		}

		//суммируем поразрядно
		int carry = 0;
		auto this_it = v1.rbegin();
		auto other_it = v2.rbegin();
		for (size_t i = 0; i < max_len; i++)
		{
			int sum = *this_it + *other_it + carry;
			auto it = k.begin();
			k.insert(it, sum % 10);
			carry = sum / 10;
			this_it++;
			other_it++;
		}
		if (carry != 0)
		{
			auto it = k.begin();
			k.insert(it, carry);
		}

		return k;
	}
	bool less(std::vector<int> one, std::vector<int> two)
	{
		if (one.size() < two.size())
		{
			return true;
		}
		else if (one.size() > two.size())
		{
			return false;
		}
		//equate
		std::vector<int> v1{ one };
		std::vector<int> v2{ two };


		size_t max_len = std::max(v1.size(), v2.size());//максимальная длина из двух чисел
		//заполняем нулями если длина меньше максимальной
		if (v1.size() < max_len)
		{
			for (size_t i = v1.size(); i < max_len; i++)
			{
				auto it = v1.begin();
				v1.insert(it, 0);
			}
		}
		//заполняем нулями если длина меньше максимальной
		if (v2.size() < max_len)
		{
			for (size_t i = v2.size(); i < max_len; i++)
			{
				auto it = v2.begin();
				v2.insert(it, 0);
			}
		}
		auto this_it = v1.begin();
		auto other_it = v2.begin();
		for (size_t i = 0; i < max_len; i++)
		{
			if (*other_it > *this_it)

			{
				return true;
			}
			this_it++;
			other_it++;
		}

		return false;
	}

public:
	//конструктор
	big_integer() = default;
	
	//деструктор
	~big_integer() = default;
	
	//конструкор с параметром
	big_integer(const std::string& value)
	{
		to_vector(value);
	}

	//конструктор с параметром-2
	big_integer(const std::vector<int>& value)
	{
		_value.assign(value.begin(), value.end());
	}

	//конструктор копирования
	big_integer(const big_integer& other) : _value{ other._value }
	{
	}

	//оператор присваивания копированием
	big_integer& operator =(const big_integer& other)
	{
		if (this != &other)
		{
			_value = other._value;
		}
		return *this;
	}

	//перегрузка оператора сложения
	big_integer operator+(big_integer& other)
	{
		big_integer k{};
		std::vector<int> v = plus(this->_value, other._value);

		k._value.assign(v.begin(), v.end());

		return k;
	}


	//перегрузка оператора меньше
	bool const operator < (const big_integer& other)
	{
		return less(this->_value, other._value);
	}


	//перегрузка оператора постинкремента
	big_integer operator++(int pref)
	{
		big_integer k{ *this };
		big_integer const1{ "1" };

		std::vector<int> v{};
		v = plus(this->_value, const1._value);

		this->_value.assign(v.begin(), v.end());

		return k;
	}

	//перегрузка оператора умножения
	big_integer operator *(big_integer& other)
	{
		big_integer k{};
		big_integer k_sum{};

		//умножение через суммирование
		while (k_sum < other)
		{
			k = k + *this;
			k_sum++;
		}

		return k;
	}

	//дружественный метод - перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& out, const big_integer& v)
	{
		for (const auto& item : v._value)
		{
			std::cout << item << " ";
		}

		out << std::endl;

		return out;
	}

};


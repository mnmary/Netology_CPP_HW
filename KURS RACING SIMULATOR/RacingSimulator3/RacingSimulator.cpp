#include <iostream>
#include "Racing.h"
#include "Camel.h"
#include "FastCamel.h"
#include "MagicCarpet.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "Broomstick.h"
#include "Eagle.h"
#include "Transport.h"

Racing racing;

void selectDistance()
{
	int _distance;

	std::cout << "Укажите длину дистанции (должна быть положительна), км: ";
	std::cin >> _distance;
	system("cls");
	if (_distance <= 0)
	{
		std::cout << "Дистанция должна быть больше 0." << std::endl;
		selectDistance();
	}
	racing.setDistance(_distance);
}

void selectRacingType()
{
	int rType = 0;

	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "2. Гонка для воздушного транспорта" << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	std::cout << "Выберите тип гонки: ";
	std::cin >> rType;
	system("cls");

	if (rType == static_cast <int>(RacingType::Ground))
	{
		racing.setRacingType(RacingType::Ground);
	}
	else if (rType == static_cast <int>(RacingType::Air))
	{
		racing.setRacingType(RacingType::Air);
	}
	else if (rType == static_cast <int>(RacingType::GroundAndAir))
	{
		racing.setRacingType(RacingType::GroundAndAir);
	}
	else
	{
		std::cout << "Некорректный выбор." << std::endl;
		selectRacingType();
	}
}
bool isRacingExit()
{
	int tmp = 0;

	std::cout << "" << std::endl;

	std::cout << "1. Провести еще одну гонку." << std::endl;
	std::cout << "2. Выйти" << std::endl;
	std::cout << "Выберите действие: ";
	std::cin >> tmp;
	system("cls");

	if (tmp == 1)
	{
		return false;
	}
	if (tmp == 2)
	{
		return true;
	}

	std::cout << "Некорректный выбор." << std::endl;
	return isRacingExit();
}
void firstSelectAction()
{
	int tmp = 0;

	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства " << std::endl;
	std::cout << "1. Зарегистрировать транспорт." << std::endl;
	std::cout << "Выберите действие: ";
	std::cin >> tmp;
	system("cls");

	if (tmp != 1)
	{
		std::cout << "Некорректный выбор." << std::endl;
		firstSelectAction();
	}
}
int secondSelectAction()
{
	int tmp = 0;

	std::cout << "1. Зарегистрировать транспорт." << std::endl;
	std::cout << "2. Начать гонку." << std::endl;
	std::cout << "Выберите действие: ";
	std::cin >> tmp;
	system("cls");

	if ((tmp != 1) && (tmp != 2))
	{
		std::cout << "Некорректный выбор." << std::endl;
		return secondSelectAction();
	}
	if ((tmp == 2) && (racing.getCntRegTransport() < 2))
	{
		std::cout << "Гонка невозможна, так как зарегистрировано меньше двух транспортных средств." << std::endl;
		return secondSelectAction();
	}
	return tmp;
}

void showRacingInfo()
{
	switch (racing.getRacingType())
	{
	case (RacingType::Ground):
		std::cout << "Гонка для наземного транспорта. Расстояние: " << racing.getDistance() << std::endl;
		break;
	case (RacingType::Air):
		std::cout << "Гонка для воздушного транспорта. Расстояние: " << racing.getDistance() << std::endl;
		break;
	case (RacingType::GroundAndAir):
		std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << racing.getDistance() << std::endl;
		break;
	default:
		std::cout << "Несуществующая гонка." << std::endl;
		break;
	}
}
void showRegisteredTransport()
{
	if (racing.getCntRegTransport() > 0)
	{
		std::cout << "Зарегистрированные транспортные средства: ";

		for (int i = 0; i < racing.getCntRegTransport(); i++)
		{
			std::cout << racing.getTransport(i)->getName() << " ";
		}
	}
	else
	{
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства " << std::endl;
	}
}

int menuRegisterTransport()
{
	int maxNum = 0;
	int type_transp = 0;

	showRegisteredTransport();
	std::cout << std::endl;
	std::cout << "1. Кентавр" << std::endl;
	std::cout << "2. Верблюд" << std::endl;
	std::cout << "3. Верблюд-скороход" << std::endl;
	std::cout << "4. Ботинки-вездеходы" << std::endl;
	std::cout << "5. Ковёр-самолёт" << std::endl;
	std::cout << "6. Метла" << std::endl;
	std::cout << "7. Орёл" << std::endl;
	if (racing.getCntRegTransport() > 1)
	{
		std::cout << "0. Закончить регистрацию" << std::endl;
		std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
	}
	else
	{
		std::cout << "Выберите транспорт: ";
	}
	std::cin >> type_transp;
	system("cls");

	if (type_transp == 0)
	{
		return type_transp;
	}
	if (type_transp > 7)
	{
		std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! " << std::endl;
		return menuRegisterTransport();
	}
	switch (racing.getRacingType())
	{
	case (RacingType::Ground):
		if (type_transp > 4)
		{
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! " << std::endl;
			return menuRegisterTransport();
		}
		break;
	case (RacingType::Air):
		if (type_transp < 5)
		{
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! " << std::endl;
			return menuRegisterTransport();
		}
		break;
	case (RacingType::GroundAndAir):
		break;
	default:
		std::cout << std::endl;
		std::cout << "Ошибка регистрации транспортного средства" << std::endl;
		//maxNum = 0;
		break;
	}

	return type_transp;
}

bool check_transp_reg(int type_transp)
{
	for (int i = 0; i < racing.getCntRegTransport(); i++)
	{
		if (racing.getTransport(i)->getIType() == type_transp)
		{
			std::cout << racing.getTransport(i)->getName() << " уже зарегистрирован!" << std::endl;
			return false;
		}
	}
	return true;
}
Camel camel(10, 30, 5, 8);
FastCamel fastCamel(40, 10, 5, 6.5, 8);
MagicCarpet magicCarpet(10);
Centaur centaur(15, 8, 2);
AllTerrainBoots allTerrainBoots(6, 60, 10, 5);
Broomstick broomstick(20);
Eagle eagle(8);

bool transport_reg(int type_transp)
{
	bool result = check_transp_reg(type_transp);

	if (!result)
	{
		return false;
	}

	if (type_transp == static_cast<int>(TransportType::TTCamel))
	{
		racing.registerTransport(&camel);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTFastCamel))
	{
		racing.registerTransport(&fastCamel);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTCentaur))
	{
		racing.registerTransport(&centaur);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTAllTerrainBoots))
	{
		racing.registerTransport(&allTerrainBoots);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTMagicCarpet))
	{
		racing.registerTransport(&magicCarpet);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTEagle))
	{
		racing.registerTransport(&eagle);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	else if (type_transp == static_cast<int>(TransportType::TTBroomstick))
	{
		racing.registerTransport(&broomstick);
		std::cout << racing.getTransport(racing.getCntRegTransport() - 1)->getName() << " успешно зарегистрирован" << std::endl;
	}
	return true;
}

void showRacingResult()
{
	system("cls");
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < racing.getCntRegTransport(); i++)
	{
		std::cout << i + 1 << ". " << racing.getTransport(i)->getName() << " : " << racing.getTransport(i)->getRacingTime() << std::endl;
	}
}


int main()
{
    setlocale(LC_ALL, "Russian");
	int result;

	while (true)
	{
		std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
		//устанавливаем начальные данные гонки
		selectRacingType();
		selectDistance();

		//начальное меню
		firstSelectAction();

		//регистрация ТС
		racing.initRacing();

		while (true)
		{
			showRacingInfo();
			result = menuRegisterTransport();
			if (result == 0)
			{
				break;
			}
			else
			{
				if (transport_reg(result) == true)
				{
					//успешно
				}
				else
				{
					//неуспешно
				}
			}
		}//register

		//начать гонку
		while (true)
		{
			if (secondSelectAction() == 2)
			{
				break;
			}
			while (true)
			{
				showRacingInfo();
				result = menuRegisterTransport();
				if (result == 0)
				{
					break;
				}
				else
				{
					if (transport_reg(result) == true)
					{
						//успешно
					}
					else
					{
						//неуспешно
					}
				}
			}   //registration

		}//start racing

		//результаты
		racing.processRacing();
		showRacingResult();

		if (isRacingExit())
		{
			break;
		}
	}

    return 0;
}
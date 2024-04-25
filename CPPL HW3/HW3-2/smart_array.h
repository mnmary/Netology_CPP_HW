#pragma once
class smart_array
{
private:
	int* array;   //������������ ������ 
	int cnt = 0;	//���������� ���������
	int size = 0;	//������ �������
public:
	smart_array();	//����������� ��� ����������
	smart_array(int size);	//����������� � �����������
	~smart_array();             // ����������
	void add_element(int value);	//�������� ������� � ����� �������
	int get_element(int index);	//������� �������� �������� � �������� 0..���������� ���������-1
	smart_array& operator=(const smart_array& other);	//�������� ������������( �� ������ ���� ������������ ����� ����  a = b = c = ...
};


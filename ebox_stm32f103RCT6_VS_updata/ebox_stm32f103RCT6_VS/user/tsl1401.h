
#ifndef __TSL1401
#define __TSL1401
#include "ebox.h"
#define TSL1401_DATA_LENGTH 128

//����TSL1401����
class TSL1401
{
public:
	
	//���캯����ȷ��IO��
	TSL1401(Gpio* pinADC, Gpio* pinSI, Gpio* pinCLK);

	//��ʼ����������ʼ��IO�ں�ADC
	void begin();

	//�ع⺯��������ʱ�Ӽ��clk_time��С�ع�ʱ�䣬ȱʡֵΪ1us,SI���delay_time�������ع�ʱ�䣬
	void capture(int delay_time);

	//��ȡ���ݺ���
	u16* getData();
private:
	Gpio* pinADC;
	//void* delayMsFunction;
	Gpio* pinSI;
	Gpio* pinCLK;
	u16 data[TSL1401_DATA_LENGTH];

};

class TSL1401Auto:public TSL1401
{
public:
	TSL1401Auto(Gpio* pinADC, Gpio* pinSI, Gpio* pinCLK);
	int capture_time(int cru_time);
private:

};
#endif
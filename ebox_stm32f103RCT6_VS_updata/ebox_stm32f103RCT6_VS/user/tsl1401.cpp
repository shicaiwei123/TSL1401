#include "tsl1401.h"

TSL1401::TSL1401(Gpio* pinADC, Gpio* pinSI, Gpio* pinCLK)
{
	this->pinADC = pinADC;
	this->pinSI = pinSI;
	this->pinCLK = pinCLK;
};
//��ʼ������
void TSL1401::begin()
{
	pinADC->mode(AIN);
	pinCLK->mode(OUTPUT_PP);
	pinSI->mode(OUTPUT_PP);
	
};
//�ع��ȡ����
void TSL1401::capture(int delay_time)
{
	int time = delay_time;
	unsigned char i,j;
	unsigned int adcx = 0;

	pinSI->set();            /* SI  = 1 */
	delay_us(1);
	pinCLK->set();         /* CLK = 1 */
	delay_us(1);
	pinSI->reset();            /* SI  = 0 */
	delay_us(1);
	pinCLK->reset();         /* CLK = 0 */

	for (i = 0; i<127; i++)
	{
		delay_us(10);
		pinCLK->set();       /* CLK = 1 */
		delay_us(1);
		pinCLK->reset();       /* CLK = 0 */
	}
	delay_us(1);
	pinCLK->set();           /* CLK = 1 */
	delay_us(1);
	pinCLK->reset();           /* CLK = 0 */

	pinSI->set();           //SI  = 1 
	delay_us(1);
	pinCLK->set();           // CLK = 1 
	delay_us(1);
	pinSI->reset();           // SI  = 0 
	delay_us(1);

	for (j = 0; j<128; j++)
	{
		delay_us(1);
		pinCLK->reset();       // CLK = 0
		delay_us(1);
		//Sampling Pixel 2~128
		adcx =analog_read(pinADC);
		data[j] = adcx;
		pinCLK->set();       // CLK = 1 
	}
	delay_us(1);
	pinCLK->reset();           // CLK = 0
	delay_us(1);
	pinCLK->set();           // CLK = 1
	delay_ms(time);

};

//���ݻ�ȡ
u16 *TSL1401::getData()
{
	return data;
};

/*//�����Զ��ع���
TSL1401Auto::TSL1401Auto(Gpio * pinADC, Gpio * pinSI, Gpio * pinCLK):TSL1401(pinADC,pinSI,pinCLK)
{

}
//�Զ��ع�ʱ�����
int TSL1401Auto::capture_time(int cru_time)
{
	u16 *temp;
	u32 adc_sum=0;
	u16 adc_avg=0;
	int time = cru_time;
	int k = 0;
	temp = getData();
	for (k = 0; k < 128; k++)
		adc_sum += *temp;
	adc_avg = adc_sum /128;
	if (adc_avg > 3500)
		time--;
	if (adc_avg < 3000)
		time++;
	return time;
}
*/
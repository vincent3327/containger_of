/**************************************************************
*此为611面试闹钟排序程序
*11/6/2020
*vincent you
*nanshan hi-tech park ShenZhen
***************************************************************/

#include<stdio.h>

#define DIM(a)  (sizeof(a)/sizeof(*a))
#define SWAP(a,b) {a=a+b,b=a-b,a=a-b}

#define CLOCK1CONFIG \
{\
.hour = 1,.minute = 20\
}

#define CLOCK2CONFIG \
{\
.hour = 9,.minute = 55\
}

#define CLOCK3CONFIG \
{\
.hour = 9,.minute = 30\
}

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef struct clock_tag{
	uint8_t hour;
	uint8_t minute;
}clock_t;

//function to swap clock type data
void clock_swap(clock_t* cp1,clock_t* cp2)
{
	clock_t c_temp = *cp1;
	*cp1 = *cp2;
	*cp2 = c_temp;
}

//function to sort clock array\
param1:start address of clock array\
param2:length of clock array\
return:clock struct array pointer
clock_t* sorted_clock(clock_t* clock_pp,uint8_t length)
{
	clock_t* cl_pp = clock_pp;
	for(uint8_t i =0;i<length-1;i++)
	{
		for(uint8_t j =0;j<length-1-i;j++)
		{
			if((cl_pp[j].hour*60+cl_pp[j].minute) > (cl_pp[j+1].hour*60+cl_pp[j+1].minute))
				clock_swap(&cl_pp[j],&cl_pp[j+1]);
				//SWAP(cl_pp[j],cl_pp[j+1]); //no way!because not a "single data"
		}
	}
	return cl_pp;
}

int main()
{
	
	clock_t clock1 = CLOCK1CONFIG,clock2 = CLOCK2CONFIG,clock3 = CLOCK3CONFIG;
	
	//int a[3];
	//a[0] = 1;a[1] = 1;a[2] = 1;
	
	
	/*clock_t clock1 = CLOCK1CONFIG;
	clock_t clock2 = CLOCK2CONFIG;
	clock_t clock3 = CLOCK3CONFIG;*/

	clock_t clock_p[3] = {clock1,clock2,clock3};
	uint8_t length_of_clockpointer_array = DIM(clock_p);
	for(uint8_t i = 0;i<length_of_clockpointer_array;i++)
	{
		printf("clcok[%d].hour = %d,clock[%d].minute = %d\n",i,clock_p[i].hour,i,clock_p[i].minute);
	}
	printf("%d\n",length_of_clockpointer_array);
	
	
	clock_t* sorted_clockarray_p = sorted_clock(clock_p,length_of_clockpointer_array);
	for(uint8_t i = 0;i<length_of_clockpointer_array;i++)
	{
		printf("after sorted,clock[%d].hour = %d,clock[%d].minute = %d\n",i,sorted_clockarray_p[i].hour,i,sorted_clockarray_p[i].minute);
	}
}

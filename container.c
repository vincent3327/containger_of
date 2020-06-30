
#include<stdio.h>
//#define container_of(ptr,type,member) (type*)((unsigned int)ptr - (unsigned int)(&((type*)0->member)))

#pragma pack(1)
//(&(((type*)0)->member))
#define container_of(ptr,type,member) (type*)((char*)ptr - (char*)(&(((type*)0)->member)))//强转(char*)是为了指针减法以单个字节方式进行
#define DIM(s) sizeof(s)/sizeof(*s)

typedef struct stu_tag{
	int a[3];
	char c1;
	int score;
	char c;
	double d;
}stu;

int main()
{
	//char *cp = 8;
	//char* c1p = (char*)(cp - 3);
	int a[4] = {0};
	
	stu st1;
	st1.d = 999;
	st1.score = 5;
	//stu *stptr;
	
	
	char *ptr1 = &st1.c;
	//同等类型指针之间才能赋值
	stu* stptr = container_of(ptr1,stu,c);//if write as : container_of(ptr1,stu,d),then a cast warning occurs
	//printf("cp %x\n",cp);
	//printf("c1p = %x\n",c1p);
	
	printf("sizeof a = %d\n",sizeof(a));
	printf("DIM(a) = %d\n",DIM(a));
	
	printf("sizeof struct stu = %d\n",sizeof(stu));
	printf("sizeof double = %d\n",sizeof(double));
	printf("sizeof int = %d\n",sizeof(int));
	printf("ptr1 = &st1.c = %x\n",ptr1);
	printf("addr of st1 = %x\n",&st1);
	printf("container_of(ptr1,stu,c) = %x\n",stptr);
	printf("container_of(ptr1,stu,c)->score = %d\n",stptr->score);
	
}
add in local master 1

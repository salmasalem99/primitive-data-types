#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_binary_char(char c) {
	     int binarynumber[8];
    int i;
    int bit=128;
    for(i=0;i<8;i++)
    {
        if((bit&c)==bit)
            binarynumber[i]=1;
        else
            binarynumber[i]=0;
        bit=(bit>>1);
    }
    for(i=0;i<8;i++)
    printf("%d",binarynumber[i]);
}
/*
 *
 */
void question1() {
	printf("printing from -16 to 15 in binary\n");
	char c;
	for(c=-16; c<16; c++) {
		printf("%d\t", c);
		print_binary_char(c);
		printf("\n");
	}
}
/*
 *
 */
void print_binary_float(float f) {
	   union converter
    {
        float IEEE_F_N;
        int integer;

    }X;
    X.IEEE_F_N=f;
    printf("%.08X",X.integer);
}
/*
 *
 */
void question2() {
	float numbers[] = {0.0f, 1.0f, 2.0f, 0.1f};
	int count = sizeof(numbers) / sizeof(numbers[0]); 
	int i;

	for(i=0; i<count; i++) {
		printf("%.2f is represented as: ", numbers[i]);
		print_binary_float(numbers[i]);
		printf("\n");
	}
}
/*
 *
 */
float get_smallest_positive_float() {
	 union converter
    {
        float IEEE_F_N;
        int integer;

    }X;
    X.integer=1;
    return X.IEEE_F_N;
}
/*
 *
 */
int get_double_epsilon() {
	union conditional
   {
       long long i;
       double d;
   }F;
   F.d=1.0;
   F.i++;
   F.i++;
   double z=F.d-1.0;
   return z;
}
/*
 *
 */
int get_longdouble_exponent_bias() {
	int i,counter=0;
    int y;
    int bit=1;
    union conversion
    {
        long double LD;
        unsigned char arr[12];
    }S;
    S.LD=1.0L;
    for(i=0;i<sizeof(S.LD);i++)
    {
        for(y=7;y>=0;y--)
        {
            char bit=S.arr[i]>>y;
            if(bit&1)
                counter++;
        }
    }
    int BE=pow(2,counter-1)-1;
	return BE;
}
/*
 *
 */
void question3() {
	printf("The smallest positive 'float' is: %f\n", get_smallest_positive_float);
	printf("Epsilon for 'double' is: %ld\n", get_double_epsilon());
	printf("'long double' has a bias of %d for its exponent\n", get_longdouble_exponent_bias());
	
}
/*
 *
 */
int get_command() {
	int choice;
	printf("\n\n");
	printf("*********************************************\n");
	printf("* Enter 1 for Signed Integer Representation *\n");
	printf("* Enter 2 for Floating-Point Endianness     *\n");
	printf("* Enter 3 for Floating-Point Representation *\n");
	printf("* Enter anything else to exit               *\n");
	printf("*********************************************\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	fseek(stdin, 0, SEEK_END);
	printf("\n");
	return choice;
}
/*
 *
 */
main() {
	int choice;
	while(1) {
		switch(get_command()) {
			case 1:
				question1();
				break;
			case 2:
				question2();
				break;
			case 3:
				question3();
				break;
			default:
				printf("Invalid Choice. Exiting...\n");
				exit(1);
		}
	}
	return 0;
}
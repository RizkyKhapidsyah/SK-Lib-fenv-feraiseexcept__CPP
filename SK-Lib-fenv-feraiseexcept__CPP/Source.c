
#include <stdio.h>      /* printf */
#include <fenv.h>       /* feraiseexcept, fetestexcept, FE_ALL_EXCEPT, FE_INVALID */
#include <conio.h>

#pragma STDC FENV_ACCESS on

double fn(double x) {  /* some function for which zero is a domain error */
	if (x == 0.0) {
		feraiseexcept(FE_INVALID);
	} else {
		//Kosongkan Dulu
	}

	return x;
}

int main() {
	feclearexcept(FE_ALL_EXCEPT);
	fn(0.9);

	if (fetestexcept(FE_INVALID)) {
		printf("FE_INVALID raised\n");
	} else {
		printf("Tidak terjadi apa apa.");
	}

	_getch();
	return 0;
}
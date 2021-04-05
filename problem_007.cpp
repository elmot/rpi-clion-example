#include <iostream>
#include <math.h>

/**
 * Problem 7
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that 
 * the 6th prime is 13.
 * 
 * What is the 10 001st prime number?
 * 
 * */

//@Author 	Xavier
//@Date		2 Oct 2013

using namespace std;

int isPrime(long num) // Returns 1 (true) if its prime, or 0 (false) if not
{
	if (num < 2) // 1 is not a prime number
		return 0;

	if (num > 2 && (num % 2) == 0)
		return 0;

	for(int i = 2; i < num; i++ )
	{
		if ( (num % i) == 0)
			return 	0;
	}
	return 1;
}


int main (int argc, char* argv[])
{
    cout << "Hello, world" <<endl;
	int threshold = 1001, i = 0;
	long prime = 0;
	
	do 
	{
		if (isPrime(++ prime)) i ++;
	}
	while (i != threshold);
	
	cout << "10 001st Prime is:  " << prime << endl;	
	
	return 0;
}

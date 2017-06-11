#include <iostream>
using namespace std;

#define SIZE_A 99999

/*從array的高位元開始存值*/
void factorial(int n)
{

	/*init array*/
	int a[SIZE_A] = { 0 };
	int tail = SIZE_A - 1;

	a[tail] = 1;

	for (int i = 1; i <= n; i++)
	{
		/* multiply the value */
		for (int j = tail; j >= 0; j--)
		{
			a[j] = a[j] * i;
		}
		//進位 
		for (int j = tail; j >= 0; j--)
		{
			if (a[j] >= 10)
				a[j - 1] = a[j - 1] + (a[j] / 10);
			a[j] = a[j] % 10;
		}
	}

	//多餘的0不print
	int k = 0;
	while (a[k] == 0) {
		k++;
	}

	for (int i = k; i< SIZE_A; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

void Factorial() {
	int n;

	while (cin >> n) {
		if (n > 0) {
			factorial(n);
		}
		else if (n % 10 != 0) {
			cout << "請輸入正整數" << endl;
		}
		else {
			cout << "請輸入大於0的整數" << endl;
		}
	}
}

int main()
{
	Factorial();

	system("pause");
	return 0;
}

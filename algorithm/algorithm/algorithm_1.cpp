#include <iostream>
#include <vector>

using namespace std;

//소수의 합 결과 : 효율성 0 정답 all
//1초안에 10000000의 소수의 더한 값을 내야함

bool Primes(vector<int>& vecPrime, int a)
{
	for (int i = 0; i < vecPrime.size(); ++i)
	{
		if (a % vecPrime[i] == 0)
			return false;
	}

	return true;
}

long long solution(int a)
{
	int iPlay = 2;
	int iAnswer = 2;
	vector<int> vecPrime;
	
	//vecPrime.reserve(100000);
	vecPrime.push_back(2);

	for (int i = 2; i <= a; ++i)
	{
		//if (Primes(vecPrime, i))
		//{
		//	iAnswer += i;
		//	vecPrime.push_back(i);
		//	//cout << i << endl;
		//}
		for (int j = 0; j < vecPrime.size(); ++j)
		{
			if (i % vecPrime[j] == 0)
				break;
			if (j + 1 == vecPrime.size())
			{
				iAnswer += i;
				vecPrime.push_back(i);
				//cout << i << endl;
			}
		}
	}

	return iAnswer;
}


void main(void)
{
	cout << solution(30000) << endl;
	system("pause");
}
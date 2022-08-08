#include <iostream>

using namespace std;

int main() {
	int		n1Dollar, n2Dollar, n5Dollar, n10Dollar, busFare;
	int		c1, c2, c5, c10, p1, p2, p5, p10;
	int		totalTender, bestTotal;

	// Original number of coins in pocket
	cout << "Original number of coins in pocket:" << endl;
	cout << "Number of One-Dollar coins: "; cin >> n1Dollar;
	cout << "Number of Two-Dollar coins: "; cin >> n2Dollar;
	cout << "Number of Five-Dollar coins: "; cin >> n5Dollar;
	cout << "Number of Ten-Dollar coins: "; cin >> n10Dollar;
	cout << endl;

	// Bus Fare to tender.
	// Assume Bus Fare is a whole integer
	cout << "Bus Fare : "; cin >> busFare;
	cout << endl;

	// Fill in the code to calculate the number of coins remaining.
	// If not enough money, cannot board the bus, then coins remaining should be the same as before.
	// Since you are supposed to tender the exact fare, if you do not have the exact change,
	// you should tender the minimum above the bus fare.
	// In any case, the number of coins remaining should be a minimum.
	
	//initialization the variable
	c1 = c2 = c5 = c10 = p1 = p2 = p5 = p10 = totalTender = bestTotal = 0;
	
	// When the fare == combination of the coins
	if ( (n1Dollar*1 + n2Dollar*2 + n5Dollar*5 + n10Dollar*10) >= busFare)
	{
		for (c10 = 0; c10<=n10Dollar; ++c10)
		{
			for (c5 = 0; c5<=n5Dollar; ++c5)
			{
				for (c2 = 0; c2<=n2Dollar; ++c2)
				{
					for (c1 = 0; c1<=n1Dollar; ++c1)
					{
						totalTender = c1*1+c2*2+c5*5+c10*10;
						if(totalTender == busFare)
						{
							{p1=c1; p2=c2; p5=c5; p10=c10;}
							{break;}
						}
					}
					if(totalTender == busFare)
					{break;}
				}
				if(totalTender == busFare)
				{break;}
			}
			if(totalTender == busFare)
			{break;}
		}
	}
	// when no combination exist == fare, find the minimun amount
	if ( (n1Dollar*1 + n2Dollar*2 + n5Dollar*5 + n10Dollar*10) > busFare && totalTender != busFare)
	{
		for (c10 = 0; c10<=n10Dollar; ++c10)
		{
			for (c5 = 0; c5<=n5Dollar; ++c5)
			{
				for (c2 = 0; c2<=n2Dollar; ++c2)
				{
					for (c1 = 0; c1<=n1Dollar; ++c1)
					{
						bestTotal = c1*1+c2*2+c5*5+c10*10;
						if(bestTotal > busFare)
						{
							{p1=c1; p2=c2; p5=c5; p10=c10;}
							{break;}
						}
					}
					if(bestTotal > busFare)
					{break;}
				}
				if(bestTotal > busFare)
				{break;}
			}
			if(bestTotal > busFare)
			{break;}
		}
	}

	cout << "Coins remaining:" << endl;
	cout << "Number of One-Dollar coins: " << n1Dollar-p1 << endl;
	cout << "Number of Two-Dollar coins: " << n2Dollar-p2 << endl;
	cout << "Number of Five-Dollar coins: " << n5Dollar-p5 << endl;
	cout << "Number of Ten-Dollar coins: " << n10Dollar-p10 << endl;
	return 0;
}
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    array<int,7> a = {{2,3,5,7,11,13,17}};

	for(int k =0; k < 100000; k++)
	{
		for_each(a.begin(), a.end(), [&](int x) {
				cout << x << ",";
		});
		cout << endl;
	}
}


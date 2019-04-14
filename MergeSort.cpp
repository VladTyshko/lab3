#include <iostream>
#include <vector>
using namespace std;

void margeSort(vector<int> &a, int l, int r)
{
		if (l == r)
		{
			return;
		}
		
		int m = (l + r) / 2;
		margeSort(a, l, m);
		margeSort(a, m + 1, r);
		int pointer1 = l;
		int pointer2 = m + 1;
		vector<int> res;
	for (int i = 0; i < r - l + 1; ++i)
	{
		if ((pointer1 <= m) && ((pointer2 > r) || (a[pointer1] < a[pointer2])))
		{
			res.push_back(a[pointer1]);
			pointer1++;
		}
		else{
			res.push_back(a[pointer2]);
			pointer2++;
		}
	}
	for (int i = 0; i < res.size(); ++i)
	{
		a[i + l] = res[i];
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	margeSort (a, 0, n - 1);
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

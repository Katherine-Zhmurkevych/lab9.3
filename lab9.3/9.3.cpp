#include <iostream>
#include <string.h>
#include<stdio.h>

using namespace std;

struct Price
{
	string product;
	string shop;
	int cost;
};

void sortByAlphabeticalOrder(Price* p, int n)
{
	Price t;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (p[j - 1].product > p[j].product)
			{
				t = p[j - 1];
				p[j - 1] = p[j];
				p[j] = t;
			}
		}
	}
}

void findAllProductsByShopName (Price* p, int n)
{
	string name;
	int counter = 0;
	cout << "Enter the name of the shop: " << endl; cin >> name;
	for (int i = 0; i < n; i++)
	{
		if (p[i].shop == name) {
			cout << "Shop: " << p[i].shop << " Product: " << p[i].product << " Cost: " << p[i].cost << endl;
		}
		else  if (counter == n) {
			cout << "Error. There is no shop by that name."<< endl;
		
		}
		counter++;
	}
}

int main ()
{
	int n;
	cout << "Enter n" << endl; cin >> n;
	Price* p = new Price[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter name of the product" << endl; cin >> p[i].product;
		cout << "Enter name of the shop" << endl; cin >> p[i].shop;
		cout << "Enter cost of the product" << endl; cin >> p[i].cost;
	}

	for (int i = 0; i < n; i++) {
		cout << "product: " << p[i].product << " shop: " << p[i].shop << " cost: " << p[i].cost<<endl;
	}
	
	sortByAlphabeticalOrder(p, n);
	cout << "Modified array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "product: " << p[i].product << " shop: " << p[i].shop << " cost: " << p[i].cost << endl;
	}
	findAllProductsByShopName(p, n);

	return 0;
}

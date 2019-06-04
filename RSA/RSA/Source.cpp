#include <iostream>
#include <vector>

using namespace std;

void SITO(int p, vector < int> &V) {
	for ( int i = 2; i < p; i++) V.push_back(i);
	int i=2;
	while (i <= sqrt(p)) {
		for (int j = i; j < V.size(); j++) {
			if (V[j] % i == 0 and V[j]!=i) V.erase(V.begin() + j);
		}
		i++;
	}

}
 long long int EUKLIDES( long long int a,  long long int b,long long int& xx,long long int& yy) {
	vector < long long int> r;
	vector < long long int> q;
	vector < long long int> x;
	vector < long long int> y;
	long long int i=0;

	r.push_back(a);
	r.push_back(b);
	q.push_back(floor((r[r.size()-2] / r[r.size()-1])));
	r.push_back(r[r.size() - 2] - r[r.size()-1] * q[q.size()-1]);
	x.push_back(1);
	y.push_back(-q[q.size() - 1]);

	q.push_back(floor((r[r.size() - 2] / r[r.size() - 1])));
	r.push_back(r[r.size() - 2] - r[r.size() - 1] * q[q.size() - 1]);
	x.push_back(-x[x.size() - 1]* q[q.size() - 1]);
	y.push_back(1-y[y.size() - 1] * q[q.size() - 1]);

	while (r[r.size()-1] != 0) {
		q.push_back(floor((r[r.size()-2] / r[r.size()-1])));
		r.push_back(r[r.size()-2] - r[r.size()-1] * q[q.size()-1]);
		x.push_back(x[x.size() - 2]-x[x.size()-1]*q[q.size()-1]);
		y.push_back(y[y.size() - 2] - y[y.size() - 1] * q[q.size() - 1]);
	}
	xx= x[x.size() - 2];
	yy = y[y.size() - 2];
	return r[r.size()-2];
 }
 void RSA(long long int p, long long int q) {
	 long long int n = p * q;
	 long long int m = (p-1)*(q-1);
	 long long int e,x,y,d;
	 
	 do
	 {
		 cout << "Wprowadz 'losowa' liczbe  'e' taka, ze e<"<<m<<" oraz NWD(e,"<<m<<")==1:";
		 cin >> e;
	 } while (EUKLIDES(e, m,x,y) != 1);
	 if (x > 0) d = x;
	 else d = x + m;
	 cout << "Klucz publiczny: (" << n << "," << e << ")"<<endl;
	 cout << "Klucz prywatny: (" << n << "," << d << ")" << endl;

 }
int main() {

	 int p,p2,p3;
	vector < int> V;
	long long int x=0, y=0;
	long long int a, b;
	cout << "Podaj zakres: ";
	cin >> p;
	SITO(p, V);
	do {
		cout << "Podaj i :";
		cin >> p2;
	} while (p2>V.size());
	cout << "i-ta liczba pierwsza: " << V[p2 - 1]<<endl;
	do {
		cout << "Podaj j :";
		cin >> p3;
	}while (p3>V.size());
	cout << "j-ta liczba pierwsza: " << V[p3 - 1] << endl;

	cout << endl << "Euklides: " << endl;
	cout << "podaj a: ";
	cin >> a;
	cout << "podaj b: ";
	cin >> b;
	cout << "NWD(a,b)=" << EUKLIDES(a,b,x,y) << endl;
	cout << "x= " << x << ", y= " << y<<endl;
	int xx, yy;
	cout << endl << "RSA: " << endl;
	cout << "podaj p:";
	cin >> xx;
	cout << "podaj q:";
	cin >> yy;
	RSA(xx,yy);


	
	//for (int i = 0; i < V.size(); i++) cout << V[i] << endl;
	
	//cout << V[100000];
	//cout << EUKLIDES(1920, 162, x, y) << endl;
	//cout << x << endl;
	//cout << y << endl;

	system("pause");
	return 0;
}
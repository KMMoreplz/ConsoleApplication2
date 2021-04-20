#include <iostream>
#include <ctime>
#include <math.h>
#include <string>	
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Возвращаем true, если разница между a и b в пределах процента эпсилона 
//bool approximatelyEqual(double a, double b, double epsilon)
//{
//	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
//}
//
//int generateID()
//{
//	static int s_itemID = 0;
//	return s_itemID++;
//	cout << s_itemID;
//}

//cin.ignore(32767, '\n'); // игнорируем символы перевода строки "\n" во входящем потоке длиной 32767 символов


/* int main()
{
    const int N = 26;
	string s;
	getline(cin, s);
	int counter=0;
	char a = 0;
	cout << s[0];
	while (a != '.') {
		cout << a << endl;
		counter++;
		a = s[counter];
	}
	cout << counter << endl;
   char b[N];
   for (int i = 0; i < 26; i++) {
	   for (int j = 0; j < counter; j++) {
		   if ((char(s[j])) - 65==i || (char(s[j])) - 97 == i) 
		   {
			   b[i]++;
		   }
	   }
   }
   int mx = b[0];
   int mxi = 0;
   for (int i = 0; i < 26; i++) {
	   cout <<char( i+65) << "  - " <<int( b[i]+52)<< " - |";
	   if (mx < b[i] && b[i] != b[0]) {
		   mx = b[i];
		   mxi = i;
	   }
   }cout << endl << endl << endl;
   cout << "max-" << char(mxi + 65) << ". count-" << mx+52;
}
*/


/* int main() {
	const int N = 26;
	string s;
	getline(cin, s);
	int counter = 0;
	int savedcount = 0;
	int spacecount = 0;
	char a = s[counter];
	while (a != '.') {
		cout << a << endl;
		if (a == ' ') {
			spacecount++;
		}
		counter++;
		a = s[counter];
	}
	savedcount = counter;
	cout << counter << endl;
	cout << spacecount << endl;
	int min = 20;
	int skip = 0;
	for (int i = 0; i < spacecount+1; i++) {
		counter = 0+skip+1;
		a = s[skip+1];
		while (a != ' ') {
			counter++;
			skip++;
			a = s[counter];
		}
		counter -= skip;
		if (counter <= min && counter !=0) { min = counter; }
	}
	cout << min << "min" << endl;
	int minm = 0;
	for (int i = 0; i < savedcount; i++) {
		if (char(s[i]) == 32) {
        cout<<' ';
		}else if((char(s[i]) - min < 65 && (char(s[i])<=89)&& (char(s[i]) >= 65)) || ((char(s[i]) - min < 97)&& (char(s[i]) <=122)&&(char(s[i]) >= 97))){
			minm =26-min;
			cout << char(s[i]+minm);
		}
		else { cout << char(s[i] - min); }
	}
}

*/
/*
 struct voting
{
	int counter;
	string name;
};
int main() 
{
	voting party[10];

	int x = 0;
	cout << "enter X-votes";
	cin >> x;
	for (int i = 0; i < x + 1; i++)
	{
		string a;
		cin >> a;
		if (a == "1" || a == "one" || a == "first" || a == "party one") {
			party[1].counter++;
		}
		else if (a == "2" || a == "two" || a == "second" || a == "party two") {
			party[2].counter++;
		}
		else if (a == "3" || a == "three" || a == "third" || a == "party three") {
			party[3].counter++;
		}
		else if (a == "4" || a == "four" || a == "foth" || a == "party four") {
			party[4].counter++;
		};
	}
	party[1].name = "party one";
	party[2].name = "party two";
	party[3].name = "party three";
	party[4].name = "party four";
	for (int i = 1; i < 10; i++) {
		for (int j = i+1; j < 10; j++) {
			if (party[i].counter < party[j].counter) {
				swap(party[i], party[j]);
			}
		}
	}
	for (int i = 1; i < 4; i++) 
	{
		 cout<<party[i].name << endl;
	}
}
*/
//сортировка по году рождения ддммгггг
/* 
struct elder
{
	string date;
	int counter = 0;
	string name;
	string day;
	string month;
	string year;
	string savedname;
};
int main()
{
	elder party[10];

	int x = 0;
	cout << "enter X-ppls";
	cin >> x;
	
	for (int i = 0; i < x+1; i++)
	{
		string s;
		getline(cin, party[i].name);
		party[i].savedname = party[i].name;
		s = (party[i].name.erase(0, party[i].name.find(' ') + 1));
		s = (party[i].name.erase(0, party[i].name.find(' ') + 1));
		party[i].date = s;
		s = party[i].date.substr(0, party[i].date.find('.'));
		party[i].day = s;

		s=party[i].date.erase(0, party[i].date.find('.')+1);
		s = s.substr(0, party[i].date.find('.'));
		party[i].month = s;

		s = party[i].date.erase(0, party[i].date.find('.') + 1);
		party[i].year = s.substr(0);
		//cout << party[i].day << endl << party[i].month << endl << party[i].year;
	}
	int max =atoi(party[1].year.c_str());
	int max1= atoi(party[1].month.c_str());
	int max2= atoi(party[1].day.c_str());
	int savedi = 1;
	for (int i = 1; i < x+1; i++) {
		int yr = atoi(party[i].year.c_str());
		int mn = atoi(party[i].month.c_str());
		int dy = atoi(party[i].day.c_str());
	
		if ((yr < max || (yr == max && mn < max1) || (yr == max && mn == max1 && dy < max2)) && i != 1) {
			max = yr; max1 = mn; max2 = dy;
			savedi = i;
		}
		else if (yr == max && max1 == mn && max2 == dy &&i!=1) {
			party[1].counter++;
				
		}
	}
	if (party[1].counter > 0) {
		cout << party[1].counter;
	}
	else { cout << party[savedi].savedname; }
}
*/
/*
int main()
{
	for (int i = 0; i < 5; i++) {
		cout << i << "  000000000000000" << endl;
	}
	int x = 0;
	for (int i = 1; i < 101; i++) {
		x += i;
	}
	cout << x << endl;
	int a[3];
	for (int i = 0; i < 3; i++) {
		a[i] = (0 + rand() % 100)-50;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j && a[i] == a[j]) {
				cout << "yes";
			}
			else { cout << "ERROR"; }
			for (int k = 0; k < 3; k++) {
				if (i != j && j != k && (a[i] == a[j] + a[k] || a[j] == a[i] + a[k] || a[k] == a[i] + a[j])) {
					cout << "yes" << endl;
				}
			}
		}
	}
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > 0) {
			counter++;
		}
	}
	cout << counter << endl;
	counter = 0;
	for (int i = 1; i < 498; i++) {
		if (i % 2 == 0) {
			counter++;
			cout << i << endl;
		}
	}
	cout << counter << endl;
	x = 0;
	for (int i = 1; i < 15; i++) {
		x += i;
	}
	cout << x << endl;
	x = 1;
	cout << "----";
	for (int i = 1; i < 9436; i++) {
		if (i % 2 != 0) {
			x *= i;
		}
	}
	cout << x << endl;
	long int b[1825];
	counter = 0;
	for (int i = 54; i < 1825; i++) {
		if (i % 5 == 0) {
			b[counter] = i;
			counter++;
		}
	}
	cout << counter;
	system("Pause");

}
*/
//тренарный оператор x?y:z
/*
int main() {
	bool isBigClass = false;
	const int classSize = isBigClass ? 30 : 20;
	cout << classSize;
}
*/
/*
int main()
{
	int counterThree = 0;
	int counterFive = 0;
	long int a[204];
	a[201] = 1000;
	a[202] = 0;
	int minThree = a[201];
	int maxFive = a[202];
	for (int i = 0; i < 200; i++) {
		a[i] = rand() % 20000;
		if (a[i] % 10 == 3 || a[i] % 100 == 3 || a[i] % 1000 == 3 || a[i] % 10000 == 3) {
			counterThree++;
			if (a[i] <= minThree) { minThree = a[i]; }
		}
		else if (a[i] % 10 == 5 || a[i] % 100 == 5 || a[i] % 1000 == 5 || a[i] % 10000 == 5) {
			counterFive++;
			if (a[i] > maxFive) { maxFive = a[i]; }
		}
	}
	cout << minThree << "-MinThree. " << maxFive << "-Maxfive." << endl;
	cout << counterThree << endl << counterFive << endl;
	if (counterFive > counterThree) {
		for (int i = 0; i < 200; i++) {
			if (a[i] % 10 == 3 || a[i] % 100 == 3 || a[i] % 1000 == 3 || a[i] % 10000 == 3) {
				a[i] = minThree;
			}
			cout << a[i] << "  ";
		}
	}
	else for (int i = 0; i < 200; i++) {
		if (a[i] % 10 == 5 || a[i] % 100 == 5 || a[i] % 1000 == 5 || a[i] % 10000 == 5) {
			a[i] = maxFive;
		}
		cout << a[i] << "  ";
	}
}
*/
//std::cin.ignore(32767, '\n'); // игнорируем символы перевода строки "\n" во входящем потоке длиной 32767 символов

// сортировка бутерброда



/*void gnomesort(int n, int a[])
{
	int i = 0;
	while(i < n) {
		if (i == 0 || a[i - 1] <= a[i]) { i++; }
		else { int tmp = a[i]; a[i] = a[i - 1]; a[--i] = tmp; }
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
*/

/*
void mergeSort(int* a, int n)
{
	int step = 1;  // шаг разбиения последовательности
	int* temp = (int*)malloc(n * sizeof(int)); // дополнительный массив
	while (step < n)  // пока шаг меньше длины массива
	{
		int index = 0;    // индекс результирующего массива
		int l = 0;      // левая граница участка
		int m = l + step;  // середина участка
		int r = l + step * 2;  // правая граница участка
		do
		{
			m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
			r = r < n ? r : n;
			int i1 = l, i2 = m; // индексы сравниваемых элементов
			for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
			{
				if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } // заполняем участок результирующей последовательности
				else { temp[index++] = a[i2++]; }
			}
			// Или i1 < m или i2 < r - только один из операторов while может выполниться
			while (i1 < m) temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
			while (i2 < r) temp[index++] = a[i2++]; // в результирующий массив
			l += step * 2; // перемещаемся на следующий сортируемый участок
			m += step * 2;
			r += step * 2;
		} while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
		for (int i = 0; i < n; i++) // переносим сформированный массив обратно в a
			a[i] = temp[i];
		step *= 2; // увеличиваем в 2 раза шаг разбиения
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}

void combsort(double a[] , int n)
{
	int i, j, gap = 1;
	bool swapped = true;
	double temp;
	gap = n;
	while (gap != 1 || swapped == true)

	{
		gap = gap * 10 / 13;
		if (gap == 9 || gap == 10)gap = 11;
		if (gap < 1)gap = 1;
		swapped = false;
		for (int i = 0; i < n - gap; i++)
		{
			if (a[i] > a[i + gap])
			{
				swap(a[i], a[i + gap]);

				swapped = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
*/

/*

	int is_sorted(int* a, int n) {
	while (--n >= 1) {
		if (a[n] < a[n - 1]) {
			return 0;
		}
	}
	return 1;
}
void shuffle(int* a, int n) {
	int temp, r;
	for (int i = 0; i < n; i++) {
		temp = a[i];
		r = rand() % n;
		a[i] = a[r];
		a[r] = temp;
	}
}
void bogosort(int* a, int n) {
	while (!is_sorted(a, n)) {
		shuffle(a, n);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}


int main() {
	int a[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = 0 + rand() % 100;
	}
	is_sorted(a, n);
	bogosort(a ,n);
}
*/
//неправильная работа(скорее всего типы данных в записи чисел и старая версия проги)
/*
int main() {
	string abcdefg;
	string s;
	string letters;
	getline(cin, s);
	int counterN = 0;
	int n = s.find('.');
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
		counterN++;
		letters += s[i];
	}
	int letterCounter = letters.size();
	int g = letterCounter;
	bool isPolindrome = true;
	bool possiblepolindrome = 0;
	int check = 1;
	int a[26];
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
		for (int j = 0; j < g; j++) {
			if (letters[j] == char(i + 65)) {
				a[i]++;
			}
		}
	}
	cout << "----" << endl;
	for (int i = 0; i < 26; i++) {
		cout << a[i] << "-" << char(i + 65) << "| " << endl;
	}
	int oddNumbers = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] % 2 != 0) {
			oddNumbers++;
		}
	}
	if (oddNumbers != 1 && oddNumbers > 0) {
		cout << "No" << endl;
		goto endfalse;
	}
	cout << "----" << endl;
	if (letterCounter % 2 == 1) {
		for (int i = 0; i < letterCounter; i++) {
			if (letters[i] == letters[g - 1] && ((letters[i] + letters[i + 1]) != 0)) {
				isPolindrome = true;
				g--;
			}
			else if (oddNumbers == 1)
			{
				possiblepolindrome = true;
			}
			else { isPolindrome = false; check = 0; }
		}
		if (isPolindrome == true && check == 1 && possiblepolindrome != 1) {
			abcdefg == letters;
			goto endtrue;
		}
		int hSaver = 0;
		cout << "----" << endl;
		if (possiblepolindrome == 1 && oddNumbers == 1)
		{
			for (int j = 0; j < 26; j++) {
				if (a[j] == 1 || a[j] % 2 == 1) {
					hSaver = j;
				}
			}
			for (int j = 0; j < 26; j++) {
				int secondJSaver = j;
				for (int i = a[j]; i > a[j] / 2; i--) {
					if (a[j] > 1 && abcdefg.size() < (letters.size() / 2) && a[j] != secondJSaver / 2)
					{
						abcdefg += char(j + 65);
						a[j]--;
					}
				}
			}
			abcdefg += char(hSaver + 65);
			a[hSaver]--;
			for (int i = 26; i >= 0; i--) {
				for (int j = a[i]; j > 0; j--) {
					if (a[i] > 0) {
						abcdefg += char(i) + 65;
						a[i]--;
					}
				}
			}
		}
	}
	else if (letterCounter % 2 == 0)
	{
		for (int i = 0; i < 26; i++) {
			int secondIsaver = a[i];
			for (int j = a[i]; j > secondIsaver / 2; j--) {
				if (abcdefg.size() < (letters.size() / 2)) {
					abcdefg += char(i) + 65;
					a[i]--;
				}
			}
		}
		for (int i = 26; i >= 0; i--) {
			for (int j = a[i]; j > 0; j--) {
				if (a[i] > 0) {
					abcdefg += char(i) + 65;
					a[i]--;
				}
			}
		}
		check = 1;
	}
endtrue:
	if (check == 0) { cout << "No"; }
	else { cout << "Yes" << endl << abcdefg << endl; }
endfalse:
	system("pause");
	return 0;
}
*/
/*
int main() {
	
	cout << "enter 2a+-2b-+2 type sample" << endl;
	string data;
	getline(cin, data);
	for (int i = 0; i < data.size(); i++) {
		char omg = data[i];
		if ((omg <= 122 && omg >= 97)||(omg==45)|| (omg == 43)||omg<=57&&omg>=48) {
		}
		else {
			cout << "incorrect cin(letters)" << endl;
			return main();
		}
	}
	int couter = 0;
	for (int i = 0; i < data.size(); i++) {
		char omg = data[i];
		if (omg == 45|| omg == 43) {
			couter++;
	    }
	}
	if (couter != 2) {
		cout << couter << endl;
		cout << "incorrect cin(sings or amout of them)";
		return main();
	}
	char letterSaver1=0;
	char letterSaver2=0;
	int ii=0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] >= 97 && data[i] <= 122&&letterSaver1==0) {
			letterSaver1 = data[i];
			
			cout << letterSaver1 << endl;
		}
	}
       for (int i = 0; i < data.size(); i++) {
		   if (data[i] >= 97 && data[i] <= 122 && data[i] != letterSaver1 && letterSaver2 == 0) {
			    letterSaver2 = data[i];
			    cout << letterSaver2 << endl;
				
		      }
	      }

	long long int a;
	long long int b;
	long long int c;
	string temp;
	temp = data.substr(0, data.find(letterSaver1));
	a = atoi(temp.c_str());
	data.erase(0, data.find(letterSaver1) + 1);
	temp = data.substr(0, data.find(letterSaver2));
	b = atoi(temp.c_str());
	data.erase(0, data.find(letterSaver2));
	data.erase(0,1);
	temp = data.substr(0);
	c = atoi(temp.c_str());
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	//d=b^2-4ac
	long double d;
	d =b * b - 4 * a * c;
	if (d < 0) {
		cout << "Incorrect discriminant";
		return main();
	}

	double firstX;
	firstX = (-b + sqrt(d)) / (2 * a);

	double secondX;
	secondX= (-b - sqrt(d)) / (2 * a);
	cout << "First X- " << firstX << "  ,Second X- " << secondX;
}
*/
/* подсчет первых букв слов и вывод их по возрастанию
struct letters
{
	int number;
	char letr;

};
void firstLetters(string data,int *a,int h) {
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < 25; i++) {
			char tempdata = data[0];
			if (tempdata == i + 97) {
				a[i]++;
			}	
		}
		data = data.erase(0, data.find(" ")+1);
	}
}

void gnomesort(int n, int a[])
{
	int i = 0;
	while (i < n) {
		if (i == 0 || a[i - 1] <= a[i]) { i++; }
		else { int tmp = a[i]; a[i] = a[i - 1]; a[--i] = tmp; }
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
int main() {
	string data;
	getline(cin, data);
	int x = data.size();
	while (data.find( "*")==-1) {
		string temp;
		getline(cin, temp);
		data += temp;
	}
	int a[25] = { 0 };
	int counterOfGaps = 1;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == 32) {
			counterOfGaps++;
		}
	}
	letters d[25];
	firstLetters(data, a, counterOfGaps);
	for (int i = 0; i < 25; i++) {
		d[i].letr = i + 97;
		d[i].number = a[i];
	}
	int i = 0;
	while (i<25) {
		if (i == 0 || d[i].number >= d[i - 1].number) { i++; }
		else { int temp = d[i].number; 
		int temp1 = d[i].letr; 
		d[i].number = d[i - 1].number;
		d[i].letr = d[i - 1].letr;
		d[i-1].number = temp; 
		d[--i].letr = temp1;
		}
	}
	for (int i = 0; i < 25; i++) {
		cout << char(d[i].letr)  << "  -  " << d[i].number << endl;
	}
}
*/

/*
int g = 0;
int counter = 0;
int razriadi(int n) {
	if (n / 10 >= 1) {
		counter++;
		return(razriadi(n / 10));
	}
		return(counter);
}
int delitel(int n, int counter) {
	if (n % 10 * pow(10, counter) != 0) {
		g += n % 10 * pow(10, counter);
	}
	if (counter-- != 0) {
		return(delitel(n / 10, counter));
	}
	else { return(g); }
}
int main() {
	int n;
	cin >> n;
	razriadi(n);
	delitel(n, counter);
	cout << g << endl;
	system("pause");
}
*/

/*int g = 0;
int counter = 0;
int delitel( int n) {
	if (n / 10 >0) {
		g = g+ ((n % 10) * (pow(10,counter)));
		cout << g <<" g      " << pow(10, counter) <<" pow10   "<<n<<" n"<< endl;
		counter++;
		return(delitel(n/10));
	}
	else {
		n = g;
		return(n);
	}
}
int main() {
	
	 int n;
	cin >> n;
	delitel(n);
	cout << delitel(n) << endl;
	system("pause");
}*/



/*
int main() {
	int x;
	cin >> x;
	int a[1000];
	for (int i = 0; i < x; i++) {
		a[i] = (0 + rand() % 1000) - 500;
		cout << a[i] << endl;
	}
	int test = a[0] + a[1];
	for (int i = 0; i < x; i++) {
		for (int j = 1; j < x; j++) {
			if (abs(i - j) > 7 && a[i] + a[j] > test) {
				test = a[i] + a[j];
			}
		}
	}
	cout << test << endl;
}
*/

/*
int main() {
	string data;
	getline(cin, data);
	data = data.substr(0, data.find("#"));
	string tempdata;
	string enddata = " ";
	int counter = 0;
		
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == char(32)) {
			counter++;
		}
	}
	counter++;
	for (int i = 0; i < counter; i++) {
		tempdata = data.substr(0, data.find(" "));
		data.erase(0, data.find(" ") + 1);
		for (int i = 0; i < tempdata.size(); i++) {
			if (tempdata[i] >= 65 && tempdata[i] <= 90 - tempdata.size()||tempdata[i]>=97&&tempdata[i]<=122-tempdata.size()) {
				tempdata[i] = tempdata[i] + tempdata.size();
				enddata += tempdata[i];
				
				
			}
			else if (tempdata[i] > 122 - tempdata.size()&& tempdata[i]<=122 &&tempdata[i]>=90) {
				tempdata[i] = 96-abs(122 - tempdata[i]) + tempdata.size();
				enddata += tempdata[i];
			}
			else if (tempdata[i] > 90 - tempdata.size()&&tempdata[i]<=90&&tempdata[i]>=65) {
				tempdata[i] += 64 - abs(90 - tempdata[i]) + tempdata.size();
			}
			else { enddata+=tempdata[i]; }
		}
		enddata += " ";
	}
	cout << "Crypted message:" << endl;
	cout << enddata << endl;	
}
*/
//struct trash
//{
//	int b;
//	int c;
//};
//int main() {
//	trash gg[100];
//	int x;
//	cin >> x;
//	string data;
//	int a[100];
//	for (int i = 0; i < 100; i++) {
//		gg[i].b = 0;
//		gg[i].c = 0;
//	}
//	cin.ignore(32767, '\n');
//	for (int i = 0; i <= x; i++) {
//		getline(cin, data);
//		gg[i].b = data.size();
//	}
//	cout << "-----------------" << endl;
//	for (int i = 0; i <= 100; i++) {
//		for (int j = 0; j <= x; j++) {
//			if (i == gg[j].b) {
//				gg[i].c++;
//				cout << gg[i].c << "   " <<i<<"   "<< gg[j].b <<"    "<<j<< endl;
//			}
//		}
//	}
//	cout << "-----------------" << endl;
//	
//	for (int i = 0; i <= x; i++) {
//		gg[i].b = i;
//	}
//	int lowestI=100000;
//	int lowest = 100000;
//	for (int i = 0; i <= x; i++) {
//		if (lowest > gg[i].c&&gg[i].c>=1&&gg[i].b!=0) {
//			lowest = gg[i].c;
//			lowestI = gg[i].b;
//		}
//	}
//	cout << lowestI << "-razriadi ,count- " << lowest << endl;
//	system("pause");
//}
struct baseData
{
	int money;
	int kurs;	
	string FIO;
};
int main() {
	baseData blanck[100];
	int x;
	cin >> x;
	cin.ignore(32767, '\n');
	for (int i = 0; i <= x; i++) {
		getline(cin, blanck[i].FIO);
	}
	string tempdata;
	for (int i = 0; i <=x; i++) {
		tempdata = blanck[i].FIO;
		tempdata = tempdata.erase(0, tempdata.find(" ")+1);
		tempdata = tempdata.erase(0, tempdata.find(" ") + 1);
		tempdata = tempdata.erase(0, tempdata.find(" ") + 1);
		string trash;
		trash = tempdata.substr(0, tempdata.find(" "));
		blanck[i].kurs = atoi(trash.c_str());
		tempdata = tempdata.erase(0, tempdata.find(" ") + 1);
		blanck[i].money= atoi(tempdata.c_str());
		tempdata = "";
		trash = "";
	}
	for (int i = 0; i <= 4; i++) {
		cout << "KURS-" << i+1 << endl;
		int maxMoney = 0;
		int studcounter = 0;
		bool check = 0;
		for (int j = 0; j <= x; j++) {
				for (int k = 0; k <= x; k++) {
					if (blanck[k].money > maxMoney&&blanck[k].kurs==i+1) {
						maxMoney = blanck[k].money;
					}
				}
				for (int k = 0; k <= x; k++) {
					if (blanck[k].money == maxMoney && check == 0) {
						cout << blanck[k].FIO << endl;
					}
				}
				check = 1;
			maxMoney = 0;
		}
	}
}
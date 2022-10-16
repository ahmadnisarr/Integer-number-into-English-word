#include<iostream>
#include<string>
using namespace std;
class Number_count
{
	int number;
	static string lessThan20[20];
	static string lessThan100[20];
	static string hund;
	static string thous;
public:
	Number_count(int x)
	{
		number = x;
	}
	void print();
	
};
string Number_count::lessThan20[20] = { "zero", "one","two","three","four","five","six","seven","eight","nine","ten"
							  ,"eleven","tweleve","thirteen","fourteen","fiveteen","sixteen","seventeen","eighteen","nineteen" };
string Number_count::lessThan100[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string Number_count::hund = "hundred";
string Number_count::thous = "thousand";
void Number_count :: print()
{
	if (number < 20)
	{
		cout << "This number in description form: " << lessThan20[number] << endl;
	}
  else if (number >= 20 && number < 100) // Condition for numbers that are greater than 20 but less than 100
  {
	int tenth[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	bool found;
	int index = 0;
	int high, low;

	do // Finds the tens value
	{
		found = false;

		if (number >= tenth[index])
		{
			high = tenth[index];
			found = true;
			index++;
		}
	} while (found);

	low = number - high;

	cout << "The number is: " << lessThan100[index - 1] << " " << (low > 0 ? lessThan20[low] : "") << endl;
}
   else if (number >= 100 && number < 1000)
   { 
	int hundreth[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
	int tenth[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	bool found;
	int index, index2;
	index = index2 = 0;
	int high, mid, low;

	do // Finds the hundreds value
	{
		found = false;

		if (number >= hundreth[index])
		{
			high = hundreth[index];
			found = true;
			index++;
		}
	} while (found);

	mid = number - high;

	if (mid != 0)
	{
		do // Finds the tens value
		{
			found = false;

			if (mid >= tenth[index2])
			{
				low = tenth[index2];
				found = true;
				index2++;
			}
		} while (found);

		low = number - high - low; // Finds the single digit value
	}

	cout << "The number is: " << lessThan20[index] << " " << hund << " " << (mid > 0 ? lessThan100[index2 - 1] : "") << " " << (low > 0 ? lessThan20[low] : "") << endl;
}
else if (number >= 1000 && number <= 9999) // Condition for numbers that are greater than 1000 but less than 9999
{
	int thousandths[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };
	int hundreth[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };
	int tenth[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	bool found;
	int index, index2, index3;
	index = index2 = index3 = 0;
	int high, mid, low, last;

	do // Finds the thousands value
	{
		found = false;

		if (number >= thousandths[index])
		{
			high = thousandths[index];
			found = true;
			index++;
		}
	} while (found);

	mid = number - high;

	if (mid != 0)
	{
		do // Finds the hundreds value
		{
			found = false;

			if (mid >= hundreth[index2])
			{
				low = hundreth[index2];
				found = true;
				index2++;
			}


		} while (found);

		mid = low;
		low = number - (high + low);

		if (low != 0)
		{
			do // Finds the tens value
			{
				found = false;

				if (low >= tenth[index3])
				{
					last = tenth[index3];
					found = true;
					index3++;
				}


			} while (found);
			last = number - (high + mid + last); // Finds the single digit value
		}
	}

	cout << "The number is: " << lessThan20[index] << " " << thous << " " << (mid > 0 ? lessThan20[index2] : "") << " " << (mid > 0 ? hund : "") << " " << (low > 0 ? lessThan100[index3 - 1] : "") << " " << (last > 0 ? lessThan20[last] : "") << endl;
}
}


int main()
{
	int x;
	cout << "Enter a number= "; cin >> x;
	Number_count obj(x);
	obj.print();

}
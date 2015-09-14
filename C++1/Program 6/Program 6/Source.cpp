#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TestGrader
{public:
	int count1 = 0;
	int count2 = 0;
	string answer[20];
	string inc[20];
	int num;

	void setKey(string a[])
	{
		for (int index = 0; index < 20; index++)
		{
			answer[index] = a[index];
		}
	}

	void grade(string b[])
	{
		int num = 0;
		for (int index = 0; index < 20; index++)
		{
			if (answer[index] == b[index])
			{
				count1++;
			}
			else
			{
				count2++;
				inc[num] = count1 + count2;
				num++;
			}
		}
		if (count1 >= 15)
			cout << "Pass\n\n\n";
		else
			cout << "Failed\n\n\n";
		cout << "Correct:   " << count1 << endl;
		cout << "Incorrect: " << count2 << endl;
		cout << "Incorrect questions are: ";
		for (int c = 0; c < count2; c++)
			cout << inc[c];
	}
};

int main()
{
	bool again;

	do
	{
		again = false;
		string takeranswer[20];
		string Key[20] = { "B", "D", "A", "A", "C", "A", "B", "A", "C", "D", "B", "C", "D", "A", "D", "C", "C", "B", "D", "A" };
		TestGrader grader;

		grader.setKey(Key);

		cout << "Please enter your answer (Only accept the letters A, B, C, and D for test answers) \n";
		for (int a = 0; a < 20; a++)
		{
			cout << "Question " << a + 1 << " : ";
			cin >> takeranswer[a];
			if (takeranswer[a] != "A" || "B" || "C" || "D")
			{
				cout << "Invaild Answer, please enter again";
				cout << "Question " << a + 1 << " : " << takeranswer[a] << endl;
			}
		}

		grader.grade[takeranswer];

		string a;
		cout << "\n\n\n";
		cout << "Test again?(y/n)";
		cin >> a;
		if (a == "y" || "Y")
			again = true;

	} while (again);
	return 0;
}
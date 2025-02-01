#pragma once
#include <iostream>
#include<string>
using namespace std;
namespace MyLibrary {
	namespace TeypeOfNumbers {
		enum enPrimeNotPrime
		{
			Prime = 1,
			NotPrime = 2

		};
		enPrimeNotPrime ChackNumberPrime(int Number) {
			int M = round(Number / 2);
			for (int i = 2; i <= M; i++)
			{
				if (Number % i == 0) {
					return enPrimeNotPrime::NotPrime;
				}

			}
			return enPrimeNotPrime::Prime;
		}
		enum enNumberType { Odd = 1, Even = 2 };
		enNumberType CheckNumberType(int Number) {
			int result = Number % 2;
			if (result == 0) {
				return enNumberType::Even;

			}
			else
			{
				return enNumberType::Odd;
			}

		}
		enum enNumberPositiveAndNegitive { Positive = 1, Negitive = 2 };
		enNumberPositiveAndNegitive CheckNumber(int number) {
			int result = number >= 0;
			if (result >= 0) {
				return enNumberPositiveAndNegitive::Positive;
			}
			else
			{
				return enNumberPositiveAndNegitive::Negitive;
			}
		}
		int ReverseNumber(int num) {
			int reminder = 0, reverse = 0;

			while (num > 0)
			{
				reminder = num % 10;
				num /= 10;
				reverse = reverse * 10 + reminder;
			}
			return reverse;
		}
		bool IsPrefectNunber(int num) {

			int sum = 0;
			for (int i = 1; i < num; i++)
			{
				if (num % i == 0) {
					sum += i;
				}
			}
			return num == sum;
		}
		bool IsPalindromNumber(int num) {
			return num == ReverseNumber(num);
		}

	}
	namespace Reader {
		string ReadPinCode() {
			string PinCode;
			cout << "Please Enter Pin Code ? \n";
			cin >> PinCode;
			return PinCode;
		}
		int ReadPositiveNumber(string Massage) {
			int num = 0;
			do
			{
				cout << Massage;
				cin >> num;

			} while (num <= 0);
			return num;
		}
		float ReadNumber() {
			float Number;
			cout << "\nPlease enter a number ? \n";
			cin >> Number;
			return Number;
		}
		string ReadPassword(string Massage) {
			string Password;

			cout << Massage;
			cin >> Password;
			return Password;
		}
		string ReadText(string massage) {
			string text;
			cout << massage;
			getline(cin, text);
			return text;
		}
	}
	namespace Arrays {
		void RandomArray(int arr[100], int& arrLength) {

			for (int i = 0; i < arrLength; i++)
			{
				//arr[i] = RandomNumber(1, 100);


			}
			cout << endl;
		}
		bool IsPalindromNumberArray(int arr[100], int& arrLength) {
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] != arr[arrLength - i - 1])
					return false;
			}
			return true;
		}
		void ReadArray(int arr[100], int& arrLength) {
			cout << "How Many Rounds 1 to 10   :\n";
			cin >> arrLength;
			for (int i = 0; i < arrLength; i++)
			{
				cout << "Round [" << i + 1 << "]  begins : ";
				cin >> arr[i];


			}
			cout << endl;
		}
		void PrintArray(int arr[100], int arrLength) {
			for (int i = 0; i < arrLength; i++)
			{
				cout << arr[i] << " ";

			}
			cout << endl;
		}
		short FoundNumberArray(int number, int arr[100], int arrLength) {
			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] == number)
					return i;
			}
			return -1;
		}
		void AddArrayEleumnt(int num, int arr[100], int& arrLength) {

			arrLength++;
			arr[arrLength - 1] = num;
		}
		bool IsFoundNumberArray(int number, int arr[100], int arrLength) {

			return FoundNumberArray(number, arr, arrLength) != -1;
		}
		void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arrDestination[i] = arrSource[i];
		}
		void CopyReversArray(int arrSource[100], int arrDestination[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
				arrDestination[i] = arrSource[arrLength - 1 - i];
		}
		void ShuffleArray(int arr[100], int arrLength) {
			for (int i = 0; i < arrLength; i++)
			{
				//Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
			}
		}
		void CopyDistinctNumberToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength) {
			for (int i = 0; i < arrLength; i++)
			{
				if (!MyLibrary::Arrays::IsFoundNumberArray(arrSource[i], arrDestination, arrDestinationLength)) {
					AddArrayEleumnt(arrSource[i], arrDestination, arrDestinationLength);
				}
			}
		}
		
		int NumberCountToArray(int arr[100], int arrLength) {
			int count = 0;
			for (int i = 0; i < arrLength; i++)
			{
				if (MyLibrary::TeypeOfNumbers::CheckNumber(arr[i]) == MyLibrary::TeypeOfNumbers::enNumberPositiveAndNegitive::Negitive) {
					count++;
				}
			}
			return count;
		}
	}
	namespace Functons {
		void Swap(int& A, int& B) {
			int temp;
			temp = A;
			A = B;
			B = temp;
		}
		string EncryptText(string Text, short EncryptionKey) {
			for (int i = 0; i <= Text.length(); i++)
			{
				Text[i] = char((int)Text[i] + EncryptionKey);
			}
			return Text;
		}
		string DecryptText(string Text, short EncryptionKey) {
			for (int i = 0; i <= Text.length(); i++)
			{
				Text[i] = char((int)Text[i] - EncryptionKey);
			}
			return Text;
		}

	}
	namespace ValidatRung {
		bool ValidateInRung(int n, int From, int To) {
			return (n >= From && n <= To);
		}
		int ReadNumberRange(string Massage, int From, int To) {
			int Number = 0;
			do
			{
				cout << Massage << endl;
				cin >> Number;

			} while (Number < From || Number > To);
			return Number;
		}
		bool Login() {
			string PinCode;
			int count = 3;
			do
			{
				count--;
				PinCode = 'read'; //ReadPinCode();
				if (PinCode == "1234") {
					return 1;
				}
				else if (count == 0)
				{
					cout << "Wrong PIN 'You Have " << count << " More Tries ." << endl << "\n";
					system("color 0F");
				}
				else
				{
					cout << "Wrong PIN 'You Have " << count << " More Tries ." << endl << "\n";
					system("color 4F");
				}

			} while (count >= 1 && PinCode != "1234");
			return 0;
		}
	}
	namespace GenerateKeysRandom {
		enum enRandom
		{
			CapitalLetter = 1,
			SmallLetter = 2,
			SpecialCharacter = 3,
			Digit = 4

		};
		int RandomNumber(int From, int To) {
			int random = rand() % (To - From + 1) + From;
			return random;
		}
		void RandomArray(int arr[100], int& arrLength) {

			for (int i = 0; i < arrLength; i++)
			{
				arr[i] = RandomNumber(-100, 100);


			}
			cout << endl;
		}
		char GetRandNumCharacter(enRandom Type) {
			switch (Type)
			{
			case enRandom::CapitalLetter:
				return char(RandomNumber(65, 90));
				break;
			case enRandom::SmallLetter:
				return char(RandomNumber(97, 122));
				break;
			case enRandom::SpecialCharacter:
				return char(RandomNumber(33, 47));
				break;
			case enRandom::Digit:
				return char(RandomNumber(48, 57));
				break;

			}


		}
		string GenerateWord(enRandom rand, short Lenght) {
			string word = "";
			for (int i = 1; i <= Lenght; i++)
			{
				word += GetRandNumCharacter(rand);
			}
			return word;
		}string GenerateKey() {
			string key = "";
			key = GenerateWord(enRandom::CapitalLetter, 4) + "-";
			key += GenerateWord(enRandom::CapitalLetter, 4) + "-";
			key += GenerateWord(enRandom::CapitalLetter, 4) + "-";
			key += GenerateWord(enRandom::CapitalLetter, 4) + "-";
			key += GenerateWord(enRandom::CapitalLetter, 4);
			return key;

		}
		void GenerateKeys(short number) {
			for (int i = 1; i <= number; i++)
			{
				cout << "Key [" << i << "] : ";
				cout << GenerateKey() << endl;

			}

		}
	}
	namespace Add {
		void AddArrayEleumnt(int num, int arr[100], int& arrLength) {

			arrLength++;
			arr[arrLength - 1] = num;
		}
		void InputNumberInArray(int arr[100], int& arrLength) {
			bool addMore = true;
			do
			{
				AddArrayEleumnt(MyLibrary::Reader::ReadNumber(), arr, arrLength);
				cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
				cin >> addMore;

			} while (addMore);
		}
	}
}

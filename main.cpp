#include <iostream>
#include <string>
using namespace std;

//1) Видалення гри за назвою
 
//2) Пошук гри за Назвою, Автором, Валюта

//3) Редагування всіх полів

//4) Сортування за заденим параметром (може бути не одне поле)

struct GameTime
{
	int hours;
	int minutes;
	int seconds;
};

struct Price
{
	int value_1; //ex: dollars
	int value_2; //ex: cents
	string currency_symbol_v1; //ex: $
	string currency_symbol_v2; //ex: c.
	Price()
	{
		value_1 = 0;
		value_2 = 0;
	}
	Price(int v1, int v2)
	{
		value_1 = v1;
		value_2 = v2;
	}
};

enum Platform
{
	Windows,
	MacOS,
	Linux
};

class Game
{
private:
	string _name;
	string _genre;
	Platform _platform;
	GameTime _timePlayed;
	string _author;
	Price _price;
public:
	Game()
	{
		_name = "";
		_genre = "";
		_platform = Windows;
		_timePlayed.hours = 0;
		_timePlayed.minutes = 0;
		_timePlayed.seconds = 0;
		_author = "";
		_price.value_1 = 0;
		_price.value_2 = 0;
		_price.currency_symbol_v1 = "";
		_price.currency_symbol_v2 = "";
	}
	Game(string name, string genre, Platform platform, GameTime timePlayed, string author, Price price)
	{
		_name = name;
		_genre = genre;
		_platform = platform;
		_timePlayed = timePlayed;
		_author = author;
		_price = price;
	}
	string GetName()
	{
		return _name;
	}
	string GetGenre()
	{
		return _genre;
	}
	Platform GetPlatform()
	{
		return _platform;
	}
	GameTime GetTimePlayed()
	{
		return _timePlayed;
	}
	string GetAuthor()
	{
		return _author;
	}
	Price GetPrice()
	{
		return _price;
	}
	void SetName(string name)
	{
		_name = name;
	}
	void SetGenre(string genre)
	{
		_genre = genre;
	}
	void SetPlatform(Platform platform)
	{
		_platform = platform;
	}
	void SetTimePlayed(GameTime timePlayed)
	{
		_timePlayed = timePlayed;
	}
	void SetAuthor(string author)
	{
		_author = author;
	}
	void SetPrice(Price price)
	{
		_price = price;
	}
	void PrintInfo()
	{
		cout << "Name: " << _name << endl;
		cout << "Genre: " << _genre << endl;
		cout << "Platform: ";
		switch (_platform)
		{
		case Windows:
			cout << "Windows" << endl;
			break;
		case MacOS:
			cout << "MacOS" << endl;
			break;
		case Linux:
			cout << "Linux" << endl;
			break;
		}
		cout << "Time Played: " << _timePlayed.hours << "h " << _timePlayed.minutes << "m " << _timePlayed.seconds << "s" << endl;
		cout << "Author: " << _author << endl;
		cout << "Price: " << _price.currency_symbol_v1 << _price.value_1 << "." << _price.value_2 << _price.currency_symbol_v2 << endl;
	}
	void EditGame()
	{
		int number;
		cout << "Select edit field: " << endl;
		cout << "1 - Name " << endl;
		cout << "2 - Genre " << endl;
		cout << "3 - Platform " << endl;
		cout << "4 - Time Played " << endl;
		cout << "5 - Author " << endl;
		cout << "6 - Price " << endl;
		cout << "Your choice: ";
		cin >> number;
		if (number == 1)
		{
			string newname;
			cin >> newname;
			SetName(newname);
		}
		else if (number == 2)
		{
			string newgenre;
			cin >> newgenre;
			SetGenre(newgenre);
		}
		else if (number == 3)
		{
			int newplatform;
			cout << "0 windows, 1 macOS, 2 linux : ";
			cin >> newplatform;
			SetPlatform(static_cast<Platform>(newplatform));
		}
		else if (number == 4)
		{
			GameTime newTImePlayed;
			cout << "hours, minutes, seconds" << endl;
			cin >> newTImePlayed.hours >> newTImePlayed.minutes >> newTImePlayed.seconds;
			SetTimePlayed(newTImePlayed);
		}
		else if (number == 5)
		{
			string newauthor;
			cin >> newauthor;
			SetAuthor(newauthor);
		}
		else if (number == 6)
		{
			Price newprice;
			cout << "dollars, cents";
			cin >> newprice.value_1 >> newprice.value_2;
			SetPrice(newprice);
		}
	}
};
class Steam
{
private:
	Game* _games;
	int _gamesCount;
public:
	Steam()
	{
		_games = nullptr;
		_gamesCount = 0;
	}
	Steam(Game* games, int gamesCount)
	{
		_games = games;
		_gamesCount = gamesCount;
	}
	Game& getGame(int number)
	{
		if (number >= 0 && number < _gamesCount)
		{
			return _games[number];
		}
	}
	void AddGame(Game game)
	{
		Game* newGames = new Game[_gamesCount + 1];
		for (int i = 0; i < _gamesCount; i++)
		{
			newGames[i] = _games[i];
		}
		newGames[_gamesCount] = game;
		_gamesCount++;
		delete[] _games;
		_games = newGames;
	}
	void RemoveGame(int index)
	{
		Game* newGames = new Game[_gamesCount - 1];
		for (int i = 0; i < index; i++)
		{
			newGames[i] = _games[i];
		}
		for (int i = index + 1; i < _gamesCount; i++)
		{
			newGames[i - 1] = _games[i];
		}
		_gamesCount--;
		delete[] _games;
		_games = newGames;
	}
	void RemoveGameByName(string name)
	{
		for (int i = 0; i < _gamesCount; i++)
		{
			if (_games[i].GetName() == name)
			{
				RemoveGame(i);
				break;
			}
		}
	}
	void PrintGames()
	{
		for (int i = 0; i < _gamesCount; i++)
		{
			cout << "Game " << i + 1 << ":" << endl;
			_games[i].PrintInfo();
			cout << endl;
		}
	}
	void SearchGame(string game_name)
	{
		for (int i = 0; i < _gamesCount; i++)
		{
			if (_games[i].GetName() == game_name)
			{
				cout << "<------------------------------------>" << endl;
				_games[i].PrintInfo();
				break;
			}
		}
	}
	void DeleteGame(string game_name)
	{
		for (int i = 0; i < _gamesCount; i++)
		{
			if (_games[i].GetName() == game_name)
			{
				RemoveGame(i);
				break;
			}
		}
	}
	int getgamesCount()
	{
		return _gamesCount;
	}
};
int main() {
	int number;
	Steam steam;
	Game game1("Game1", "Genre1", Windows, { 1, 2, 3 }, "Author1", { 10, 50 });
	Game game2("Game2", "Genre2", MacOS, { 4, 5, 6 }, "Author2", { 20, 60 });
	Game game3("Game3", "Genre3", Linux, { 7, 8, 9 }, "Author3", { 30, 70 });
	steam.AddGame(game1);
	steam.AddGame(game2);
	steam.AddGame(game3);
	do
	{
		cout << ">---------------------------------< Menu >---------------------------------<" << endl;
		cout << "1. Show all games" << endl;
		cout << "2. Search game" << endl;
		cout << "3. Delete game" << endl;
		cout << "4. Edit game" << endl;
		cout << "5. Add game" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> number;
		if (number == 1)
		{
			steam.PrintGames();
		}
		else if (number == 2)
		{
			string name;
			cout << "Enter game name : ";
			cin >> name;
			steam.SearchGame(name);
		}
		else if (number == 3)
		{
			string name;
			cout << "Enter game name : ";
			cin >> name;
			steam.DeleteGame(name);
		}
		else if (number == 4)
		{
			string name;
			cout << "Enter game name : ";
			cin >> name;
			for (int i = 0; i < steam.getgamesCount(); i++)
			{
				if (steam.getGame(i).GetName() == name)
				{
					steam.getGame(i).EditGame();
				}
			}
		}
		else if (number == 5)
		{
			string name, genre, author;
			int platform, hours, minutes, seconds, price_dollars, price_cents;
			cout << "Game name : ";
			cin >> name;
			cout << "Game genre : ";
			cin >> genre;
			cout << "Game author : ";
			cin >> author;
			cout << "Platform (windows - 0, MacOS - 1, linux - 2) : ";
			cin >> platform;
			cout << "Time played : ";
			cin >> hours >> minutes >> seconds;
			cout << "Enter price (dollar, cents) : ";
			cin >> price_dollars >> price_cents;
			Game newGame(name, genre, static_cast<Platform>(platform), { hours, minutes, seconds }, author, { price_dollars, price_cents });
			steam.AddGame(newGame);
		}
		else if (number == 6)
		{
			break;
			return 0;
		}
		else
		{
			cout << "Error" << endl;
			break;
		}

	} while (true);
	return 0;
}
// DL2_L4_Teredesai.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <cmath>

using namespace std;

double calculateDistanceToHome(int latitude, int longitude) {

	// distance = square root of ((latitude ^ 2) + (longitude ^ 2))
	double distance = pow(pow(latitude, 2.0) + pow(longitude, 2.0), 0.5);
	// cout << "lat =" << latitude << " long = " << longitude << " distance = " << distance << endl;
	return distance;
}

string latitudeDirection(int latitude) {
	return latitude < 0 ? "S" : "N";
}

string longitudeDirection(int longitude) {
	return longitude < 0 ? "W" : "E";
}

int main()
{
	int longitude = 0;
	int latitude = 0;
	int totalDistTraveled = 0;
	int stepSize = 10;

	enum class Direction_t { North = 'n', South = 's', East = 'e', West = 'w', Home = 'h', Distance = 'd', Quit = 'q' };

	string welcome = "Starting home at 0 North/South and 0 East/West, this program shows your position\n"
		"after traveling stepSize miles: north, south, east or west, how far you are from home,\n"
		"and how far you traveled in total.You can jump home or quit.\n";
	cout << welcome;

	while (true) {
		//If the longitude is positive, show N for North; if negative, show S for South. 
		//If the latitude is positive, show E for East; if negative, show W for West.
		// It is always lat, long (x,y)
		// Since I am displaying direction using NSEW, I am using absolute values i.e. "-10 S" becomes 10 S
		cout << "Location: latitude: " << abs(latitude) << " " << latitudeDirection(latitude) << " longitude: " << abs(longitude) << " " << longitudeDirection(longitude)
			<< " distance from home: " << calculateDistanceToHome(latitude, longitude) << " total distance traveled: " << totalDistTraveled << endl;

		cout << "\nChoose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.";
		Direction_t option;
		char userInput;
		cin >> userInput;
		option = static_cast<Direction_t>(tolower(userInput));
		switch (option) {
		case Direction_t::North:
			latitude += stepSize;
			totalDistTraveled += stepSize;
			break;

		case Direction_t::South:
			latitude -= stepSize;
			totalDistTraveled += stepSize;
			break;

		case Direction_t::East:
			longitude += stepSize;
			totalDistTraveled += stepSize;
			break;

		case Direction_t::West:
			longitude -= stepSize;
			totalDistTraveled += stepSize;
			break;
		case Direction_t::Home:
			cout << "You magically went home" << endl;
			longitude = 0;
			latitude = 0;
			totalDistTraveled = 0;
			break;
		case Direction_t::Distance:
			cout << "Enter a positive integer to choose your step size" << endl;
			cin >> stepSize;
			stepSize = abs(stepSize);
			cout << "New Step Size is: " << stepSize << endl;
			break;
		case Direction_t::Quit:
			cout << "Goodbye, Happy Wanderer." << endl;
			return 0;
		default:
			cout << "Invalid Input\n";
			break;
		}

	}

}

/*
Starting home at 0 North/South and 0 East/West, this program shows your position
after traveling stepSize miles: north, south, east or west, how far you are from home,
and how far you traveled in total.You can jump home or quit.
Location: latitude: 0 N longitude: 0 E distance from home: 0 total distance traveled: 0

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.n
Location: latitude: 10 N longitude: 0 E distance from home: 10 total distance traveled: 10

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.n
Location: latitude: 20 N longitude: 0 E distance from home: 20 total distance traveled: 20

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.e
Location: latitude: 20 N longitude: 10 E distance from home: 22.3607 total distance traveled: 30

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.e
Location: latitude: 20 N longitude: 20 E distance from home: 28.2843 total distance traveled: 40

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.h
You magically went home
Location: latitude: 0 N longitude: 0 E distance from home: 0 total distance traveled: 0

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.d
Enter a positive integer to choose your step size
20
New Step Size is: 20
Location: latitude: 0 N longitude: 0 E distance from home: 0 total distance traveled: 0

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.s
Location: latitude: 20 S longitude: 0 E distance from home: 20 total distance traveled: 20

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.s
Location: latitude: 40 S longitude: 0 E distance from home: 40 total distance traveled: 40

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.w
Location: latitude: 40 S longitude: 20 W distance from home: 44.7214 total distance traveled: 60

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.e
Location: latitude: 40 S longitude: 0 E distance from home: 40 total distance traveled: 80

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.e
Location: latitude: 40 S longitude: 20 E distance from home: 44.7214 total distance traveled: 100

Choose direction to travel (or quit) n)orth, s)outh, e)ast, w)est, h)ome, d)istance, or q)uit.q
Goodbye, Happy Wanderer.

C:\Users\rohan\Desktop\CPP\DL2_L4_Teredesai\out\build\x64-Debug\DL2_L4_Teredesai\DL2_L4_Teredesai.exe (process 28708) ex
ited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the conso
le when debugging stops.
Press any key to close this window . . .

*/

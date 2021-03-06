#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "time.h"
#include "Flight.h"
#include "Date.h"

using namespace std;

class Graph {
	
	struct City {
		string name;
		vector<Flight> flightList;
		bool visited;
		int distance; 											//used to tell distance from parent node in breadth first search 
	};

	public:
		Graph ();												//constructor
		~Graph ();												//destructor
		void add_flight (string cityInfo[], int size);			//add flight info to graph. check if city already exists
		void add_city (string cityName);						//add city to city struct
		int city_pos (string cityName);							//get index of cityName in cityList

		vector<Flight> breadthFirst(const string &departCity, const string &retCity, Time &departTime);
		//used to compute the shortest travel time.
		void shortest_travel_time(string, string, string);

		vector< vector<Flight> > j_flightPaths;
		void set_all_visited(string city);						//once a certain city name has been seen, all cities with that name are marked as visited. Used in breadth first search
		void reset_all_visited();								//set all flights in a city to not visited
		void reset_breadth_first();								//resets all City values changed from breadth first search

		/*=checks if user input matches info in graph. returns true or false=*/
		bool set_depart_city(string user_choice);
		bool set_destination(string user_choice);
		bool set_depart_date(string user_choice);
		bool set_depart_time(string user_choice);
		bool set_return_date(string user_choice);
		bool set_return_time(string user_choice);
		/*======================================*/

		void print_results(vector<Flight> breadth_results);		//prints results for Fewest Hops itinerary
		void print_flight_sched();								//displays entire Daily Flight schedule
		void j_itin();											//Just Get Me There
		void f_itin();											//Fewest Hops
		void c_itin();											//Cheapest
		void s_itin();											//Shortest Trip
		void j_recursive(int start, int current, int destination, Time currentTime, vector <Flight> path, Flight currentFlight);
	private:

		/*====values from file=====*/		
		string departure_city;
		string destination_city; 
		float cost; 
		//time objects created in function calls
		/*=========================*/

		/*====user given values====*/
		string user_depart_city;
		string user_destination_city;
		Date user_return_date;
		Date user_depart_date;
		Time user_depart_time;
		Time user_return_time;
		//time objects created in function calls
		/*=========================*/

		TimeLength roundTripTime;
		float roundTripCost;
		int roundTripHops;
		
		vector<City> cityList;
};

#endif

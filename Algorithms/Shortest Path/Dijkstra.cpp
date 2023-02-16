// დასასრულებელი
#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;

// აბრუნებს ყველა უნიკალურ ვერტექსს გრაფიდან
set<char> GetAllVertex(map<char, map<char, int>> graph) {
	set<char> keys;
	for (const auto& item : graph) {
		keys.insert(item.first);
	}
	return keys;
}

// ცხრილი სვეტებით (ვერტექსი, უმოკლესი მანძილი src-დან, წინა ვერტექსი)
map<char, map<int, char>> BuildTable(set<char> vertexs, char src) {
	map<char, map<int, char>> table;
	for (auto v : vertexs) {
		table[v] = map<int, char>{
			{numeric_limits<int>::max(), ' '}
		};
	}
	table[src] = map<int, char>{
		{0, ' '}
	};
	return table;
}

// ცხრილის დაბეჭდვა შესაბამისი სვეტებით
void PrintTable(map<char, map<int, char>> table) {
	cout << setw(10) << left << "Vertex";
	cout << setw(20) << left << "Shortest Path";
	cout << setw(15) << left << "Last Vertex" << endl;

	for (const auto& outer_pair : table) {
		cout << setw(10) << left << outer_pair.first;
		for (const auto& inner_pair : outer_pair.second) {
			cout << setw(20) << left << inner_pair.first;
			cout << setw(15) << left << inner_pair.second;
		}
		cout << endl;
	}
	cout << endl << endl << endl;

}


// უმოკლესი მანძილის პოვნა src-დან ყველა ვერტექსამდე
void Dijkstra(map<char, map<char, int>> graph, char src) {
	set<char> unvisited = GetAllVertex(graph);
	set<char> visited;

	map<char, map<int, char>> table = BuildTable(unvisited, src);
	PrintTable(table);

	// სანამ ყველა ვერტექს არ მოივლის
	while (!unvisited.empty()) {
		char currVertex = '\0';;

		// უახლოესი მეზობელი გახდება currVertex
		int min_value = std::numeric_limits<int>::max();
		for (const auto& p1 : graph[src]) {
				if (p1.second < min_value) {
					currVertex = p1.first;
					min_value = p1.second;
			}
		}
		cout << "Kvelaze Patara Dzma: " << currVertex << endl;
		break;
	}
}

int main() {
	// ნოდების კავშირი
	map<char, map<char, int>> graph = {
		{'A', {{'B', 6}, {'D', 1}} },
		{'B', {{'A', 6}, {'D', 2}, {'E', 2}, {'C', 5}} },
		{'C', {{'B', 5}, {'E', 5}} },
		{'D', {{'A', 1}, {'B', 2}, {'E', 1}} },
		{'E', {{'D', 1}, {'B', 2}, {'C',5}} }
	};

	Dijkstra(graph, 'B');
}

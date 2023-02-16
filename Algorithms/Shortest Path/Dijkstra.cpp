#include <iostream>
#include <map>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;

// აბრუნებს ყველა უნიკალურ ვერტექსს გრაფიდან
set<char> GetAllVertex(map<char, map<char, int>>& graph) {
	set<char> keys;
	for (const auto& item : graph) {
		keys.insert(item.first);
	}
	return keys;
}

// ავაგოთ ცარიელი ცხრილი სვეტებით (ვერტექსი, უმოკლესი მანძილი src-დან, წინა ვერტექსი)
map<char, map<int, char>> BuildTable(set<char>& vertexs, char src) {
	map<char, map<int, char>> table;
	for (auto& v : vertexs) {
		table[v] = map<int, char>{
			{numeric_limits<int>::max(), ' '}
		};
	}
	// თავის თავთან მანძილი = 0
	table[src] = map<int, char>{
		{0, ' '}
	};
	return table;
}

// ცხრილის დაბეჭდვა შესაბამისი სვეტებით
void PrintTable(map<char, map<int, char>>& table) {
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
	set<char> visited = {};

	map<char, map<int, char>> table = BuildTable(unvisited, src);
	PrintTable(table);

	// სანამ ყველა ვერტექს არ მოივლის
	while (!unvisited.empty()) {
		char currVertex = '\0';;

		// უახლოესი მეზობელი გახდება currVertex
		int minDist = std::numeric_limits<int>::max();
		
		for (const auto& p : table) {
			// ვერტექსს უკვე თუ არ ვესტუმრეთ
			if (unvisited.find(p.first) != unvisited.end() && p.second.begin()->first < minDist) {
				currVertex = p.first;
				minDist = p.second.begin()->first;
			}
		}
		//cout << "Kvelaze Patara Dzma: " << currVertex << endl;

		// თუ არ არის მისაწვდომი ვერტექსი შევწყვიტოთ ლუპი
		if (currVertex == '\0') break;

		// განვაახლოთ თეიბლი currVertex ისთვის
		for (const auto& neighbor : graph[currVertex]) {
			if (unvisited.find(neighbor.first) != unvisited.end()) {
				int newDist = minDist + neighbor.second;
				if (newDist < table[neighbor.first].begin()->first) {
					table[neighbor.first].clear();
					table[neighbor.first][newDist] = currVertex;
				}
			}
		}

		// currVertex დავამატოტ მონახულ ვერტექსში და ამოვშალოთ არ ნახულებიდან.
		visited.insert(currVertex);
		unvisited.erase(currVertex);

		// დავბეჭდოთ თეიბლი ყველა ნაბიჯზე
		PrintTable(table);
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

	Dijkstra(graph, 'A');
}

#include <vector>
#include <iostream>

struct Node {
	std::vector<Node*> neighbours;
	uint64_t squawks;
	uint64_t squawksReceived;
};

int main() {
	int users, links, startNode, time, x, y;
	uint64_t totalSquawks = 0;
	std::cin >> users >> links >> startNode >> time;

	std::vector<Node*> network;

	for (int i = 0; i < users; i++) {
		Node* n = new Node;
		n->squawks = 0;
		n->squawksReceived = 0;
		network.push_back(n);
	}

	for (int i = 0; i < links; i++) {
		std::cin >> x >> y;
		network[x]->neighbours.push_back(network[y]);
		network[y]->neighbours.push_back(network[x]);
	}

	network[startNode]->squawks = 1;

	for (int i = 0; i < time; i++) {
		totalSquawks = 0;
		for (int n = 0; n < network.size(); n++) {
			if(network[n]->squawks != 0)
				for (int m = 0; m < network[n]->neighbours.size(); m++) {
					network[n]->neighbours[m]->squawksReceived += network[n]->squawks;
					totalSquawks += network[n]->squawks;
				}
		}

		for (int n = 0; n < network.size(); n++) {
			network[n]->squawks = network[n]->squawksReceived;
			network[n]->squawksReceived = 0;
		}
	}

	std::cout << totalSquawks << std::endl;
}
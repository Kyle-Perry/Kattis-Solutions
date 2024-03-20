#include <iostream>
#include <utility>
#include <map>
#include <queue>

std::map<uint32_t, std::priority_queue<uint64_t>> quests = {};

uint64_t begin(uint32_t energy) {
    uint64_t gold = 0;
    uint32_t remain = energy;

    while (remain > 0 && !quests.empty() && quests.begin()->first <= remain)
    {
        auto it = quests.upper_bound(remain);
        it--;

        remain -= it->first;
        gold += it->second.top();
        it->second.pop();
        if (it->second.empty())
        {
            quests.erase(it);
        }

    }
    return gold;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

    uint32_t lines;
    std::string command;
    uint32_t energy = 0;
    uint64_t gold = 0;
    std::cin >> lines;

    for (int i = 0; i < lines; i++) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> energy >> gold;
            quests[energy].push(gold);
        }
        else
        {
            std::cin >> energy;
            gold = begin(energy);
            std::cout << gold << '\n';
        }
    }

    std::cout << std::endl;
    return 0;
}
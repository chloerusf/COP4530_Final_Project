/*
std::vector<std::string> vertices1 = { "1", "2", "3", "4", "5", "6" };
std::vector<std::tuple<std::string, std::string, unsigned long>>
edges1 = { {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, {"2", "3",
10}, {"2", "4", 15}, {"3", "4", 11}, {"3", "6", 2}, {"4", "5", 6},
{"5", "6", 9} };
g.shortestPath("1", "5", path); // == 20
g.shortestPath("1", "5", path); // = { "1", "3", "6", "5" }
*/